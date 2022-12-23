#ifndef AIUR_FLATTEN_PARSER_H_
#define AIUR_FLATTEN_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class Flatten : public Node {
public:
    Flatten(onnx::NodeProto node);
    ~Flatten(){};
    void Parser() override;
};
} // namespace Aiur
#endif // AIUR_FLATTEN_PARSER_H_