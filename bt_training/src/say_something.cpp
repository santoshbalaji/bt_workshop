#include "bt_training/say_something.hpp"

using SaySomething = bt_training::SaySomething;

SaySomething:: SaySomething(const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{

}

PortsList SaySomething::providedPorts()
{
  return { BT::InputPort<std::string>("message") };
}

NodeStatus SaySomething::tick() 
{
  BT::Expected<std::string> msg = getInput<std::string>("message");
  if (!msg)
  {
    throw BT::RuntimeError("missing required input [message]: ", 
                            msg.error() );
  }
  std::cout << "Robot says: " << msg.value() << std::endl;
  return NodeStatus::SUCCESS;
}
