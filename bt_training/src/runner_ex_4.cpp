#include "behaviortree_cpp/bt_factory.h"

#include "bt_training/charger_dock.hpp"
#include "bt_training/charger_request_subscriber.hpp"

#include "rclcpp/rclcpp.hpp"

using BehaviorTreeFactory = BT::BehaviorTreeFactory; 
using ChargerRequestSubscriber = bt_training::ChargerRequestSubscriber;
using ChargerDock = bt_training::ChargerDock;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  BehaviorTreeFactory factory;

  factory.registerNodeType<ChargerDock>("ChargerDock");
  factory.registerNodeType<ChargerRequestSubscriber>("ChargerRequestSubscriber");

  auto tree = factory.createTreeFromFile("install/bt_training/lib/bt_training/config/ex4_tree.xml");
  
  std::cout << tree.tickWhileRunning() << std::endl;

  return 0;
}
