#include <ros/ros.h>
#include <std_msgs/String.h>

class SUB{
    
    public:

    SUB();
    ~SUB();
    
    
    private:

    ros::NodeHandle nh;
    ros::Subscriber time_sub;
    std::string time_sec, time_nsec;

    int messageCallback(const std_msgs::StringConstPtr &msg);
};

SUB::SUB(){

    nh = ros::NodeHandle("~");

    time_sub = nh.subscribe<std_msgs::String>("/time_publisher/ros_time", 10, boost::bind(&SUB::messageCallback, this, _1));
}

SUB::~SUB(){

};

int SUB::messageCallback(const std_msgs::StringConstPtr &msg){

    std::cout << msg->data << std::endl;
}

int main(int argc, char **argv){

    ros::init(argc, argv, "time_subscriber");
    
    SUB sub;

    ros::Rate spinRate(30);

    while(ros::ok()){

        spinRate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}