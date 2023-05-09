#include "behaviortree_cpp/bt_factory.h"

#include "bt_training/say_something.hpp"
#include "bt_training/think_something.hpp"

using BehaviorTreeFactory = BT::BehaviorTreeFactory; 
using SaySomething = bt_training::SaySomething;
using ThinkSomething = bt_training::ThinkSomething;


int main()
{
  BehaviorTreeFactory factory;

  factory.registerNodeType<SaySomething>("SaySomething");
  factory.registerNodeType<ThinkSomething>("ThinkSomething");

  auto tree = factory.createTreeFromFile("install/bt_training/lib/bt_training/config/tree.xml");
  
  tree.tickWhileRunning();

  return 0;
}