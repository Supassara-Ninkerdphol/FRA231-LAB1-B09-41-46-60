/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: encoder.h
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

#ifndef encoder_h_
#define encoder_h_
#ifndef encoder_COMMON_INCLUDES_
#define encoder_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
#endif                                 /* encoder_COMMON_INCLUDES_ */

#include "encoder_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>/MATLAB Function1' */
typedef struct {
  real_T prev_signal;                  /* '<Root>/MATLAB Function1' */
  real_T corrected_sum;                /* '<Root>/MATLAB Function1' */
  int32_T sfEvent;                     /* '<Root>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function1' */
  boolean_T prev_signal_not_empty;     /* '<Root>/MATLAB Function1' */
  boolean_T corrected_sum_not_empty;   /* '<Root>/MATLAB Function1' */
} DW_MATLABFunction1_encoder_T;

/* Block states (default storage) for system '<Root>/MATLAB Function3' */
typedef struct {
  real_T prevPosition;                 /* '<Root>/MATLAB Function3' */
  real_T prevTime;                     /* '<Root>/MATLAB Function3' */
  real_T pulseCount;                   /* '<Root>/MATLAB Function3' */
  int32_T sfEvent;                     /* '<Root>/MATLAB Function3' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function3' */
  boolean_T prevA;                     /* '<Root>/MATLAB Function3' */
  boolean_T prevA_not_empty;           /* '<Root>/MATLAB Function3' */
  boolean_T prevB;                     /* '<Root>/MATLAB Function3' */
  boolean_T prevB_not_empty;           /* '<Root>/MATLAB Function3' */
  boolean_T prevPosition_not_empty;    /* '<Root>/MATLAB Function3' */
  boolean_T prevTime_not_empty;        /* '<Root>/MATLAB Function3' */
  boolean_T pulseCount_not_empty;      /* '<Root>/MATLAB Function3' */
} DW_MATLABFunction3_encoder_T;

/* Block signals (default storage) */
typedef struct {
  real_T velocity_1X_QEI;              /* '<Root>/Gain1' */
  real_T position_1X_QEI;              /* '<Root>/Gain' */
  real_T position_2X_QEI;              /* '<Root>/Gain2' */
  real_T Velocity_2X_QEI;              /* '<Root>/Gain3' */
  real_T position_4X_QEI;              /* '<Root>/Gain4' */
  real_T Velocity_4X_QEI;              /* '<Root>/Gain5' */
  real_T position_1X_Poling;           /* '<Root>/Gain6' */
  real_T Velocity_1X_Poling;           /* '<Root>/Gain7' */
  real_T position_4X_Poling;           /* '<Root>/Gain10' */
  real_T Velocity_4X_Poling;           /* '<Root>/Gain11' */
  real_T position_2X_Poling;           /* '<Root>/Gain8' */
  real_T Velocity_2X_Poling;           /* '<Root>/Gain9' */
  real_T pulse;                        /* '<Root>/MATLAB Function5' */
  real_T pulse_f;                      /* '<Root>/MATLAB Function4' */
  real_T pulse_d;                      /* '<Root>/MATLAB Function3' */
  uint32_T Encoder2_o1;                /* '<Root>/Encoder2' */
  uint32_T Encoder1_o1;                /* '<Root>/Encoder1' */
  uint32_T Encoder_o1;                 /* '<Root>/Encoder' */
  boolean_T Dirx2;                     /* '<Root>/Encoder2' */
  boolean_T Dirx2_h;                   /* '<Root>/Encoder1' */
  boolean_T Dir1;                      /* '<Root>/Encoder' */
  boolean_T DigitalPortRead;           /* '<S12>/Digital Port Read' */
  boolean_T DigitalPortRead_j;         /* '<S10>/Digital Port Read' */
} B_encoder_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/Encoder2' */
  stm32cube_blocks_EncoderBlock_T obj_d;/* '<Root>/Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_p;/* '<Root>/Encoder' */
  DW_MATLABFunction1_encoder_T sf_MATLABFunction6;/* '<Root>/MATLAB Function6' */
  DW_MATLABFunction3_encoder_T sf_MATLABFunction5;/* '<Root>/MATLAB Function5' */
  DW_MATLABFunction3_encoder_T sf_MATLABFunction4;/* '<Root>/MATLAB Function4' */
  DW_MATLABFunction3_encoder_T sf_MATLABFunction3;/* '<Root>/MATLAB Function3' */
  DW_MATLABFunction1_encoder_T sf_MATLABFunction2;/* '<Root>/MATLAB Function2' */
  DW_MATLABFunction1_encoder_T sf_MATLABFunction1;/* '<Root>/MATLAB Function1' */
} DW_encoder_T;

/* Real-time Model Data Structure */
struct tag_RTM_encoder_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_encoder_T encoder_B;

/* Block states (default storage) */
extern DW_encoder_T encoder_DW;

/* Model entry point functions */
extern void encoder_initialize(void);
extern void encoder_step(void);
extern void encoder_terminate(void);

/* Real-time Model object */
extern RT_MODEL_encoder_T *const encoder_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'encoder'
 * '<S1>'   : 'encoder/Digital Port Read'
 * '<S2>'   : 'encoder/Digital Port Read1'
 * '<S3>'   : 'encoder/MATLAB Function1'
 * '<S4>'   : 'encoder/MATLAB Function2'
 * '<S5>'   : 'encoder/MATLAB Function3'
 * '<S6>'   : 'encoder/MATLAB Function4'
 * '<S7>'   : 'encoder/MATLAB Function5'
 * '<S8>'   : 'encoder/MATLAB Function6'
 * '<S9>'   : 'encoder/Digital Port Read/ECSoC'
 * '<S10>'  : 'encoder/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S11>'  : 'encoder/Digital Port Read1/ECSoC'
 * '<S12>'  : 'encoder/Digital Port Read1/ECSoC/ECSimCodegen'
 */
#endif                                 /* encoder_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
