import socket 

HEADER = 64 #Message with 64 bits
PORT = 5050 #Port
SERVER = socket.gethostbyname(socket.gethostname())
ADDRESS = (SERVER,PORT)

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect(ADDRESS) 

def send(msg):
    message = msg.encode(FORMAT)
    