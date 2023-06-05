#! /usr/bin/python3

import socket

Ports = [21, 22, 25, 3306]

for Port in Ports:

    s = socket.socket()

    print('This is the Banner for the Port')

    print(Port)

    s.connect(("192.168.1.101", Port))

    answer = s.recv(1024)

    print(answer)

    s.close()