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

bool handle_function(rospy_tutorials::AddTwoInts::Request &req,
                    rospy_tutorials::AddTwoInts::Response &resp) 
{
    int result =(req.a +req.b) ;
    ROS_INFO("%d+%d=%d",(int)req.a,(int)req.b,(int)result);
    resp.sum=result;
    return true;
}
                                                      

int main(int argc ,char **argv){
    ros::init(argc,argv,"server_node");
    ros::NodeHandle nh;
    ROS_INFO("Server has been started");
    ros::ServiceServer server;
    server = nh.advertiseService("/twoint",handle_function);
    ros::spin();
    return 0;
}