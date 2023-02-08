import socket

target_host = '0.0.0.0'
target_port = 9998

# Create a socket object
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the client
client.connect((target_host,target_port))

# Send some data
client.send(b"Hello flyboi")

# Receive some data
response = client.recv(9998)

print(response.decode())
client.close
