//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: synthesis_snh.cpp
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
#include "synthesis_snh.h"
#include "synthesis_snh_private.h"

// Block signals (default storage)
B_synthesis_snh_T synthesis_snh_B;

// Block states (default storage)
DW_synthesis_snh_T synthesis_snh_DW;

// Real-time model
RT_MODEL_synthesis_snh_T synthesis_snh_M_ = RT_MODEL_synthesis_snh_T();
RT_MODEL_synthesis_snh_T *const synthesis_snh_M = &synthesis_snh_M_;

// Model step function
void synthesis_snh_step(void)
{
  SL_Bus_synthesis_snh_ros_time_Time tmp;
  SL_Bus_synthesis_snh_std_msgs_Float64 rtb_BusAssignment2;
  SL_Bus_synthesis_snh_std_msgs_Float64 rtb_BusAssignment3;
  real_T rtb_Add;
  real_T value;
  real_T value_0;
  boolean_T b_varargout_1;

  // MATLABSystem: '<Root>/Current Time'
  currentROSTimeBus(&tmp);

  // Sum: '<Root>/Add' incorporates:
  //   Gain: '<Root>/Gain'
  //   MATLABSystem: '<Root>/Current Time'

  rtb_Add = synthesis_snh_P.Gain_Gain * tmp.Nsec + tmp.Sec;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S8>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  b_varargout_1 = Sub_synthesis_snh_44.getLatestMessage
    (&synthesis_snh_B.BusAssignment1);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (b_varargout_1) {
    synthesis_snh_B.In1 = synthesis_snh_B.BusAssignment1;
  }

  // End of MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // MATLABSystem: '<Root>/Get Parameter'
  ParamGet_synthesis_snh_17.get_parameter(&value);

  // MATLABSystem: '<Root>/Get Parameter1'
  ParamGet_synthesis_snh_18.get_parameter(&value_0);

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter'
  //   MATLABSystem: '<Root>/Get Parameter1'

  if (!synthesis_snh_DW.last_time_not_empty) {
    synthesis_snh_DW.last_time = rtb_Add;
    synthesis_snh_DW.last_time_not_empty = true;
    synthesis_snh_DW.last_value = synthesis_snh_B.In1.Linear.X;
    value = synthesis_snh_B.In1.Linear.X;

    // BusAssignment: '<Root>/Bus Assignment2'
    rtb_BusAssignment2.Data = -1.0;

    // BusAssignment: '<Root>/Bus Assignment3'
    rtb_BusAssignment3.Data = 0.0;
  } else {
    // BusAssignment: '<Root>/Bus Assignment3'
    rtb_BusAssignment3.Data = rtb_Add - synthesis_snh_DW.last_time;
    if (rtb_Add - synthesis_snh_DW.last_time <= value_0) {
      value = synthesis_snh_DW.last_value;

      // BusAssignment: '<Root>/Bus Assignment2'
      rtb_BusAssignment2.Data = 0.0;
    } else {
      if (fabs(synthesis_snh_B.In1.Linear.X - synthesis_snh_DW.last_value) >=
          value) {
        value_0 = synthesis_snh_B.In1.Linear.X - synthesis_snh_DW.last_value;
        if (value_0 < 0.0) {
          value_0 = -1.0;
        } else if (value_0 > 0.0) {
          value_0 = 1.0;
        } else if (value_0 == 0.0) {
          value_0 = 0.0;
        } else {
          value_0 = (rtNaN);
        }

        value = value * value_0 + synthesis_snh_DW.last_value;
        synthesis_snh_DW.last_value = value;

        // BusAssignment: '<Root>/Bus Assignment2' incorporates:
        //   MATLABSystem: '<Root>/Get Parameter'

        rtb_BusAssignment2.Data = 1.0;
      } else {
        value = synthesis_snh_B.In1.Linear.X;
        synthesis_snh_DW.last_value = synthesis_snh_B.In1.Linear.X;

        // BusAssignment: '<Root>/Bus Assignment2'
        rtb_BusAssignment2.Data = 2.0;
      }

      synthesis_snh_DW.last_time = rtb_Add;
    }
  }

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<S1>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function'

  synthesis_snh_B.BusAssignment1 = synthesis_snh_P.Constant_Value;
  synthesis_snh_B.BusAssignment1.Linear.X = value;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_synthesis_snh_37.publish(&synthesis_snh_B.BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_synthesis_snh_40.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // Outputs for Atomic SubSystem: '<Root>/Publish3'
  // MATLABSystem: '<S7>/SinkBlock'
  Pub_synthesis_snh_43.publish(&rtb_BusAssignment3);

  // End of Outputs for SubSystem: '<Root>/Publish3'
}

// Model initialize function
void synthesis_snh_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_1[16];
    char_T b_zeroDelimName[11];
    char_T b_zeroDelimTopic[8];
    char_T b_zeroDelimTopic_0[7];
    static const char_T tmp[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[6] = { 'o', 'u', 't', 'p', 'u', 't' };

    static const char_T tmp_1[6] = { 's', 't', 'a', 't', 'u', 's' };

    static const char_T tmp_2[15] = { 'c', 'u', 'r', 'r', 'e', 'n', 't', '_',
      'd', 'e', 'l', 't', 'a', '_', 't' };

    static const char_T tmp_3[10] = { 'm', 'a', 'x', '_', 'd', 'e', 'l', 't',
      'a', 'y' };

    static const char_T tmp_4[7] = { 'd', 'e', 'l', 't', 'a', '_', 't' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S9>/Out1' incorporates:
    //   Inport: '<S9>/In1'

    synthesis_snh_B.In1 = synthesis_snh_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    synthesis_snh_DW.obj_d.matlabCodegenIsDeleted = false;
    synthesis_snh_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_synthesis_snh_44.createSubscriber(&b_zeroDelimTopic[0], 1);
    synthesis_snh_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    synthesis_snh_DW.obj_o.matlabCodegenIsDeleted = false;
    synthesis_snh_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[6] = '\x00';
    Pub_synthesis_snh_37.createPublisher(&b_zeroDelimTopic_0[0], 1);
    synthesis_snh_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    synthesis_snh_DW.obj_h.matlabCodegenIsDeleted = false;
    synthesis_snh_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic_0[i] = tmp_1[i];
    }

    b_zeroDelimTopic_0[6] = '\x00';
    Pub_synthesis_snh_40.createPublisher(&b_zeroDelimTopic_0[0], 1);
    synthesis_snh_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish3'
    // Start for MATLABSystem: '<S7>/SinkBlock'
    synthesis_snh_DW.obj_k.matlabCodegenIsDeleted = false;
    synthesis_snh_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_1[i] = tmp_2[i];
    }

    b_zeroDelimTopic_1[15] = '\x00';
    Pub_synthesis_snh_43.createPublisher(&b_zeroDelimTopic_1[0], 1);
    synthesis_snh_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish3'

    // Start for MATLABSystem: '<Root>/Current Time'
    synthesis_snh_DW.obj.matlabCodegenIsDeleted = false;
    synthesis_snh_DW.obj.isInitialized = 1;
    synthesis_snh_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter'
    synthesis_snh_DW.obj_l.matlabCodegenIsDeleted = false;
    synthesis_snh_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimName[i] = tmp_3[i];
    }

    b_zeroDelimName[10] = '\x00';
    ParamGet_synthesis_snh_17.initialize(&b_zeroDelimName[0]);
    ParamGet_synthesis_snh_17.initialize_error_codes(0, 1, 2, 3);
    ParamGet_synthesis_snh_17.set_initial_value(1.0);
    synthesis_snh_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter'

    // Start for MATLABSystem: '<Root>/Get Parameter1'
    synthesis_snh_DW.obj_e.matlabCodegenIsDeleted = false;
    synthesis_snh_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp_4[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    ParamGet_synthesis_snh_18.initialize(&b_zeroDelimTopic[0]);
    ParamGet_synthesis_snh_18.initialize_error_codes(0, 1, 2, 3);
    ParamGet_synthesis_snh_18.set_initial_value(1.0);
    synthesis_snh_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter1'
  }
}

// Model terminate function
void synthesis_snh_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/Current Time'
  if (!synthesis_snh_DW.obj.matlabCodegenIsDeleted) {
    synthesis_snh_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Current Time'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!synthesis_snh_DW.obj_d.matlabCodegenIsDeleted) {
    synthesis_snh_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for MATLABSystem: '<Root>/Get Parameter'
  if (!synthesis_snh_DW.obj_l.matlabCodegenIsDeleted) {
    synthesis_snh_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter'

  // Terminate for MATLABSystem: '<Root>/Get Parameter1'
  if (!synthesis_snh_DW.obj_e.matlabCodegenIsDeleted) {
    synthesis_snh_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter1'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!synthesis_snh_DW.obj_o.matlabCodegenIsDeleted) {
    synthesis_snh_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!synthesis_snh_DW.obj_h.matlabCodegenIsDeleted) {
    synthesis_snh_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Publish3'
  // Terminate for MATLABSystem: '<S7>/SinkBlock'
  if (!synthesis_snh_DW.obj_k.matlabCodegenIsDeleted) {
    synthesis_snh_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish3'
}

//
// File trailer for generated code.
//
// [EOF]
//
