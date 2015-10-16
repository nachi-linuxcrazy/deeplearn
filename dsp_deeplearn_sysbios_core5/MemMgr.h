#ifndef _MEM_MGR_H_INCLUDED_
#define _MEM_MGR_H_INCLUDED_

#include "CriticalMem.h"
#include "xdc/std.h"

void MemMgr_InitCriticalMemory(void);

#define		CORE0_ACTIVE	*((volatile BOOL*)0x81AF1A00)
#define		CORE1_ACTIVE	*((volatile BOOL*)0x81AF1A01)
#define		CORE2_ACTIVE	*((volatile BOOL*)0x81AF1A02)
#define		CORE3_ACTIVE	*((volatile BOOL*)0x81AF1A03)
#define		CORE4_ACTIVE	*((volatile BOOL*)0x81AF1A04)
#define		CORE5_ACTIVE	*((volatile BOOL*)0x81AF1A05)
#define		CORE6_ACTIVE	*((volatile BOOL*)0x81AF1A06)
#define		CORE7_ACTIVE	*((volatile BOOL*)0x81AF1A07)

#endif //_MEM_MGR_H_INCLUDED_
