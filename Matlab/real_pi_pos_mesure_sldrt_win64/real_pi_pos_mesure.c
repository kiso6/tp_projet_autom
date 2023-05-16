/*
 * real_pi_pos_mesure.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "real_pi_pos_mesure".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue May 16 10:50:29 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "real_pi_pos_mesure.h"
#include "real_pi_pos_mesure_private.h"
#include "real_pi_pos_mesure_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.005, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6024E", 4294967295U, 6, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_real_pi_pos_mesure_T real_pi_pos_mesure_B;

/* Continuous states */
X_real_pi_pos_mesure_T real_pi_pos_mesure_X;

/* Block states (default storage) */
DW_real_pi_pos_mesure_T real_pi_pos_mesure_DW;

/* Real-time model */
RT_MODEL_real_pi_pos_mesure_T real_pi_pos_mesure_M_;
RT_MODEL_real_pi_pos_mesure_T *const real_pi_pos_mesure_M =
  &real_pi_pos_mesure_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  real_pi_pos_mesure_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  real_pi_pos_mesure_output();
  real_pi_pos_mesure_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  real_pi_pos_mesure_output();
  real_pi_pos_mesure_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  real_pi_pos_mesure_output();
  real_pi_pos_mesure_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void real_pi_pos_mesure_output(void)
{
  real_T rtb_epsilon;
  real_T u0;
  if (rtmIsMajorTimeStep(real_pi_pos_mesure_M)) {
    /* set solver stop time */
    if (!(real_pi_pos_mesure_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&real_pi_pos_mesure_M->solverInfo,
                            ((real_pi_pos_mesure_M->Timing.clockTickH0 + 1) *
        real_pi_pos_mesure_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&real_pi_pos_mesure_M->solverInfo,
                            ((real_pi_pos_mesure_M->Timing.clockTick0 + 1) *
        real_pi_pos_mesure_M->Timing.stepSize0 +
        real_pi_pos_mesure_M->Timing.clockTickH0 *
        real_pi_pos_mesure_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(real_pi_pos_mesure_M)) {
    real_pi_pos_mesure_M->Timing.t[0] = rtsiGetT
      (&real_pi_pos_mesure_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(real_pi_pos_mesure_M)) {
    /* Step: '<Root>/Step' */
    if (real_pi_pos_mesure_M->Timing.t[1] < real_pi_pos_mesure_P.Step_Time) {
      real_pi_pos_mesure_B.Step = real_pi_pos_mesure_P.Step_Y0;
    } else {
      real_pi_pos_mesure_B.Step = real_pi_pos_mesure_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */
  }

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Clock: '<S3>/Clock'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Product: '<S3>/Product'
   *  Step: '<S3>/Step'
   *  Sum: '<S3>/Output'
   *  Sum: '<S3>/Sum'
   */
  if (real_pi_pos_mesure_P.ManualSwitch_CurrentSetting == 1) {
    real_pi_pos_mesure_B.u = real_pi_pos_mesure_B.Step;
  } else {
    if (real_pi_pos_mesure_M->Timing.t[0] < real_pi_pos_mesure_P.Ramp_start) {
      /* Step: '<S3>/Step' */
      rtb_epsilon = real_pi_pos_mesure_P.Step_Y0_a;
    } else {
      /* Step: '<S3>/Step' */
      rtb_epsilon = real_pi_pos_mesure_P.Ramp_slope;
    }

    real_pi_pos_mesure_B.u = (real_pi_pos_mesure_M->Timing.t[0] -
      real_pi_pos_mesure_P.Ramp_start) * rtb_epsilon +
      real_pi_pos_mesure_P.Ramp_InitialOutput;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(real_pi_pos_mesure_M)) {
    /* S-Function (sldrtai): '<Root>/Analog Input1' */
    /* S-Function Block: <Root>/Analog Input1 */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_pi_pos_mesure_P.AnalogInput1_RangeMode;
      parm.rangeidx = real_pi_pos_mesure_P.AnalogInput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &real_pi_pos_mesure_P.AnalogInput1_Channels,
                     &real_pi_pos_mesure_B.AnalogInput1, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_pi_pos_mesure_P.AnalogInput_RangeMode;
      parm.rangeidx = real_pi_pos_mesure_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &real_pi_pos_mesure_P.AnalogInput_Channels,
                     &real_pi_pos_mesure_B.angle, &parm);
    }
  }

  /* Sum: '<Root>/Sum1' */
  real_pi_pos_mesure_B.Sum1 = real_pi_pos_mesure_B.u -
    real_pi_pos_mesure_B.AnalogInput1;

  /* StateSpace: '<S1>/Internal' */
  rtb_epsilon = real_pi_pos_mesure_P.Internal_C *
    real_pi_pos_mesure_X.Internal_CSTATE + real_pi_pos_mesure_P.Internal_D *
    real_pi_pos_mesure_B.Sum1;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_epsilon > real_pi_pos_mesure_P.Saturation_UpperSat) {
    rtb_epsilon = real_pi_pos_mesure_P.Saturation_UpperSat;
  } else {
    if (rtb_epsilon < real_pi_pos_mesure_P.Saturation_LowerSat) {
      rtb_epsilon = real_pi_pos_mesure_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<Root>/Sum' */
  rtb_epsilon -= real_pi_pos_mesure_B.angle;

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  real_pi_pos_mesure_B.FilterCoefficient = (real_pi_pos_mesure_P.PIDController_D
    * rtb_epsilon - real_pi_pos_mesure_X.Filter_CSTATE) *
    real_pi_pos_mesure_P.PIDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Gain: '<S43>/Proportional Gain'
   *  Integrator: '<S38>/Integrator'
   */
  u0 = (real_pi_pos_mesure_P.Kp * rtb_epsilon +
        real_pi_pos_mesure_X.Integrator_CSTATE) +
    real_pi_pos_mesure_B.FilterCoefficient;

  /* Saturate: '<S45>/Saturation' */
  if (u0 > real_pi_pos_mesure_P.PIDController_UpperSaturationLimit) {
    real_pi_pos_mesure_B.Saturation =
      real_pi_pos_mesure_P.PIDController_UpperSaturationLimit;
  } else if (u0 < real_pi_pos_mesure_P.PIDController_LowerSaturationLimit) {
    real_pi_pos_mesure_B.Saturation =
      real_pi_pos_mesure_P.PIDController_LowerSaturationLimit;
  } else {
    real_pi_pos_mesure_B.Saturation = u0;
  }

  /* End of Saturate: '<S45>/Saturation' */
  if (rtmIsMajorTimeStep(real_pi_pos_mesure_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) real_pi_pos_mesure_P.AnalogOutput_RangeMode;
        parm.rangeidx = real_pi_pos_mesure_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &real_pi_pos_mesure_P.AnalogOutput_Channels, ((real_T*) (
          &real_pi_pos_mesure_B.Saturation)), &parm);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Analog Input1' */
    if (rtmIsMajorTimeStep(real_pi_pos_mesure_M)) {
      {
        double time = real_pi_pos_mesure_M->Timing.t[1];
        void *pData = (void *)&real_pi_pos_mesure_B.AnalogInput1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4019367317U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Analog Input' */
    if (rtmIsMajorTimeStep(real_pi_pos_mesure_M)) {
      {
        double time = real_pi_pos_mesure_M->Timing.t[1];
        void *pData = (void *)&real_pi_pos_mesure_B.angle;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3103237278U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Step' */
    if (rtmIsMajorTimeStep(real_pi_pos_mesure_M)) {
      {
        double time = real_pi_pos_mesure_M->Timing.t[1];
        void *pData = (void *)&real_pi_pos_mesure_B.Step;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(776527521U, time, pData, size);
      }
    }
  }

  /* Gain: '<S35>/Integral Gain' */
  real_pi_pos_mesure_B.IntegralGain = real_pi_pos_mesure_P.Ki * 2.0 *
    rtb_epsilon;
}

/* Model update function */
void real_pi_pos_mesure_update(void)
{
  if (rtmIsMajorTimeStep(real_pi_pos_mesure_M)) {
    rt_ertODEUpdateContinuousStates(&real_pi_pos_mesure_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++real_pi_pos_mesure_M->Timing.clockTick0)) {
    ++real_pi_pos_mesure_M->Timing.clockTickH0;
  }

  real_pi_pos_mesure_M->Timing.t[0] = rtsiGetSolverStopTime
    (&real_pi_pos_mesure_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++real_pi_pos_mesure_M->Timing.clockTick1)) {
      ++real_pi_pos_mesure_M->Timing.clockTickH1;
    }

    real_pi_pos_mesure_M->Timing.t[1] = real_pi_pos_mesure_M->Timing.clockTick1 *
      real_pi_pos_mesure_M->Timing.stepSize1 +
      real_pi_pos_mesure_M->Timing.clockTickH1 *
      real_pi_pos_mesure_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void real_pi_pos_mesure_derivatives(void)
{
  XDot_real_pi_pos_mesure_T *_rtXdot;
  _rtXdot = ((XDot_real_pi_pos_mesure_T *) real_pi_pos_mesure_M->derivs);

  /* Derivatives for StateSpace: '<S1>/Internal' */
  _rtXdot->Internal_CSTATE = 0.0;
  _rtXdot->Internal_CSTATE += real_pi_pos_mesure_P.Internal_A *
    real_pi_pos_mesure_X.Internal_CSTATE;
  _rtXdot->Internal_CSTATE += real_pi_pos_mesure_P.Internal_B *
    real_pi_pos_mesure_B.Sum1;

  /* Derivatives for Integrator: '<S38>/Integrator' */
  _rtXdot->Integrator_CSTATE = real_pi_pos_mesure_B.IntegralGain;

  /* Derivatives for Integrator: '<S33>/Filter' */
  _rtXdot->Filter_CSTATE = real_pi_pos_mesure_B.FilterCoefficient;
}

/* Model initialize function */
void real_pi_pos_mesure_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_pi_pos_mesure_P.AnalogOutput_RangeMode;
      parm.rangeidx = real_pi_pos_mesure_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &real_pi_pos_mesure_P.AnalogOutput_Channels,
                     &real_pi_pos_mesure_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for StateSpace: '<S1>/Internal' */
  real_pi_pos_mesure_X.Internal_CSTATE =
    real_pi_pos_mesure_P.Internal_InitialCondition;

  /* InitializeConditions for Integrator: '<S38>/Integrator' */
  real_pi_pos_mesure_X.Integrator_CSTATE =
    real_pi_pos_mesure_P.PIDController_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S33>/Filter' */
  real_pi_pos_mesure_X.Filter_CSTATE =
    real_pi_pos_mesure_P.PIDController_InitialConditionForFilter;
}

/* Model terminate function */
void real_pi_pos_mesure_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_pi_pos_mesure_P.AnalogOutput_RangeMode;
      parm.rangeidx = real_pi_pos_mesure_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &real_pi_pos_mesure_P.AnalogOutput_Channels,
                     &real_pi_pos_mesure_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  real_pi_pos_mesure_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  real_pi_pos_mesure_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  real_pi_pos_mesure_initialize();
}

void MdlTerminate(void)
{
  real_pi_pos_mesure_terminate();
}

/* Registration function */
RT_MODEL_real_pi_pos_mesure_T *real_pi_pos_mesure(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)real_pi_pos_mesure_M, 0,
                sizeof(RT_MODEL_real_pi_pos_mesure_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&real_pi_pos_mesure_M->solverInfo,
                          &real_pi_pos_mesure_M->Timing.simTimeStep);
    rtsiSetTPtr(&real_pi_pos_mesure_M->solverInfo, &rtmGetTPtr
                (real_pi_pos_mesure_M));
    rtsiSetStepSizePtr(&real_pi_pos_mesure_M->solverInfo,
                       &real_pi_pos_mesure_M->Timing.stepSize0);
    rtsiSetdXPtr(&real_pi_pos_mesure_M->solverInfo,
                 &real_pi_pos_mesure_M->derivs);
    rtsiSetContStatesPtr(&real_pi_pos_mesure_M->solverInfo, (real_T **)
                         &real_pi_pos_mesure_M->contStates);
    rtsiSetNumContStatesPtr(&real_pi_pos_mesure_M->solverInfo,
      &real_pi_pos_mesure_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&real_pi_pos_mesure_M->solverInfo,
      &real_pi_pos_mesure_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&real_pi_pos_mesure_M->solverInfo,
      &real_pi_pos_mesure_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&real_pi_pos_mesure_M->solverInfo,
      &real_pi_pos_mesure_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&real_pi_pos_mesure_M->solverInfo, (&rtmGetErrorStatus
      (real_pi_pos_mesure_M)));
    rtsiSetRTModelPtr(&real_pi_pos_mesure_M->solverInfo, real_pi_pos_mesure_M);
  }

  rtsiSetSimTimeStep(&real_pi_pos_mesure_M->solverInfo, MAJOR_TIME_STEP);
  real_pi_pos_mesure_M->intgData.y = real_pi_pos_mesure_M->odeY;
  real_pi_pos_mesure_M->intgData.f[0] = real_pi_pos_mesure_M->odeF[0];
  real_pi_pos_mesure_M->intgData.f[1] = real_pi_pos_mesure_M->odeF[1];
  real_pi_pos_mesure_M->intgData.f[2] = real_pi_pos_mesure_M->odeF[2];
  real_pi_pos_mesure_M->intgData.f[3] = real_pi_pos_mesure_M->odeF[3];
  real_pi_pos_mesure_M->contStates = ((real_T *) &real_pi_pos_mesure_X);
  rtsiSetSolverData(&real_pi_pos_mesure_M->solverInfo, (void *)
                    &real_pi_pos_mesure_M->intgData);
  rtsiSetSolverName(&real_pi_pos_mesure_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = real_pi_pos_mesure_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    real_pi_pos_mesure_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    real_pi_pos_mesure_M->Timing.sampleTimes =
      (&real_pi_pos_mesure_M->Timing.sampleTimesArray[0]);
    real_pi_pos_mesure_M->Timing.offsetTimes =
      (&real_pi_pos_mesure_M->Timing.offsetTimesArray[0]);

    /* task periods */
    real_pi_pos_mesure_M->Timing.sampleTimes[0] = (0.0);
    real_pi_pos_mesure_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    real_pi_pos_mesure_M->Timing.offsetTimes[0] = (0.0);
    real_pi_pos_mesure_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(real_pi_pos_mesure_M, &real_pi_pos_mesure_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = real_pi_pos_mesure_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    real_pi_pos_mesure_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(real_pi_pos_mesure_M, -1);
  real_pi_pos_mesure_M->Timing.stepSize0 = 0.005;
  real_pi_pos_mesure_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  real_pi_pos_mesure_M->Sizes.checksums[0] = (2541438594U);
  real_pi_pos_mesure_M->Sizes.checksums[1] = (297319138U);
  real_pi_pos_mesure_M->Sizes.checksums[2] = (350244539U);
  real_pi_pos_mesure_M->Sizes.checksums[3] = (1291657465U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    real_pi_pos_mesure_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(real_pi_pos_mesure_M->extModeInfo,
      &real_pi_pos_mesure_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(real_pi_pos_mesure_M->extModeInfo,
                        real_pi_pos_mesure_M->Sizes.checksums);
    rteiSetTPtr(real_pi_pos_mesure_M->extModeInfo, rtmGetTPtr
                (real_pi_pos_mesure_M));
  }

  real_pi_pos_mesure_M->solverInfoPtr = (&real_pi_pos_mesure_M->solverInfo);
  real_pi_pos_mesure_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&real_pi_pos_mesure_M->solverInfo, 0.005);
  rtsiSetSolverMode(&real_pi_pos_mesure_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  real_pi_pos_mesure_M->blockIO = ((void *) &real_pi_pos_mesure_B);
  (void) memset(((void *) &real_pi_pos_mesure_B), 0,
                sizeof(B_real_pi_pos_mesure_T));

  /* parameters */
  real_pi_pos_mesure_M->defaultParam = ((real_T *)&real_pi_pos_mesure_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &real_pi_pos_mesure_X;
    real_pi_pos_mesure_M->contStates = (x);
    (void) memset((void *)&real_pi_pos_mesure_X, 0,
                  sizeof(X_real_pi_pos_mesure_T));
  }

  /* states (dwork) */
  real_pi_pos_mesure_M->dwork = ((void *) &real_pi_pos_mesure_DW);
  (void) memset((void *)&real_pi_pos_mesure_DW, 0,
                sizeof(DW_real_pi_pos_mesure_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    real_pi_pos_mesure_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  real_pi_pos_mesure_M->Sizes.numContStates = (3);/* Number of continuous states */
  real_pi_pos_mesure_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  real_pi_pos_mesure_M->Sizes.numY = (0);/* Number of model outputs */
  real_pi_pos_mesure_M->Sizes.numU = (0);/* Number of model inputs */
  real_pi_pos_mesure_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  real_pi_pos_mesure_M->Sizes.numSampTimes = (2);/* Number of sample times */
  real_pi_pos_mesure_M->Sizes.numBlocks = (30);/* Number of blocks */
  real_pi_pos_mesure_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  real_pi_pos_mesure_M->Sizes.numBlockPrms = (40);/* Sum of parameter "widths" */
  return real_pi_pos_mesure_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
