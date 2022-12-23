#ifndef AIUR_MAXPOOL_PARSER_H_
#define AIUR_MAXPOOL_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class MaxPool : public Node {
public:
    MaxPool(onnx::NodeProto node);
    ~MaxPool(){};
    void Parser() override;

private:
    std::vector<int> kernel_shape_;
    std::vector<int> pads_;
    std::vector<int> strides_;
};
} // namespace Aiur
#endif // AIUR_MAXPOOL_PARSER_H_