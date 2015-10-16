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
#include <csl_tsc.h>
#include <tistdtypes.h>
#include <csl_types.h>
#include <csl_cacheAux.h>

#include "deep_learning.h"
#include "user_config.h"
#include "res/img_dd_28x28.h"

void main()
{
	CSL_Uint64        startVal,endVal;

	CACHE_disableCaching (128);
	CORE_L1_SYNC = 0x0;
	CORE_L2_SYNC = 0x0;
	CORE_L3_SYNC = 0x0;

    printf("Given input image size: %dx%d \n", WIDTH, HEIGHT);
    CSL_tscEnable();
    startVal = CSL_tscRead();

    //initializeData(WIDTH, HEIGHT);
    //MemMgr_InitCriticalMemory();
    deeplearn((uint8_t*)in_img, WIDTH, HEIGHT);
    //deinitializeData();

    endVal = CSL_tscRead();
    printf (" Timetaken is %lf us\n", (double)(endVal-startVal)/DSP_FREQ_IN_MHZ);

}
