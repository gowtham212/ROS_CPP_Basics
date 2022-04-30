#include "ros/ros.h"
#include <custom_messages/sensor.h>
void call_back(const custom_messages::sensor &msgs){
    ROS_INFO("i get sensor messages  temperature %d \n motor_status %d \n message %s",msgs.temperature,msgs.motor,msgs.messages.c_str());
    //   ROS_INFO(" %d %d %s",msgs.temperature,msgs.motor,msgs.messages.c_str());
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "sensor_subscriber_node");
    ROS_INFO("subscriber node has been started");
    ros::NodeHandle nh;
    ros::Subscriber sub;
    sub = nh.subscribe("/sensor_topic",1000,call_back);
    ros::spin(); 
    return 0;

}