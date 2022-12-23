#include "GlobalAveragePoolParser.h"

namespace Aiur {
GlobalAveragePool::GlobalAveragePool(onnx::NodeProto node) : Node(node)
{
}
void GlobalAveragePool::Parser()
{
    std::cout << "GlobalAveragePool Attr :" << std::endl << "    No Attr" << std::endl << std::endl;
}

NodePtr GlobalAveragePoolCreator(onnx::NodeProto proto)
{
    auto other = std::make_shared<GlobalAveragePool>(proto);
    auto node = std::static_pointer_cast<Node>(other);
    return node;
}
NodeParserRegistrar g_GlobalAveragePoolParser("GlobalAveragePool", GlobalAveragePoolCreator);
} // namespace Aiur