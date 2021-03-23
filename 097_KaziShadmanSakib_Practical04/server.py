# Kazi Shadman Sakib
# Roll : 097

import socket 

s = socket.socket()
host = socket.gethostname()
port = 11122
s.bind((host,port))

s.listen()
while True:
	client, addr = s.accept()
	print("Got connection from client", addr)
	print()

	# get the parity bit stream here below,
	parityBitStream = client.recv(1024).decode()
	fileOpen = open("parityBitStreamInServer.txt","w")
	fileOpen.write(parityBitStream)
	fileOpen.close()
	print("2D Parity Bit Stream Received")
	print("Saved 2D Parity Bit Stream in ""parityBitStreamInServer.txt"" file")
	
	client.send("Thank You for connecting".encode())
	
	client.close()
	exit()