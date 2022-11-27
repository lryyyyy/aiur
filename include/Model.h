#ifndef AIUR_MODEL_H_
#define AIUR_MODEL_H_

#include "Proto.h"
#include "Graph.h"

namespace Aiur {
class Model {
public:
    Model(onnx::ModelProto model)
    {
        graph_ = std::make_shared<Graph>(model.graph());
    }
    ~Model(){};

    GraphPtr GetGraph();

    void PrintGraph();

private:
    GraphPtr graph_;
};
} // namespace Aiur
#endif // AIUR_MODEL_H_