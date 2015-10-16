#include "MemMgr.h"
#include "user_config.h"

#ifdef _CORE0
	
//#pragma DATA_SECTION(InputData, ".critical_section")
//char 	InputData[WIDTH][HEIGHT] ={0};

//#pragma DATA_SECTION(ImageData2, ".critical_section")
//#pragma DATA_ALIGN(ImageData2,4)
//char 	ImageData2[WIDTH][HEIGHT] ={{0}};

#pragma DATA_SECTION(L1Data1, ".critical_section")
#pragma DATA_ALIGN(L1Data1,4)
char 	L1Data1[L1_MAPS][WIDTH/2][HEIGHT/2] ={{{0}}};


//#pragma DATA_SECTION(L1Data3, ".critical_section")
//#pragma DATA_ALIGN(L1Data3,4)
//char 	L1Data3[L1_MAPS][WIDTH/2][HEIGHT/2] ={{{0}}};

#pragma DATA_SECTION(L2Data1, ".critical_section")
#pragma DATA_ALIGN(L2Data1,4)
char 	L2Data1[L2_MAPS][WIDTH/4][HEIGHT/4] ={{{0}}};


//#pragma DATA_SECTION(L2Data3, ".critical_section")
//#pragma DATA_ALIGN(L2Data3,4)
//char 	L2Data3[L2_MAPS][WIDTH/4][HEIGHT/4] ={{{0}}};

#pragma DATA_SECTION(L3Data1, ".critical_section")
#pragma DATA_ALIGN(L3Data1,4)
char 	L3Data1[L3_MAPS][WIDTH/8][HEIGHT/8]={{{0}}};

//#pragma DATA_SECTION(L3Data2, ".critical_section")
//#pragma DATA_ALIGN(L3Data2,4)
//char 	L3Data2[L3_MAPS][WIDTH/8][HEIGHT/8]={{{0}}};
//
//#pragma DATA_SECTION(L3Data3, ".critical_section")
//#pragma DATA_ALIGN(L3Data3,4)
//char 	L3Data3[L3_MAPS][WIDTH/8][HEIGHT/8]={{{0}}};

#pragma DATA_SECTION(gCriticalMemRef, ".critical_section_reference")
SharedMem	gCriticalMemRef[MAX_CRITICAL_SECTION] =
{
	//WIDTH*HEIGHT, 1, (void*)&InputData[0][0],

	//WIDTH*HEIGHT, 1, (void*)&ImageData1[0][0],

	//WIDTH*HEIGHT, 1, (void*)&ImageData2[0][0],

	WIDTH/2*HEIGHT/2, 1,(void*)&L1Data1[0][0][0],

	//WIDTH/2*HEIGHT/2, 1,(void*)&L1Data2[0][0][0],

	//WIDTH/2*HEIGHT/2, 1,(void*)&L1Data3[0][0][0],

	WIDTH/4*HEIGHT/4, 1,(void*)&L2Data1[0][0][0],

	//WIDTH/4*HEIGHT/4, 1,(void*)&L2Data2[0][0][0],

	//WIDTH/4*HEIGHT/4, 1,(void*)&L2Data3[0][0][0],

	WIDTH/8*HEIGHT/8, 1,(void*)&L3Data1[0][0][0],

	//WIDTH/8*HEIGHT/8, 1,(void*)&L3Data2[0][0][0],

	//WIDTH/8*HEIGHT/8, 1,(void*)&L3Data3[0][0][0],

};

volatile SharedMem *gCriticalMemRefPtr = (volatile SharedMem *)&gCriticalMemRef;

#else /* _CORE0 */

volatile SharedMem *gCriticalMemRefPtr = (SharedMem *)CX_CRITICAL_SECTION_REFERENCE;

#endif

volatile char 	*gInputdata 	= NULL;
//volatile char 	*gImageData1 	= NULL;
//volatile char 	*gImageData2 	= NULL;
volatile char   *gL1Data1       = NULL;
//volatile char   *gL1Data2       = NULL;
//volatile char   *gL1Data3       = NULL;
volatile char	*gL2Data1 		= NULL;
//volatile char	*gL2Data2 		= NULL;
//volatile char	*gL2Data3 		= NULL;
volatile char	*gL3Data1		= NULL;
//volatile char	*gL3Data2		= NULL;
//volatile char	*gL3Data3		= NULL;


