/*
 * real_prop_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "real_prop".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue May  9 12:02:39 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "real_prop.h"
#include "real_prop_private.h"

/* Block parameters (default storage) */
P_real_prop_T real_prop_P = {
  /* Variable: Ki
   * Referenced by: '<S31>/Integral Gain'
   */
  0.91078,

  /* Variable: Kp
   * Referenced by: '<S39>/Proportional Gain'
   */
  5.282524,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S28>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S29>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S34>/Integrator'
   */
  10.0,

  /* Mask Parameter: Ramp_InitialOutput
   * Referenced by: '<S2>/Constant1'
   */
  -5.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLimit
   * Referenced by: '<S41>/Saturation'
   */
  -10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S37>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_UpperSaturationLimit
   * Referenced by: '<S41>/Saturation'
   */
  10.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: Ramp_slope
   * Referenced by: '<S2>/Step'
   */
  0.5,

  /* Mask Parameter: Ramp_start
   * Referenced by:
   *   '<S2>/Constant'
   *   '<S2>/Step'
   */
  20.0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
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

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<Root>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Expression: 20
   * Referenced by: '<Root>/Step'
   */
  20.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Step'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Step'
   */
  0.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};
