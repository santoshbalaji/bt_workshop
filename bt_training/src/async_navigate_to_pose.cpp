#include "bt_training/async_navigate_to_pose.hpp"

#include <thread>
#include <chrono>

using AsyncNavigateToPose = bt_training::AsyncNavigateToPose;

AsyncNavigateToPose:: AsyncNavigateToPose(
  const std::string& name, const NodeConfig& config) : StatefulActionNode(name, config)
{}

PortsList AsyncNavigateToPose::providedPorts()
{
  return {};
}

BT::NodeStatus AsyncNavigateToPose::onStart()
{
  std::cout << "AsyncNavigateToPose: On start" << std::endl;
  _completion_time = std::chrono::system_clock::now() + std::chrono::milliseconds(5000);
  return BT::NodeStatus::RUNNING;
}

void AsyncNavigateToPose::onHalted()
{
  std::cout << "AsyncNavigateToPose: Aborted" << std::endl;
}

BT::NodeStatus AsyncNavigateToPose::onRunning()
{
  std::cout << "AsyncNavigateToPose: On Run" << std::endl;

  std::this_thread::sleep_for (std::chrono::seconds(1));

  if(std::chrono::system_clock::now() >= _completion_time)
  {
    std::cout << "[ AsyncNavigateToPose: FINISHED ]" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }

  return NodeStatus::RUNNING;
}
