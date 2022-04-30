#include "ros/ros.h"
#include <custom_messages/hardware.h>
bool handle_function(custom_messages::hardware::Request &req,
                    custom_messages::hardware::Response &resp){
 int results=(req.a+req.b);
 ROS_INFO("%d + %d = %d",(int)req.a,(int)req.b,results);
 resp.c=results;
 return true;}

int main(int argc ,char **argv){
    ros::init(argc,argv,"sensor_server_node");
    ros::NodeHandle nh;
    ros::ServiceServer server;
    server = nh.advertiseService("/hardware_srv",handle_function);
    ros::spin();
    return 0;
    
} 