#include "GemmParser.h"

namespace Aiur {
Gemm::Gemm(onnx::NodeProto node) : Node(node)
{
    alpha_ = node.attribute(0).f();
    beta_ = node.attribute(1).f();
    transA_= node.attribute(2).i();
    transA_ = node.attribute(3).i();
}
void Gemm::Parser()
{
    std::cout << "Gemm Attr :" << std::endl;
    std::cout << "    Alpha : " << alpha_ << std::endl;
    std::cout << "    Beta : " << beta_ << std::endl;
    std::cout << "    TransA : " << transA_ << std::endl;
    std::cout << "    TransB : " << transB_ << std::endl;
    std::cout << std::endl;
}

NodePtr GemmCreator(onnx::NodeProto proto)
{
    auto other = std::make_shared<Gemm>(proto);
    auto node = std::static_pointer_cast<Node>(other);
    return node;
}
NodeParserRegistrar g_GemmParser("Gemm", GemmCreator);
} // namespace Aiur