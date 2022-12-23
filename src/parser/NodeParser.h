#ifndef AIUR_NODE_PARSER_H_
#define AIUR_NODE_PARSER_H_

#include <functional>
#include "Node.h"

namespace Aiur {
using NodeParserCreator = std::function<NodePtr(onnx::NodeProto)>;
class NodeParserRegistry {
public:
    static NodeParserRegistry *GetInstance();
    NodeParserCreator GetCreator(std::string op_type);
    void SetCreator(std::string op_type, NodeParserCreator creator);

private:
    std::map<std::string, NodeParserCreator> creators_;
};

class NodeParserRegistrar {
public:
    NodeParserRegistrar(std::string op_type, NodeParserCreator creator);
    ~NodeParserRegistrar(){};
    static NodeParserCreator GetCreator(std::string op_type);
};
} // namespace Aiur
#endif // AIUR_NODE_PARSER_H_