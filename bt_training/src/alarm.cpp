#include "bt_training/alarm.hpp"

using Alarm = bt_training::Alarm;

Alarm:: Alarm(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{}

PortsList Alarm::providedPorts()
{
  return {};
}

NodeStatus Alarm::tick() 
{
  std::cout << "Signal red: Failure" << std::endl;
  return NodeStatus::FAILURE;
}
