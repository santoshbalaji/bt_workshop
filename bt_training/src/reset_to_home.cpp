#include "bt_training/reset_to_home.hpp"

using ResetToHome = bt_training::ResetToHome;

ResetToHome:: ResetToHome(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{}

PortsList ResetToHome::providedPorts()
{
  return {};
}

NodeStatus ResetToHome::tick() 
{
  std::cout << "Reset to home: Success" << std::endl;
  return NodeStatus::SUCCESS;
}
