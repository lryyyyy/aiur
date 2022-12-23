#ifndef AIUR_NODE_H_
#define AIUR_NODE_H_

#include "Proto.h"

namespace Aiur {
class Node {
public:
    Node(onnx::NodeProto node);
    ~Node(){};

    void PrintNode();
    virtual void Parser();
    std::string GetName();
    std::vector<std::string> GetInputs();
    std::vector<std::string> GetOutputs();

private:
    std::string name_;
    std::vector<std::string> inputs_;
    std::vector<std::string> outputs_;
};
using NodePtr = std::shared_ptr<Node>;
} // namespace Aiur
#endif // AIUR_NODE_H_