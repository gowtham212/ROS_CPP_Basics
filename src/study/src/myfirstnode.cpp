#include "ros/ros.h"
int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_first_cpp_node");
    ros::NodeHandle nh;
    ROS_INFO("node has started");
    // ros::Duration(3.0).sleep();
    // ROS_INFO("exit");
    ros::Rate rate(10);
    while (ros::ok())
    {
        ROS_INFO("hai");
        rate.sleep();
    }
 return 0;
}
