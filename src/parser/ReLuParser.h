#ifndef AIUR_RELU_PARSER_H_
#define AIUR_RELU_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class ReLu : public Node {
public:
    ReLu(onnx::NodeProto node);
    ~ReLu(){};
    void Parser() override;
};
} // namespace Aiur
#endif // AIUR_RELU_PARSER_H_