cmake_minimum_required(VERSION 3.0)
project(zmq_cpp)

include_directories(include)

add_executable(naive_zmq_client naive_client.cpp)
target_link_libraries(naive_zmq_client zmq)

add_executable(op_zmq_client op_client.cpp)
target_link_libraries(op_zmq_client zmq)