import socket 

HEADER = 64 #Message with 64 bits
PORT = 5050 #Port
SERVER = socket.gethostbyname(socket.gethostname())
ADDRESS = (SERVER,PORT)
FORMAT = 'UTF-8'
DISCONNECT_MESSAGE = '!DISCONNECT'

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect(ADDRESS) 

def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message) 
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' '*(HEADER - len(send_length)) #byte representation in string
    client.send(send_length)
    client.send(message)

send('Hello World!')
input()
send('Hello Everyone!')
input()
send('Hello Louis Sungwoo Cho!')

send(DISCONNECT_MESSAGE)