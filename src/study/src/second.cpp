#include "ros/ros.h"
int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_second_node");
    ros::NodeHandle nh;
    ROS_INFO("node has started");
    ros::Rate rate(10);
    while(ros::ok()){
        ROS_INFO("hai");
        rate.sleep();
    } 
    return 0;

}

