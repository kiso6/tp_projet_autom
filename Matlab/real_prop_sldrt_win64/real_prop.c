/*
 * real_prop.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "real_prop".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue Apr 18 10:43:00 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "real_prop.h"
#include "real_prop_private.h"
#include "real_prop_dt.h"

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
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6024E", 4294967295U, 6, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_real_prop_T real_prop_B;

/* Block states (default storage) */
DW_real_prop_T real_prop_DW;

/* Real-time model */
RT_MODEL_real_prop_T real_prop_M_;
RT_MODEL_real_prop_T *const real_prop_M = &real_prop_M_;

/* Model output function */
void real_prop_output(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;
  real_T rtb_epsilon;

  /* Step: '<Root>/Step' */
  if (real_prop_M->Timing.t[0] < real_prop_P.Step_Time) {
    real_prop_B.u = real_prop_P.Step_Y0;
  } else {
    real_prop_B.u = real_prop_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* S-Function (sldrtai): '<Root>/Analog Input' */
  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) real_prop_P.AnalogInput_RangeMode;
    parm.rangeidx = real_prop_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &real_prop_P.AnalogInput_Channels,
                   &real_prop_B.y, &parm);
  }

  /* Sum: '<Root>/Sum' */
  rtb_epsilon = real_prop_B.u - real_prop_B.y;

  /* Gain: '<S36>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S28>/Filter'
   *  Gain: '<S27>/Derivative Gain'
   *  Sum: '<S28>/SumD'
   */
  real_prop_B.FilterCoefficient = (real_prop_P.PIDController_D * rtb_epsilon -
    real_prop_DW.Filter_DSTATE) * real_prop_P.PIDController_N;

  /* Sum: '<S42>/Sum' incorporates:
   *  DiscreteIntegrator: '<S33>/Integrator'
   *  Gain: '<S38>/Proportional Gain'
   */
  rtb_Saturation = (real_prop_P.Kp * rtb_epsilon +
                    real_prop_DW.Integrator_DSTATE) +
    real_prop_B.FilterCoefficient;

  /* Saturate: '<S40>/Saturation' */
  if (rtb_Saturation > real_prop_P.PIDController_UpperSaturationLimit) {
    rtb_Saturation = real_prop_P.PIDController_UpperSaturationLimit;
  } else {
    if (rtb_Saturation < real_prop_P.PIDController_LowerSaturationLimit) {
      rtb_Saturation = real_prop_P.PIDController_LowerSaturationLimit;
    }
  }

  /* End of Saturate: '<S40>/Saturation' */

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_prop_P.AnalogOutput_RangeMode;
      parm.rangeidx = real_prop_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &real_prop_P.AnalogOutput_Channels, ((real_T*)
        (&rtb_Saturation)), &parm);
    }
  }

  /* ToAsyncQueueBlock generated from: '<Root>/Analog Input' */
  {
    {
      double time = real_prop_M->Timing.t[0];
      void *pData = (void *)&real_prop_B.y;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(793659215U, time, pData, size);
    }
  }

  /* Gain: '<S30>/Integral Gain' */
  real_prop_B.IntegralGain = real_prop_P.Ki * rtb_epsilon;
}

/* Model update function */
void real_prop_update(void)
{
  /* Update for DiscreteIntegrator: '<S33>/Integrator' */
  real_prop_DW.Integrator_DSTATE += real_prop_P.Integrator_gainval *
    real_prop_B.IntegralGain;

  /* Update for DiscreteIntegrator: '<S28>/Filter' */
  real_prop_DW.Filter_DSTATE += real_prop_P.Filter_gainval *
    real_prop_B.FilterCoefficient;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++real_prop_M->Timing.clockTick0)) {
    ++real_prop_M->Timing.clockTickH0;
  }

  real_prop_M->Timing.t[0] = real_prop_M->Timing.clockTick0 *
    real_prop_M->Timing.stepSize0 + real_prop_M->Timing.clockTickH0 *
    real_prop_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void real_prop_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_prop_P.AnalogOutput_RangeMode;
      parm.rangeidx = real_prop_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &real_prop_P.AnalogOutput_Channels,
                     &real_prop_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Integrator' */
  real_prop_DW.Integrator_DSTATE =
    real_prop_P.PIDController_InitialConditionForIntegrator;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Filter' */
  real_prop_DW.Filter_DSTATE =
    real_prop_P.PIDController_InitialConditionForFilter;
}

/* Model terminate function */
void real_prop_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) real_prop_P.AnalogOutput_RangeMode;
      parm.rangeidx = real_prop_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &real_prop_P.AnalogOutput_Channels,
                     &real_prop_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  real_prop_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  real_prop_update();
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
  real_prop_initialize();
}

void MdlTerminate(void)
{
  real_prop_terminate();
}

/* Registration function */
RT_MODEL_real_prop_T *real_prop(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)real_prop_M, 0,
                sizeof(RT_MODEL_real_prop_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = real_prop_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    real_prop_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    real_prop_M->Timing.sampleTimes = (&real_prop_M->Timing.sampleTimesArray[0]);
    real_prop_M->Timing.offsetTimes = (&real_prop_M->Timing.offsetTimesArray[0]);

    /* task periods */
    real_prop_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    real_prop_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(real_prop_M, &real_prop_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = real_prop_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    real_prop_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(real_prop_M, -1);
  real_prop_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  real_prop_M->Sizes.checksums[0] = (71958420U);
  real_prop_M->Sizes.checksums[1] = (1132029268U);
  real_prop_M->Sizes.checksums[2] = (2331323124U);
  real_prop_M->Sizes.checksums[3] = (1928777140U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    real_prop_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(real_prop_M->extModeInfo,
      &real_prop_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(real_prop_M->extModeInfo, real_prop_M->Sizes.checksums);
    rteiSetTPtr(real_prop_M->extModeInfo, rtmGetTPtr(real_prop_M));
  }

  real_prop_M->solverInfoPtr = (&real_prop_M->solverInfo);
  real_prop_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&real_prop_M->solverInfo, 0.001);
  rtsiSetSolverMode(&real_prop_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  real_prop_M->blockIO = ((void *) &real_prop_B);
  (void) memset(((void *) &real_prop_B), 0,
                sizeof(B_real_prop_T));

  /* parameters */
  real_prop_M->defaultParam = ((real_T *)&real_prop_P);

  /* states (dwork) */
  real_prop_M->dwork = ((void *) &real_prop_DW);
  (void) memset((void *)&real_prop_DW, 0,
                sizeof(DW_real_prop_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    real_prop_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  real_prop_M->Sizes.numContStates = (0);/* Number of continuous states */
  real_prop_M->Sizes.numY = (0);       /* Number of model outputs */
  real_prop_M->Sizes.numU = (0);       /* Number of model inputs */
  real_prop_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  real_prop_M->Sizes.numSampTimes = (1);/* Number of sample times */
  real_prop_M->Sizes.numBlocks = (15); /* Number of blocks */
  real_prop_M->Sizes.numBlockIO = (4); /* Number of block outputs */
  real_prop_M->Sizes.numBlockPrms = (25);/* Sum of parameter "widths" */
  return real_prop_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
