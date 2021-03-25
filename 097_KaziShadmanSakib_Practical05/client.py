# Kazi Shadman Sakib
# Roll : 097

import socket
import random

def errorInserted(encodedVoltageStream):
	length = len(encodedVoltageStream)
	while(1):
		i = random.randint(0,length)
		if(encodedVoltageStream[i] != " " and encodedVoltageStream[i] != "5" and encodedVoltageStream[i] != "V"):
			if(encodedVoltageStream[i] == "+"):
				print("Randomly changed positive level, " + encodedVoltageStream[i])
				encodedVoltageStream = encodedVoltageStream[:i] + '-' + encodedVoltageStream[i+1:]
				print("To a negative level, " + encodedVoltageStream[i])
				break
			elif(encodedVoltageStream[i] == "-"):
				print("Randomly changed negative level, " + encodedVoltageStream[i])
				encodedVoltageStream = encodedVoltageStream[:i] + '+' + encodedVoltageStream[i+1:]
				print("To a positive level, " + encodedVoltageStream[i])
				break
	return encodedVoltageStream

def encode(parityBitStream):
	outputStream = ""
	length = len(parityBitStream)
	for i in range(length):
		if(parityBitStream[i] == "0"):
			if(i == length-1):
				outputStream = outputStream + "+5V -5V"
			else:
				outputStream = outputStream + "+5V -5V "
		elif(parityBitStream[i] == "1"):
			if(i == length-1):
				outputStream = outputStream + "-5V +5V"
			else:
				outputStream = outputStream + "-5V +5V "
		else:
			outputStream = "Incorrect bit stream"
			break
	return outputStream

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
port = 22122

s.connect((host,port))

print("Considering bit stream from ""inputBitStream.txt"" file")
fileOpen_1 = open("inputBitStream.txt", "r")
bitStream = fileOpen_1.read()
fileOpen_1.close()
print("Input bit stream is - ", bitStream)
print()

#sending server the length of original data
lengthOfOriginalData = str(len(bitStream))
s.send(lengthOfOriginalData.encode())

#add 2D parity
print("Added 2D parity with the bit stream and saved it in ""2DParity.txt"" file")
parityCheck(bitStream)
fileOpen_2 = open("2DParity.txt","r")
parityBitStream = fileOpen_2.read()
fileOpen_2.close()
print("Bit stream after adding 2D parity is: " + parityBitStream)
print()

#encode
print("Encoding the 2D parity bit stream given in ""2DParity.txt"" file according to Manchester Scheme")
encodedVoltageStream = encode(parityBitStream)
print("Manchester Encoded Bit Stream is:")
print(encodedVoltageStream)
fileOpen_3 = open("encodedBitStream.txt","w")
fileOpen_3.write(encodedVoltageStream)
fileOpen_3.close()
print("Manchester Encoded Bit Stream is saved in ""encodedBitStream.txt"" file")
print()

#send it to server
print("Sending the valid Manchester Encoded Bit Stream to Server")
print()
s.send(encodedVoltageStream.encode())

#errorInserted
print("Inserting an error voltage level to the valid encoded bit stream")
errorVoltageStream = errorInserted(encodedVoltageStream)
print("Error Encoded Bit Stream is: ")
print(errorVoltageStream)
fileOpen_4 = open("errorVoltageStream.txt","w")
fileOpen_4.write(errorVoltageStream)
fileOpen_4.close()
print("Error Encoded Bit Stream is saved in ""errorVoltageStream.txt"" file")
print()

#send it to server
print("Sending the Invalid Encoded Bit Stream to Server")
print()
s.send(errorVoltageStream.encode())

print("Server says: " + s.recv(1024).decode())
s.close()