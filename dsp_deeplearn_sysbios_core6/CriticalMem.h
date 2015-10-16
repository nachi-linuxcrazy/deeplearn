#ifndef _CRITICAL_MEM_H_INCLUDED_
#define _CRITICAL_MEM_H_INCLUDED_

#include "stdint.h"

#define 	CX_CRITICAL_SECTION_REFERENCE       0x80100000

typedef enum CRITICAL_SECTION
{
	//INPUT_DATA = 0,
	IMAGE_DATA_1 = 0,
	IMAGE_DATA_2,
	L1_MAPS,
	L2_MAPS,
	L3_MAPS,
	MAX_CRITICAL_SECTION
}CRITICAL_SECTION;

typedef struct SharedMem
{
	uint16_t		nSize;
	uint16_t		nElements;
	void*			nSegment;
}SharedMem;

extern volatile SharedMem 		*gCriticalMemRefPtr;
extern far volatile char 		*gInputdata;
extern far volatile char 		*gImageData1;
extern far volatile char 		*gImageData2;
extern far volatile char		*gL1Data;
extern far volatile char		*gL2Data;
extern far volatile char		*gL3Data;



#endif 
