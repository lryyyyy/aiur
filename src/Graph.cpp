#include "Graph.h"
#include <algorithm>

namespace Aiur {
Graph::Graph(onnx::GraphProto graph)
{
    for (int i = 0; i < graph.node_size(); i++) {
        NodePtr node = std::make_shared<Node>(graph.node(i));
        node_list_.push_back(node);
    }
    for (int i = 0; i < graph.initializer_size(); i++) {
        input_list_.emplace(graph.initializer(i).name());
    }
    for (int i = 0; i < graph.input_size(); i++) {
        input_list_.emplace(graph.input(i).name());
    }
}

void Graph::PrintGraph()
{
    for (auto it : node_list_) {
        it->PrintNode();
    }
}

bool IsReady(NodePtr node, std::set<std::string> ready_list)
{
    for (auto it : node->GetInputs()) {
        if (ready_list.find(it) == ready_list.end()) {
            return false;
        }
    }
    return true;
}

void Graph::TopoSort()
{
    std::set<std::string> ready_list;
    ready_list = input_list_;
    std::vector<NodePtr> temp = {};
    srand(time(0));
    std::random_shuffle(node_list_.begin(), node_list_.end());
    while (!node_list_.empty()) {
        for (auto it = node_list_.begin(); it != node_list_.end(); it++) {
            if (IsReady(*it, ready_list)) {
                temp.push_back(*it);
                ready_list.emplace((*it)->GetName());
                node_list_.erase(it);
                it--;
            }
        }
    }
    node_list_ = temp;
    for (auto it : node_list_) {
        std::cout << it->GetName() << std::endl;
    }
}
} // namespace Aiur