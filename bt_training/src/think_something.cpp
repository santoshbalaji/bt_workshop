#include "bt_training/think_something.hpp"

using ThinkSomething = bt_training::ThinkSomething;

ThinkSomething::ThinkSomething(const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{

}

PortsList ThinkSomething::providedPorts()
{
  return { BT::InputPort<std::string>("clue"), BT::OutputPort<std::string>("text") };
}

NodeStatus ThinkSomething::tick()
{
  BT::Expected<std::string> msg = getInput<std::string>("clue");
  setOutput("text", "The answer is 42 "  + msg.value());
  return NodeStatus::SUCCESS;
}
