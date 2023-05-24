#include "behaviortree_cpp/bt_factory.h"

#include "bt_training/charger_scanner.hpp"
#include "bt_training/alarm.hpp"
#include "bt_training/dock_to_charger.hpp"
#include "bt_training/reset_to_home.hpp"
#include "bt_training/publish_to_charger.hpp"

#include "rclcpp/rclcpp.hpp"

using BehaviorTreeFactory = BT::BehaviorTreeFactory; 
using Alarm = bt_training::Alarm;
using ResetToHome = bt_training::ResetToHome;
using ChargerScanner = bt_training::ChargerScanner;
using DockToCharger = bt_training::DockToCharger;
using PublishToCharger = bt_training::PublishToCharger;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  BehaviorTreeFactory factory;

  factory.registerNodeType<ChargerScanner>("ChargerScanner");
  factory.registerNodeType<Alarm>("Alarm");
  factory.registerNodeType<DockToCharger>("DockToCharger");
  factory.registerNodeType<ResetToHome>("ResetToHome");
  factory.registerNodeType<PublishToCharger>("PublishToCharger");

  auto tree = factory.createTreeFromFile("install/bt_training/lib/bt_training/config/ex3_tree.xml");
  
  std::cout << tree.tickWhileRunning() << std::endl;

  return 0;
}
