#ifndef AIUR_GLOBAL_AVERAGE_POOL_PARSER_H_
#define AIUR_GLOBAL_AVERAGE_POOL_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class GlobalAveragePool : public Node {
public:
    GlobalAveragePool(onnx::NodeProto node);
    ~GlobalAveragePool(){};
    void Parser() override;
};
} // namespace Aiur
#endif // AIUR_GLOBAL_AVERAGE_POOL_PARSER_H_