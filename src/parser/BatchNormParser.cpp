#include "BatchNormParser.h"

namespace Aiur {
BatchNorm::BatchNorm(onnx::NodeProto node) : Node(node)
{
    epsilon_ = node.attribute(0).f();
    momentum_ = node.attribute(1).f();
    spatial_ = node.attribute(2).i();

}
void BatchNorm::Parser()
{
    std::cout << "BatchNorm Attr :" << std::endl;
    std::cout << "    Epsilon : " << epsilon_ << std::endl;
    std::cout << "    Momentum : " << momentum_ << std::endl;
    std::cout << "    Spatial : " << spatial_ << std::endl;
    std::cout << std::endl;
}

NodePtr BatchNormCreator(onnx::NodeProto proto)
{
    auto conv = std::make_shared<BatchNorm>(proto);
    auto node = std::static_pointer_cast<Node>(conv);
    return node;
}
NodeParserRegistrar g_BatchNormParser("BatchNormalization", BatchNormCreator);
} // namespace Aiur