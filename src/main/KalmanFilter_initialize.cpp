/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * KalmanFilter_initialize.c
 *
 * Code generation for function 'KalmanFilter_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "KalmanFilter.h"
#include "KalmanFilter_initialize.h"

/* Function Definitions */
void KalmanFilter_initialize(void)
{
  rt_InitInfAndNaN(8U);
  KalmanFilter_init();
}

/* End of code generation (KalmanFilter_initialize.c) */
