#include "Model.h"

namespace Aiur {
std::shared_ptr<Graph> Model::GetGraph()
{
    return graph_;
}

void Model::PrintGraph()
{
    return graph_->PrintGraph();
}
} // namespace Aiur