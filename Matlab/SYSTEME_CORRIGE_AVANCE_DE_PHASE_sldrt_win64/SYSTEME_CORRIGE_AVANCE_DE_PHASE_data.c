/*
 * SYSTEME_CORRIGE_AVANCE_DE_PHASE_data.c
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

#include "SYSTEME_CORRIGE_AVANCE_DE_PHASE.h"
#include "SYSTEME_CORRIGE_AVANCE_DE_PHASE_private.h"

/* Block parameters (default storage) */
P_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T SYSTEME_CORRIGE_AVANCE_DE_PHASE_P = {
  /* Variable: Ki
   * Referenced by: '<S35>/Integral Gain'
   */
  0.91078,

  /* Variable: Kp
   * Referenced by: '<S43>/Proportional Gain'
   */
  5.282524,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S32>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S33>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S38>/Integrator'
   */
  10.0,

  /* Mask Parameter: Ramp_InitialOutput
   * Referenced by: '<S3>/Constant1'
   */
  -5.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLimit
   * Referenced by: '<S45>/Saturation'
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
   * Referenced by: '<S41>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_UpperSaturationLimit
   * Referenced by: '<S45>/Saturation'
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

  /* Mask Parameter: Ramp_slope
   * Referenced by: '<S3>/Step'
   */
  0.5,

  /* Mask Parameter: Ramp_start
   * Referenced by:
   *   '<S3>/Constant'
   *   '<S3>/Step'
   */
  20.0,

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

  /* Expression: 10
   * Referenced by: '<Root>/Step'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step'
   */
  0.0,

  /* Computed Parameter: Internal_A
   * Referenced by: '<S1>/Internal'
   */
  -1.0,

  /* Computed Parameter: Internal_B
   * Referenced by: '<S1>/Internal'
   */
  1.0,

  /* Computed Parameter: Internal_C
   * Referenced by: '<S1>/Internal'
   */
  -1.0,

  /* Computed Parameter: Internal_D
   * Referenced by: '<S1>/Internal'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S1>/Internal'
   */
  0.0,

  /* Expression: 9.5
   * Referenced by: '<Root>/Saturation'
   */
  9.5,

  /* Expression: -9
   * Referenced by: '<Root>/Saturation'
   */
  -9.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};
