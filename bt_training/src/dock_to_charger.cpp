#include "bt_training/dock_to_charger.hpp"

using DockToCharger = bt_training::DockToCharger;

DockToCharger:: DockToCharger(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{}

PortsList DockToCharger::providedPorts()
{
  return 
  { 
    BT::InputPort<std::string>("x"),
    BT::InputPort<std::string>("y")
  };
}

NodeStatus DockToCharger::tick() 
{
  BT::Expected<std::string> x = getInput<std::string>("x");
  BT::Expected<std::string> y = getInput<std::string>("y");

  if (!x)
  {
    throw BT::RuntimeError(
      "missing required input [x]: ",
      x.error());
  }

  if (!y)
  {
    throw BT::RuntimeError(
      "missing required input [y]: ",
      y.error());
  }

  std::cout << "Dock x on robot: " << x.value() << std::endl;
  std::cout << "Dock y on robot: " << y.value() << std::endl;

  unsigned int seed = time(NULL);
  int choice = rand_r(&seed) % 2;
  std::cout << "Dock to charger : " << choice << std::endl;

  return choice ==  0 ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}
