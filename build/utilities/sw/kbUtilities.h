/*=============================================================================================
*
* kbUtilities.h
*
* ---------------------------------------------------------------------------------------------
*
* MIT License
*
* Copyright(C) 2017 : KUNBUS GmbH, Heerweg 15C, 73370 Denkendorf, Germany
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files(the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions :
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*=============================================================================================
*/

#ifndef KBUTILITIES_H_INC
#define KBUTILITIES_H_INC

//+=============================================================================================
//|		Typen / types
//+=============================================================================================

typedef struct kbUT_StrTimer
{
    INT32U i32uStartTime;
    INT32U i32uDuration;
    TBOOL bRun;
    TBOOL bExpired;
} kbUT_Timer;

typedef struct kbUT_StrArgHeap
{
    INT8U i8uState;                         //!< State of block; free or occupied
    INT8U i8uOwner;                         //!< Debug Marker. Who has allocated the block ?
    INT16U i16uLen;                         //!< Length of block
    struct kbUT_StrArgHeap *ptPrev;         //!< Previous descriptor structure
    struct kbUT_StrArgHeap *ptNext;         //!< Previous descriptor structure
} kbUT_TArgHeap;

//+=============================================================================================
//|		Makros / macros
//+=============================================================================================

#define kbUT_TimerReTrigger(TIMER, DURATION)	kbUT_TimerStart (TIMER, DURATION)

// macro to check if something is within a range ...
#define CHECK_LAPPING(OUTER_LOW, OUTER_HIGH, INNER)\
((INNER <= OUTER_HIGH) && (INNER >= OUTER_LOW))

// macro to check if a range is completely within another range ...
#define CHECK_INSIDE(OUTER_LOW,OUTER_HIGH,INNER_LOW,INNER_HIGH)\
((INNER_HIGH <= OUTER_HIGH) && (INNER_LOW >= OUTER_LOW ))

// macro for a comlete range check for two ranges ...
#define CHECK_OVERLAPPING(OUTER_LOW,OUTER_HIGH,INNER_LOW,INNER_HIGH) \
CHECK_INSIDE( OUTER_LOW, OUTER_HIGH, INNER_LOW, INNER_HIGH) || \
CHECK_LAPPING( OUTER_LOW, OUTER_HIGH, INNER_LOW ) || \
CHECK_LAPPING( OUTER_LOW, OUTER_HIGH, INNER_HIGH ) || \
CHECK_INSIDE( INNER_LOW, INNER_HIGH, OUTER_LOW, OUTER_HIGH) || \
CHECK_LAPPING( INNER_LOW, INNER_HIGH, OUTER_LOW ) || \
CHECK_LAPPING( INNER_LOW, INNER_HIGH, OUTER_HIGH )


//+=============================================================================================
//|		Prototypen / prototypes
//+=============================================================================================
#ifdef __cplusplus
extern "C" { 
#endif 


extern void				kbUT_TimerInit (kbUT_Timer *ptTimer_p);
extern void				kbUT_TimerStart (kbUT_Timer *ptTimer_p, INT32U i32uDuration_p);
extern TBOOL			kbUT_TimerRunning (kbUT_Timer *ptTimer_p);
extern TBOOL			kbUT_TimerExpired (kbUT_Timer *ptTimer_p);
extern INT32U			kbUT_TimeElapsed (kbUT_Timer *ptTimer_p);
extern TBOOL			kbUT_TimerInUse (kbUT_Timer *ptTimer_p);
extern INT32U			kbUT_getCurrentMs (void);
extern void				kbUT_crc32 (INT8U *pi8uData_p, INT32U i32uCnt_p, INT32U *pi32uCrc_p);
extern void				kbUT_crc8XX(INT8U *pi8uData_p, INT16U i16uCnt_p, INT8U i8uPolynom_p, INT8U *pi8uCrc_p);
extern TBOOL			kbUT_uitoa(INT32U p_value, INT8U* p_string, INT8U p_radix);
extern unsigned long	kbUT_atoi(const char *s, int *success);
extern char *			kbUT_itoa(INT32U val, INT16S radix, INT16U len);


#ifdef  __cplusplus 
} 
#endif 

//#else
//#error "KBUTILITIES_H_INC already defined !"
#endif // KBUTILITIES_H_INC

