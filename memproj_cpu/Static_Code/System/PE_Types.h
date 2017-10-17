
#ifndef __PE_Types_H
#define __PE_Types_H

#ifdef __cplusplus
extern "C" {
#endif

/* Standard ANSI C types */
/*lint -save -e???? */
#include <stdint.h>
/*lint -restore */

typedef char                char_t;

#ifndef FALSE
  #define  FALSE  0U                   /* Boolean value FALSE. FALSE is defined always as a zero value. */
#endif
#ifndef TRUE
  #define  TRUE   1U                   /* Boolean value TRUE. TRUE is defined always as a non zero value. */
#endif

#ifndef NULL
  #define  NULL   0U
#endif

/* PE types definition */
typedef unsigned char bool;
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];
typedef uint8_t TPE_ErrCode;
#ifndef TPE_Float
typedef float TPE_Float;
#endif

/* SDK types definition */
typedef signed char    Word8;
typedef unsigned char  UWord8;
typedef short          Word16;
typedef unsigned short UWord16;
typedef long           Word32;
typedef unsigned long  UWord32;
typedef signed char    Int8;
typedef unsigned char  UInt8;
typedef int            Int16;
typedef unsigned int   UInt16;
typedef long           Int32;
typedef unsigned long  UInt32;
typedef __typeof__(sizeof(0)) ssize_t;
typedef int ibool;

/*lint -save  -esym(960,19.12) -esym(961,19.13) Disable MISRA rule (19.12,19.13) checking. */
/**************************************************/
/* PE register access macros                      */
/**************************************************/

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphReadReg8                                                                         **
**               PeriphReadReg16                                                                        **
**               PeriphReadReg32                                                                        **
** Description:                                                                                         **
**               Reads an uint8_t from 8-bit memory location, an uint16_t from 16-bit memory location   **
**               or an uint32_t from 32-bit memory location.                                            **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
** Result:                                                                                              **
**               data                                                                                   **
** Example:                                                                                             **
**                uint8_t data8;                                                                        **
**                uint16_t data16;                                                                      **
**                uint32_t data32;                                                                      **
**                . . .                                                                                 **
**               data8 = PeriphReadReg8( *(uint8_t*)0x1000 );                                           **
**               data16 = PeriphReadReg16( *(uint16_t*)0x1000 );                                        **
**               data32 = PeriphReadReg32( *(uint32_t*)0x1000 );                                        **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphReadReg8( Register )   (Register)
#define PeriphReadReg16( Register )  (Register)
#define PeriphReadReg32( Register )  (Register)

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphWriteReg8                                                                        **
**               PeriphWriteReg16                                                                       **
**               PeriphWriteReg32                                                                       **
** Description:                                                                                         **
**               Writes data to 8-bit, 16-bit or 32-bit memory location.                                **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               Data - written data                                                                    **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphWriteReg8( *(uint8_t*)0x1000, 0x0055 );                                          **
**               PeriphWriteReg16( *(uint16_t*)0x1000, 0x0055 );                                        **
**               PeriphWriteReg32( *(uint32_t*)0x1000, 0x0055 );                                        **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphWriteReg8( Register, Data )   ( (Register) = Data )
#define PeriphWriteReg16( Register, Data )  ( (Register) = Data )
#define PeriphWriteReg32( Register, Data )  ( (Register) = Data )

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphSetBitMask8                                                                      **
**               PeriphSetBitMask16                                                                     **
**               PeriphSetBitMask32                                                                     **
** Description:                                                                                         **
**               Sets specified bits in memory.                                                         **
**               32-bit register access done using accumulator to override compiler optimizations and   **
**               ensure that full register is always accessed instead of just high/low 16-bit part.     **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitMask - bit mask - set bits will be set in the memory                                **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphBitSet8( *(uint8_t*)0x1000, 0x02 );                                              **
**               PeriphBitSet16( *(uint16_t*)0x1000, 0x02 );                                            **
**               PeriphBitSet32( *(uint32_t*)0x1000, 0x02 );                                            **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphSetBitMask8( Register, BitMask )   ((Register) |= BitMask)
#define PeriphSetBitMask16( Register, BitMask )  ((Register) |= BitMask)
#define PeriphSetBitMask32( Register, BitMask )  ((Register) = (Register) | BitMask)

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphClearBitMask8                                                                    **
**               PeriphClearBitMask16                                                                   **
**               PeriphClearBitMask32                                                                   **
** Description:                                                                                         **
**               Clears specified bits in memory.                                                       **
**               32-bit register access done using accumulator to override compiler optimizations and   **
**               ensure that full register is always accessed instead of just high/low 16-bit part.     **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitMask - bit mask - set bits will be cleared in the memory                            **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphBitClear8( *(uint8_t*)0x1000, 0x02 );                                            **
**               PeriphBitClear16( *(uint16_t*)0x1000, 0x02 );                                          **
**               PeriphBitClear32( *(uint32_t*)0x1000, 0x02 );                                          **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphClearBitMask8( Register, BitMask )   ((Register) &= ~(BitMask))
#define PeriphClearBitMask16( Register, BitMask )  ((Register) &= ~(BitMask))
#define PeriphClearBitMask32( Register, BitMask )  ((Register) = (Register) & (~(BitMask)))

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphGetBitMask8                                                                      **
**               PeriphGetBitMask16                                                                     **
**               PeriphGetBitMask32                                                                     **
** Description:                                                                                         **
**               Test specified bits in memory.                                                         **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitMask - bit mask - set bits will be tested if they are set                           **
** Result:                                                                                              **
**               word                                                                                   **
** Example:                                                                                             **
**                word w;                                                                               **
**                . . .                                                                                 **
**               w = PeriphBitTest8( *(uint8_t*)0x1000, 0x02 );                                         **
**               w = PeriphBitTest16( *(uint16_t*)0x1000, 0x02 );                                       **
**               w = PeriphBitTest32( *(uint32_t*)0x1000, 0x02 );                                       **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphGetBitMask8( Register, BitMask )   ( (Register) & (BitMask) )
#define PeriphGetBitMask16( Register, BitMask )  ( (Register) & (BitMask) )
#define PeriphGetBitMask32( Register, BitMask )  ( (Register) & (BitMask) )

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphInvertBitMask8                                                                   **
**               PeriphInvertBitMask16                                                                  **
**               PeriphInvertBitMask32                                                                  **
** Description:                                                                                         **
**               Change specified bits in memory.                                                       **
**               32-bit register access done using accumulator to override compiler optimizations and   **
**               ensure that full register is always accessed instead of just high/low 16-bit part.     **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitMask - bit mask - set bits will be changed from 0 to 1 and vice versa               **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphBitChange8( *(uint8_t*)0x1000, 0x02 );                                           **
**               PeriphBitChange16( *(uint16_t*)0x1000, 0x02 );                                         **
**               PeriphBitChange32( *(uint32_t*)0x1000, 0x02 );                                         **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphInvertBitMask8( Register, BitMask )   ((Register) ^= BitMask)
#define PeriphInvertBitMask16( Register, BitMask )  ((Register) ^= BitMask)
#define PeriphInvertBitMask32( Register, BitMask )  ((Register) = (Register) ^ BitMask)

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphSetBits8                                                                         **
**               PeriphSetBits16                                                                        **
**               PeriphSetBits32                                                                        **
** Description:                                                                                         **
**               Set group of bits. If BitValue and BitMask are 16-bit constants, BitValue is subset of **
**               BitMask and 56800EX instructions are enabled both in compiler and core then            **
**               one non-interruptible instruction is used. Otherwise an accumulator is used.           **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitMask - bit mask - mask of the group of bits                                         **
**               BitValue - bit mask - this mask will be written into the specified bits by             **
**               parameter BitMask                                                                      **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphBitGrpSet8( *(uint8_t*)0x1000, 0x0F, 0x02 );                                     **
**               PeriphBitGrpSet16( *(uint16_t*)0x1000, 0x0F, 0x02 );                                   **
**               PeriphBitGrpSet32( *(uint32_t*)0x1000, 0x0F, 0x02 );                                   **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphSetBits8( Register, BitMask, BitValue )     (Register) = ((Register) & ~(BitMask)) | (BitValue)
#define PeriphSetBits16( Register, BitMask, BitValue )    (Register) = ((Register) & ~(BitMask)) | (BitValue)
#define PeriphSetBits32( Register, BitMask, BitValue )    (Register) = ((Register) & ~(BitMask)) | (BitValue)

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphSetClearBits8                                                                    **
**               PeriphSetClearBits16                                                                   **
**               PeriphSetClearBits32                                                                   **
** Description:                                                                                         **
**               Set group of bits. If BitValue and BitMask are 16-bit constants two non-interruptible  **
**               instructions (set,reset) are used.                                                     **
**               32-bit register access done using accumulator to override compiler optimizations and   **
**               ensure that full register is always accessed instead of just high/low 16-bit part.     **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitMask - bit mask - mask of the group of bits                                         **
**               BitValue - bit mask - this mask will be written into the specified bits by             **
**               parameter BitMask                                                                      **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphSetClearBits8( *(uint8_t*)0x1000, 0x0F, 0x02 );                                  **
**               PeriphSetClearBits16( *(uint16_t*)0x1000, 0x0F, 0x02 );                                **
**               PeriphSetClearBits32( *(uint32_t*)0x1000, 0x0F, 0x02 );                                **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphSetClearBits8( Register, BitMask, BitValue )   ( \
        (Register) |= ((BitValue) & (BitMask)),        /* set "one" bits */ \
        (Register) &= ~((~(BitValue)) & (BitMask)) )  /* clear "zero" bits */
#define PeriphSetClearBits16( Register, BitMask, BitValue )   ( \
        (Register) |= ((BitValue) & (BitMask)),        /* set "one" bits */ \
        (Register) &= ~((~(BitValue)) & (BitMask)) )  /* clear "zero" bits */
#define PeriphSetClearBits32( Register, BitMask, BitValue )   ( \
        (Register) = (Register) | ((BitValue) & (BitMask)),        /* set "one" bits */ \
        (Register) = (Register) & (~((~(BitValue)) & (BitMask))) )  /* clear "zero" bits */

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphClearSetBits8                                                                    **
**               PeriphClearSetBits16                                                                   **
**               PeriphClearSetBits32                                                                   **
** Description:                                                                                         **
**               Set group of bits. If BitValue and BitMask are 16-bit constants two non-interruptible  ** 
**               instructions (reset,set) are used.                                                     **
**               32-bit register access done using accumulator to override compiler optimizations and   **
**               ensure that full register is always accessed instead of just high/low 16-bit part.     **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitMask - bit mask - mask of the group of bits                                         **
**               BitValue - bit mask - this mask will be written into the specified bits by             **
**               parameter BitMask                                                                      **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphClearSetBits8( *(uint8_t*)0x1000, 0x0F, 0x02 );                                  **
**               PeriphClearSetBits16( *(uint16_t*)0x1000, 0x0F, 0x02 );                                **
**               PeriphClearSetBits32( *(uint32_t*)0x1000, 0x0F, 0x02 );                                **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphClearSetBits8( Register, BitMask, BitValue )   ( \
        (Register) &= ~((~(BitValue)) & (BitMask)),  /* clear "zero" bits */ \
        (Register) |= ((BitValue) & (BitMask)) )    /* set "one" bits */
#define PeriphClearSetBits16( Register, BitMask, BitValue )   ( \
        (Register) &= ~((~(BitValue)) & (BitMask)),  /* clear "zero" bits */ \
        (Register) |= ((BitValue) & (BitMask)) )    /* set "one" bits */
#define PeriphClearSetBits32( Register, BitMask, BitValue )   ( \
        (Register) = (Register) & (~((~(BitValue)) & (BitMask))),  /* clear "zero" bits */ \
        (Register) = (Register) | ((BitValue) & (BitMask)) )    /* set "one" bits */

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphResetSetBits8                                                                    **
**               PeriphResetSetBits16                                                                   **
**               PeriphResetSetBits32                                                                   **
** Description:                                                                                         **
**               Set group of bits. If BitValue and BitMask are 16-bit constants two non-interruptible  ** 
**               instructions (zero,set) are used.                                                      **
**               32-bit register access done using accumulator to override compiler optimizations and   **
**               ensure that full register is always accessed instead of just high/low 16-bit part.     **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitMask - bit mask - mask of the group of bits                                         **
**               BitValue - bit mask - this mask will be written into the specified bits by             **
**               parameter BitMask                                                                      **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphResetSetBits8( *(uint8_t*)0x1000, 0x0F, 0x02 );                                  **
**               PeriphResetSetBits16( *(uint16_t*)0x1000, 0x0F, 0x02 );                                **
**               PeriphResetSetBits32( *(uint32_t*)0x1000, 0x0F, 0x02 );                                **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphResetSetBits8( Register, BitMask, BitValue )   ( \
        (Register) &= ~(BitMask),               /* clear all bits in group */ \
        (Register) |= ((BitValue) & (BitMask)) )   /* set "one" bits */
#define PeriphResetSetBits16( Register, BitMask, BitValue )   ( \
        (Register) &= ~(BitMask),               /* clear all bits in group */ \
        (Register) |= ((BitValue) & (BitMask)) )   /* set "one" bits */
#define PeriphResetSetBits32( Register, BitMask, BitValue )   ( \
        (Register) = (Register) & (~(BitMask)),               /* clear all bits in group */ \
        (Register) = (Register) | ((BitValue) & (BitMask)) )   /* set "one" bits */

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphSafeClearFlags8                                                                  **
**               PeriphSafeClearFlags16                                                                 **
**               PeriphSafeClearFlags32                                                                 **
** Description:                                                                                         **
**               Clear (acknowlege) bit flags which are active-high and are cleared-by-write-one.       **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               AllFlagsMask - bit mask - set bits will be cleared in the memory                       **
**               FlagMask - �ones� bit mask.                                                            **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphSafeAckByOne8( *(uint8_t*)0x1000, 0xF0, 0x80 );                                  **
**               PeriphSafeAckByOne16( *(uint16_t*)0x1000, 0xF0, 0x80 );                                **
**               PeriphSafeAckByOne32( *(uint32_t*)0x1000, 0xF0, 0x80 );                                **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphSafeClearFlags8(Register, AllFlagsMask, FlagMask )   PeriphClearBitMask8(Register, (~(FlagMask)) & (AllFlagsMask))
#define PeriphSafeClearFlags16(Register, AllFlagsMask, FlagMask )  PeriphClearBitMask16(Register, (~(FlagMask)) & (AllFlagsMask))
#define PeriphSafeClearFlags32(Register, AllFlagsMask, FlagMask )  PeriphClearBitMask32(Register, (~(FlagMask)) & (AllFlagsMask))

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphInvertRegSetBitMask8                                                             **
**               PeriphInvertRegSetBitMask16                                                            **
**               PeriphInvertRegSetBitMask32                                                            **
** Description:                                                                                         **
**               Invert memory content and set selected.                                                **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               BitValue - bit mask - set bits will be set in the memory                               **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphInvertRegSetBitMask8( *(uint8_t*)0x1000, 0x02 );                                 **
**               PeriphInvertRegSetBitMask16( *(uint16_t*)0x1000, 0x02 );                               **
**               PeriphInvertRegSetBitMask32( *(uint32_t*)0x1000, 0x02 );                               **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphInvertRegSetBitMask8( Register, BitValue )   ((Register) = BitValue | ~(Register))
#define PeriphInvertRegSetBitMask16( Register, BitValue )  ((Register) = BitValue | ~(Register))
#define PeriphInvertRegSetBitMask32( Register, BitValue )  ((Register) = BitValue | ~(Register))

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphSafeClearBitMask8                                                                **
**               PeriphSafeClearBitMask16                                                               **
**               PeriphSafeClearBitMask32                                                               **
** Description:                                                                                         **
**               Clear selected bits without modifying (acknowlege) bit flags which are active-high and **
**               are cleared-by-write-one.                                                              **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               AllFlagsMask - bit mask - mask for bits cleared by writing one                         **
**               BitValue - bit mask - set bits will be cleared in the memory                           **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphSafeClearBitMask8( *(uint8_t*)0x1000, 0xF0, 0x01 );                              **
**               PeriphSafeClearBitMask16( *(uint16_t*)0x1000, 0xF0, 0x01 );                            **
**               PeriphSafeClearBitMask32( *(uint32_t*)0x1000, 0xF0, 0x01 );                            **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphSafeClearBitMask8( Register, AllFlagsMask, BitValue )   PeriphClearBitMask8(Register, (BitValue) | (AllFlagsMask))
#define PeriphSafeClearBitMask16( Register, AllFlagsMask, BitValue )  PeriphClearBitMask16(Register, (BitValue) | (AllFlagsMask))
#define PeriphSafeClearBitMask32( Register, AllFlagsMask, BitValue )  PeriphClearBitMask32(Register, (BitValue) | (AllFlagsMask))

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphSafeSetBitMask8                                                                  **
**               PeriphSafeSetBitMask16                                                                 **
**               PeriphSafeSetBitMask32                                                                 **
** Description:                                                                                         **
**               Clear selected bits without modifying (acknowlege) bit flags which are active-high     **
**               and are cleared-by-write-one.                                                          **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               AllFlagsMask - bit mask - mask for bits cleared by writing one                         **
**               BitValue - bit mask - set bits will be set in the memory                               **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphSafeSetBitMask8( *(uint8_t*)0x1000, 0xF0, 0x01 );                                **
**               PeriphSafeSetBitMask16( *(uint16_t*)0x1000, 0xF0, 0x01 );                              **
**               PeriphSafeSetBitMask32( *(uint32_t*)0x1000, 0xF0, 0x01 );                              **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphSafeSetBitMask8( Register, AllFlagsMask, BitValue )   PeriphWriteReg8(Register, (PeriphReadReg8(Register) & ~((AllFlagsMask) | (BitValue))) | (BitValue))
#define PeriphSafeSetBitMask16( Register, AllFlagsMask, BitValue )  PeriphWriteReg16(Register, (PeriphReadReg16(Register) & ~((AllFlagsMask) | (BitValue))) | (BitValue))
#define PeriphSafeSetBitMask32( Register, AllFlagsMask, BitValue )  PeriphWriteReg32(Register, (PeriphReadReg32(Register) & ~((AllFlagsMask) | (BitValue))) | (BitValue))

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphSafeResetSetBits8                                                                **
**               PeriphSafeResetSetBits16                                                               **
**               PeriphSafeResetSetBits32                                                               **
** Description:                                                                                         **
**               Set group of bits using two non-interruptible instructions (zero,set) without          **
**               modifying (acknowlege) bit flags which are active-high and are cleared-by-write-one.   **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               AllFlagsMask - bit mask - mask for bits cleared by writing one                         **
**               BitMask - bit mask - mask of the group of bits                                         **
**               BitValue - bit mask - this mask will be written into the specified bits by             **
**               parameter BitMask                                                                      **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphSafeResetSetBits8( *(uint8_t*)0x1000, 0xF0, 0x0F, 0x01 );                        **
**               PeriphSafeResetSetBits16( *(uint16_t*)0x1000, 0xF0, 0x0F, 0x01 );                      **
**               PeriphSafeResetSetBits32( *(uint32_t*)0x1000, 0xF0, 0x0F, 0x01 );                      **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphSafeResetSetBits8( Register, AllFlagsMask, BitMask, BitValue )  \
  ( \
     PeriphSafeClearBitMask8(Register, AllFlagsMask, BitMask), \
     PeriphSafeSetBitMask8(Register, AllFlagsMask, BitValue)  \
  )
#define PeriphSafeResetSetBits16( Register, AllFlagsMask, BitMask, BitValue )  \
  ( \
     PeriphSafeClearBitMask16(Register, AllFlagsMask, BitMask), \
     PeriphSafeSetBitMask16(Register, AllFlagsMask, BitValue)  \
  )
#define PeriphSafeResetSetBits32( Register, AllFlagsMask, BitMask, BitValue )  \
  ( \
     PeriphSafeClearBitMask32(Register, AllFlagsMask, BitMask), \
     PeriphSafeSetBitMask32(Register, AllFlagsMask, BitValue)  \
  )

/*********************************************************************************************************
** Method:                                                                                              **
**               PeriphSafeSetBits8                                                                     **
**               PeriphSafeSetBits16                                                                    **
**               PeriphSafeSetBits32                                                                    **
** Description:                                                                                         **
**               Set group of bits using without modifying (acknowlege) bit flags which are active-high **
**               and are cleared-by-write-one.                                                          **
** Parameters:                                                                                          **
**               Register - Register content (content of the memory location)                           **
**               AllFlagsMask - bit mask - mask for bits cleared by writing one                         **
**               BitMask - bit mask - mask of the group of bits                                         **
**               BitValue - bit mask - this mask will be written into the specified bits by             **
**               parameter BitMask                                                                      **
** Result:                                                                                              **
**               NULL                                                                                   **
** Example:                                                                                             **
**               PeriphSafeSetBits8( *(uint8_t*)0x1000, 0xF0, 0x0F, 0x01 );                             **
**               PeriphSafeSetBits16( *(uint16_t*)0x1000, 0xF0, 0x0F, 0x01 );                           **
**               PeriphSafeSetBits32( *(uint32_t*)0x1000, 0xF0, 0x0F, 0x01 );                           **
**                                                                                                      **
**                                                                                                      **
*********************************************************************************************************/
#define PeriphSafeSetBits8( Register, AllFlagsMask, BitMask, BitValue )     PeriphWriteReg8(Register, (PeriphReadReg8(Register) & ((~(AllFlagsMask)) & (~(BitMask)))) | (BitValue)) 
#define PeriphSafeSetBits16( Register, AllFlagsMask, BitMask, BitValue )    PeriphWriteReg16(Register, (PeriphReadReg16(Register) & ((~(AllFlagsMask)) & (~(BitMask)))) | (BitValue)) 
#define PeriphSafeSetBits32( Register, AllFlagsMask, BitMask, BitValue )    PeriphWriteReg32(Register, (PeriphReadReg32(Register) & ((~(AllFlagsMask)) & (~(BitMask)))) | (BitValue)) 

/**************************************************/
/* PE register access macros - DEPRECATED         */
/**************************************************/

#define setRegBit(reg, bit)                                     (reg |= (word)(reg##_##bit##_##MASK))
#define clrRegBit(reg, bit)                                     (reg &= (word)(~(word)reg##_##bit##_##MASK))
#define getRegBit(reg, bit)                                     (reg & reg##_##bit##_##MASK)
#define setReg(reg, val)                                        (reg = (word)(val))
#define getReg(reg)                                             (reg)
#define setRegBits(reg, mask)                                   (reg |= (word)(mask))
#define getRegBits(reg, mask)                                   (reg & (word)(mask))
#define clrRegBits(reg, mask)                                   (reg &= (word)(~(word)(mask)))
#define setRegBitGroup(reg, bits, val)                          (reg = (word)((word)(reg & ~(word)reg##_##bits##_##MASK) | ((word)(val) << reg##_##bits##_##SHIFT)))
#define getRegBitGroup(reg, bits)                               ((reg & reg##_##bits##_##MASK) >> reg##_##bits##_##SHIFT)
/* If 16-bit mask constants are used and 56800EX instructions are enabled then this macro compiles as atomic operation */
#define setRegMask(reg, maskAnd, maskOr)                        (reg = (word)((getReg(reg) & (word)(~(word)((word)(maskAnd) | (word)(maskOr)))) | (word)(maskOr)))
#define setRegBitVal(reg, bit, val)                             (((val) == 0U) ? (reg &= ~(word)reg##_##bit##_##MASK) : (reg |= reg##_##bit##_##MASK))
#define changeRegBits(reg, mask)                                (reg ^= (mask))
#define changeRegBit(reg, bit)                                  (reg ^= reg##_##bit##_##MASK)


/**********************************************************/
/* Uniform multiplatform 8-bits peripheral access macros */
/**********************************************************/

#define setReg8Bit(RegName, BitName)                            (RegName |= (byte)(RegName##_##BitName##_##MASK))
#define clrReg8Bit(RegName, BitName)                            (RegName &= (byte)(~(byte)RegName##_##BitName##_##MASK))
#define invertReg8Bit(RegName, BitName)                         (RegName ^= (byte)(RegName##_##BitName##_##MASK))
#define testReg8Bit(RegName, BitName)                           (RegName & RegName##_##BitName##_##MASK)

/* Whole peripheral register access macros */
#define setReg8(RegName, val)                                   (RegName = (byte)(val))
#define getReg8(RegName)                                        (RegName)

/* Bits peripheral register access macros */
#define testReg8Bits(RegName, GetMask)                          (RegName & (byte)(GetMask))
#define clrReg8Bits(RegName, ClrMask)                           (RegName &= (byte)(~(byte)(ClrMask)))
#define setReg8Bits(RegName, SetMask)                           (RegName |= (byte)(SetMask))
#define invertReg8Bits(RegName, InvMask)                        (RegName ^= (byte)(InvMask))
#define clrSetReg8Bits(RegName, ClrMask, SetMask)               (RegName = (byte)((RegName & (~(byte)(ClrMask))) | (byte)(SetMask)))
#define seqClrSetReg8Bits(RegName, BitsMask, BitsVal)           ( RegName &= (byte)(~((~(byte)(BitsVal)) & (byte)(BitsMask))),\
                                                                 RegName |= (byte)((byte)(BitsVal) & (byte)(BitsMask)) )
#define seqSetClrReg8Bits(RegName, BitsMask, BitsVal)           ( RegName |= (byte)((byte)(BitsVal) & (byte)(BitsMask)),\
                                                                 RegName &= (byte)(~(~(byte)(BitsVal) & (byte)(BitsMask))) )
#define seqResetSetReg8Bits(RegName, BitsMask, BitsVal)         ( RegName &= (byte)(~(byte)(BitsMask)),\
                                                                 RegName |= (byte)((byte)(BitsVal) & (byte)(BitsMask)) )
#define clrReg8BitsByOne(RegName, ClrMask, BitsMask)            (RegName &= (byte)((byte)(ClrMask) & (byte)(BitsMask)))

/* Bit group peripheral register access macros */
#define testReg8BitGroup(RegName, GroupName)                    (RegName & RegName##_##GroupName##_##MASK)
#define getReg8BitGroupVal(RegName, GroupName)                  ((RegName & RegName##_##GroupName##_##MASK) >> RegName##_##GroupName##_##SHIFT)
#define setReg8BitGroupVal(RegName, GroupName, GroupVal)        (RegName = (byte)((RegName & ~(byte)RegName##_##GroupName##_##MASK) | ((byte)(GroupVal) << RegName##_##GroupName##_##SHIFT)))
#define seqClrSetReg8BitGroupVal(RegName,GroupName,GroupVal)    ( RegName &= (byte)(~(~((byte)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK)),\
                                                                 RegName |= (byte)(((byte)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK) )
#define seqSetClrReg8BitGroupVal(RegName,GroupName,GroupVal)    ( RegName |= (byte)(((byte)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK),\
                                                                 RegName &= (byte)(~(~((byte)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK)) )
#define seqResetSetReg8BitGroupVal(RegName,GroupName,GroupVal)  ( RegName &= (byte)(~(byte)RegName##_##GroupName##_##MASK),\
                                                                 RegName |= (byte)(((byte)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK) )

/* Peripheral access macros based on the memory address */
#define periphMemWrite8(Address, Val)                           (*((volatile uint8_t *)(Address)) = (uint8_t)(Val))
#define periphMemRead8(Address)                                 (*((volatile uint8_t *)(Address)))
#define periphBitsClr8(Address, ClrMask)                        (*((volatile uint8_t *)(Address)) &= (uint8_t)(~(uint8_t)(ClrMask)))
#define periphBitsSet8(Address, SetMask)                        (*((volatile uint8_t *)(Address)) |= (uint8_t)(SetMask))
#define periphBitsTest8(Address, GetMask)                       (*((volatile uint8_t *)(Address)) & (uint8_t)(GetMask))


/**********************************************************/
/* Uniform multiplatform 16-bits peripheral access macros */
/**********************************************************/

#define setReg16Bit(RegName, BitName)                           (RegName |= (word)(RegName##_##BitName##_##MASK))
#define clrReg16Bit(RegName, BitName)                           (RegName &= (word)(~(word)RegName##_##BitName##_##MASK))
#define invertReg16Bit(RegName, BitName)                        (RegName ^= (word)(RegName##_##BitName##_##MASK))
#define testReg16Bit(RegName, BitName)                          (RegName & RegName##_##BitName##_##MASK)

/* Whole peripheral register access macros */
#define setReg16(RegName, val)                                   (RegName = (word)(val))
#define getReg16(RegName)                                        (RegName)

/* Bits peripheral register access macros */
#define testReg16Bits(RegName, GetMask)                          (RegName & (word)(GetMask))
#define clrReg16Bits(RegName, ClrMask)                           (RegName &= (word)(~(word)(ClrMask)))
#define setReg16Bits(RegName, SetMask)                           (RegName |= (word)(SetMask))
#define invertReg16Bits(RegName, InvMask)                        (RegName ^= (word)(InvMask))
/* If 16-bit mask constants are used and 56800EX instructions are enabled then this macro compiles as atomic operation */
#define clrSetReg16Bits(RegName, ClrMask, SetMask)               (RegName = (word)((RegName & (word)(~(word)((word)(ClrMask) | (word)(SetMask)))) | (word)(SetMask)))
#define seqClrSetReg16Bits(RegName, BitsMask, BitsVal)           ( RegName &= (word)(~(word)(~(word)(BitsVal) & (word)(BitsMask))),\
                                                                 RegName |= (word)((word)(BitsVal) & (word)(BitsMask)) )
#define seqSetClrReg16Bits(RegName, BitsMask, BitsVal)           ( RegName |= (word)((word)(BitsVal) & (word)(BitsMask)),\
                                                                 RegName &= (word)(~(~(word)(BitsVal) & (word)(BitsMask))) )
#define seqResetSetReg16Bits(RegName, BitsMask, BitsVal)         ( RegName &= (word)(~(word)(BitsMask)),\
                                                                 RegName |= (word)((word)(BitsVal) & (word)(BitsMask)) )
#define clrReg16BitsByOne(RegName, ClrMask, BitsMask)            (RegName &= (word)((word)(ClrMask) & (word)(BitsMask)))

/* Bit group peripheral register access macros */
#define testReg16BitGroup(RegName, GroupName)                    (RegName & (word)(RegName##_##GroupName##_##MASK))
#define getReg16BitGroupVal(RegName, GroupName)                  ((RegName & RegName##_##GroupName##_##MASK) >> RegName##_##GroupName##_##SHIFT)
#define setReg16BitGroupVal(RegName, GroupName, GroupVal)        (RegName = (word)((RegName & ~(word)RegName##_##GroupName##_##MASK) | ((word)(GroupVal) << RegName##_##GroupName##_##SHIFT)))
#define seqClrSetReg16BitGroupVal(RegName,GroupName,GroupVal)    ( RegName &= (word)(~(~((word)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK)),\
                                                                 RegName |= (word)(((word)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK) )
#define seqSetClrReg16BitGroupVal(RegName,GroupName,GroupVal)    ( RegName |= (word)(((word)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK),\
                                                                 RegName &= (word)(~(~((word)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK)) )
#define seqResetSetReg16BitGroupVal(RegName,GroupName,GroupVal)  ( RegName &= (word)(~(word)RegName##_##GroupName##_##MASK),\
                                                                 RegName |= (word)(((word)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK) )

/* Peripheral access macros based on the memory address */
#define periphMemWrite16(Address, Val)                           (*((volatile uint16_t *)(Address)) = (uint16_t)(Val))
#define periphMemRead16(Address)                                 (*((volatile uint16_t *)(Address)))
#define periphBitsClr16(Address, ClrMask)                        (*((volatile uint16_t *)(Address)) &= (uint16_t)(~(uint16_t)(ClrMask)))
#define periphBitsSet16(Address, SetMask)                        (*((volatile uint16_t *)(Address)) |= (uint16_t)(SetMask))
#define periphBitsTest16(Address, GetMask)                       (*((volatile uint16_t *)(Address)) & (uint16_t)(GetMask))



/**********************************************************/
/* Uniform multiplatform 32-bits peripheral access macros */
/**********************************************************/
#define setReg32Bit(RegName, BitName)                           (RegName = ((RegName) | ((dword)(RegName##_##BitName##_##MASK))))
#define clrReg32Bit(RegName, BitName)                           (RegName = ((RegName) & ((dword)(~(dword)RegName##_##BitName##_##MASK))))
#define invertReg32Bit(RegName, BitName)                        (RegName = ((RegName) ^ ((dword)(RegName##_##BitName##_##MASK))))
#define testReg32Bit(RegName, BitName)                          (RegName & RegName##_##BitName##_##MASK)

/* Whole peripheral register access macros */
#define setReg32(RegName, val)                                   (RegName = (dword)(val))
#define getReg32(RegName)                                        (RegName)

/* Bits peripheral register access macros */
#define testReg32Bits(RegName, GetMask)                          (RegName & (dword)(GetMask))
#define clrReg32Bits(RegName, ClrMask)                           (RegName = ((RegName) & ((dword)(~(dword)(ClrMask)))))
#define setReg32Bits(RegName, SetMask)                           (RegName = ((RegName) | ((dword)(SetMask))))
#define invertReg32Bits(RegName, InvMask)                        (RegName = ((RegName) ^ ((dword)(InvMask))))
#define clrSetReg32Bits(RegName, ClrMask, SetMask)               (RegName = (dword)((RegName & (~(dword)(ClrMask))) | (dword)(SetMask)))
#define seqClrSetReg32Bits(RegName, BitsMask, BitsVal)           ( RegName = (RegName) & ((dword)(~(~(dword)(BitsVal) & (dword)(BitsMask)))),\
                                                                 RegName = (RegName) | ((dword)((dword)(BitsVal) & (dword)(BitsMask))) )
#define seqSetClrReg32Bits(RegName, BitsMask, BitsVal)           ( RegName = (RegName) | ((dword)((dword)(BitsVal) & (dword)(BitsMask))),\
                                                                 RegName = (RegName) & ((dword)(~(~(dword)(BitsVal) & (dword)(BitsMask)))) )
#define seqResetSetReg32Bits(RegName, BitsMask, BitsVal)         ( RegName = (RegName) & ((dword)(~(dword)(BitsMask))),\
                                                                 RegName |= (dword)((dword)(BitsVal) & (dword)(BitsMask)) )
#define clrReg32BitsByOne(RegName, ClrMask, BitsMask)            (RegName = (RegName) & ((dword)((dword)(ClrMask) & (dword)(BitsMask))))

/* Bit group peripheral register access macros */
#define testReg32BitGroup(RegName, GroupName)                    (RegName & RegName##_##GroupName##_##MASK)
#define getReg32BitGroupVal(RegName, GroupName)                  ((RegName & RegName##_##GroupName##_##MASK) >> RegName##_##GroupName##_##SHIFT)
#define setReg32BitGroupVal(RegName, GroupName, GroupVal)        (RegName = (dword)((RegName & ~(dword)RegName##_##GroupName##_##MASK) | ((dword)(GroupVal) << RegName##_##GroupName##_##SHIFT)))
#define seqClrSetReg32BitGroupVal(RegName,GroupName,GroupVal)    ( RegName = (RegName) & ((dword)(~(~((dword)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK))),\
                                                                 RegName = (RegName) | ((dword)(((dword)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK)) )
#define seqSetClrReg32BitGroupVal(RegName,GroupName,GroupVal)    ( RegName = (RegName) | ((dword)(((dword)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK)),\
                                                                 RegName = (RegName) & ((dword)(~(~((dword)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK))) )
#define seqResetSetReg32BitGroupVal(RegName,GroupName,GroupVal)  ( RegName = (RegName) & ((dword)(~(dword)RegName##_##GroupName##_##MASK)),\
                                                                 RegName = (RegName) | ((dword)(((dword)(GroupVal) << RegName##_##GroupName##_##SHIFT) & RegName##_##GroupName##_##MASK)) )

/* Peripheral access macros based on the memory address */
#define periphMemWrite32(Address, Val)                           (*((volatile uint32_t *)(Address)) = (uint32_t)(Val))
#define periphMemRead32(Address)                                 (*((volatile uint32_t *)(Address)))
#define periphBitsClr32(Address, ClrMask)                        (*((volatile uint32_t *)(Address)) &= (uint32_t)(~(uint32_t)(ClrMask)))
#define periphBitsSet32(Address, SetMask)                        (*((volatile uint32_t *)(Address)) |= (uint32_t)(SetMask))
#define periphBitsTest32(Address, GetMask)                       (*((volatile uint32_t *)(Address)) & (uint32_t)(GetMask))

/*lint -esym(765,periphMemDummyRead) Disable MISRA rule (8.10) checking for symbols (periphMemDummyRead). */
/* a direct address read, result is thrown away */
inline void periphMemDummyRead(register volatile UWord16* addr)
{
  register UWord16 reg;
  asm { move.w X:(addr),reg }
}

#define in16(var,l,h)  (var = ((word)(l)) | (((word)(h)) << 8))
#define out16(l,h,val) { l = (byte)(val); h = (byte)((val) >> 8); }

#define output(P, V) setReg(P,V)
#define input(P) getReg(P)

#define __EI0() do { asm(bfclr  #0x0300,SR); } while(0) /* Enable interrupts of level 0,1,2,3 */
#define __EI1() do { asm(bfset  #0x0100,SR); asm(bfclr  #0x0200,SR); } while(0) /* Enable interrupts of level 1,2,3 */
#define __EI2() do { asm(bfset  #0x0200,SR); asm(bfclr  #0x0100,SR); } while(0) /* Enable interrupts of level 2,3 */
#define __EI3() do { asm(bfset  #0x0300,SR); } while(0) /* Enable interrupts of level 3 */
/*lint -save  -esym(960,14.3) Disable MISRA rule (14.3) checking. */
#define __EI(level) __EI##level()      /* Enable interrupts of the given level */
/*lint -restore  +esym(960,14.3) Enable MISRA rule (14.3) checking. */
#define __DI()  __EI3()                /* Disable interrupts, only level 3 is allowed */


/* Save status register and disable interrupts */
#define EnterCritical()     do {\
                              /*lint -save  -e530 Disable MISRA rule (9.1) checking. */\
                              volatile word StatusReg;\
                              asm(move.w SR, StatusReg);\
                              asm(bfset  #0x0300,SR);\
                              asm(nop);\
                              asm(nop);\
                              asm(nop);\
                              asm(nop);\
                              asm(nop);\
                              asm(nop);\
                              if (SR_lock++ == 0U) {\
                                SR_reg = StatusReg;\
                              }\
                              /*lint -restore Enable MISRA rule (9.1) checking. */\
                            } while (0)

/* Restore status register  */
#define ExitCritical()      do {\
                              if (--SR_lock == 0U) {\
                                asm(moveu.w SR_reg, SR);\
                                asm(nop);\
                                asm(nop);\
                              }\
                            } while (0)


/*lint -restore  +esym(960,19.12) +esym(961,19.13) Enable MISRA rule (19.12,19.13) checking. */

typedef struct {          /* Black&White Image  */
  word width;             /* Image width  */
  word height;            /* Image height */
  byte *pixmap;           /* Image pixel bitmap */
  dword size;             /* Image size */
  char_t *name;           /* Image name */
} TIMAGE;
typedef TIMAGE* PIMAGE ; /* Pointer to image */

/* 16-bit register (big endian) */
typedef union {
   word w;
   struct {
     byte high,low;
   } b;
} TWREG;

typedef union
{
        struct
        {
          UWord16 LSBpart;
          Word16 MSBpart;
        } RegParts;

        Word32 Reg32bit;

} decoder_uReg32bit;

typedef struct
{
        union { Word16 PositionDifferenceHoldReg;
                Word16 posdh; };
        union { Word16 RevolutionHoldReg;
                Word16 revh; };
        union { decoder_uReg32bit PositionHoldReg;
                Word32 posh; };

}decoder_sState;

typedef struct
{
        UWord16 EncPulses;
        UWord16 RevolutionScale;

        Int16   scaleDiffPosCoef;
        UInt16  scalePosCoef;
        Int16   normDiffPosCoef;
        Int16   normPosCoef;
}decoder_sEncScale;

typedef struct
{
        /*lint -save  -e46 Disable MISRA rule (6.4) checking. */
        UWord16 Index    :1;
        UWord16 PhaseB   :1;
        UWord16 PhaseA   :1;
        UWord16 Reserved :13;
        /*lint -restore Enable MISRA rule (6.4) checking. */
}decoder_sEncSignals;

typedef union{
        decoder_sEncSignals  EncSignals;
        UWord16 Value;
} decoder_uEncSignals;

/******************************************************************************
*
* This Motor Control section contains generally useful and generic
* types that are used throughout the domain of motor control.
*
******************************************************************************/
/* Fractional data types for portability */
typedef short          Frac16;
typedef long           Frac32;

typedef enum
{
        mcPhaseA,
        mcPhaseB,
        mcPhaseC
} mc_ePhaseType;

typedef struct
{
        Frac16 PhaseA;
        Frac16 PhaseB;
        Frac16 PhaseC;
} mc_s3PhaseSystem;

/* general types, primary used in FOC */

typedef struct
{
        Frac16 alpha;
        Frac16 beta;
} mc_sPhase;

typedef struct
{
        Frac16 sine;
        Frac16 cosine;
} mc_sAngle;

typedef struct
{
        Frac16 d_axis;
        Frac16 q_axis;
} mc_sDQsystem;

typedef struct
{
        Frac16 psi_Rd;
        Frac16 omega_field;
        Frac16 i_Sd;
        Frac16 i_Sq;
} mc_sDQEstabl;

typedef UWord16 mc_tPWMSignalMask;    /*  pwm_tSignalMask contains six control bits
                                          representing six PWM signals, shown below.
                                          The bits can be combined in a numerical value
                                          that represents the union of the appropriate
                                          bits.  For example, the value 0x15 indicates
                                          that PWM signals 0, 2, and 4 are set.
                                      */

#define MC_PWM_SIGNAL_0       0x0001
#define MC_PWM_SIGNAL_1       0x0002
#define MC_PWM_SIGNAL_2       0x0004
#define MC_PWM_SIGNAL_3       0x0008
#define MC_PWM_SIGNAL_4       0x0010
#define MC_PWM_SIGNAL_5       0x0020
#define MC_PWM_NO_SIGNALS     0x0000     /* No (none) PWM signals */
#define MC_PWM_ALL_SIGNALS   (MC_PWM_SIGNAL_0 | \
                              MC_PWM_SIGNAL_1 | \
                              MC_PWM_SIGNAL_2 | \
                              MC_PWM_SIGNAL_3 | \
                              MC_PWM_SIGNAL_4 | \
                              MC_PWM_SIGNAL_5)

/* general types, primary used in PI, PID and other controllers */

typedef struct
{
   Word16 ProportionalGain;
   Word16 ProportionalGainScale;
   Word16 IntegralGain;
   Word16 IntegralGainScale;
   Word16 DerivativeGain;
   Word16 DerivativeGainScale;
   Word16 PositivePIDLimit;
   Word16 NegativePIDLimit;
   Word16 IntegralPortionK_1;
   Word16 InputErrorK_1;
}mc_sPIDparams;

typedef struct
{
   Word16 ProportionalGain;
   Word16 ProportionalGainScale;
   Word16 IntegralGain;
   Word16 IntegralGainScale;
   Word16 PositivePILimit;
   Word16 NegativePILimit;
   Word16 IntegralPortionK_1;
}mc_sPIparams;

#ifdef __cplusplus
}
#endif

#endif /* __PE_Types_H */
