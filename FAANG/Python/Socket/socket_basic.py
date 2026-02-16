import socket

def initSocket():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print ("Socket connection successfull")
        return s    
    except socket.error as err:
        print("Socket connection failed %s" %(err))

def connectToHost(hostName):
    port = 80

    try:
        host_ip = socket.gethostbyname(hostName)
        print(host_ip)
    except socket.gaierror as err:
        print("There was an error resolving the host")

    s = initSocket()
    s.connect((host_ip, port))

    print("The socket has successfully connected to host")


connectToHost("www.google.com")












# 142.250.4.147