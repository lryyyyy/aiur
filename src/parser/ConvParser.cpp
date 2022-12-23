#include "ConvParser.h"

namespace Aiur {
Conv::Conv(onnx::NodeProto node) : Node(node)
{
    dilations_.clear();
    auto dilations = node.attribute(0);
    for (int i = 0; i < dilations.ints_size(); i++) {
        dilations_.push_back(dilations.ints(i));
    }

    group_ = node.attribute(1).i();

    kernel_shape_.clear();
    auto kernel_shape = node.attribute(2);
    for (int i = 0; i < kernel_shape.ints_size(); i++) {
        kernel_shape_.push_back(kernel_shape.ints(i));
    }

    pads_.clear();
    auto pads = node.attribute(3);
    for (int i = 0; i < pads.ints_size(); i++) {
        pads_.push_back(pads.ints(i));
    }

    strides_.clear();
    auto strides = node.attribute(4);
    for (int i = 0; i < strides.ints_size(); i++) {
        strides_.push_back(strides.ints(i));
    }
}
void Conv::Parser()
{
    std::cout << "Conv Attr :" << std::endl;
    std::cout << "    Dilations : ";
    for (auto it : dilations_) {
        std::cout << it << "  ";
    }
    std::cout << std::endl;

    std::cout << "    Group : " << group_ << std::endl;

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

NodePtr ConvCreator(onnx::NodeProto proto)
{
    auto conv = std::make_shared<Conv>(proto);
    auto node = std::static_pointer_cast<Node>(conv);
    return node;
}
NodeParserRegistrar g_ConvParser("Conv", ConvCreator);
} // namespace Aiur