import socket 
import threading 

PORT = 5050
#SERVER = '172.17.64.1' #run on local network
SERVER = socket.gethostbyname(socket.gethostname())
ADDRESS = (SERVER,PORT) #needs to have server and port

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #(family,type)
server.bind(ADDRESS)

def handle_client(connections,address):
    print(f'[NEW CONNECTION]{addr} connected.') 

    connected = True 
    while connected:
        msg = conn.recv()
        


def start():
    server.listen() 
    while True: 
        conn,addr = server.accept()
        thread = threading.Thread(target=handle_client,args=(connections, address))
        thread.start() 
        print(f'[ACTIVE CONNECTIONS] {threading.activeCount()-1}')


print('[STARTING] server is starting...')
start()