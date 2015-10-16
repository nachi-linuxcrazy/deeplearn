#include "CriticalMem.h"
#include "MemMgr.h"
#include "string.h"
#include "xdc/std.h"

#include "res/img_dd_28x28.h"

void MemMgr_InitCriticalMemory()
{

#ifdef _CORE0
	gInputdata 		= (char*) in_img;
	//memset((void*)gInputdata, 0, gCriticalMemRefPtr[INPUT_DATA].nSize*gCriticalMemRefPtr[INPUT_DATA].nElements);
	memset((void*)gImageData1, 0, gCriticalMemRefPtr[IMAGE_DATA_1].nSize*gCriticalMemRefPtr[IMAGE_DATA_1].nElements);
	memset((void*)gImageData2, 0, gCriticalMemRefPtr[IMAGE_DATA_2].nSize*gCriticalMemRefPtr[IMAGE_DATA_2].nElements);
	memset((void*)gL1Data, 0, gCriticalMemRefPtr[L1_MAPS].nSize*gCriticalMemRefPtr[L1_MAPS].nElements);
	memset((void*)gL2Data, 0, gCriticalMemRefPtr[L2_MAPS].nSize*gCriticalMemRefPtr[L2_MAPS].nElements);
	memset((void*)gL3Data, 0, gCriticalMemRefPtr[L3_MAPS].nSize*gCriticalMemRefPtr[L3_MAPS].nElements);
#endif

	gInputdata 		= (char*) in_img;
	gImageData1 	= (char*)(gCriticalMemRefPtr[IMAGE_DATA_1].nSegment);
	gImageData2 	= (char*)(gCriticalMemRefPtr[IMAGE_DATA_2].nSegment);
	gL1Data 		= (char*)(gCriticalMemRefPtr[L1_MAPS].nSegment);
	gL2Data 		= (char*)(gCriticalMemRefPtr[L2_MAPS].nSegment);
	gL3Data 		= (char*)(gCriticalMemRefPtr[L3_MAPS].nSegment);
}












