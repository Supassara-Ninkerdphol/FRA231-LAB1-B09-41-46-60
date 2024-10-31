/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: encoder.c
 *
 * Code generated for Simulink model 'encoder'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Oct 30 18:52:15 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "encoder.h"
#include "rtwtypes.h"
#include "encoder_types.h"
#include "encoder_private.h"
#include <math.h>
#include "stm_timer_ll.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function1' */
#define encoder_CALL_EVENT             (-1)

/* Named constants for MATLAB Function: '<Root>/MATLAB Function3' */
#define encoder_CALL_EVENT_g           (-1)

/* Block signals (default storage) */
B_encoder_T encoder_B;

/* Block states (default storage) */
DW_encoder_T encoder_DW;

/* Real-time model */
static RT_MODEL_encoder_T encoder_M_;
RT_MODEL_encoder_T *const encoder_M = &encoder_M_;

/* Forward declaration for local functions */
static void encoder_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void encoder_SystemCore_setup_c(stm32cube_blocks_EncoderBlock_T *obj);
static void encoder_SystemCore_setup_ck(stm32cube_blocks_EncoderBlock_T *obj);

/*
 * System initialize for atomic system:
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 *    '<Root>/MATLAB Function6'
 */
void encoder_MATLABFunction1_Init(DW_MATLABFunction1_encoder_T *localDW)
{
  localDW->sfEvent = encoder_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 *    '<Root>/MATLAB Function6'
 */
void encoder_MATLABFunction1(real_T rtu_encoder_signal, real_T rtu_max_counts,
  real_T *rty_Position, real_T *rty_Velocity, real_T *rty_Pulse,
  DW_MATLABFunction1_encoder_T *localDW)
{
  real_T delta;
  localDW->sfEvent = encoder_CALL_EVENT;
  if (!localDW->prev_signal_not_empty) {
    localDW->prev_signal = rtu_encoder_signal;
    localDW->prev_signal_not_empty = true;
    localDW->corrected_sum = rtu_encoder_signal;
    localDW->corrected_sum_not_empty = true;
  }

  *rty_Velocity = 0.0;
  delta = rtu_encoder_signal - localDW->prev_signal;
  if (delta < -rtu_max_counts / 2.0) {
    localDW->corrected_sum += delta + rtu_max_counts;
  } else if (delta > rtu_max_counts / 2.0) {
    localDW->corrected_sum += delta - rtu_max_counts;
  } else {
    localDW->corrected_sum += delta;
    *rty_Velocity = delta / 0.1;
  }

  localDW->prev_signal = rtu_encoder_signal;
  *rty_Position = localDW->corrected_sum;
  *rty_Pulse = rtu_encoder_signal;
}

/*
 * System initialize for atomic system:
 *    '<Root>/MATLAB Function3'
 *    '<Root>/MATLAB Function4'
 *    '<Root>/MATLAB Function5'
 */
void encoder_MATLABFunction3_Init(DW_MATLABFunction3_encoder_T *localDW)
{
  localDW->sfEvent = encoder_CALL_EVENT_g;
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function3'
 *    '<Root>/MATLAB Function4'
 *    '<Root>/MATLAB Function5'
 */
void encoder_MATLABFunction3(boolean_T rtu_A, boolean_T rtu_B, real_T rtu_nx,
  real_T *rty_position, real_T *rty_velocity, real_T *rty_pulse,
  DW_MATLABFunction3_encoder_T *localDW)
{
  int32_T deltaPosition;
  localDW->sfEvent = encoder_CALL_EVENT_g;
  if (!localDW->prevA_not_empty) {
    localDW->prevA = rtu_A;
    localDW->prevA_not_empty = true;
    localDW->prevB = rtu_B;
    localDW->prevB_not_empty = true;
    localDW->prevPosition_not_empty = true;
    localDW->prevTime_not_empty = true;
    localDW->pulseCount_not_empty = true;
  }

  deltaPosition = 0;
  if (rtu_nx == 1.0) {
    if ((rtu_A != localDW->prevA) && rtu_A) {
      if (!rtu_B) {
        deltaPosition = 1;
      } else {
        deltaPosition = -1;
      }
    }
  } else if (rtu_nx == 2.0) {
    if (rtu_A != localDW->prevA) {
      if (!rtu_B) {
        deltaPosition = rtu_A - localDW->prevA;
        if (deltaPosition < 0) {
          deltaPosition = -1;
        } else {
          deltaPosition = (deltaPosition > 0);
        }
      } else {
        deltaPosition = rtu_A - localDW->prevA;
        if (deltaPosition < 0) {
          deltaPosition = 1;
        } else {
          deltaPosition = -(deltaPosition > 0);
        }
      }
    }
  } else if (rtu_nx == 4.0) {
    if ((rtu_A != localDW->prevA) && rtu_A) {
      if (rtu_B) {
        deltaPosition = -1;
      } else {
        deltaPosition = 1;
      }
    }

    if ((rtu_A != localDW->prevA) && (!rtu_A)) {
      if (rtu_B) {
        deltaPosition = 1;
      } else {
        deltaPosition = -1;
      }
    }

    if ((rtu_B != localDW->prevB) && rtu_B) {
      if (rtu_A) {
        deltaPosition = 1;
      } else {
        deltaPosition = -1;
      }
    }

    if ((rtu_B != localDW->prevB) && (!rtu_B)) {
      if (rtu_A) {
        deltaPosition = -1;
      } else {
        deltaPosition = 1;
      }
    }
  }

  localDW->pulseCount += fabs((real_T)deltaPosition);
  localDW->prevPosition += (real_T)deltaPosition;
  *rty_velocity = (real_T)deltaPosition / 0.001;
  *rty_position = localDW->prevPosition;
  *rty_pulse = localDW->pulseCount;
  localDW->prevA = rtu_A;
  localDW->prevB = rtu_B;
}

static void encoder_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void encoder_SystemCore_setup_c(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void encoder_SystemCore_setup_ck(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Encoder2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void encoder_step(void)
{
  real_T Position;
  real_T Pulse;
  real_T Velocity;
  uint32_T pinReadLoc;

  /* MATLABSystem: '<Root>/Encoder' */
  encoder_B.Encoder_o1 = getTimerCounterValueForG4(encoder_DW.obj_p.TimerHandle,
    false, NULL);

  /* MATLABSystem: '<Root>/Encoder' */
  encoder_B.Dir1 = ouputDirectionOfCounter(encoder_DW.obj_p.TimerHandle);

  /* MATLAB Function: '<Root>/MATLAB Function6' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  encoder_MATLABFunction1((real_T)encoder_B.Encoder_o1, 65535.0, &Position,
    &Velocity, &Pulse, &encoder_DW.sf_MATLABFunction6);

  /* Gain: '<Root>/Gain1' */
  encoder_B.velocity_1X_QEI = 0.26179938779914941 * Velocity;

  /* Gain: '<Root>/Gain' */
  encoder_B.position_1X_QEI = 0.26179938779914941 * Position;

  /* MATLABSystem: '<Root>/Encoder1' */
  encoder_B.Encoder1_o1 = getTimerCounterValueForG4(encoder_DW.obj_d.TimerHandle,
    false, NULL);

  /* MATLABSystem: '<Root>/Encoder1' */
  encoder_B.Dirx2_h = ouputDirectionOfCounter(encoder_DW.obj_d.TimerHandle);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  encoder_MATLABFunction1((real_T)encoder_B.Encoder1_o1, 65535.0, &Velocity,
    &Position, &Pulse, &encoder_DW.sf_MATLABFunction1);

  /* Gain: '<Root>/Gain2' */
  encoder_B.position_2X_QEI = 0.1308996938995747 * Velocity;

  /* Gain: '<Root>/Gain3' */
  encoder_B.Velocity_2X_QEI = 0.1308996938995747 * Position;

  /* MATLABSystem: '<Root>/Encoder2' */
  encoder_B.Encoder2_o1 = getTimerCounterValueForG4(encoder_DW.obj.TimerHandle,
    false, NULL);

  /* MATLABSystem: '<Root>/Encoder2' */
  encoder_B.Dirx2 = ouputDirectionOfCounter(encoder_DW.obj.TimerHandle);

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Constant: '<Root>/Constant2'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  encoder_MATLABFunction1((real_T)encoder_B.Encoder2_o1, 65535.0, &Velocity,
    &Position, &Pulse, &encoder_DW.sf_MATLABFunction2);

  /* Gain: '<Root>/Gain4' */
  encoder_B.position_4X_QEI = 0.065449846949787352 * Velocity;

  /* Gain: '<Root>/Gain5' */
  encoder_B.Velocity_4X_QEI = 0.065449846949787352 * Position;

  /* MATLABSystem: '<S12>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* MATLABSystem: '<S12>/Digital Port Read' */
  encoder_B.DigitalPortRead = ((pinReadLoc & 256U) != 0U);

  /* MATLABSystem: '<S10>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOB);

  /* MATLABSystem: '<S10>/Digital Port Read' */
  encoder_B.DigitalPortRead_j = ((pinReadLoc & 1024U) != 0U);

  /* MATLAB Function: '<Root>/MATLAB Function4' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  encoder_MATLABFunction3(encoder_B.DigitalPortRead_j, encoder_B.DigitalPortRead,
    1.0, &Velocity, &Position, &encoder_B.pulse_f,
    &encoder_DW.sf_MATLABFunction4);

  /* Gain: '<Root>/Gain6' */
  encoder_B.position_1X_Poling = 0.26179938779914941 * Velocity;

  /* Gain: '<Root>/Gain7' */
  encoder_B.Velocity_1X_Poling = 0.26179938779914941 * Position;

  /* MATLAB Function: '<Root>/MATLAB Function5' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  encoder_MATLABFunction3(encoder_B.DigitalPortRead_j, encoder_B.DigitalPortRead,
    4.0, &Velocity, &Position, &encoder_B.pulse, &encoder_DW.sf_MATLABFunction5);

  /* Gain: '<Root>/Gain10' */
  encoder_B.position_4X_Poling = 0.065449846949787352 * Velocity;

  /* Gain: '<Root>/Gain11' */
  encoder_B.Velocity_4X_Poling = 0.065449846949787352 * Position;

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  encoder_MATLABFunction3(encoder_B.DigitalPortRead_j, encoder_B.DigitalPortRead,
    2.0, &Velocity, &Position, &encoder_B.pulse_d,
    &encoder_DW.sf_MATLABFunction3);

  /* Gain: '<Root>/Gain8' */
  encoder_B.position_2X_Poling = 0.1308996938995747 * Velocity;

  /* Gain: '<Root>/Gain9' */
  encoder_B.Velocity_2X_Poling = 0.1308996938995747 * Position;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  encoder_M->Timing.taskTime0 =
    ((time_T)(++encoder_M->Timing.clockTick0)) * encoder_M->Timing.stepSize0;
}

/* Model initialize function */
void encoder_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(encoder_M, -1);
  encoder_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  encoder_M->Sizes.checksums[0] = (3969079557U);
  encoder_M->Sizes.checksums[1] = (2395932629U);
  encoder_M->Sizes.checksums[2] = (2343384383U);
  encoder_M->Sizes.checksums[3] = (1573758312U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(encoder_M->extModeInfo,
      &encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(encoder_M->extModeInfo, encoder_M->Sizes.checksums);
    rteiSetTPtr(encoder_M->extModeInfo, rtmGetTPtr(encoder_M));
  }

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function6' */
  encoder_MATLABFunction1_Init(&encoder_DW.sf_MATLABFunction6);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
  encoder_MATLABFunction1_Init(&encoder_DW.sf_MATLABFunction1);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function2' */
  encoder_MATLABFunction1_Init(&encoder_DW.sf_MATLABFunction2);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function4' */
  encoder_MATLABFunction3_Init(&encoder_DW.sf_MATLABFunction4);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function5' */
  encoder_MATLABFunction3_Init(&encoder_DW.sf_MATLABFunction5);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function3' */
  encoder_MATLABFunction3_Init(&encoder_DW.sf_MATLABFunction3);

  /* Start for MATLABSystem: '<Root>/Encoder' */
  encoder_DW.obj_p.isInitialized = 0;
  encoder_DW.obj_p.matlabCodegenIsDeleted = false;
  encoder_SystemCore_setup(&encoder_DW.obj_p);

  /* Start for MATLABSystem: '<Root>/Encoder1' */
  encoder_DW.obj_d.isInitialized = 0;
  encoder_DW.obj_d.matlabCodegenIsDeleted = false;
  encoder_SystemCore_setup_c(&encoder_DW.obj_d);

  /* Start for MATLABSystem: '<Root>/Encoder2' */
  encoder_DW.obj.isInitialized = 0;
  encoder_DW.obj.matlabCodegenIsDeleted = false;
  encoder_SystemCore_setup_ck(&encoder_DW.obj);
}

/* Model terminate function */
void encoder_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!encoder_DW.obj_p.matlabCodegenIsDeleted) {
    encoder_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((encoder_DW.obj_p.isInitialized == 1) &&
        encoder_DW.obj_p.isSetupComplete) {
      disableCounter(encoder_DW.obj_p.TimerHandle);
      disableTimerInterrupts(encoder_DW.obj_p.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(encoder_DW.obj_p.TimerHandle, ChannelInfo);
      disableTimerChannel2(encoder_DW.obj_p.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!encoder_DW.obj_d.matlabCodegenIsDeleted) {
    encoder_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((encoder_DW.obj_d.isInitialized == 1) &&
        encoder_DW.obj_d.isSetupComplete) {
      disableCounter(encoder_DW.obj_d.TimerHandle);
      disableTimerInterrupts(encoder_DW.obj_d.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(encoder_DW.obj_d.TimerHandle, ChannelInfo);
      disableTimerChannel2(encoder_DW.obj_d.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/Encoder2' */
  if (!encoder_DW.obj.matlabCodegenIsDeleted) {
    encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((encoder_DW.obj.isInitialized == 1) && encoder_DW.obj.isSetupComplete) {
      disableCounter(encoder_DW.obj.TimerHandle);
      disableTimerInterrupts(encoder_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(encoder_DW.obj.TimerHandle, ChannelInfo);
      disableTimerChannel2(encoder_DW.obj.TimerHandle, ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
