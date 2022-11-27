#include "Node.h"

namespace Aiur {
Node::Node(onnx::NodeProto node)
{
    name_ = node.name();
    for (int i = 0; i < node.input_size(); i++) {
        inputs_.push_back(node.input(i));
    }
    for (int i = 0; i < node.output_size(); i++) {
        outputs_.push_back(node.output(i));
    }
}

void Node::PrintNode()
{
    std::cout << name_ << std::endl;
}

std::string Node::GetName()
{
    return name_;
}

std::vector<std::string> Node::GetInputs()
{
    return inputs_;
}

std::vector<std::string> Node::GetOutputs()
{
    return outputs_;
}
} // namespace Aiur