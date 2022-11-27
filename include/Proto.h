#ifndef AIUR_PROTO_H_
#define AIUR_PROTO_H_

#include "onnx-ml.proto3.pb.h"
#include <google/protobuf/message.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>

using ::google::protobuf::io::FileInputStream;
using ::google::protobuf::io::CodedInputStream;
using ::google::protobuf::io::ZeroCopyInputStream;

#endif // AIUR_PROTO_H_