#ifndef _CRITICAL_MEM_H_INCLUDED_
#define _CRITICAL_MEM_H_INCLUDED_

#include "stdint.h"

#define 	CX_CRITICAL_SECTION_REFERENCE       0x80000000

typedef enum CRITICAL_SECTION
{
	//INPUT_DATA = 0,
	//IMAGE_DATA_1 = 0,
	//IMAGE_DATA_2,
	L1_MAPS1,
	//L1_MAPS2,
	//L1_MAPS3,
	L2_MAPS1,
	//L2_MAPS2,
	//L2_MAPS3,
	L3_MAPS1,
	//L3_MAPS2,
	//L3_MAPS3,
	MAX_CRITICAL_SECTION
}CRITICAL_SECTION;

typedef struct SharedMem
{
	uint16_t		nSize;
	uint16_t		nElements;
	void*			nSegment;
}SharedMem;

extern volatile SharedMem 		*gCriticalMemRefPtr;
extern far volatile char 	*gInputdata;
//extern far volatile char 	*gImageData1;
//extern far volatile char 	*gImageData2;
extern far volatile char    *gL1Data1;
//extern far volatile char    *gL1Data2;
//extern far volatile char    *gL1Data3;
extern far volatile char	*gL2Data1;
//extern far volatile char	*gL2Data2;
//extern far volatile char	*gL2Data3;
extern far volatile char	*gL3Data1;
//extern far volatile char	*gL3Data2;
//extern far volatile char	*gL3Data3;


#endif 
