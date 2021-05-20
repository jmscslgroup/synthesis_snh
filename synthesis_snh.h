//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: synthesis_snh.h
//
// Code generated for Simulink model 'synthesis_snh'.
//
// Model version                  : 3.4
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu May 20 02:34:47 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_synthesis_snh_h_
#define RTW_HEADER_synthesis_snh_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "synthesis_snh_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_synthesis_snh_T {
  SL_Bus_synthesis_snh_geometry_msgs_Twist In1;// '<S9>/In1'
  SL_Bus_synthesis_snh_geometry_msgs_Twist BusAssignment1;// '<Root>/Bus Assignment1' 
};

// Block states (default storage) for system '<Root>'
struct DW_synthesis_snh_T {
  ros_slros_internal_block_Curr_T obj; // '<Root>/Current Time'
  ros_slros_internal_block_GetP_T obj_e;// '<Root>/Get Parameter1'
  ros_slros_internal_block_GetP_T obj_l;// '<Root>/Get Parameter'
  ros_slroscpp_internal_block_P_T obj_k;// '<S7>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_h;// '<S6>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_o;// '<S5>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_d;// '<S8>/SourceBlock'
  real_T last_time;                    // '<Root>/MATLAB Function'
  real_T last_value;                   // '<Root>/MATLAB Function'
  boolean_T last_time_not_empty;       // '<Root>/MATLAB Function'
};

// Parameters (default storage)
struct P_synthesis_snh_T_ {
  SL_Bus_synthesis_snh_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S1>/Constant'

  SL_Bus_synthesis_snh_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                      //  Referenced by: '<S9>/Out1'

  SL_Bus_synthesis_snh_geometry_msgs_Twist Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                               //  Referenced by: '<S8>/Constant'

  SL_Bus_synthesis_snh_std_msgs_Float64 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                            //  Referenced by: '<S2>/Constant'

  SL_Bus_synthesis_snh_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                            //  Referenced by: '<S3>/Constant'

  real_T Gain_Gain;                    // Expression: 1e-9
                                          //  Referenced by: '<Root>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_synthesis_snh_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_synthesis_snh_T synthesis_snh_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_synthesis_snh_T synthesis_snh_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_synthesis_snh_T synthesis_snh_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void synthesis_snh_initialize(void);
  extern void synthesis_snh_step(void);
  extern void synthesis_snh_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_synthesis_snh_T *const synthesis_snh_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'synthesis_snh'
//  '<S1>'   : 'synthesis_snh/Blank Message1'
//  '<S2>'   : 'synthesis_snh/Blank Message2'
//  '<S3>'   : 'synthesis_snh/Blank Message3'
//  '<S4>'   : 'synthesis_snh/MATLAB Function'
//  '<S5>'   : 'synthesis_snh/Publish1'
//  '<S6>'   : 'synthesis_snh/Publish2'
//  '<S7>'   : 'synthesis_snh/Publish3'
//  '<S8>'   : 'synthesis_snh/Subscribe'
//  '<S9>'   : 'synthesis_snh/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_synthesis_snh_h_

//
// File trailer for generated code.
//
// [EOF]
//
