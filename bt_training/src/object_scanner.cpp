#include "bt_training/object_scanner.hpp"

using ObjectScanner = bt_training::ObjectScanner;

ObjectScanner:: ObjectScanner(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{}

PortsList ObjectScanner::providedPorts()
{
  return {};
}

NodeStatus ObjectScanner::tick() 
{
  unsigned int seed = time(NULL);
  int choice = rand_r(&seed) % 2;
  std::string state = choice ==  0 ? "Success" : "Failure";
  std::cout << "Object Scanner : " << state << std::endl;

  return choice ==  0 ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}
