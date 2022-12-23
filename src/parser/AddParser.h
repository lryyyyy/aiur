#ifndef AIUR_ADD_PARSER_H_
#define AIUR_ADD_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class Add : public Node {
public:
    Add(onnx::NodeProto node);
    ~Add(){};
    void Parser() override;
};
} // namespace Aiur
#endif // AIUR_ADD_PARSER_H_