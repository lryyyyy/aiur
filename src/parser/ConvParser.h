#ifndef AIUR_CONV_PARSER_H_
#define AIUR_CONV_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class Conv : public Node {
public:
    Conv(onnx::NodeProto node);
    ~Conv(){};
    void Parser() override;

private:
    std::vector<int> dilations_;
    int group_;
    std::vector<int> kernel_shape_;
    std::vector<int> pads_;
    std::vector<int> strides_;
};
} // namespace Aiur
#endif // AIUR_CONV_PARSER_H_