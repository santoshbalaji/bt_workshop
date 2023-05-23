#include "behaviortree_cpp/bt_factory.h"

#include "bt_training/navigate_to_pose.hpp"
#include "bt_training/alarm.hpp"
#include "bt_training/object_scanner.hpp"
#include "bt_training/reset_to_home.hpp"

using BehaviorTreeFactory = BT::BehaviorTreeFactory; 
using NavigateToPose = bt_training::NavigateToPose;
using Alarm = bt_training::Alarm;
using ObjectScanner = bt_training::ObjectScanner;
using ResetToHome = bt_training::ResetToHome;

int main()
{
  BehaviorTreeFactory factory;

  factory.registerNodeType<NavigateToPose>("NavigateToPose");
  factory.registerNodeType<Alarm>("Alarm");
  factory.registerNodeType<ObjectScanner>("ObjectScanner");
  factory.registerNodeType<ResetToHome>("ResetToHome");

  auto tree = factory.createTreeFromFile("install/bt_training/lib/bt_training/config/ex2_tree.xml");
  
  std::cout << tree.tickWhileRunning() << std::endl;

  return 0;
}
