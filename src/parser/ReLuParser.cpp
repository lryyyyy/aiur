#include "ReLuParser.h"

namespace Aiur {
ReLu::ReLu(onnx::NodeProto node) : Node(node)
{
}
void ReLu::Parser()
{
    std::cout << "ReLu Attr :" << std::endl << "    No Attr" << std::endl << std::endl;
}

NodePtr ReLuCreator(onnx::NodeProto proto)
{
    auto other = std::make_shared<ReLu>(proto);
    auto node = std::static_pointer_cast<Node>(other);
    return node;
}
NodeParserRegistrar g_ReLuParser("Relu", ReLuCreator);
} // namespace Aiur