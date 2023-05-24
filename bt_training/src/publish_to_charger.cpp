#include "bt_training/publish_to_charger.hpp"

#include <thread>
#include <chrono>

using PublishToCharger = bt_training::PublishToCharger;

PublishToCharger:: PublishToCharger(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{
  ros_node_ = rclcpp::Node::make_shared("PublishToCharger");
  publisher_ = ros_node_->create_publisher<std_msgs::msg::String>("charger_request", 10);
}

PortsList PublishToCharger::providedPorts()
{
  return 
  {
    BT::InputPort<std::string>("distance")
  };
}

NodeStatus PublishToCharger::tick() 
{
  BT::Expected<std::string> distance = getInput<std::string>("distance");

  if (!distance)
  {
    throw BT::RuntimeError(
      "missing required input [distance]: ",
      distance.error());
  }

  std::this_thread::sleep_for (std::chrono::seconds(10));

  auto message = std_msgs::msg::String();
  message.data = distance.value();
  publisher_->publish(message);

  return NodeStatus::SUCCESS;
}
