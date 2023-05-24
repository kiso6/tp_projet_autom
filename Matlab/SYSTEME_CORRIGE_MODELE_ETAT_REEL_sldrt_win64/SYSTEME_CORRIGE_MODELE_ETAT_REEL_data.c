/*
 * SYSTEME_CORRIGE_MODELE_ETAT_REEL_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "SYSTEME_CORRIGE_MODELE_ETAT_REEL".
 *
 * Model version              : 1.13
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed May 24 12:32:48 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SYSTEME_CORRIGE_MODELE_ETAT_REEL.h"
#include "SYSTEME_CORRIGE_MODELE_ETAT_REEL_private.h"

/* Block parameters (default storage) */
P_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T SYSTEME_CORRIGE_MODELE_ETAT_REEL_P = {
  /* Variable: K
   * Referenced by: '<Root>/Gain'
   */
  { 2.3150489953937647, 2.2050716648291067 },

  /* Variable: Ki
   * Referenced by: '<S30>/Integral Gain'
   */
  0.91078,

  /* Variable: Kp
   * Referenced by: '<S38>/Proportional Gain'
   */
  5.282524,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S27>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S28>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S33>/Integrator'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLimit
   * Referenced by: '<S40>/Saturation'
   */
  -10.0,

  /* Mask Parameter: AnalogInput1_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input1'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S36>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_UpperSaturationLimit
   * Referenced by: '<S40>/Saturation'
   */
  10.0,

  /* Mask Parameter: AnalogInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input1'
   */
  0.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_Channels
   * Referenced by: '<Root>/Analog Input1'
   */
  1,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput1_RangeMode
   * Referenced by: '<Root>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput1_VoltRange
   * Referenced by: '<Root>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 9.5
   * Referenced by: '<Root>/Saturation'
   */
  9.5,

  /* Expression: -9
   * Referenced by: '<Root>/Saturation'
   */
  -9.0
};
