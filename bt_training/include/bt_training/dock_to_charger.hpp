#ifndef BT_TRAINING__DOCK_TO_CHARGER_HPP_
#define BT_TRAINING__DOCK_TO_CHARGER_HPP_

#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/tree_node.h"
#include "behaviortree_cpp/basic_types.h"

using SyncActionNode = BT::SyncActionNode;
using NodeConfig = BT::NodeConfig;
using NodeStatus = BT::NodeStatus;
using PortsList = BT::PortsList;

namespace bt_training
{

class DockToCharger : public SyncActionNode
{
  public:
    DockToCharger(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    NodeStatus tick();
};

}  // namespace bt_training


#endif  // BT_TRAINING__DOCK_TO_CHARGER_HPP_
