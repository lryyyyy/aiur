#include "FlattenParser.h"

namespace Aiur {
Flatten::Flatten(onnx::NodeProto node) : Node(node)
{
}
void Flatten::Parser()
{
    std::cout << "Flatten Attr :" << std::endl << "    No Attr" << std::endl << std::endl;
}

NodePtr FlattenCreator(onnx::NodeProto proto)
{
    auto other = std::make_shared<Flatten>(proto);
    auto node = std::static_pointer_cast<Node>(other);
    return node;
}
NodeParserRegistrar g_FlattenParser("Flatten", FlattenCreator);
} // namespace Aiur