#ifndef AIUR_GRAPH_H_
#define AIUR_GRAPH_H_

#include "Proto.h"
#include "Node.h"
#include <set>

namespace Aiur {
class Graph {
public:
    Graph(onnx::GraphProto graph);
    ~Graph(){};

    void PrintGraph();
    void Parser();
    void TopoSort();

private:
    std::vector<NodePtr> node_list_;
    std::set<std::string> input_list_;
};
using GraphPtr = std::shared_ptr<Graph>;
} // namespace Aiur
#endif // AIUR_GRAPH_H_