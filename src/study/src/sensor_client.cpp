#include "ros/ros.h"
#include <custom_messages/hardware.h>

int main(int argc ,char **argv){
    ros::init(argc,argv,"sensor_client_node");
    if (argc !=3){
        ROS_INFO("enter the x and y");
        return 1 ;
    }
    
    ros::NodeHandle nh;
    ros::ServiceClient client;
    client = nh.serviceClient<custom_messages::hardware>("/hardware_srv");
    custom_messages::hardware srv;
    srv.request.a= atoll(argv[1]);
    srv.request.b= atoll(argv[2]);
    if(client.call(srv)){
        ROS_INFO("response %d",(int)srv.response.c);
    }
    else{
        ROS_INFO("service failed"); 
    }
    return 0;
}