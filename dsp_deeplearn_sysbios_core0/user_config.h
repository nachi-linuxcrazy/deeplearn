/*
 * user_config.h
 *
 *  Created on: Sep 30, 2015
 *      Author: chipes
 */

#ifndef USER_CONFIG_H_
#define USER_CONFIG_H_

#define WIDTH  28
#define HEIGHT  28


/* DSP Frequency */
#define DSP_FREQ_IN_MHZ				1000

#define NUM_CORES 8

#define L1_MAPS 16
#define L2_MAPS 64
#define L3_MAPS 128

#define L1_KERNEL_SIZE 9
#define L2_KERNEL_SIZE 7
#define L3_KERNEL_SIZE 5

#define		CORE_L1_SYNC	*((volatile char*)0x80000000)
#define		CORE_L2_SYNC	*((volatile char*)0x80000010)
#define		CORE_L3_SYNC	*((volatile char*)0x80000020)

#endif /* USER_CONFIG_H_ */
