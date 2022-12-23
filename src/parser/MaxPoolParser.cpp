#include "MaxPoolParser.h"

namespace Aiur {
MaxPool::MaxPool(onnx::NodeProto node) : Node(node)
{
    kernel_shape_.clear();
    auto kernel_shape = node.attribute(0);
    for (int i = 0; i < kernel_shape.ints_size(); i++) {
        kernel_shape_.push_back(kernel_shape.ints(i));
    }

    pads_.clear();
    auto pads = node.attribute(1);
    for (int i = 0; i < pads.ints_size(); i++) {
        pads_.push_back(pads.ints(i));
    }

    strides_.clear();
    auto strides = node.attribute(2);
    for (int i = 0; i < strides.ints_size(); i++) {
        strides_.push_back(strides.ints(i));
    }
}
void MaxPool::Parser()
{
    std::cout << "MaxPool Attr :" << std::endl;
    std::cout << "    Kernel Shape : ";
    for (auto it : kernel_shape_) {
        std::cout << it << "  ";
    }
    std::cout << std::endl;

    std::cout << "    Pads : ";
    for (auto it : pads_) {
        std::cout << it << "  ";
    }
    std::cout << std::endl;

    std::cout << "    Strides : ";
    for (auto it : strides_) {
        std::cout << it << "  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

NodePtr MaxPoolCreator(onnx::NodeProto proto)
{
    auto other = std::make_shared<MaxPool>(proto);
    auto node = std::static_pointer_cast<Node>(other);
    return node;
}
NodeParserRegistrar g_MaxPoolParser("MaxPool", MaxPoolCreator);
} // namespace Aiur