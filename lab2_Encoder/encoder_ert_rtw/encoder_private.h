/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: encoder_private.h
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

#ifndef encoder_private_h_
#define encoder_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "encoder.h"
#include "encoder_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void encoder_MATLABFunction1_Init(DW_MATLABFunction1_encoder_T *localDW);
extern void encoder_MATLABFunction1(real_T rtu_encoder_signal, real_T
  rtu_max_counts, real_T *rty_Position, real_T *rty_Velocity, real_T *rty_Pulse,
  DW_MATLABFunction1_encoder_T *localDW);
extern void encoder_MATLABFunction3_Init(DW_MATLABFunction3_encoder_T *localDW);
extern void encoder_MATLABFunction3(boolean_T rtu_A, boolean_T rtu_B, real_T
  rtu_nx, real_T *rty_position, real_T *rty_velocity, real_T *rty_pulse,
  DW_MATLABFunction3_encoder_T *localDW);

#endif                                 /* encoder_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
