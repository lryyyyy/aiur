#include <fcntl.h>
#include <unistd.h>
#include "Proto.h"
#include "Model.h"
#include "Graph.h"

bool ReadModel(std::string file_name, onnx::ModelProto *model)
{
    ZeroCopyInputStream *raw_input;
    CodedInputStream *coded_input;
    int fd = open(file_name.c_str(), 0);
    if (fd == 0) {
        return false;
    }
    raw_input = new FileInputStream(fd);
    coded_input = new CodedInputStream(raw_input);
    auto ret = model->ParseFromCodedStream(coded_input);
    delete coded_input;
    delete raw_input;
    close(fd);
    return ret;
}

int main(int argc, char *argv[])
{
    onnx::ModelProto proto;
    ReadModel(argv[1], &proto);
    Aiur::Model model(proto);
    model.GetGraph()->TopoSort();
    return 0;
}
