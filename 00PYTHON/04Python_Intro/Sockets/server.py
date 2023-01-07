import socket 
import threading 

HEADER = 64 #Message with 64 bits
PORT = 5050
#SERVER = '172.17.64.1' #run on local network
SERVER = socket.gethostbyname(socket.gethostname())
ADDRESS = (SERVER,PORT) #needs to have server and port
FORMAT = 'UTF-8'

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #(family,type)
server.bind(ADDRESS)

def handle_client(connections,address):
    print(f'[NEW CONNECTION]{addr} connected.') 

    connected = True 
    while connected:
        msg_length= conn.recv(HEADER).decode(FORMAT)
        msg_length = int(msg_length)
        msg = conn.recv(msg_length).decode(FORMAT)
        print(f'[{addr}] {msg}')


def start():
    server.listen() 
    while True: 
        conn,addr = server.accept()
        thread = threading.Thread(target=handle_client,args=(connections, address))
        thread.start() 
        print(f'[ACTIVE CONNECTIONS] {threading.activeCount()-1}')


print('[STARTING] server is starting...')
start()