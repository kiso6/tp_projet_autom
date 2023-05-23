/*
 * SYSTEME_CORRIGE_AVANCE_DE_PHASE_dt.h
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "SYSTEME_CORRIGE_AVANCE_DE_PHASE".
 *
 * Model version              : 1.13
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue May 23 12:03:25 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Step), 0, 0, 8 }
  ,

  { (char_T *)(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_DW.AnalogInput1_PWORK), 11, 0, 9
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  2U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Ki), 0, 0, 19 },

  { (char_T *)(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogInput1_Channels), 6, 0,
    9 },

  { (char_T *)(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Step_Time), 0, 0, 11 },

  { (char_T *)(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.ManualSwitch_CurrentSetting),
    3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] SYSTEME_CORRIGE_AVANCE_DE_PHASE_dt.h */
