/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * KalmanFilter.c
 *
 * Code generation for function 'KalmanFilter'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "KalmanFilter.h"
#include "mrdivide.h"

/* Variable Definitions */
static double P[144];

/* Function Definitions */
void KalmanFilter(double x[12], const double z[6])
{
  int k;
  double a[12];
  int i0;
  static const double b_a[144] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.037, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.037, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.037, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.037, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.037,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.037, 0.0, 0.0,
    1.0 };

  double c_a[144];
  int i1;
  double K[72];
  double d_a[36];
  double d0;
  double e_a[72];
  static const double b[144] = { 1.0, 0.0, 0.0, 0.037, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.037, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.037, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.037, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.037, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.037, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  signed char I[144];
  static const signed char f_a[72] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1 };

  static const signed char b_b[72] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1 };

  double b_z[6];
  static const double R[36] = { 4.841E-35, 2.46E-36, -8.85E-35, 3.377E-33,
    4.851E-5, -4.566E-6, 2.46E-36, 1.069E-5, 6.678E-8, 9.12E-33, 1.5124E-5,
    -1.013E-5, -8.85E-35, 6.678E-8, 5.49E-7, -2.022E-31, -2.991E-5, -9.259E-7,
    3.377E-33, 9.12E-33, -2.022E-31, 0.06636, -0.01034, 0.002165, 4.851E-5,
    1.5124E-5, -2.991E-5, -0.01035, 0.06261, 0.005194, -4.566E-6, -1.013E-5,
    -9.259E-7, 0.002165, 0.005194, 0.07548 };

  double b_I[144];

  /*   */
  /*  Kalman Filter Function */
  /*  By: Adam Mirza */
  /*  Avionics Northeastern AIAA */
  /*  Summer 1 2018 */
  /*  */
  /*  calculate time step in s */
  /*  accelerometer moment arms */
  /*  P matrix guess */
  /*  calculate F matrix */
  /*  Q matrix */
  /*  H matrix */
  /*  calculate R matrix */
  /*  prediction step */
  for (k = 0; k < 12; k++) {
    a[k] = 0.0;
    for (i0 = 0; i0 < 12; i0++) {
      a[k] += b_a[k + 12 * i0] * x[i0];
    }
  }

  for (k = 0; k < 12; k++) {
    x[k] = a[k];
    for (i0 = 0; i0 < 12; i0++) {
      c_a[k + 12 * i0] = 0.0;
      for (i1 = 0; i1 < 12; i1++) {
        c_a[k + 12 * i0] += b_a[k + 12 * i1] * P[i1 + 12 * i0];
      }
    }
  }

  /*  measurement step     */
  for (k = 0; k < 12; k++) {
    for (i0 = 0; i0 < 12; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 12; i1++) {
        d0 += c_a[k + 12 * i1] * b[i1 + 12 * i0];
      }

      P[k + 12 * i0] = d0 + 0.1;
    }

    for (i0 = 0; i0 < 6; i0++) {
      K[k + 12 * i0] = 0.0;
      for (i1 = 0; i1 < 12; i1++) {
        K[k + 12 * i0] += P[k + 12 * i1] * (double)b_b[i1 + 12 * i0];
      }
    }
  }

  for (k = 0; k < 6; k++) {
    for (i0 = 0; i0 < 12; i0++) {
      e_a[k + 6 * i0] = 0.0;
      for (i1 = 0; i1 < 12; i1++) {
        e_a[k + 6 * i0] += (double)f_a[k + 6 * i1] * P[i1 + 12 * i0];
      }
    }

    for (i0 = 0; i0 < 6; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 12; i1++) {
        d0 += e_a[k + 6 * i1] * (double)b_b[i1 + 12 * i0];
      }

      d_a[k + 6 * i0] = d0 + R[k + 6 * i0];
    }
  }

  mrdivide(K, d_a);
  for (k = 0; k < 6; k++) {
    d0 = 0.0;
    for (i0 = 0; i0 < 12; i0++) {
      d0 += (double)f_a[k + 6 * i0] * x[i0];
    }

    b_z[k] = z[k] - d0;
  }

  for (k = 0; k < 12; k++) {
    d0 = 0.0;
    for (i0 = 0; i0 < 6; i0++) {
      d0 += K[k + 12 * i0] * b_z[i0];
    }

    x[k] += d0;
  }

  memset(&I[0], 0, 144U * sizeof(signed char));
  for (k = 0; k < 12; k++) {
    I[k + 12 * k] = 1;
  }

  memcpy(&c_a[0], &P[0], 144U * sizeof(double));
  for (k = 0; k < 12; k++) {
    for (i0 = 0; i0 < 12; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d0 += K[k + 12 * i1] * (double)f_a[i1 + 6 * i0];
      }

      b_I[k + 12 * i0] = (double)I[k + 12 * i0] - d0;
    }

    for (i0 = 0; i0 < 12; i0++) {
      P[k + 12 * i0] = 0.0;
      for (i1 = 0; i1 < 12; i1++) {
        P[k + 12 * i0] += b_I[k + 12 * i1] * c_a[i1 + 12 * i0];
      }
    }
  }
}

void KalmanFilter_init(void)
{
  int k;
  memset(&P[0], 0, 144U * sizeof(double));
  for (k = 0; k < 12; k++) {
    P[k + 12 * k] = 1.0;
  }
}

/* End of code generation (KalmanFilter.c) */
