/********************************************************
*   Copyright (C) 2017 All rights reserved.
*   
*   Filename: test_tic_toc.cpp
*   Author  : lubing.han
*   Date    : 2017-11-02
*   Describe: 
*
********************************************************/
#include "tic_toc.h"
#include <ros/ros.h>
#include <ros/package.h>

using namespace std;
using namespace performance_tools;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "test_tic_toc");
	ros::NodeHandle nh;

  TicToc tt;

  // simple example
  tt.tic();
  usleep(123000);
  tt.toc();


  tt.tic("Total tasks"); // print each iteration for task id: Total tasks
  tt.tic("Task A", 10); // print every 10 iterations

  while (ros::ok()) {
    // tt.tic("Total tasks"); // not necessary
    tt.tic("Task A");
    usleep(50000); // doing task a
    tt.toc("Task A");

    tt.tic("Task B", 20);
    usleep(30000); // doing task b
    tt.toc("Task B");

    usleep(100000); // doing task c
    tt.toc("Total tasks");
  }

	return 0;
}