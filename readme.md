## install cpp dependency
```bash
sudo apt install libzmq3-dev

```

## install py dependency
```bash
pip install pyzmq
```

## build cpp
```bash
cd cmq_cpp

mkdir build
cd build
cmake ..
make
```

## run
```bash
# start python server
cd zmq_py
python op_server.py

# start cpp client
cd zmq_cpp/build
./op_zmq_client
```

### result
cpp client
```
Connecting to hello world server…
Sending op request 0 and 3
Receive op result 3
Sending op request 1 and 5
Receive op result 6
Sending op request 2 and 7
Receive op result 9
Sending op request 3 and 9
Receive op result 12
Sending op request 4 and 11
Receive op result 15
Sending op request 5 and 13
Receive op result 18
Sending op request 6 and 15
Receive op result 21
Sending op request 7 and 17
Receive op result 24
Sending op request 8 and 19
Receive op result 27
Sending op request 9 and 21
Receive op result 30
```
### python server
```
------------------------------
Received raw request: b'\x00\x00\x00\x00\x03\x00\x00\x00'
Received ops:0 3
Send res:3
Send raw res:b'\x03\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\x01\x00\x00\x00\x05\x00\x00\x00'
Received ops:1 5
Send res:6
Send raw res:b'\x06\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\x02\x00\x00\x00\x07\x00\x00\x00'
Received ops:2 7
Send res:9
Send raw res:b'\t\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\x03\x00\x00\x00\t\x00\x00\x00'
Received ops:3 9
Send res:12
Send raw res:b'\x0c\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\x04\x00\x00\x00\x0b\x00\x00\x00'
Received ops:4 11
Send res:15
Send raw res:b'\x0f\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\x05\x00\x00\x00\r\x00\x00\x00'
Received ops:5 13
Send res:18
Send raw res:b'\x12\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\x06\x00\x00\x00\x0f\x00\x00\x00'
Received ops:6 15
Send res:21
Send raw res:b'\x15\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\x07\x00\x00\x00\x11\x00\x00\x00'
Received ops:7 17
Send res:24
Send raw res:b'\x18\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\x08\x00\x00\x00\x13\x00\x00\x00'
Received ops:8 19
Send res:27
Send raw res:b'\x1b\x00\x00\x00'
------------------------------
------------------------------
Received raw request: b'\t\x00\x00\x00\x15\x00\x00\x00'
Received ops:9 21
Send res:30
Send raw res:b'\x1e\x00\x00\x00'
------------------------------
```