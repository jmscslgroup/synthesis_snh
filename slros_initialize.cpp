#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "synthesis_snh";

// For Block synthesis_snh/Subscribe
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_synthesis_snh_geometry_msgs_Twist> Sub_synthesis_snh_44;

// For Block synthesis_snh/Publish1
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_synthesis_snh_geometry_msgs_Twist> Pub_synthesis_snh_37;

// For Block synthesis_snh/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_synthesis_snh_std_msgs_Float64> Pub_synthesis_snh_40;

// For Block synthesis_snh/Publish3
SimulinkPublisher<std_msgs::Float64, SL_Bus_synthesis_snh_std_msgs_Float64> Pub_synthesis_snh_43;

// For Block synthesis_snh/Get Parameter
SimulinkParameterGetter<real64_T, double> ParamGet_synthesis_snh_17;

// For Block synthesis_snh/Get Parameter1
SimulinkParameterGetter<real64_T, double> ParamGet_synthesis_snh_18;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

