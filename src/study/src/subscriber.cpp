#include "ros/ros.h"
#include <std_msgs/String.h>
// http://docs.ros.org/en/noetic/api/std_msgs/html/msg/String.html
// std_msgs/String Message
// File: std_msgs/String.msg
// Raw Message Definition
// string data

void call_back(const std_msgs::String &msgs){
    ROS_INFO("data i get : %s",msgs.data.c_str());
}

int main(int argc,char **argv){
    ros::init(argc,argv,"subscriber_node");
    ros::NodeHandle nh;
    ros::Subscriber sub;
    sub = nh.subscribe("/chatter",1000,call_back);
    ros::spin();
    return 0;
}