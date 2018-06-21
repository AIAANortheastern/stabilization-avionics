/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * KalmanFilter.h
 *
 * Code generation for function 'KalmanFilter'
 *
 */

#ifndef KALMANFILTER_H
#define KALMANFILTER_H

#if defined (_cplusplus)
  extern "C" {
#endif

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "KalmanFilter_types.h"

/* Function Declarations */
extern void KalmanFilter(double x[12], const double z[6]);
extern void KalmanFilter_init(void);

#if defined (_cplusplus)
  }
#endif

#endif

/* End of code generation (KalmanFilter.h) */
