/*
 * SYSTEME_CORRIGE_AVANCE_DE_PHASE.c
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
#include "SYSTEME_CORRIGE_AVANCE_DE_PHASE_dt.h"

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
B_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T SYSTEME_CORRIGE_AVANCE_DE_PHASE_B;

/* Continuous states */
X_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T SYSTEME_CORRIGE_AVANCE_DE_PHASE_X;

/* Block states (default storage) */
DW_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T SYSTEME_CORRIGE_AVANCE_DE_PHASE_DW;

/* Real-time model */
RT_MODEL_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T SYSTEME_CORRIGE_AVANCE_DE_PHASE_M_;
RT_MODEL_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T *const
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M = &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M_;

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
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_output();
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_output();
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_output();
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void SYSTEME_CORRIGE_AVANCE_DE_PHASE_output(void)
{
  real_T rtb_epsilon;
  real_T u0;
  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
    /* set solver stop time */
    if (!(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                            ((SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTickH0
        + 1) * SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                            ((SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTick0
        + 1) * SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize0 +
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTickH0 *
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[0] = rtsiGetT
      (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
    /* Step: '<Root>/Step' */
    if (SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[1] <
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Step_Time) {
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Step =
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Step_Y0;
    } else {
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Step =
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Step_YFinal;
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
  if (SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.ManualSwitch_CurrentSetting == 1) {
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.u = SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Step;
  } else {
    if (SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[0] <
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Ramp_start) {
      /* Step: '<S3>/Step' */
      rtb_epsilon = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Step_Y0_a;
    } else {
      /* Step: '<S3>/Step' */
      rtb_epsilon = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Ramp_slope;
    }

    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.u =
      (SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[0] -
       SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Ramp_start) * rtb_epsilon +
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Ramp_InitialOutput;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
    /* S-Function (sldrtai): '<Root>/Analog Input1' */
    /* S-Function Block: <Root>/Analog Input1 */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogInput1_RangeMode;
      parm.rangeidx = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogInput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogInput1_Channels,
                     &SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.AnalogInput1, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogInput_RangeMode;
      parm.rangeidx = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogInput_Channels,
                     &SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.angle, &parm);
    }
  }

  /* Sum: '<Root>/Sum1' */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Sum1 = SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.u -
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.AnalogInput1;

  /* StateSpace: '<S1>/Internal' */
  rtb_epsilon = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Internal_C *
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_X.Internal_CSTATE +
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Internal_D *
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Sum1;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_epsilon > SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Saturation_UpperSat) {
    rtb_epsilon = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Saturation_UpperSat;
  } else {
    if (rtb_epsilon < SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Saturation_LowerSat) {
      rtb_epsilon = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<Root>/Sum' */
  rtb_epsilon -= SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.angle;

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Gain: '<S32>/Derivative Gain'
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.FilterCoefficient =
    (SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.PIDController_D * rtb_epsilon -
     SYSTEME_CORRIGE_AVANCE_DE_PHASE_X.Filter_CSTATE) *
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.PIDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Gain: '<S43>/Proportional Gain'
   *  Integrator: '<S38>/Integrator'
   */
  u0 = (SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Kp * rtb_epsilon +
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_X.Integrator_CSTATE) +
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.FilterCoefficient;

  /* Saturate: '<S45>/Saturation' */
  if (u0 > SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.PIDController_UpperSaturationLimit)
  {
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Saturation =
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.PIDController_UpperSaturationLimit;
  } else if (u0 <
             SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.PIDController_LowerSaturationLimit)
  {
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Saturation =
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.PIDController_LowerSaturationLimit;
  } else {
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Saturation = u0;
  }

  /* End of Saturate: '<S45>/Saturation' */
  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_RangeMode;
        parm.rangeidx = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_Channels,
                       ((real_T*) (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Saturation)),
                       &parm);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Analog Input1' */
    if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
      {
        double time = SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[1];
        void *pData = (void *)&SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.AnalogInput1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2511145457U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Analog Input' */
    if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
      {
        double time = SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[1];
        void *pData = (void *)&SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.angle;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1992967478U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Step' */
    if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
      {
        double time = SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[1];
        void *pData = (void *)&SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Step;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3153680260U, time, pData, size);
      }
    }
  }

  /* Gain: '<S35>/Integral Gain' */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.IntegralGain =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Ki * 2.0 * rtb_epsilon;
}

/* Model update function */
void SYSTEME_CORRIGE_AVANCE_DE_PHASE_update(void)
{
  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)) {
    rt_ertODEUpdateContinuousStates
      (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo);
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
  if (!(++SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTick0)) {
    ++SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTickH0;
  }

  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[0] = rtsiGetSolverStopTime
    (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo);

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
    if (!(++SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTick1)) {
      ++SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTickH1;
    }

    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.t[1] =
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTick1 *
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize1 +
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.clockTickH1 *
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void SYSTEME_CORRIGE_AVANCE_DE_PHASE_derivatives(void)
{
  XDot_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T *_rtXdot;
  _rtXdot = ((XDot_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T *)
             SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->derivs);

  /* Derivatives for StateSpace: '<S1>/Internal' */
  _rtXdot->Internal_CSTATE = 0.0;
  _rtXdot->Internal_CSTATE += SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Internal_A *
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_X.Internal_CSTATE;
  _rtXdot->Internal_CSTATE += SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Internal_B *
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.Sum1;

  /* Derivatives for Integrator: '<S38>/Integrator' */
  _rtXdot->Integrator_CSTATE = SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.IntegralGain;

  /* Derivatives for Integrator: '<S33>/Filter' */
  _rtXdot->Filter_CSTATE = SYSTEME_CORRIGE_AVANCE_DE_PHASE_B.FilterCoefficient;
}

/* Model initialize function */
void SYSTEME_CORRIGE_AVANCE_DE_PHASE_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_RangeMode;
      parm.rangeidx = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_Channels,
                     &SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for StateSpace: '<S1>/Internal' */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_X.Internal_CSTATE =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.Internal_InitialCondition;

  /* InitializeConditions for Integrator: '<S38>/Integrator' */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_X.Integrator_CSTATE =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.PIDController_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S33>/Filter' */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_X.Filter_CSTATE =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.PIDController_InitialConditionForFilter;
}

/* Model terminate function */
void SYSTEME_CORRIGE_AVANCE_DE_PHASE_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_RangeMode;
      parm.rangeidx = SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_Channels,
                     &SYSTEME_CORRIGE_AVANCE_DE_PHASE_P.AnalogOutput_FinalValue,
                     &parm);
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
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_update();
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
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_initialize();
}

void MdlTerminate(void)
{
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_terminate();
}

/* Registration function */
RT_MODEL_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T *SYSTEME_CORRIGE_AVANCE_DE_PHASE(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SYSTEME_CORRIGE_AVANCE_DE_PHASE_M, 0,
                sizeof(RT_MODEL_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                          &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.simTimeStep);
    rtsiSetTPtr(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo, &rtmGetTPtr
                (SYSTEME_CORRIGE_AVANCE_DE_PHASE_M));
    rtsiSetStepSizePtr(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                       &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize0);
    rtsiSetdXPtr(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                 &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->derivs);
    rtsiSetContStatesPtr(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo, (real_T
      **) &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->contStates);
    rtsiSetNumContStatesPtr(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
      &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
       &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
       &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
       &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                          (&rtmGetErrorStatus(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M)));
    rtsiSetRTModelPtr(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                      SYSTEME_CORRIGE_AVANCE_DE_PHASE_M);
  }

  rtsiSetSimTimeStep(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                     MAJOR_TIME_STEP);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->intgData.y =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->odeY;
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->intgData.f[0] =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->odeF[0];
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->intgData.f[1] =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->odeF[1];
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->intgData.f[2] =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->odeF[2];
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->intgData.f[3] =
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->odeF[3];
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->contStates = ((real_T *)
    &SYSTEME_CORRIGE_AVANCE_DE_PHASE_X);
  rtsiSetSolverData(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo, (void *)
                    &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->intgData);
  rtsiSetSolverName(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.sampleTimes =
      (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.sampleTimesArray[0]);
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.offsetTimes =
      (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.sampleTimes[0] = (0.0);
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.offsetTimes[0] = (0.0);
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M,
             &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M, -1);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize0 = 0.005;
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.checksums[0] = (1700809823U);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.checksums[1] = (2234058248U);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.checksums[2] = (3649046280U);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.checksums[3] = (3585375720U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->extModeInfo,
      &SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->extModeInfo,
                        SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.checksums);
    rteiSetTPtr(SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->extModeInfo, rtmGetTPtr
                (SYSTEME_CORRIGE_AVANCE_DE_PHASE_M));
  }

  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfoPtr =
    (&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo);
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo, 0.005);
  rtsiSetSolverMode(&SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->blockIO = ((void *)
    &SYSTEME_CORRIGE_AVANCE_DE_PHASE_B);
  (void) memset(((void *) &SYSTEME_CORRIGE_AVANCE_DE_PHASE_B), 0,
                sizeof(B_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T));

  /* parameters */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->defaultParam = ((real_T *)
    &SYSTEME_CORRIGE_AVANCE_DE_PHASE_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &SYSTEME_CORRIGE_AVANCE_DE_PHASE_X;
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->contStates = (x);
    (void) memset((void *)&SYSTEME_CORRIGE_AVANCE_DE_PHASE_X, 0,
                  sizeof(X_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T));
  }

  /* states (dwork) */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->dwork = ((void *)
    &SYSTEME_CORRIGE_AVANCE_DE_PHASE_DW);
  (void) memset((void *)&SYSTEME_CORRIGE_AVANCE_DE_PHASE_DW, 0,
                sizeof(DW_SYSTEME_CORRIGE_AVANCE_DE_PHASE_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numContStates = (3);/* Number of continuous states */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numY = (0);/* Number of model outputs */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numU = (0);/* Number of model inputs */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numSampTimes = (2);/* Number of sample times */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numBlocks = (30);/* Number of blocks */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  SYSTEME_CORRIGE_AVANCE_DE_PHASE_M->Sizes.numBlockPrms = (40);/* Sum of parameter "widths" */
  return SYSTEME_CORRIGE_AVANCE_DE_PHASE_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
