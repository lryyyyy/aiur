[ ! -d "./build" ] && mkdir build
cd build && cmake .. && make -j4 && cd ..

./output/aiur_main model/resnet18-v1-7.onnx