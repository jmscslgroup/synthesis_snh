#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "slros_time.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block synthesis_snh/Subscribe
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_synthesis_snh_geometry_msgs_Twist> Sub_synthesis_snh_44;

// For Block synthesis_snh/Publish1
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_synthesis_snh_geometry_msgs_Twist> Pub_synthesis_snh_37;

// For Block synthesis_snh/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_synthesis_snh_std_msgs_Float64> Pub_synthesis_snh_40;

// For Block synthesis_snh/Publish3
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_synthesis_snh_std_msgs_Float64> Pub_synthesis_snh_43;

// For Block synthesis_snh/Get Parameter
extern SimulinkParameterGetter<real64_T, double> ParamGet_synthesis_snh_17;

// For Block synthesis_snh/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_synthesis_snh_18;

void slros_node_init(int argc, char** argv);

#endif
