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
	//memset((void*)gImageData1, 0, gCriticalMemRefPtr[IMAGE_DATA_1].nSize*gCriticalMemRefPtr[IMAGE_DATA_1].nElements);
	//memset((void*)gImageData2, 0, gCriticalMemRefPtr[IMAGE_DATA_2].nSize*gCriticalMemRefPtr[IMAGE_DATA_2].nElements);
	memset((void*)gL1Data1, 0, gCriticalMemRefPtr[L1_MAPS1].nSize*gCriticalMemRefPtr[L1_MAPS1].nElements);
	//memset((void*)gL1Data2, 0, gCriticalMemRefPtr[L1_MAPS2].nSize*gCriticalMemRefPtr[L1_MAPS2].nElements);
	//memset((void*)gL1Data3, 0, gCriticalMemRefPtr[L1_MAPS3].nSize*gCriticalMemRefPtr[L1_MAPS3].nElements);
	memset((void*)gL2Data1, 0, gCriticalMemRefPtr[L2_MAPS1].nSize*gCriticalMemRefPtr[L2_MAPS1].nElements);
	//memset((void*)gL2Data2, 0, gCriticalMemRefPtr[L2_MAPS2].nSize*gCriticalMemRefPtr[L2_MAPS2].nElements);
	//memset((void*)gL2Data3, 0, gCriticalMemRefPtr[L2_MAPS3].nSize*gCriticalMemRefPtr[L2_MAPS3].nElements);
	memset((void*)gL3Data1, 0, gCriticalMemRefPtr[L3_MAPS1].nSize*gCriticalMemRefPtr[L3_MAPS1].nElements);
	//memset((void*)gL3Data2, 0, gCriticalMemRefPtr[L3_MAPS2].nSize*gCriticalMemRefPtr[L3_MAPS2].nElements);
	//memset((void*)gL3Data3, 0, gCriticalMemRefPtr[L3_MAPS3].nSize*gCriticalMemRefPtr[L3_MAPS3].nElements);
#endif

	gInputdata 		= (char*) in_img;
	//gImageData1 	= (char*)(gCriticalMemRefPtr[IMAGE_DATA_1].nSegment);
	//gImageData2 	= (char*)(gCriticalMemRefPtr[IMAGE_DATA_2].nSegment);
	gL1Data1 		= (char*)(gCriticalMemRefPtr[L1_MAPS1].nSegment);
	//gL1Data2 		= (char*)(gCriticalMemRefPtr[L1_MAPS2].nSegment);
	//gL1Data3		= (char*)(gCriticalMemRefPtr[L1_MAPS3].nSegment);
	gL2Data1 		= (char*)(gCriticalMemRefPtr[L2_MAPS1].nSegment);
	//gL2Data2 		= (char*)(gCriticalMemRefPtr[L2_MAPS2].nSegment);
	//gL2Data3 		= (char*)(gCriticalMemRefPtr[L2_MAPS3].nSegment);
	gL3Data1 		= (char*)(gCriticalMemRefPtr[L3_MAPS1].nSegment);
	//gL3Data2 		= (char*)(gCriticalMemRefPtr[L3_MAPS2].nSegment);
	//gL3Data3 		= (char*)(gCriticalMemRefPtr[L3_MAPS3].nSegment);
}












