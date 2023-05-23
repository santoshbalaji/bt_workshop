#include "bt_training/navigate_to_pose.hpp"

using NavigateToPose = bt_training::NavigateToPose;

NavigateToPose:: NavigateToPose(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{}

PortsList NavigateToPose::providedPorts()
{
  return {};
}

NodeStatus NavigateToPose::tick() 
{
  unsigned int seed = time(NULL);
  int choice = rand_r(&seed) % 2;
  std::string state = choice ==  0 ? "Success" : "Failure";
  std::cout << "Navigate to pose : " << state << std::endl;

  return choice ==  0 ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}
