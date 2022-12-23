#include "OtherParser.h"

namespace Aiur {
Other::Other(onnx::NodeProto node) : Node(node)
{
    op_type_ = node.op_type();
}
void Other::Parser()
{
    std::cout << op_type_ << std::endl << std::endl;
}

NodePtr OtherCreator(onnx::NodeProto proto)
{
    auto other = std::make_shared<Other>(proto);
    auto node = std::static_pointer_cast<Node>(other);
    return node;
}
NodeParserRegistrar g_OtherParser("Other", OtherCreator);
} // namespace Aiur