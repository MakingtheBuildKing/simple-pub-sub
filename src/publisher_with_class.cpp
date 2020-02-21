#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>

class PUB{
    
    public:

    PUB();   
    ~PUB();
    
    private:

    ros::NodeHandle nh;
    ros::Publisher time_pub;
    std::string time_sec, time_nsec;

    int task();
};

PUB::PUB(){

    nh = ros::NodeHandle();
    time_pub = nh.advertise<std_msgs::String>("/time_publisher/ros_timer", 10);
    task();
}

PUB::~PUB(){};

int PUB::task(){

    ros::Rate taskRate(60);

    while(ros::ok()){

        std_msgs::String msg;        
        std::stringstream ss;
        
        time_sec =  std::to_string(ros::Time::now().sec);        
        time_nsec =  std::to_string(ros::Time::now().nsec);
        ss << time_sec << "."<< time_nsec;

        msg.data = ss.str();
        time_pub.publish(msg);

        ros::spinOnce();
        taskRate.sleep();
    }

    return 0;
}

int main(int argc, char **argv){

    ros::init(argc, argv, "time_publisher");

    PUB pub;
    
    ros::Rate spinRate(30);

    while(ros::ok()){

        spinRate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}