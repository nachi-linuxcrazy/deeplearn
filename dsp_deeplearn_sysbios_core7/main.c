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
#include "CriticalMem.h"
#include "deep_learning.h"
#include "user_config.h"

void main()
{
	CSL_Uint64        startVal,endVal;

    printf("Given input image size: %dx%d \n", WIDTH, HEIGHT);
    CSL_tscEnable();
    startVal = CSL_tscRead();

    initializeData(WIDTH, HEIGHT);
    deeplearn((uint8_t*)gInputdata, WIDTH, HEIGHT);
    deinitializeData();

    endVal = CSL_tscRead();
    printf (" Timetaken is %lf ms\n", (double)(endVal-startVal)/DSP_FREQ_IN_KHZ);

}
