import zmq
import struct

context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://0.0.0.0:5556")

while True:
    #  Wait for next request from client
    message = socket.recv()
    print("-" * 30)
    print("Received raw request: %s" % message)
    ops = struct.unpack("ii", message)
    print("Received ops:{} {}".format(ops[0], ops[1]))

    #  Do some 'work'
    res = ops[0] + ops[1]
    print("Send res:{}".format(res))
    b_res = struct.pack("i", res)
    print("Send raw res:{}".format(b_res))
    print("-" * 30)
    #  Send reply back to client
    socket.send(b_res)