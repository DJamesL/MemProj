/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CPU_Config.h
**     Project     : memproj_cpu
**     Processor   : MC56F82748VLH
**     Version     : Component 01.055, Driver 01.00, CPU db: 3.50.001
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2017-10-18, 11:12, # CodeGen: 2
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file CPU_Config.h                                                  
** @version 01.00
*/         
/*!
**  @addtogroup CPU_Config_module CPU_Config module documentation
**  @{
*/         

#ifndef __CPU_Config_H
#define __CPU_Config_H

/* MODULE CPU_Config.h */

/* Include C integer types declaration header */
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Component method constants. Internal methods are not included. */

#define CPU_SET_CLOCK_CONFIGURATION                        0x00U      
#define CPU_GET_CLOCK_CONFIGURATION                        0x00U      
#define CPU_SET_OPERATION_MODE                             0x00U      
#define CPU_ENABLE_INT                                     0x01U      
#define CPU_DISABLE_INT                                    0x01U      
#define CPU_GET_RESET_SOURCE                               0x00U      
#define CPU_SET_WAIT_MODE                                  0x01U      
#define CPU_SET_STOP_MODE                                  0x01U      
#define CPU_GET_BUS_FREQ_HZ                                0x00U      
#define CPU_OPEN_BACKDOOR                                  0x00U      
#define CPU_SET_FLEX_RAM_FUNCTION                          0x00U      
#define CPU_SET_FLEX_NVM_PARTITION                         0x00U      
#define CPU_INIT_SHADOW_REGS                               0x00U      
#define CPU_DELAY_100US                                    0x00U      
#define CPU_ENABLE_PLL                                     0x00U      


/* Declaration of types used in static CPU module */

/* Clock source enumeration declaration. Used in SetClockConfiguration method */
typedef enum {
  CPU_CLOCK_SOURCE_INTERNAL_FAST,
  CPU_CLOCK_SOURCE_INTERNAL_SLOW,
  CPU_CLOCK_SOURCE_EXTERNAL
} TCpuClockSource;

/* PLL enable control type declaration. Used in SetClockConfiguration method */
typedef uint16_t TCpuPllEnabled;

/* Clock divider type declaration. Used in SetClockConfiguration method */
typedef uint16_t TCpuClockDivider;

/* Clock rate register type declaration. Used in SetClockConfiguration method */
typedef uint16_t TCpuClockRate;

/* Peripheral bus clock frequency type declaration. Used in CPU_GetBusFreqHz method */
typedef uint32_t TCpuBusFreqHz;

#define CPU_CLOCK_CONFIGURATIONS_NUMBER                    0x01U     /* Number of set clock configurations */ 
#define CPU_CLOCK_CONFIGURATION_0                          0x00U     /* Clock configuration 0 CPU_Init module identifier */ 

/* After reset values optimization */

/* Property: Common settings\Utilize after reset values */
#define CPU_AFTER_RESET_VALUES                             0x00U     /* After reset values optimization is disabled */ 

/* 
   Startup - parameterization
   
   Following constants contains parameterization of the MCU startup sequence 
   placed in the _EntryPoint() method according to Processor Expert 
   CPU component settings but can be used to parameterize any user startup 
   code.   
   Values of the constants are generated from the component properties 
   specified in comments. If not specified differently, value 0 = feature 
   disabled and 1 = feature enabled. If constant has no defined value it 
   means feature is not available.
*/
  
/* Fast interrupts initialization */
  
/* Fast interrupt 0 */
#define STARTUP_FAST_INT_0                                 0x00U     /* Fast interrupt 0 not initialized */ 
/* Fast interrupt 1 */
#define STARTUP_FAST_INT_1                                 0x00U     /* Fast interrupt 1 not initialized */ 
  
/* MCU timing initialization */
  
/* Internal clock */
/* Properties: Clock settings\Internal oscillator\Internal 200kHz relaxation oscillator and 
               Clock settings\Internal oscillator\Internal 8MHz relaxation oscillator */
#define STARTUP_CLOCK_INTERNAL                             0x01U     /* Internal clock source enabled */ 
/* Internal clock: 200kHz */
/* Property: Clock settings\Internal oscillator\Internal 200kHz relaxation oscillator */
#define STARTUP_CLOCK_INTERNAL_SLOW                        0x00U     /* 200KHz internal clock source disabled */ 
/* Property: Clock settings\Internal oscillator\Internal 200kHz relaxation oscillator\Initialize frequency trim */
#define STARTUP_CLOCK_INTERNAL_SLOW_FREQ_TRIM                        /* 200KHz internal clock source factory trim not used */
/* Property: Clock settings\Internal oscillator\Internal 200kHz relaxation oscillator\Initialize frequency trim\Frequency trim value address */
#define STARTUP_CLOCK_INTERNAL_SLOW_FREQ_TRIM_VALUE                  /* 200KHz internal clock source factory trim value not used */
/* Internal clock: 8MHz */
/* Property: Clock settings\Internal oscillator\Internal 8MHz relaxation oscillator */
#define STARTUP_CLOCK_INTERNAL_FAST                        0x01U     /* 8MHz internal relaxation oscillator enabled */ 
/* Property: Clock settings\Internal oscillator\Internal 8MHz relaxation oscillator\Initialize frequency trim */
#define STARTUP_CLOCK_INTERNAL_FAST_FREQ_TRIM              0x01U     /* 8MHz internal relaxation oscillator factory frequency trim used */ 
/* Property: Clock settings\Internal oscillator\Internal 8MHz relaxation oscillator\Initialize frequency trim\Frequency trim value address */
#define STARTUP_CLOCK_INTERNAL_FAST_FREQ_TRIM_VALUE        ((*(uint16_t *)0xE42C) & 0x3FFU) /* Masked, not shifted 8MHz internal relaxation oscillator factory frequency trim value */
/* Property: Clock settings\Internal oscillator\Internal 8MHz relaxation oscillator\Initialize temperature trim */
#define STARTUP_CLOCK_INTERNAL_FAST_TEMP_TRIM              0x00U     /* 8MHz internal relaxation oscillator factory temperature trim not used */ 
 /* Property: Clock settings\Internal oscillator\Internal 8MHz relaxation oscillator\Initialize frequency trim\Temperature trim value address */
#define STARTUP_CLOCK_INTERNAL_FAST_TEMP_TRIM_VALUE                  /* 8MHz internal relaxation oscillator factory temperature trim value not used */
/* External clock */
/* Property: Clock settings\External reference clock */
#define STARTUP_CLOCK_EXTERNAL                             0x00U     /* External reference clock not used */ 
/* External clock select: 0 = External crystal, 1 = External clock input 0, 2 = External clock input 1, no value = External reference disabled */
/* Property: Clock settings\External reference clock\Clock source */
#define STARTUP_CLOCK_EXTERNAL_SELECT                                /* External reference clock not used */
/* Clock select: 0 = Internal 8MHz, 1 = Internal 200KHz, 2 = External */
/* Property: Clock settings\Clock configurations\Clock configuration 0\Input clock source */
#define STARTUP_CLOCK_SOURCE_SELECT                        0x00U     /* Select 8MHz relaxation oscillator as clock source for the CPU core */ 
/* PLL */
/* Properties: Clock settings\Clock configurations\Clock configuration 0\PLL clock and
               Clock settings\Clock configurations\Clock configuration 0\PLL clock\Enable PLL after reset */
#define STARTUP_PLL                                        0x01U     /* Enable PLL */ 
  
/* PLL interrupts */

/* PLL interrupts */
/* Property: CPU interrupts\Interrupt PLL */
#define STARTUP_PLL_INT                                    0x00U     /* PLL interrupt disabled */ 
/* Lock detector interrupt: 0 = disabled, 1 = rising range, 2 = falling edge, 3 = both edges, no value = all PLL interrupts disabled */
/* Property: CPU interrupts\Interrupt PLL\Lock detector 0 */
#define STARTUP_PLL_INT_LOCK_0                                       /* PLL interrupts disabled */
/* Property: CPU interrupts\Interrupt PLL\Lock detector 1 */
#define STARTUP_PLL_INT_LOCK_1                                       /* PLL interrupts disabled */
/* Property: CPU interrupts\Interrupt PLL\Loss of reference */
#define STARTUP_PLL_INT_REFERENCE                                    /* PLL interrupts disabled */
/* PLL interrupt priority: 0 = disabled, 1 = level 1, 2 = level 2, 3 = level 3, 4 = fast interrupt 0, 5 = fast interrupt 1, 6 = fast interrupt */
/* Property: CPU interrupts\Interrupt PLL\Interrupt priority */
#define STARTUP_PLL_INT_PRIORITY                                     /* PLL interrupts disabled */
  
/* Peripheral clock rates */
  
/* Peripheral clock rate: 0 = bus clock, 1 = 2x bus clock */
/* Property: Clock settings\Clock configurations\Clock configuration 0\Peripheral clock rates\QSCI0 clock rate */
#define STARTUP_CLOCK_RATE_QSCI0                           0x00U     /* Bus clock */ 
/* Property: Clock configurations\Clock configuration 0\Peripheral clock rates\QSCI1 clock rate */
#define STARTUP_CLOCK_RATE_QSCI1                           0x00U     /* Bus clock */ 
/* Property: Clock configurations\Clock configuration 0\Peripheral clock rates\TMR clock rate */
#define STARTUP_CLOCK_RATE_TMR                             0x00U     /* Bus clock */ 
/* Property: Clock configurations\Clock configuration 0\Peripheral clock rates\PWM clock rate */
#define STARTUP_CLOCK_RATE_PWM                             0x01U     /* 2x bus clock */ 
/* Property: Clock configurations\Clock configuration 0\Peripheral clock rates\I2C clock rate */
#define STARTUP_CLOCK_RATE_I2C                             0x00U     /* Bus clock */ 
  
/* Clock registers protection */

/* Protection: 0 = Off, 1 = On, 2 = Off and locked, 3 = On and locked */
/* Property: Clock settings\Clock protection\Frequency */
#define STARTUP_CLOCK_PROTECTION_FREQUENCY                 0x00U     /* Frequency protection off */ 
/* Property: Clock settings\Clock protection\Oscillator */
#define STARTUP_CLOCK_PROTECTION_OSCILLATOR                0x00U     /* Oscillator protection off */ 
/* Property: Clock settings\Clock protection\Oscillator */
#define STARTUP_CLOCK_PROTECTION_PLL                       0x00U     /* PLL protection off */ 
  
/* Fast mode */
  
/* Property: Clock settings\Dual speed clock */
#define STARTUP_FAST_MODE                                  0x00U      
  
/* Watchdog initialization */

/* Property: Common settings\Watchdog */
#define STARTUP_WDOG                                       0x00U      
  
/* 
   Startup - register values
   
   Following constants represents the full set of registers accessed during 
   MCU startup sequence placed in the _EntryPoint() method and their values depends 
   on Processor Expert CPU component settings. 
   The constants have values of registers after the startup is finished.
   Although the list of registers accessed during the startup sequence may vary 
   across different CPU component settings, following constants represents 
   a superset of all registers which might be accessed. If register or register 
   bitfield is not modified during the particular startup sequence
   then its after reset value is presented.
   If register or register bitfield is accessed multiple times during the startup
   then the last written value is used.
*/

/* OCCS */

#define STARTUP_OCCS_CTRL_VALUE                            0x81U     /* OCCS_CTRL value */ 
#define STARTUP_OCCS_DIVBY_VALUE                           0x2131U   /* OCCS_DIVBY value */ 
#define STARTUP_OCCS_STAT_VALUE                            0x00U     /* OCCS_STAT value */ 
#define STARTUP_OCCS_OSCTL1_VALUE                          0x0400 | STARTUP_CLOCK_INTERNAL_FAST_FREQ_TRIM_VALUE /* OCCS_OSCTL1 value */
#define STARTUP_OCCS_OSCTL2_VALUE                          0xC100U   /* OCCS_OSCTL2 value */ 
#define STARTUP_OCCS_CLKCHKR_VALUE                         0x00U     /* OCCS_CLKCHKR value */ 
#define STARTUP_OCCS_CLKCHKT_VALUE                         0x00U     /* OCCS_CLKCHKT value */ 
#define STARTUP_OCCS_PROT_VALUE                            0x00U     /* OCCS_PROT value */ 

/* External clock pin routing */

/* No pins routed - external reference clock disabled. 
   See Clock settings\External reference clock property in CPU component */

/* SIM */

#define STARTUP_SIM_PCR_VALUE                              0x0400U   /* Peripheral clock rate settings constant */ 

/* INTC */

#define STARTUP_INTC_IPR1_VALUE                            0x00U     /* INTC_IPR1 value */ 

/* COP */

#define STARTUP_COP_CTRL_VALUE                             0x0302U    
  
/* PE_low_level_init() parameterization constants */

  
/* Vector base address initialization */

/* Build options property: Generate linker file\ROM/RAM Areas\MemoryArea0\ROM/RAM Area\Address */
#define CPU_VECTOR_BASE_ADDRESS                            0x00U     /* Vector base address not initialized */ 
#define CPU_INTC_VBA_VALUE                                 0x00U     /* Vector base address register value */ 

/* Unused pins initialization settings */

/* Properties: Common settings\Initialize unused I/O pins, 
               Common settings\Initialize unused I/O pins\Pull resistor,
               Common settings\Initialize unused I/O pins\Open drain,
               Common settings\Initialize unused I/O pins\Output value,
               Common settings\Initialize unused I/O pins\Include Rest pin and
               Common settings\Initialize unused I/O pins\Include JTAG pins */
#define CPU_UNUSED_PINS_INIT                               0x00U     /* Unused pins initialization is disabled */ 
/* Port initialization control constants */
#define CPU_UNUSED_PINS_GPIOA                              0x00U     /* GPIOA unused pins not initialized */ 
#define CPU_UNUSED_PINS_GPIOB                              0x00U     /* GPIOB unused pins not initialized */ 
#define CPU_UNUSED_PINS_GPIOC                              0x00U     /* GPIOC unused pins not initialized */ 
#define CPU_UNUSED_PINS_GPIOD                              0x00U     /* GPIOD unused pins not initialized */ 
#define CPU_UNUSED_PINS_GPIOE                              0x00U     /* GPIOE unused pins not initialized */ 
#define CPU_UNUSED_PINS_GPIOF                              0x00U     /* GPIOF unused pins not initialized */ 
/* Pins direction: 0 = Input, 1 = Output, no value = pins not initialized */
#define CPU_UNUSED_PINS_DIRECTION                                    /* Unused pins not initialized */
  
/* Two's complement rounding and saturation settings */
  
/* Property: Common settings\Saturation mode */
#define CPU_SATURATION                                     0x00U     /* Two's complement rounding and saturation disabled */ 
  
/* Shadow registers initialization settings */

/* Properties: Common settings\Initialize shadow registers, 
               Common settings\Initialize shadow registers\R0,
               Common settings\Initialize shadow registers\R1,
               Common settings\Initialize shadow registers\R2,
               Common settings\Initialize shadow registers\R3,
               Common settings\Initialize shadow registers\R4,
               Common settings\Initialize shadow registers\R5,
               Common settings\Initialize shadow registers\N,
               Common settings\Initialize shadow registers\N3 and
               Common settings\Initialize shadow registers\M01 */  
#define CPU_SHADOW_REGISTERS                               0x01U     /* Shadow registers initialized in PE_low_level_init() */ 
#define CPU_SHADOW_R0_VALUE                                0x00U     /* Shadow registers R0 initialization constant */ 
#define CPU_SHADOW_R1_VALUE                                0x00U     /* Shadow registers R1 initialization constant */ 
#define CPU_SHADOW_R2_VALUE                                0x00U     /* Shadow registers R2 initialization constant */ 
#define CPU_SHADOW_R3_VALUE                                0x00U     /* Shadow registers R3 initialization constant */ 
#define CPU_SHADOW_R4_VALUE                                0x00U     /* Shadow registers R4 initialization constant */ 
#define CPU_SHADOW_R5_VALUE                                0x00U     /* Shadow registers R5 initialization constant */ 
#define CPU_SHADOW_N_VALUE                                 0x00U     /* Shadow registers N initialization constant */ 
#define CPU_SHADOW_N3_VALUE                                0xFFFFU   /* Shadow registers N3 initialization constant */ 
#define CPU_SHADOW_M01_VALUE                               0xFFFFU   /* Shadow registers M01 initialization constant */ 
  
/* Bndgap trim initialization settings */  

/* Property: Common settings\Initialize bandgap trim value */
#define CPU_BANDGAP_TRIM                                   0x01U     /* Bandgap trim initialized in PE_low_level_init() */ 
/* Property: Common settings\Trim value address */
#define CPU_BANDGAP_TRIM_VALUE                             ((*(uint16_t *)0xE42D) & SIM_NVMOPT2L_PMC_BGTRIM_MASK) /* Masked, not shifted bandgap trim value in non-volatile memory */
     
/* Flash configuration field constants */
#define CPU_FLASH_CONFIG_FIELD \
               /* NV_BACKKEY3: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY2: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY1: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY0: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY7: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY6: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY5: KEY=0xFF */ \
               0xFFU, \
               /* NV_BACKKEY4: KEY=0xFF */ \
               0xFFU, \
               /* NV_FPROT3: PROT=0xFF */ \
               0xFFU, \
               /* NV_FPROT2: PROT=0xFF */ \
               0xFFU, \
               /* NV_FPROT1: PROT=0xFF */ \
               0xFFU, \
               /* NV_FPROT0: PROT=0xFF */ \
               0xFFU, \
               /* NV_FSEC: KEYEN=1,MEEN=3,FSLACC=3,SEC=0 */ \
               0x7CU, \
               /* NV_FOPT: ??=1,??=1,??=1,??=1,??=1,??=1,??=0,ALPBOOT=1 */ \
               0xFDU, \
               /* Reserved */ \
               0xFFU, \
               /* Reserved */ \
               0xFFU

/* Reset pin settings */

/* Property: Common settings\Reset pin */
#define CPU_RESET_PIN                                      0x00U     /* Reset pin not initialized in PE_low_level_init() */ 
  
/* JTAG pin settings */

/* Property: Common settings\JTAG pins\TDI */
#define CPU_TDI_PIN                                        0x01U     /* Test data in pin initialized in PE_low_level_init() */ 
/* Property: Common settings\JTAG pins\TDO */
#define CPU_TDO_PIN                                        0x01U     /* Test data out pin initialized in PE_low_level_init() */ 
/* Property: Common settings\JTAG pins\TCK */
#define CPU_TCK_PIN                                        0x01U     /* Test clock pin initialized in PE_low_level_init() */ 
/* Property: Common settings\JTAG pins\TMS */
#define CPU_TMS_PIN                                        0x01U     /* Test mode select pin initialized in PE_low_level_init() */ 
  
/* Interrupts priority level settings */
  
/* Property: Common settings\Initialization priority */
#define CPU_INT_PRIORITY                                   0x00U     /* Priority level constant of enabled interrupts initialized in PE_low_level_init() */ 
  
/* Common_Init() parameterization settings */
  
#define CPU_COMMON_INIT                                    0x01U     /* Call Common_Init() method in PE_low_level_init() */ 
  
/* Peripherals_Init() parameterization settings */
  
#define CPU_PERIPHERALS_INIT                               0x00U     /* Peripherals_Init() method is not called in PE_low_level_init() */ 

/* Components_Init() parameterization settings */
  
#define CPU_COMPONENTS_INIT                                0x00U     /* Components_Init() method is not called in PE_low_level_init() */ 

/* CPU_SetClockConfiguration() parameterization constants */

static TCpuClockSource CpuClockSources[CPU_CLOCK_CONFIGURATIONS_NUMBER] = {
  CPU_CLOCK_SOURCE_INTERNAL_FAST
};

static const TCpuPllEnabled CpuPllEnabled[CPU_CLOCK_CONFIGURATIONS_NUMBER] = {
  1U
};
  
static const TCpuClockDivider CpuClockDividers[CPU_CLOCK_CONFIGURATIONS_NUMBER] = {
  0x2131U
};
  
static const TCpuClockRate CpuClockRates[CPU_CLOCK_CONFIGURATIONS_NUMBER] = {
  0x0600U
};
  
/* CPU_GetBusFreqHz() parameterization constants */

static const TCpuBusFreqHz CpuBusFreqHz[CPU_CLOCK_CONFIGURATIONS_NUMBER] = {
  0x02FAF080UL
};
  
/* CPU_Delay100US() parameterization constants */

/*
 * Clock configuration 0
 *   - requested                  : 100 us @ 50 MHz, 1 instruction cycle takes 20 ns
 *   - possible                   : 5000 instruction cycles, 100000 ns
 *   - without overhead           : 4968 instruction cycles, 99360 ns
 */
    
#define CPU_DELAY_100US_CLOCK_CONFIG_0_LOOP_1 4958 /* DO loop counter, counter value in register */


#ifdef __cplusplus
}
#endif

#endif
/* __CPU_Config_H */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
