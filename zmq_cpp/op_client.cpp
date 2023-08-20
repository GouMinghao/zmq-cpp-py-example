#include <zmq.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include "ops.h"


int main(void)
{
    printf("Connecting to hello world server…\n");
    void *context = zmq_ctx_new();
    void *requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5556");

    int request_nbr;
    OpOutput_t *op_output_p = new OpOutput_t;
    OpInput_t *op_input_p = new OpInput_t;
    for (request_nbr = 0; request_nbr != 10; request_nbr++)
    {
        op_input_p -> op1 = request_nbr;
        op_input_p -> op2 = request_nbr * 2 + 3;

        std::cout << "Sending op request " << op_input_p -> op1 << " and " << op_input_p -> op2;
        std::cout << std::endl;
        zmq_send(requester, reinterpret_cast<void*>(op_input_p), sizeof(OpInput_t), 0);
        zmq_recv(requester, reinterpret_cast<void*>(op_output_p), sizeof(OpOutput_t), 0);
        std::cout << "Receive op result " << op_output_p -> res << std::endl;
    }
    delete op_output_p;
    delete op_input_p;
    zmq_close(requester);
    zmq_ctx_destroy(context);

    return 0;
}