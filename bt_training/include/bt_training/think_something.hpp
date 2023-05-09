#ifndef BT_TRAINING__THINK_SOMETHING_HPP_
#define BT_TRAINING__THINK_SOMETHING_HPP_

#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/tree_node.h"

using SyncActionNode = BT::SyncActionNode;
using NodeConfig = BT::NodeConfig;
using NodeStatus = BT::NodeStatus;
using PortsList = BT::PortsList;

namespace bt_training 
{

class ThinkSomething : public SyncActionNode
{
  public:
    ThinkSomething(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    NodeStatus tick();
};

}  // namespace bt_training


#endif  // BT_TRAINING__THINK_SOMETHING_HPP_
