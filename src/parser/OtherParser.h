#ifndef AIUR_OTHER_PARSER_H_
#define AIUR_OTHER_PARSER_H_

#include "Node.h"
#include "NodeParser.h"

namespace Aiur {
class Other : public Node {
public:
    Other(onnx::NodeProto node);
    ~Other(){};
    void Parser() override;

private:
    std::string op_type_;
};
} // namespace Aiur
#endif // AIUR_OTHER_PARSER_H_