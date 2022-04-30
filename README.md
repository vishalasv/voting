# Voting System

## About
This is a Voting System metapackage containing ROS packages, developed as an assignment work as a part of Robotics training faciliatated by Robotics Club, IIITDM Kancheepuram.

## Setup
To setup the repository onto your local machine:

 1. Navigate to the src directory of your catkin workspace
 2. Then clone it to PC use the following command:
```
git clone --recursive https://github.com/vishalasv/voting_sys
```
 3. setup bash

## Dependencies

roscpp
std_msgs
message_generation


## Nodes and Commands

**vote** (Publisher node)
This node helps the user entering the voter details and casting vote i.e., publishes the entered details to topic
To run:
```
rosrun voting vote
```

**collect** (Subscriber node)
This node helps to fetch the last voting details and to count the votes simultaneously after casting each vote

```
rosrun voting collect
```
