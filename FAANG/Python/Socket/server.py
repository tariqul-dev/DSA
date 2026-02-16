import socket

s = socket.socket()
print("Socket successfully created")


port = 12345

s.bind(('', port))
print(f"Socket is binded to {port}")

s.listen(5)
print("Socket is listening")

while True:
    c, addr = s.accept()
    print("Got connection from", addr)

    c.send("You are hacked".encode())
    print()

    c.close()
    # s.close()

    break


# Instruction for  Client
# start the server
# $ python server.py

# # keep the above terminal open 
# # now open another terminal and type: 
 
# $ telnet localhost 12345