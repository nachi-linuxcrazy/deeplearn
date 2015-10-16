#include "MemMgr.h"
#include "user_config.h"

#if (defined(_CORE0))
	
//#pragma DATA_SECTION(InputData, ".critical_section")
//char 	InputData[WIDTH][HEIGHT] ={0};

#pragma DATA_SECTION(ImageData1, ".critical_section")
char 	ImageData1[WIDTH][HEIGHT] ={0};

#pragma DATA_SECTION(ImageData2, ".critical_section")
char 	ImageData2[WIDTH][HEIGHT] ={0};

#pragma DATA_SECTION(L1Data, ".critical_section")
char 	L1Data[L1_MAPS][WIDTH/2][HEIGHT/2] ={0};

#pragma DATA_SECTION(L2Data, ".critical_section")
char 	L2Data[L2_MAPS][WIDTH/4][HEIGHT/4] ={0};

#pragma DATA_SECTION(L3Data, ".critical_section")
char 	L3Data[L3_MAPS][WIDTH/8][HEIGHT/8]={0};

#pragma DATA_SECTION(gCriticalMemRef, ".critical_section_reference")
SharedMem	gCriticalMemRef[MAX_CRITICAL_SECTION] =
{
	//WIDTH*HEIGHT, 1, (void*)&InputData[0][0],

	WIDTH*HEIGHT, 1, (void*)&ImageData1[0][0],

	WIDTH*HEIGHT, 1, (void*)&ImageData2[0][0],

	WIDTH/2*HEIGHT/2, 1,(void*)&L1Data[0][0][0],

	WIDTH/4*HEIGHT/4, 1,(void*)&L2Data[0][0][0],

	WIDTH/8*HEIGHT/8, 1,(void*)&L3Data[0][0][0],
};

volatile SharedMem *gCriticalMemRefPtr = (volatile SharedMem *)&gCriticalMemRef;

#else /* _CORE0 */

volatile SharedMem *gCriticalMemRefPtr = (SharedMem *)CX_CRITICAL_SECTION_REFERENCE;

#endif

volatile char 		*gInputdata 	= NULL;
volatile char 		*gImageData1 	= NULL;
volatile char 		*gImageData2 	= NULL;
volatile char		*gL1Data 		= NULL;
volatile char		*gL2Data 		= NULL;
volatile char		*gL3Data 		= NULL;


