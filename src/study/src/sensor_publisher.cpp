#include "ros/ros.h"
#include <custom_messages/sensor.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sensor_publisher_node");
    ROS_INFO("publisher node has been started");
    ros::NodeHandle nh;
    ros::Publisher pub;
    pub = nh.advertise<custom_messages::sensor>("/sensor_topic", 10);
    ros::Rate rate(10);
    while (ros::ok()){
        custom_messages::sensor msgs;
        ROS_INFO("publisher node has been started");
        msgs.temperature = 10;
        msgs.motor = true;
        msgs.messages = "on";
        pub.publish(msgs);
        rate.sleep();
         
}
return 0;
}