//*--------------------------------------------------------------------------------------
//*                    RADM - Rotork Actuators Data acquisition Module
//*                         		(c) Synergy AST 2013
//*--------------------------------------------------------------------------------------
//* File Name           : RADM_macros.h
//* Object              : project macros
//* Creation            : Jiri Hofman 18/11/2013
//* Last modified       : Thomas Zhen 11/10/2021
//*--------------------------------------------------------------------------------------
#ifndef _RADM_macros_H_
#define _RADM_macros_H_

//*--------------------------------------------------------------------------------------
//* Revision
//*--------------------------------------------------------------------------------------
#define RADM_REV		0.00

//*--------------------------------------------------------------------------------------
//* Definition of USART port to be used for master commands bus
//*--------------------------------------------------------------------------------------
#define MASTER_CMD_USART2 	//USART2 to be used for master bus
//#define MASTER_CMD_USART6 	//USART6 to be used for master bus

//*--------------------------------------------------------------------------------------
//* Definition of development related macros
//*--------------------------------------------------------------------------------------
//#define SIMULATION_MODE 	//RADM is simulated using discovery main board

//*--------------------------------------------------------------------------------------
//* Definition of new global types
//*--------------------------------------------------------------------------------------


//*--------------------------------------------------------------------------------------
//* Definition of macros to be used for version control
//*--------------------------------------------------------------------------------------
//#define HW_PROTOTYPE //Development version
//#define HW_FINAL //Final HW release

//*--------------------------------------------------------------------------------------
//* Definition of general macros
//*--------------------------------------------------------------------------------------
#define SYS_LED_CALLS			100000	//number of loops before system LED toggles
#define CMD_PACK_MIN			8		//min length of command packet
#define CMD_PACK_MAX		   	22		//max length of command packet
#define RESP_PACK_MAX		   	30		//max length of command packet
#define CRC_INIT			 	0xFF	//initial value for CRC check
#define NR_ACT_PS			 	5		//number of actuator position switches
#define	RADM_DATA_PACK			5		//Number of measurements per packet
#define	ADAM_ATTEMPTS			3		//Number of attempts to talk to ADAM


//*--------------------------------------------------------------------------------------
//* Measurement and control related macros
//*--------------------------------------------------------------------------------------
//#define MAVG_SAMPS			 	10		//Moving average buffer size

//*--------------------------------------------------------------------------------------
//* OWB related macros
//*--------------------------------------------------------------------------------------
#define NR_TEMP_CH		   	   	1		//number of temperature channels
#define TEMP_SEN_ERR		 	1000	//temperature sensor error value
#define NR_OWB_SEN_ATTEMPTS	   	10		//number of attempts to read data from 1-Wire sensors
#define DS2480_RX_TOUT	   	   	10000	//DS2480 RX timeout 100ms (10000 * 10us = 100ms)

//*--------------------------------------------------------------------------------------
//* Definition of Status Byte bits
//*--------------------------------------------------------------------------------------
#define	SB_OK_CLK_SYNC		0xFE	// Bit 0. - synchronisation clock present
#define	SB_OK_ADAM			0xFD	// Bit 1. - ADAM module OK

#define	SB_OK_RDP_THRUST	0xEF	// Bit 4. - RDP thrust OK
#define	SB_OK_RDP_TORQUE	0xDF	// Bit 5. - RDP thrust OK
//*--------------------------------------------------------------------------------------
//* Definition of master commands - commands received by the module
//*--------------------------------------------------------------------------------------
enum MASTER_COMMANDSs
{
	CMD_NONE = 0, 			//No CMD to be executed
	CMD_PING,				//Ping module
	CMD_MEAS_START,			//CMD Start measurement
	CMD_MEAS_END,			//CMD End measurement
	CMD_SELF_TEST,			//CMD Self-test
	CMD_RADM_SETUP,			//CMD RADM setup
	CMD_ALARM_CTRL,			//CMD alarm control
	CMD_LAST				//last item in the enum = number of CMDs
};
//*--------------------------------------------------------------------------------------
//* Definition of slave commands - commands generated by the module
//*--------------------------------------------------------------------------------------
enum SLAVE_COMMANDS
{
	SCMD_PING = 0,			//Ping slave module
	SCMD_RDM_WR_ALL_REL,	//RDM  Write to all relay driver data registers
	SCMD_RADEX_SPI_SINGLE,	//RadEx SPI single byte test
	SCMD_LAST				//last item in the enum = number of CMDs
};
//*--------------------------------------------------------------------------------------
//* Definition of module modes
//*--------------------------------------------------------------------------------------
enum MODULE_MODES
{
	MM_STANDBY = 0,		//no activities
	MM_MEAS_INIT, 		//measurement activated - first sample in progress
	MM_MEAS,			//measurement running
	MM_LAST
};
//*--------------------------------------------------------------------------------------
//* Definition of RDP meters
//*--------------------------------------------------------------------------------------
enum RDP_METERS
{
	RDP_THRUST = 0,	//RDP meter for thrust measurement
	RDP_TORQUE,		//RDP meter for torque measurement
	RDP_LAST
};
//*--------------------------------------------------------------------------------------
//* Definition of USARTS
//*--------------------------------------------------------------------------------------
enum USARTS_NR
{
	USART_1 = 0,
	USART_2,
	USART_3,
	USART_4,
	USART_5,
	USART_6,
	USART_LAST
};
//*--------------------------------------------------------------------------------------
//* Definition of UART4 devices
//*--------------------------------------------------------------------------------------
enum UART4_SW_DEV
{
	UART4_SW_RDM = 0,
	UART4_SW_OWB,
	UART4_SW_SPARE1,
	UART4_SW_SPARE2,
	UART4_SW_LAST
};

//*--------------------------------------------------------------------------------------
//* Definition of Slave module Types
//*--------------------------------------------------------------------------------------
//Here to add module
#define SMT_RADEX  				0x0D	//Module RadEx
#define SMT_RDM   				0x11	//Module RDM
#define SMT_RADMS 				0x12	//Module RADMS

//*--------------------------------------------------------------------------------------
//* Definition of UART timeouts
//*--------------------------------------------------------------------------------------
#define UART_TOUT_100MS			10000	//UART timeout 100ms (10000*10us)
#define UART_TOUT_1S 			100000	//UART timeout 1s (100000*10us)

//*--------------------------------------------------------------------------------------
//* EVE module SPI transmit direction
//*--------------------------------------------------------------------------------------
enum EVE_SPI_DIR
{
	EVE_SPI_READ = 0,	//Read memory data from EVE
	EVE_SPI_WRITE,		//Write memory data to EVE
	EVE_SPI_LAST
};
//*--------------------------------------------------------------------------------------
//* Definition of source position states
//*--------------------------------------------------------------------------------------
enum SOURCE_POS
{
	SOURCE_POS_DOWN = 0,	//Source UP
	SOURCE_POS_UP,			//Source DOWN
	SOURCE_POS_LAST
};
//*--------------------------------------------------------------------------------------
//* Definition of SPI slave devices
//*--------------------------------------------------------------------------------------
//enum SPI_DEVICES
//{
//	SPI_DEV_ADS1211 = 0,	//ADS1211 ADC
//	SPI_DEV_LAST
//};
//*--------------------------------------------------------------------------------------
//* Definition of Sleep intervals
//*--------------------------------------------------------------------------------------
#define SLEEP_2				20 		//2ms
#define SLEEP_5				50 		//5ms
#define SLEEP_10			100 	//10ms
#define SLEEP_20			200 	//20ms
#define SLEEP_100			1000 	//100ms
#define SLEEP_800			8000	//800ms
#define SLEEP_1000			10000 	//1s

#endif /*_RADM_macros_H_*/
//*----------------------------end of file RADM_macros.h--------------------------------
