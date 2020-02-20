cmake_minimum_required(VERSION 2.8.3)
project(tutorial_0)
set(CMAKE_VERBOSE_MAKEFILE no)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "-O3 -g -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

find_package(
  catkin REQUIRED
    COMPONENTS
        roscpp
        std_msgs
        geometry_msgs
        sensor_msgs
)

catkin_package(
  CATKIN_DEPENDS 
    roscpp
    std_msgs
    geometry_msgs
    sensor_msgs
  DEPENDS
    Boost
)

include_directories(
    ${catkin_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_publisher
    src/publisher_with_class.cpp
)

target_link_libraries(${PROJECT_NAME}_publisher
    ${Boost_LIBRARIES}
    ${catkin_LIBRARIES}
)

add_dependencies(${PROJECT_NAME}_publisher
    ${catkin_EXPORTED_TARGETS}
)


add_executable(${PROJECT_NAME}_subscriber
    src/subscriber_with_class.cpp
)

target_link_libraries(${PROJECT_NAME}_subscriber
    ${Boost_LIBRARIES}
    ${catkin_LIBRARIES}
)

add_dependencies(${PROJECT_NAME}_subscriber
    ${catkin_EXPORTED_TARGETS}
)
