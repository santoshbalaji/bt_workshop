#include "bt_training/charger_scanner.hpp"

using ChargerScanner = bt_training::ChargerScanner;

ChargerScanner:: ChargerScanner(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{}

PortsList ChargerScanner::providedPorts()
{
  return 
  { 
    BT::OutputPort<std::string>("x"),
    BT::OutputPort<std::string>("y")
  };
}

NodeStatus ChargerScanner::tick() 
{
  setOutput("x", "2");
  setOutput("y", "4");

  unsigned int seed = time(NULL);
  int choice = rand_r(&seed) % 2;
  std::cout << "Charger scanner : " << choice << std::endl;

  return choice ==  0 ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}
