/*
 * SYSTEME_CORRIGE_MODELE_ETAT_REEL.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "SYSTEME_CORRIGE_MODELE_ETAT_REEL".
 *
 * Model version              : 1.12
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue May 23 12:09:43 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SYSTEME_CORRIGE_MODELE_ETAT_REEL.h"
#include "SYSTEME_CORRIGE_MODELE_ETAT_REEL_private.h"
#include "SYSTEME_CORRIGE_MODELE_ETAT_REEL_dt.h"

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
B_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T SYSTEME_CORRIGE_MODELE_ETAT_REEL_B;

/* Continuous states */
X_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T SYSTEME_CORRIGE_MODELE_ETAT_REEL_X;

/* Block states (default storage) */
DW_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T SYSTEME_CORRIGE_MODELE_ETAT_REEL_DW;

/* Real-time model */
RT_MODEL_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T SYSTEME_CORRIGE_MODELE_ETAT_REEL_M_;
RT_MODEL_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T *const
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M = &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_output();
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_output();
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_output();
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void SYSTEME_CORRIGE_MODELE_ETAT_REEL_output(void)
{
  real_T rtb_epsilon;
  real_T u0;
  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)) {
    /* set solver stop time */
    if (!(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                            ((SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTickH0
        + 1) * SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                            ((SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTick0
        + 1) * SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize0 +
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTickH0 *
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)) {
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.t[0] = rtsiGetT
      (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)) {
    /* Step: '<Root>/Step' */
    if (SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.t[1] <
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Step_Time) {
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.u =
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Step_Y0;
    } else {
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.u =
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */

    /* S-Function (sldrtai): '<Root>/Analog Input1' */
    /* S-Function Block: <Root>/Analog Input1 */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogInput1_RangeMode;
      parm.rangeidx = SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogInput1_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogInput1_Channels,
                     &SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.AnalogInput1, &parm);
    }

    /* S-Function (sldrtai): '<Root>/Analog Input' */
    /* S-Function Block: <Root>/Analog Input */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogInput_RangeMode;
      parm.rangeidx = SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogInput_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                     &SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogInput_Channels,
                     &SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.angle, &parm);
    }

    /* Gain: '<Root>/Gain' incorporates:
     *  SignalConversion generated from: '<Root>/Vector Concatenate'
     *  Sum: '<Root>/Sum1'
     * */
    u0 = (SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.u -
          SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.AnalogInput1) *
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.K[0] +
      (SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.u -
       SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.angle) *
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.K[1];

    /* Saturate: '<Root>/Saturation' incorporates:
     *  Gain: '<Root>/Gain'
     */
    if (u0 > SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Saturation_UpperSat) {
      u0 = SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Saturation_UpperSat;
    } else {
      if (u0 < SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Saturation_LowerSat) {
        u0 = SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Sum: '<Root>/Sum' */
    rtb_epsilon = u0 - SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.angle;

    /* Gain: '<S38>/Proportional Gain' */
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.ProportionalGain =
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Kp * rtb_epsilon;

    /* Gain: '<S27>/Derivative Gain' */
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.DerivativeGain =
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.PIDController_D * rtb_epsilon;
  }

  /* Gain: '<S36>/Filter Coefficient' incorporates:
   *  Integrator: '<S28>/Filter'
   *  Sum: '<S28>/SumD'
   */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.FilterCoefficient =
    (SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.DerivativeGain -
     SYSTEME_CORRIGE_MODELE_ETAT_REEL_X.Filter_CSTATE) *
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.PIDController_N;

  /* Sum: '<S42>/Sum' incorporates:
   *  Integrator: '<S33>/Integrator'
   */
  u0 = (SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.ProportionalGain +
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_X.Integrator_CSTATE) +
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.FilterCoefficient;

  /* Saturate: '<S40>/Saturation' */
  if (u0 > SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.PIDController_UpperSaturationLimit)
  {
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.Saturation =
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.PIDController_UpperSaturationLimit;
  } else if (u0 <
             SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.PIDController_LowerSaturationLimit)
  {
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.Saturation =
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.PIDController_LowerSaturationLimit;
  } else {
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.Saturation = u0;
  }

  /* End of Saturate: '<S40>/Saturation' */
  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_RangeMode;
        parm.rangeidx =
          SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_Channels,
                       ((real_T*)
                        (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.Saturation)), &parm);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Analog Input1' */
    if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)) {
      {
        double time = SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.t[1];
        void *pData = (void *)&SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.AnalogInput1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(500280523U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Analog Input' */
    if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)) {
      {
        double time = SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.t[1];
        void *pData = (void *)&SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.angle;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1936195079U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Step' */
    if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)) {
      {
        double time = SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.t[1];
        void *pData = (void *)&SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.u;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1792380958U, time, pData, size);
      }
    }

    /* Gain: '<S30>/Integral Gain' */
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.IntegralGain =
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.Ki * 2.0 * rtb_epsilon;
  }
}

/* Model update function */
void SYSTEME_CORRIGE_MODELE_ETAT_REEL_update(void)
{
  if (rtmIsMajorTimeStep(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)) {
    rt_ertODEUpdateContinuousStates
      (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo);
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
  if (!(++SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTick0)) {
    ++SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTickH0;
  }

  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.t[0] = rtsiGetSolverStopTime
    (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo);

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
    if (!(++SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTick1)) {
      ++SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTickH1;
    }

    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.t[1] =
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTick1 *
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize1 +
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.clockTickH1 *
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void SYSTEME_CORRIGE_MODELE_ETAT_REEL_derivatives(void)
{
  XDot_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T *_rtXdot;
  _rtXdot = ((XDot_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T *)
             SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->derivs);

  /* Derivatives for Integrator: '<S33>/Integrator' */
  _rtXdot->Integrator_CSTATE = SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.IntegralGain;

  /* Derivatives for Integrator: '<S28>/Filter' */
  _rtXdot->Filter_CSTATE = SYSTEME_CORRIGE_MODELE_ETAT_REEL_B.FilterCoefficient;
}

/* Model initialize function */
void SYSTEME_CORRIGE_MODELE_ETAT_REEL_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_RangeMode;
      parm.rangeidx = SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_Channels,
                     &SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_InitialValue,
                     &parm);
    }
  }

  /* InitializeConditions for Integrator: '<S33>/Integrator' */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_X.Integrator_CSTATE =
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.PIDController_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S28>/Filter' */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_X.Filter_CSTATE =
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.PIDController_InitialConditionForFilter;
}

/* Model terminate function */
void SYSTEME_CORRIGE_MODELE_ETAT_REEL_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE)
        SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_RangeMode;
      parm.rangeidx = SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_Channels,
                     &SYSTEME_CORRIGE_MODELE_ETAT_REEL_P.AnalogOutput_FinalValue,
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
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_update();
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
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_initialize();
}

void MdlTerminate(void)
{
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_terminate();
}

/* Registration function */
RT_MODEL_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T *SYSTEME_CORRIGE_MODELE_ETAT_REEL
  (void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SYSTEME_CORRIGE_MODELE_ETAT_REEL_M, 0,
                sizeof(RT_MODEL_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                          &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.simTimeStep);
    rtsiSetTPtr(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo, &rtmGetTPtr
                (SYSTEME_CORRIGE_MODELE_ETAT_REEL_M));
    rtsiSetStepSizePtr(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                       &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize0);
    rtsiSetdXPtr(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                 &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->derivs);
    rtsiSetContStatesPtr(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                         (real_T **)
                         &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->contStates);
    rtsiSetNumContStatesPtr(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
      &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
       &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
       &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
       &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                          (&rtmGetErrorStatus(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M)));
    rtsiSetRTModelPtr(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                      SYSTEME_CORRIGE_MODELE_ETAT_REEL_M);
  }

  rtsiSetSimTimeStep(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                     MAJOR_TIME_STEP);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->intgData.y =
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->odeY;
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->intgData.f[0] =
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->odeF[0];
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->intgData.f[1] =
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->odeF[1];
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->intgData.f[2] =
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->odeF[2];
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->intgData.f[3] =
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->odeF[3];
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->contStates = ((real_T *)
    &SYSTEME_CORRIGE_MODELE_ETAT_REEL_X);
  rtsiSetSolverData(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo, (void *)
                    &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->intgData);
  rtsiSetSolverName(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap
      [0]);
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.sampleTimes =
      (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.sampleTimesArray[0]);
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.offsetTimes =
      (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.offsetTimesArray[0]);

    /* task periods */
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.sampleTimes[0] = (0.0);
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.offsetTimes[0] = (0.0);
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M,
             &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M, -1);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize0 = 0.005;
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.checksums[0] = (1159194831U);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.checksums[1] = (4022816912U);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.checksums[2] = (4031038767U);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.checksums[3] = (192826109U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->extModeInfo,
      &SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->extModeInfo,
                        SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.checksums);
    rteiSetTPtr(SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->extModeInfo, rtmGetTPtr
                (SYSTEME_CORRIGE_MODELE_ETAT_REEL_M));
  }

  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfoPtr =
    (&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo);
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo, 0.005);
  rtsiSetSolverMode(&SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->blockIO = ((void *)
    &SYSTEME_CORRIGE_MODELE_ETAT_REEL_B);
  (void) memset(((void *) &SYSTEME_CORRIGE_MODELE_ETAT_REEL_B), 0,
                sizeof(B_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T));

  /* parameters */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->defaultParam = ((real_T *)
    &SYSTEME_CORRIGE_MODELE_ETAT_REEL_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &SYSTEME_CORRIGE_MODELE_ETAT_REEL_X;
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->contStates = (x);
    (void) memset((void *)&SYSTEME_CORRIGE_MODELE_ETAT_REEL_X, 0,
                  sizeof(X_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T));
  }

  /* states (dwork) */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->dwork = ((void *)
    &SYSTEME_CORRIGE_MODELE_ETAT_REEL_DW);
  (void) memset((void *)&SYSTEME_CORRIGE_MODELE_ETAT_REEL_DW, 0,
                sizeof(DW_SYSTEME_CORRIGE_MODELE_ETAT_REEL_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numContStates = (2);/* Number of continuous states */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numY = (0);/* Number of model outputs */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numU = (0);/* Number of model inputs */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numSampTimes = (2);/* Number of sample times */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numBlocks = (24);/* Number of blocks */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  SYSTEME_CORRIGE_MODELE_ETAT_REEL_M->Sizes.numBlockPrms = (32);/* Sum of parameter "widths" */
  return SYSTEME_CORRIGE_MODELE_ETAT_REEL_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
