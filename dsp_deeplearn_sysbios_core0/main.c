/*******************************************************
* File Name -- main.c
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
#include <csl_tsc.h>
#include <csl_chipAux.h>
#include <tistdtypes.h>
#include <csl_types.h>
#include <csl_cacheAux.h>
#include "c6x.h"
#include "deep_learning.h"
#include "user_config.h"
#include "res/img_dd_28x28.h"


void delaycycles(uint32_t cycles)
{
	uint32_t start_val  = CSL_chipReadTSCL();

	while ((CSL_chipReadTSCL() - start_val) < cycles);

	return;
}

void main()
{
	CSL_Uint64        startVal,endVal;
	uint8_t core_id = DNUM;

    CSL_tscEnable();

	CACHE_setL2Size (CACHE_0KCACHE);
	CACHE_setL1DSize(CACHE_L1_32KCACHE);
	CACHE_disableCaching (128);

#ifdef _CORE0
	memset((void*)0x80001000,0x0,0x40); //clear all the flag bytes
    printf("Given input image size: %dx%d \n", WIDTH, HEIGHT);
#endif

//    CORE_ALL_ACTIVE = CORE_ALL_ACTIVE +1;
//    while(CORE_ALL_ACTIVE != NUM_CORES);
//	*((char *)0x80001030) = *((char *)0x80001030) | (1<<core_id);
//	while(0xFF == *((char * )0x80001030));
//  while(memcmp((const void*)0x80001030,&value,1));

    startVal = CSL_tscRead();
    deeplearn((uint8_t*)in_img, WIDTH, HEIGHT);
    endVal = CSL_tscRead();

    printf (" Timetaken is %lf us\n", (double)(endVal-startVal)/DSP_FREQ_IN_MHZ);

}
