# Prequisite

* Install [ROS Kinetic Kame](http://wiki.ros.org/kinetic/Installation/Ubuntu)
* Install boost library(1.58)
    ```
    sudo apt install libboost-all-dev
    ```

# Getting Started

1. First, turn on ros core

    ```bash
    roscore
    ```

1. Create another terminal (ctrl + alt + t)

    ```bash
    rosrun tutorial_0 tutorial_0_publisher 
    ```


1. Again, create another terminal (ctrl + alt + t)
    ```bash
    rosrun tutorial_0 tutorial_0_subscriber
    ```