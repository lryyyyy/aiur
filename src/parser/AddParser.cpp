#include "AddParser.h"

namespace Aiur {
Add::Add(onnx::NodeProto node) : Node(node)
{
}
void Add::Parser()
{
    std::cout << "Add Attr :" << std::endl << "    No Attr" << std::endl << std::endl;
}

NodePtr AddCreator(onnx::NodeProto proto)
{
    auto other = std::make_shared<Add>(proto);
    auto node = std::static_pointer_cast<Node>(other);
    return node;
}
NodeParserRegistrar g_AddParser("Add", AddCreator);
} // namespace Aiur