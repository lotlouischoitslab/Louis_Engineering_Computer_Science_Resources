import socket
from _thread import *
serversocket = socket.socket()

host = '127.0.0.1'
port = 1233
ThreadCount = 0

try:
    serversocket.bind((host,port))
except socket.error as e:
    print(str(e))

print('Wait for connection')
serversocket.listen(5)

def client_thread(connection):
    connection.send(str.encode('Welcome to the server'))
    while True:
        data=connection.recv(2048)
        reply = 'Hello I am server: ' + data.decode('utf-8')
        if not data:
            break 
        connection.sendall(str.encode(reply))
    connection.close()

while True:
    client,address = serversocket.accept()
    print('connected to: '+address[0]+' '+str(address[1]))
    start_new_thread(client_thread, (client,))
    ThreadCount+=1
    print('ThreadCount=',str(ThreadCount))
    