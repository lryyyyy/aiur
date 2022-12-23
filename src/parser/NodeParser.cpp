#include "NodeParser.h"

namespace Aiur {
NodeParserRegistry *NodeParserRegistry::GetInstance()
{
    static NodeParserRegistry instance;
    return &instance;
}

NodeParserCreator NodeParserRegistry::GetCreator(std::string op_type)
{
    if (creators_.find(op_type) == creators_.end()) {
        return nullptr;
    }
    return creators_[op_type];
}

void NodeParserRegistry::SetCreator(std::string op_type, NodeParserCreator creator)
{
    creators_[op_type] = creator;
}

NodeParserRegistrar::NodeParserRegistrar(std::string op_type, NodeParserCreator creator)
{
    auto instance = NodeParserRegistry::GetInstance();
    instance->SetCreator(op_type, creator);
}

NodeParserCreator NodeParserRegistrar::GetCreator(std::string op_type)
{
    auto instance = NodeParserRegistry::GetInstance();
    auto creator = instance->GetCreator(op_type);
    if (creator != nullptr) {
        return creator;
    }
    return instance->GetCreator("Other");
}
} // namespace Aiur