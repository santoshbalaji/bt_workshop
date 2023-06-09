#ifndef BT_TRAINING__PUBLISH_TO_CHARGER_HPP_
#define BT_TRAINING__PUBLISH_TO_CHARGER_HPP_

#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/tree_node.h"
#include "behaviortree_cpp/basic_types.h"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using StatefulActionNode = BT::StatefulActionNode;
using NodeConfig = BT::NodeConfig;
using NodeStatus = BT::NodeStatus;
using PortsList = BT::PortsList;

namespace bt_training
{

class PublishToCharger : public StatefulActionNode
{
  public:
    PublishToCharger(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;

  private:
    rclcpp::Node::SharedPtr ros_node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

}  // namespace bt_training


#endif  // BT_TRAINING__PUBLISH_TO_CHARGER_HPP_
