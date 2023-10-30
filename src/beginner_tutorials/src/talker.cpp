/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{ 
  ros::init(argc, argv, "talker");
    // argc, argv: 2 paraments to deliver the value; 
    // "talker": name of node
  ros::NodeHandle n; 
    // create the handle

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    // create the publisher
    // “chapter”: name of topic
    // 1000: the info can be stored in list
  ros::Rate loop_rate(10);
    // the rate of loop (rate of delivering infos): 1000times/10s

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg; // create an String (from std_msg) called 'msg', involving infos
    std::stringstream ss; // create an sringstream (from std) called 'ss', involving original infos
    
    // transfer info 'hello world' into ss, then into msg.data
    ss << "hello world " << count;
    msg.data = ss.str();

    // print info
    ROS_INFO("%s", msg.data.c_str());
    // pub the msg
    chatter_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();

    ++count;
  }

  return 0;
}