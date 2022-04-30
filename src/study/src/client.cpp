#include "ros/ros.h"
#include "rospy_tutorials/AddTwoInts.h"
// http://docs.ros.org/en/melodic/api/rospy_tutorials/html/srv/AddTwoInts.html
// rospy_tutorials/AddTwoInts Service
// File: rospy_tutorials/AddTwoInts.srv
// Raw Message Definition
// int64 a
// int64 b
// ---
// int64 sum

//install this package for rospy-tutorials
//  sudo apt install ros-melodic-rospy-tutorials

int main(int argc ,char **argv)
{
    ros::init(argc, argv,"client_node");
    if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }
    ros::NodeHandle nh;
    ros::ServiceClient client;
    client = nh.serviceClient<rospy_tutorials::AddTwoInts>("/twoint");
    rospy_tutorials::AddTwoInts srv ;
   srv.request.a = atoll(argv[1]);
   srv.request.b = atoll(argv[2]);

    if (client.call(srv)){
        ROS_INFO("I get response %d",(int)srv.response.sum);
    }
    else{
        ROS_WARN("service call failed");
    }
    return 0;
    
}