#include "bt_training/charger_request_subscriber.hpp"

using std::placeholders::_1;
using ChargerRequestSubscriber = bt_training::ChargerRequestSubscriber;

ChargerRequestSubscriber:: ChargerRequestSubscriber(
  const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
{
  ros_node_ = rclcpp::Node::make_shared("ChargerRequestSubscriber");
  subscriber_ = ros_node_->create_subscription<std_msgs::msg::String>(
    "charger_request", 
    10, 
    std::bind(&ChargerRequestSubscriber::topic_callback, this, _1));
}

void ChargerRequestSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
  distance_ = msg->data;
  trigger_ = true;
  std::cout << "Received new distance from robot side" << std::endl; 
}

PortsList ChargerRequestSubscriber::providedPorts()
{
  return 
  {
    BT::OutputPort<std::string>("distance")
  };
}

NodeStatus ChargerRequestSubscriber::tick() 
{
  while (!trigger_) {
      rclcpp::spin_some(ros_node_);
  }

  if(trigger_)
  {
    std::cout << "Charger request subscriber : Success" << std::endl;
    setOutput("distance", distance_);
    return NodeStatus::SUCCESS;
  }
  else
  {
    std::cout << "Charger request subscriber : Failure" << std::endl;
    setOutput("distance", "-1");
    return NodeStatus::FAILURE;
  }
}
