#include "ros/ros.h"
#include <std_msgs/String.h>
// http://docs.ros.org/en/noetic/api/std_msgs/html/msg/String.html
// std_msgs/String Message
// File: std_msgs/String.msg
// Raw Message Definition
// string data

int main(int argc ,char **argv){
    ros::init(argc,argv,"publisher_node");
    ros::NodeHandle nh;
    ROS_INFO("Node has been started");
    ros::Publisher pub;
    pub =nh.advertise<std_msgs::String>("/chatter",10);
    ros::Rate rate(10);
    while (ros::ok()){
        std_msgs::String msgs;
        msgs.data ="hai";
        pub.publish(msgs);
        rate.sleep();

    } 
    return 0;

}