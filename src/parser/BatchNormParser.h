#ifndef AIUR_BATCHNORM_PARSER_H_
#define AIUR_BATCHNORM_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class BatchNorm : public Node {
public:
    BatchNorm(onnx::NodeProto node);
    ~BatchNorm(){};
    void Parser() override;

private:
    float epsilon_;
    float momentum_;
    int spatial_;
};
} // namespace Aiur
#endif // AIUR_BATCHNORM_PARSER_H_