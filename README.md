# Aiur
## 工程目录结构
    .
    ├── 3rdparty
    │   ├── googletest
    │   └── protobuf-3.11.0
    ├── CMakeLists.txt
    ├── include
    ├── main.cpp
    ├── model
    │   └── resnet18-v1-7.onnx
    ├── proto
    │   ├── onnx-ml.proto3
    │   ├── onnx-ml.proto3.pb.cc
    │   └── onnx-ml.proto3.pb.h
    ├── README.md
    ├── run.sh
    └── src

## ProtoBuffer 安装
    https://github.com/protocolbuffers/protobuf/releases/download/v3.11.0/protobuf-cpp-3.11.0.tar.gz
### 将protobuf-all-3.11.0.tar.gz复制到3rdparty目录下并解压
    ./autogen.sh
    ./configure CXXFLAGS=-fPIC --enable-shared=no LDFLAGS="-static"
    make
    make check
    > 注意protobuf在cmake里的路径
    > protoc文件会编译好放在3rdparty/protobuf-3.11.0/src下
    > 可以使用make install将protoc和库文件放在/usr/bin和/usr/include下

## Proto .h .cc文件生成
    cd proto
    protoc --cpp_out=. onnx-ml.proto3
    > 如果没有make install,就使用上一步编译出的protoc文件的路径

## Google gtest 安装
    git clone https://github.com/google/googletest
    cd googletest
    mkdir build; cd build; cmake ..; make
    > 注意googletest在cmake里的路径

## ONNX模型下载
    https://github.com/onnx/models/blob/main/vision/classification/resnet/model/resnet18-v1-7.onnx

## 编译运行
    ./run.sh