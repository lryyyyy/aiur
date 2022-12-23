#ifndef AIUR_GEMM_PARSER_H_
#define AIUR_GEMM_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class Gemm : public Node {
public:
    Gemm(onnx::NodeProto node);
    ~Gemm(){};
    void Parser() override;

private:
    float alpha_;
    float beta_;
    int transA_;
    int transB_;
};
} // namespace Aiur
#endif // AIUR_GEMM_PARSER_H_