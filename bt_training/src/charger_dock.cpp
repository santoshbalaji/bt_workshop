#include "bt_training/charger_dock.hpp"

using ChargerDock = bt_training::ChargerDock;

ChargerDock:: ChargerDock(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{}

PortsList ChargerDock::providedPorts()
{
  return 
  { 
    BT::InputPort<std::string>("distance"),
  };
}

NodeStatus ChargerDock::tick() 
{
  BT::Expected<std::string> distance = getInput<std::string>("distance");

  if (!distance)
  {
    throw BT::RuntimeError(
      "missing required input [distance]: ",
      distance.error());
  }

  std::cout << "Dock distance from robot: " << distance.value() << std::endl;

  unsigned int seed = time(NULL);
  int choice = rand_r(&seed) % 2;
  std::string state = choice ==  0 ? "Success" : "Failure";
  std::cout << "Dock to charger : " << state << std::endl;

  return choice ==  0 ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}
