#ifndef _MEM_MGR_H_INCLUDED_
#define _MEM_MGR_H_INCLUDED_

#include "CriticalMem.h"
#include "xdc/std.h"

void MemMgr_InitCriticalMemory(void);

#define		CORE0_ACTIVE	*((volatile BOOL*)0x81000000)
#define		CORE1_ACTIVE	*((volatile BOOL*)0x81000001)
#define		CORE2_ACTIVE	*((volatile BOOL*)0x81000002)
#define		CORE3_ACTIVE	*((volatile BOOL*)0x81000003)
#define		CORE4_ACTIVE	*((volatile BOOL*)0x81000004)
#define		CORE5_ACTIVE	*((volatile BOOL*)0x81000005)
#define		CORE6_ACTIVE	*((volatile BOOL*)0x81000006)
#define		CORE7_ACTIVE	*((volatile BOOL*)0x81000007)

#endif //_MEM_MGR_H_INCLUDED_
