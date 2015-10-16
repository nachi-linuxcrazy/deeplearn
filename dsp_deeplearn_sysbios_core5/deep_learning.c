/*******************************************************
* File Name -- deep_learn.c
*
* Authors:  Nachiappan, Gourav, Mahesh
*
* Created on : 27-September-2015
*
* Contents: Deeplearn algorithm implementation
*           for TI TMS320C6678 - DSP
*
********************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "user_config.h"
#include <csl_tsc.h>

#include "imglib.h"
#include "DSP_maxval.h"
#include "IMG_conv_9x9_i8_c8s_cn.h"
#include "DSPF_sp_dotprod.h"

#include "inc/kernel.h"
#include "inc/kernel_3x3.h"
#include "inc/kernel_5x5.h" /*TODO*/
#include "inc/kernel_7x7.h"
#include "inc/kernel_9x9.h"
#include "inc/weights.h"

signed char* data1 = NULL;
signed char* data2 = NULL;
signed char* dilate = NULL;

static float * fData  = NULL;
static float * fData1 = NULL;
static float * fData2 = NULL;
static float * fData3 = NULL;

static signed char* pL1Data[L1_MAPS];
static signed char* pL2Data[L2_MAPS];
static signed char* pL3Data[L3_MAPS];

uint8_t initializeData(uint32_t w, uint32_t h)
{
    int i;
	data1 = (signed char*)memalign(4,w*h);
	data2 = (signed char*)memalign(4,w*h);
	dilate= (signed char*)memalign(8,9);

    fData  = (float*)memalign(8,104 * sizeof(float));
    fData1 = (float*)memalign(8,104 * sizeof(float));
    fData2 = (float*)memalign(8,104 * sizeof(float));
    fData3 = (float*)memalign(8,104 * sizeof(float));

    for (i = 0; i<L1_MAPS; i++)
    {
    	pL1Data[i] = (signed char*)memalign(4,w/2*h/2);
    }

    for (i = 0; i<L2_MAPS; i++)
    {
    	pL2Data[i] = (signed char*)memalign(4,w/4*h/4);
    }

    for (i = 0; i<L3_MAPS; i++)
    {
    	pL3Data[i] = (signed char*)memalign(4,w/8*h/8);
    }

    return 0;
}

uint8_t deinitializeData()
{
    uint8_t i;

    free(data1);
    free(data2);
    free(dilate);

    free(fData);
    free(fData1);
    free(fData2);
    free(fData3);

    for ( i = 0; i<L1_MAPS; i++)
    {
        free(pL1Data[i]);
    }
    for (i = 0; i<L2_MAPS; i++)
    {
        free(pL2Data[i]);
    }
    for (i = 0; i<L3_MAPS; i++)
    {
        free(pL3Data[i]);
    }
    return 0;
}

int find_maximum(signed char a[], int n)
{
    int c, max, index;

    max = a[0];
    index = 0;

    for (c = 1; c < n; c++)
    {
        if (a[c] > max)
        {
            index = c;
            max = a[c];
        }
    }

    return index;
}

static void Dilate3x3(unsigned char *image, unsigned char *dest_image, int M, int N)
{
    const char kernel[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int row, col;
    int location;
    memset(dilate,0x0,9);
    for (row = 0; row < M; row++)
    {
        for (col = 0; col < N; col++)
        {
        	IMG_conv_3x3_i8_c8s(image,(unsigned char *)dilate,9,N,kernel,0);
            location = find_maximum(dilate, 9); 		/*TODO: DSP_maxval/DSPF_sp_maxval*/
            *(dest_image + N*row + col) = dilate[location];
        }
    }
}

static void SubSampleBy2Fun(uint8_t *image, uint8_t *dest_image, int R, int C)
{
    int row, col;
    for (row = 0; row < R; row++)
    {
        for (col = 0; col <C; col++)
        {
            *(dest_image + C*row + col) = (*(image + 2 * (C*row + col) + 1));
        }

    }
}

static void s_img_add_weighted(uint8_t *image1, uint8_t *image2, int M, int N, int scale)
{
   int row,col;
   for (row = 0; row < M; row++)
   {
       for (col = 0; col < N; col++)
       {
        	   *(image2 + N*row + col) = (*(image1 + N*row + col) + *(image2 + N*row + col)) >> scale;
       }
   }
}

uint32_t operateLayer1(uint8_t** src, uint32_t w, uint32_t h)
{
    uint8_t i;
    uint32_t j;
    const unsigned char *src_ptr = *src;
    short pixels = w*h;
    short shift = 0;

    for (i = 0; i<L1_MAPS; i++)
    {
    	IMG_conv_9x9_i8_c8s_cn (src_ptr, (unsigned char*)data1, pixels, h,(const char*) &kernel9x9[i][0],shift); /*TODO* 9x9 */
        for (j=0; j<w*h; j++)
        {
        	data1[j] = ((data1[j] < 0) ? 0 : data1[j]);
        }
        Dilate3x3((unsigned char*)data1,(unsigned char*) data1, w, h);
        SubSampleBy2Fun((uint8_t*)data1, (uint8_t*)pL1Data[i], w/2, h/2);
    }
    return 0;
}

uint32_t operateLayer2(uint32_t w, uint32_t h)
{
    uint8_t i,k;
    uint32_t j;
    uint8_t selection;
    signed char* ptr1 = NULL;
    signed char* ptr2 = NULL;
    short pixels = w*h;
    short shift = 0;

    for (i = 0; i<L2_MAPS; i++)
    {
    	selection = rand() % L1_MAPS;
        ptr1 = pL1Data[selection];
        for(k=0;k<1;k++)
        {
        	selection = rand() % L1_MAPS;
        	ptr2 = pL1Data[selection];
        	s_img_add_weighted((uint8_t*)ptr1,(uint8_t*)ptr2,w,h,1);
        }
        IMG_conv_7x7_i8_c8s ((unsigned char*)ptr2,(unsigned char*)ptr2, pixels, h, &kernel7x7[i][0],shift);
        for (j=0; j<w*h; j++)
        {
        	ptr2[j] = ((ptr2[j] < 0) ? 0 : ptr2[j]);
        }
        Dilate3x3((unsigned char*)ptr2, (unsigned char*)ptr2, w, h);
        SubSampleBy2Fun((uint8_t*)ptr2, (uint8_t*)pL2Data[i], w/2, h/2);
    }

    return 0;
}

uint32_t operateLayer3(uint32_t w, uint32_t h)
{
    uint8_t i,k;
    uint32_t j;
    uint8_t selection;
    signed char* ptr1 = NULL;
    signed char* ptr2 = NULL;
    short pixels = w*h;
    short shift = 0;

    for (i = 0; i<L3_MAPS; ++i)
    {
    	selection = rand() % L2_MAPS;
        ptr1 = pL2Data[selection];
        for(k=0;k<1;k++) /*TODO*/
        {
        	selection = rand() % L2_MAPS;
        	ptr2 = pL2Data[selection];
        	s_img_add_weighted((uint8_t*)ptr1,(uint8_t*)ptr2,w,h,1);
        }
        IMG_conv_5x5_i8_c8s((unsigned char*)ptr2,(unsigned char*)ptr2, pixels, h, &kernel5x5[i][0],shift);
        for (j=0; j<w*h; j++)
        {
        	ptr2[j] = ((ptr2[j] < 0) ? 0 : ptr2[j]);
        }
        Dilate3x3((unsigned char*)ptr2, (unsigned char*)ptr2, w, h);
        SubSampleBy2Fun((uint8_t*)ptr2, (uint8_t*)pL3Data[i], w/2, h/2);

    }

    return 0;
}

uint8_t MaxValue(uint8_t *image1, int M, int N)
{
    int row, col;
    uint8_t max;

    max = image1[0]; //1st element

    for (row = 0; row < M; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (*(image1 + N* row + col) > max)
            {
                max = (*(image1 + N* row + col));
            }
        }
    }

    return max;
}


uint8_t classifier(uint8_t** src_initial, int w, int h)
{
    uint8_t  maxVal;
    uint32_t index;
    uint8_t* src = *src_initial;
    float   sum;
    const float * const fKernel = input_weights[0];

    //Normalize.
    maxVal = MaxValue(src, w,h);
    //maxVal = DSP_maxval(src,w*h);

    for (index = 0; index<104; index++)
    {
        fData[index] = (float)(src[index] / maxVal);
    }

    //Input layer.
    for (index = 0; index<104; index++)
    {
        sum = DSPF_sp_dotprod(fData,fKernel,104);
        fData1[index] = (float)tanh(sum);
    }
    //Hidden Layer.
    for (index = 0; index<104; index++)
    {
        sum = DSPF_sp_dotprod(fData1,fKernel,104);
        fData2[index] = (float)tanh(sum);
    }
    //Output Layer.
    for (index = 0; index<104; index++)
    {
        sum = DSPF_sp_dotprod(fData1,fKernel,104);
        fData3[index] = (float)tanh(sum);
    }

    return 0;
}


uint8_t deeplearn(uint8_t* data, uint32_t w, uint32_t h)
{
	CSL_Uint64  startVal,endVal;

    startVal = CSL_tscRead();
    operateLayer1(&data, w, h);
    endVal = CSL_tscRead();
    printf ("L1 %lf \n", (double)(endVal-startVal)/DSP_FREQ_IN_KHZ);

    startVal = CSL_tscRead();
    operateLayer2(w / 2, h / 2);
    endVal = CSL_tscRead();
    printf ("L2 %lf \n", (double)(endVal-startVal)/DSP_FREQ_IN_KHZ);

    startVal = CSL_tscRead();
    operateLayer3(w / 4, h / 4);
    endVal = CSL_tscRead();
    printf ("L3 %lf \n", (double)(endVal-startVal)/DSP_FREQ_IN_KHZ);

    startVal = CSL_tscRead();
    classifier(&data, w / 8, h / 8);
    endVal = CSL_tscRead();
    printf ("classifier %lf \n", (double)(endVal-startVal)/DSP_FREQ_IN_KHZ);

    return 0;

}
