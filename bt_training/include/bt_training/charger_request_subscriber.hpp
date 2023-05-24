#ifndef BT_TRAINING__CHARGER_REQUEST_SUBSCRIBER_HPP_
#define BT_TRAINING__CHARGER_REQUEST_SUBSCRIBER_HPP_

#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/tree_node.h"
#include "behaviortree_cpp/basic_types.h"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using SyncActionNode = BT::SyncActionNode;
using NodeConfig = BT::NodeConfig;
using NodeStatus = BT::NodeStatus;
using PortsList = BT::PortsList;

namespace bt_training
{

class ChargerRequestSubscriber : public SyncActionNode
{
  public:
    ChargerRequestSubscriber(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    NodeStatus tick();
  
  private:
    std::string distance_;
    bool trigger_;
    rclcpp::Node::SharedPtr ros_node_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;

    void topic_callback(const std_msgs::msg::String::SharedPtr msg);
};

}  // namespace bt_training


#endif  // BT_TRAINING__CHARGER_REQUEST_SUBSCRIBER_HPP_
