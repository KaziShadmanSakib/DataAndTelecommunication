# Kazi Shadman Sakib
# Roll : 097

import socket

def parityCheck(bitStream):
	n = len(bitStream)
	n = n/8
	rows, cols = (int(n),8)
	arr = []
	k = 0
	count_1 = 0
	for i in range(rows):
		col = []
		count = 0
		for j in range(cols):
			if(bitStream[k] == "1"):
				count_1 = count_1 + 1
			col.append(bitStream[k])
			k = k + 1
			if(j == 7):
				if(count_1 % 2 == 0):
					col.append(0)
				else:
					col.append(1)
		arr.append(col)
	col = []
	for j in range(cols):
		count_2 = 0
		for i in range(rows):
			if(arr[i][j] == "1"):
				count_2 = count_2 + 1
			if(i == n-1):
				if(count_2 % 2 == 0):
					col.append(0)
				else:
					col.append(1)
	arr.append(col)
	count_3 = 0
	for i in range(cols):
		if(arr[int(n)][i] == 1):
			count_3 = count_3 + 1
		if(i == cols-1):
			if(count_3 % 2 == 0):
				arr[int(n)].append(0)
			else:
				arr[int(n)].append(1)
	fileOpen = open("2DParity.txt","w")
	for i in range(int(n)+1):
		for j in range(9):
			fileOpen.write(str(arr[i][j]))
	fileOpen.close()

s = socket.socket()
host = socket.gethostname()
port = 11122

s.connect((host,port))

print("Considering bit stream from ""inputBitStream.txt"" text file")
fileOpen_1 = open("inputBitStream.txt", "r")
bitStream = fileOpen_1.read()
fileOpen_1.close()
print("Input bit stream is - ", bitStream)

#add 2D parity
print("Added 2D parity with the bit stream and saved it in ""2DParity.txt"" file")
parityCheck(bitStream)

#send it to server
fileOpen_2 = open("2DParity.txt","r")
parityBitStream = fileOpen_2.read()
fileOpen_2.close()
print("Sending 2D parity bit stream to server")
print()
s.send(parityBitStream.encode())


print("Server says: " + s.recv(1024).decode())
s.close()