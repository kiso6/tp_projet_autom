/*
 * identification.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "identification".
 *
 * Model version              : 1.8
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed May 24 12:39:42 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "identification.h"
#include "identification_private.h"
#include "identification_dt.h"

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
B_identification_T identification_B;

/* Block states (default storage) */
DW_identification_T identification_DW;

/* Real-time model */
RT_MODEL_identification_T identification_M_;
RT_MODEL_identification_T *const identification_M = &identification_M_;

/* Model output function */
void identification_output(void)
{
  real_T rtb_Clock1;

  /* Sin: '<Root>/Sine Wave' */
  if (identification_DW.systemEnable != 0) {
    rtb_Clock1 = identification_P.SineWave_Freq * identification_M->Timing.t[1];
    identification_DW.lastSin = sin(rtb_Clock1);
    identification_DW.lastCos = cos(rtb_Clock1);
    identification_DW.systemEnable = 0;
  }

  /* Step: '<Root>/Step' */
  if (identification_M->Timing.t[1] < identification_P.Step_Time) {
    rtb_Clock1 = identification_P.Step_Y0;
  } else {
    rtb_Clock1 = identification_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  identification_B.Sum1 = (((identification_DW.lastSin *
    identification_P.SineWave_PCos + identification_DW.lastCos *
    identification_P.SineWave_PSin) * identification_P.SineWave_HCos +
    (identification_DW.lastCos * identification_P.SineWave_PCos -
     identification_DW.lastSin * identification_P.SineWave_PSin) *
    identification_P.SineWave_Hsin) * identification_P.SineWave_Amp +
    identification_P.SineWave_Bias) + rtb_Clock1;

  /* Clock: '<S1>/Clock1' */
  rtb_Clock1 = identification_M->Timing.t[0];

  /* Gain: '<S1>/Gain' incorporates:
   *  Constant: '<S1>/deltaFreq'
   *  Constant: '<S1>/targetTime'
   *  Product: '<S1>/Product'
   */
  identification_B.Gain = (identification_P.ChirpSignal_f2 -
    identification_P.ChirpSignal_f1) * 6.2831853071795862 /
    identification_P.ChirpSignal_T * identification_P.Gain_Gain_m;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S1>/initialFreq'
   *  Gain: '<Root>/Gain'
   *  Product: '<S1>/Product1'
   *  Product: '<S1>/Product2'
   *  Sum: '<Root>/Sum'
   *  Sum: '<S1>/Sum'
   *  Trigonometry: '<S1>/Output'
   */
  if (identification_P.ManualSwitch_CurrentSetting == 1) {
    identification_B.tension = identification_B.Sum1;
  } else {
    identification_B.tension = sin((rtb_Clock1 * identification_B.Gain +
      6.2831853071795862 * identification_P.ChirpSignal_f1) * rtb_Clock1) *
      identification_P.Gain_Gain + identification_P.Constant2_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* S-Function (sldrtao): '<Root>/Analog Output' */
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) identification_P.AnalogOutput_RangeMode;
      parm.rangeidx = identification_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &identification_P.AnalogOutput_Channels, ((real_T*)
        (&identification_B.tension)), &parm);
    }
  }

  /* S-Function (sldrtai): '<Root>/Analog Input' */
  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) identification_P.AnalogInput_RangeMode;
    parm.rangeidx = identification_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &identification_P.AnalogInput_Channels,
                   &identification_B.angle, &parm);
  }

  /* ToAsyncQueueBlock generated from: '<Root>/Analog Input' */
  {
    {
      double time = identification_M->Timing.t[1];
      void *pData = (void *)&identification_B.angle;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(1662794648U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<Root>/Manual Switch' */
  {
    {
      double time = identification_M->Timing.t[1];
      void *pData = (void *)&identification_B.tension;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(973419381U, time, pData, size);
    }
  }
}

/* Model update function */
void identification_update(void)
{
  real_T HoldSine;

  /* Update for Sin: '<Root>/Sine Wave' */
  HoldSine = identification_DW.lastSin;
  identification_DW.lastSin = identification_DW.lastSin *
    identification_P.SineWave_HCos + identification_DW.lastCos *
    identification_P.SineWave_Hsin;
  identification_DW.lastCos = identification_DW.lastCos *
    identification_P.SineWave_HCos - HoldSine * identification_P.SineWave_Hsin;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++identification_M->Timing.clockTick0)) {
    ++identification_M->Timing.clockTickH0;
  }

  identification_M->Timing.t[0] = identification_M->Timing.clockTick0 *
    identification_M->Timing.stepSize0 + identification_M->Timing.clockTickH0 *
    identification_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++identification_M->Timing.clockTick1)) {
      ++identification_M->Timing.clockTickH1;
    }

    identification_M->Timing.t[1] = identification_M->Timing.clockTick1 *
      identification_M->Timing.stepSize1 + identification_M->Timing.clockTickH1 *
      identification_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void identification_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) identification_P.AnalogOutput_RangeMode;
      parm.rangeidx = identification_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &identification_P.AnalogOutput_Channels,
                     &identification_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* Enable for Sin: '<Root>/Sine Wave' */
  identification_DW.systemEnable = 1;
}

/* Model terminate function */
void identification_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) identification_P.AnalogOutput_RangeMode;
      parm.rangeidx = identification_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &identification_P.AnalogOutput_Channels,
                     &identification_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  identification_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  identification_update();
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
  identification_initialize();
}

void MdlTerminate(void)
{
  identification_terminate();
}

/* Registration function */
RT_MODEL_identification_T *identification(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)identification_M, 0,
                sizeof(RT_MODEL_identification_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&identification_M->solverInfo,
                          &identification_M->Timing.simTimeStep);
    rtsiSetTPtr(&identification_M->solverInfo, &rtmGetTPtr(identification_M));
    rtsiSetStepSizePtr(&identification_M->solverInfo,
                       &identification_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&identification_M->solverInfo, (&rtmGetErrorStatus
      (identification_M)));
    rtsiSetRTModelPtr(&identification_M->solverInfo, identification_M);
  }

  rtsiSetSimTimeStep(&identification_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&identification_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = identification_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    identification_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    identification_M->Timing.sampleTimes =
      (&identification_M->Timing.sampleTimesArray[0]);
    identification_M->Timing.offsetTimes =
      (&identification_M->Timing.offsetTimesArray[0]);

    /* task periods */
    identification_M->Timing.sampleTimes[0] = (0.0);
    identification_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    identification_M->Timing.offsetTimes[0] = (0.0);
    identification_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(identification_M, &identification_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = identification_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    identification_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(identification_M, -1);
  identification_M->Timing.stepSize0 = 0.005;
  identification_M->Timing.stepSize1 = 0.005;

  /* External mode info */
  identification_M->Sizes.checksums[0] = (3646123820U);
  identification_M->Sizes.checksums[1] = (1623756794U);
  identification_M->Sizes.checksums[2] = (4258268896U);
  identification_M->Sizes.checksums[3] = (853876963U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    identification_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(identification_M->extModeInfo,
      &identification_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(identification_M->extModeInfo,
                        identification_M->Sizes.checksums);
    rteiSetTPtr(identification_M->extModeInfo, rtmGetTPtr(identification_M));
  }

  identification_M->solverInfoPtr = (&identification_M->solverInfo);
  identification_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&identification_M->solverInfo, 0.005);
  rtsiSetSolverMode(&identification_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  identification_M->blockIO = ((void *) &identification_B);
  (void) memset(((void *) &identification_B), 0,
                sizeof(B_identification_T));

  /* parameters */
  identification_M->defaultParam = ((real_T *)&identification_P);

  /* states (dwork) */
  identification_M->dwork = ((void *) &identification_DW);
  (void) memset((void *)&identification_DW, 0,
                sizeof(DW_identification_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    identification_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  identification_M->Sizes.numContStates = (0);/* Number of continuous states */
  identification_M->Sizes.numY = (0);  /* Number of model outputs */
  identification_M->Sizes.numU = (0);  /* Number of model inputs */
  identification_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  identification_M->Sizes.numSampTimes = (2);/* Number of sample times */
  identification_M->Sizes.numBlocks = (23);/* Number of blocks */
  identification_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  identification_M->Sizes.numBlockPrms = (29);/* Sum of parameter "widths" */
  return identification_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
