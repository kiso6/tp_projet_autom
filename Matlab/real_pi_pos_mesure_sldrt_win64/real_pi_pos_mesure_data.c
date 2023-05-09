/*
 * real_pi_pos_mesure_data.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "real_pi_pos_mesure".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue May  9 12:12:38 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "real_pi_pos_mesure.h"
#include "real_pi_pos_mesure_private.h"

/* Block parameters (default storage) */
P_real_pi_pos_mesure_T real_pi_pos_mesure_P = {
  /* Variable: Ki
   * Referenced by: '<S31>/Integral Gain'
   */
  0.91078,

  /* Variable: Kp
   * Referenced by: '<S39>/Proportional Gain'
   */
  5.282524,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S76>/Derivative Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S28>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S79>/Integral Gain'
   */
  3.0,

  /* Mask Parameter: PIDController1_InitialConditionForFilter
   * Referenced by: '<S77>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S29>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditionForIntegrator
   * Referenced by: '<S82>/Integrator'
   */
  10.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S34>/Integrator'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: PIDController1_LowerSaturationLimit
   * Referenced by: '<S89>/Saturation'
   */
  -10.0,

  /* Mask Parameter: PIDController_LowerSaturationLimit
   * Referenced by: '<S41>/Saturation'
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

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S85>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S37>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S87>/Proportional Gain'
   */
  20.0,

  /* Mask Parameter: PIDController1_UpperSaturationLimit
   * Referenced by: '<S89>/Saturation'
   */
  10.0,

  /* Mask Parameter: PIDController_UpperSaturationLimit
   * Referenced by: '<S41>/Saturation'
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
  0.0
};
