import socket 
import threading 

HEADER = 64 #Message with 64 bits
PORT = 5050 #Port
SERVER = socket.gethostbyname(socket.gethostname())
ADDRESS = (SERVER,PORT) #needs to have server and port
FORMAT = 'UTF-8'
DISCONNECT_MESSAGE = '!DISCONNECT'

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #(family,type)
server.bind(ADDRESS)

def handle_client(connections,address):
    print(f'[NEW CONNECTION]{address} connected.') 

    connected = True 
    while connected:
        msg_length= connections.recv(HEADER).decode(FORMAT)
        if msg_length:
            msg_length = int(msg_length)
            msg = connections.recv(msg_length).decode(FORMAT)
            if msg == DISCONNECT_MESSAGE:
                connected = False
            print(f'[{address}] {msg}')
    connections.close()

def start():
    server.listen() 
    print(f'[LISTENING] Server is listening on {SERVER}')
    while True: 
        connections,address = server.accept()
        thread = threading.Thread(target=handle_client,args=(connections, address))
        thread.start() 
        print(f'[ACTIVE CONNECTIONS] {threading.activeCount()-1}')


print('[STARTING] server is starting...')
start()