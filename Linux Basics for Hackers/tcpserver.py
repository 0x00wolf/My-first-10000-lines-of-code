#! /usr/bin/python3

import socket

TCP_IP = "100.115.92.197"
TCP_PORT = 2222
BUFFER_SIZE = 100

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

conn, addr = s.accept()
print('Connection address: ', addr)

while True:

    data=conn.recv(BUFFER_SIZE)
    if not data:
        break
    print("Reived data: ", data)
    conn.send(data) # echo

conn.close()