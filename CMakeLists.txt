cmake_minimum_required(VERSION 3.0.2)
project(voting)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  vote.msg
#   Message2.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

## Generate added messages and services with any dependencies listed here

catkin_package(
  CATKIN_DEPENDS message_generation roscpp rospy std_msgs
  )
  
  
###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
include
  ${catkin_INCLUDE_DIRS}
)
add_executable(vote src/vote.cpp)
add_executable(collect src/collect.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(vote ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(collect ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(vote
   ${catkin_LIBRARIES}
 )

 target_link_libraries(collect
   ${catkin_LIBRARIES}
 )