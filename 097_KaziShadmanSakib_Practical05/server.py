# Kazi Shadman Sakib
# Roll : 097

import socket 

def retrieveData(decodedBitStream, lengthOfOriginalData):
	outputBitStream = ""
	mainOutputBitStream = ""
	length = len(decodedBitStream)
	for i in range(0,length):
		if(i == 0):
			outputBitStream = outputBitStream + decodedBitStream[i]
		elif(not i%9 == 0):
			outputBitStream = outputBitStream + decodedBitStream[i]
	for i in range(int(lengthOfOriginalData)):
		mainOutputBitStream = mainOutputBitStream + outputBitStream[i]
	return mainOutputBitStream	

def decode(voltage):
	outputStream = ""
	nextVoltage = ""
	length = len(voltage)
	for i in range(0,length,8):
		if(voltage[i] == "+" ):
			outputStream = outputStream + "0"
			nextVoltage = "-"
		elif(voltage[i] == "-"):
			outputStream = outputStream + "1"
			nextVoltage = "+"
		elif(voltage[i] == "+" and nextVoltage == "+" or voltage[i] == "-" and nextVoltage == "-"):
			outputStream = "Incorrect Voltage Stream"
			break
		else:
			outputStream = "Incorrect Voltage Stream"
			break
	return outputStream

s = socket.socket()
host = socket.gethostname()
port = 22122
s.bind((host,port))

s.listen()
while True:
	client, addr = s.accept()
	print("Got connection from client", addr)
	print()

	#get the original data length from client
	lengthOfOriginalData = client.recv(1024).decode()

	#get valid voltage stream here
	validVoltage = client.recv(1024).decode()
	print("Valid Voltage Stream is: ")
	print(validVoltage)
	fileOpen_1 = open("validVoltageStreamInServer.txt","w")
	fileOpen_1.write(validVoltage)
	fileOpen_1.close()
	print("Valid Voltage Stream is saved in ""validVoltageStreamInServer.txt"" file")
	print()

	#decode valid voltage
	print("Decoding valid voltage stream given by client according to Manchester Scheme")
	decodedBitStream = decode(validVoltage)
	print("Manchester Decoded voltage stream is: " + decodedBitStream)
	fileOpen_2 = open("DecodedVoltageStreamInServer.txt","w")
	fileOpen_2.write(decodedBitStream)
	fileOpen_2.close()
	print("Manchester Decoded valid voltage stream is saved in ""DecodedVoltageStreamInServer.txt"" file")
	print()

	#Retrieve Original Data
	print("Retrieving Original Data")
	originalData = retrieveData(decodedBitStream,lengthOfOriginalData)
	print("Retrieved Original Data is: " + originalData)
	fileOpen_3 = open("retrievedOriginalDataInServer.txt","w")
	fileOpen_3.write(originalData)
	fileOpen_3.close()
	print("Retrieved Original Data is saved in ""retrievedOriginalDataInServer.txt"" file")
	print()

	# get the error voltage stream here below,
	invalidVoltage = client.recv(1024).decode()
	print("Invalid Voltage Stream is: ")
	print(invalidVoltage)
	fileOpen_4 = open("invalidVoltageStreamInServer.txt","w")
	fileOpen_4.write(invalidVoltage)
	fileOpen_4.close()
	print("Invalid Voltage Stream is saved in ""invalidVoltageStreamInServer.txt"" file")
	print()

	#decode error voltage
	print("Decoding invalid voltage stream given by client")
	decodedInvalidBitStream = decode(invalidVoltage)
	print("Decoded invalid voltage stream is: " + decodedInvalidBitStream)
	fileOpen_5 = open("DecodedInvalidVoltageStreamInServer.txt","w")
	fileOpen_5.write(decodedInvalidBitStream)
	fileOpen_5.close()
	print("Decoded invalid voltage stream is saved in ""DecodedInvalidVoltageStreamInServer.txt"" file")
	print()

	#Retrieve Error Data
	print("Retrieving Error Data")
	errorData = retrieveData(decodedInvalidBitStream,lengthOfOriginalData)
	print("Retrieved Error Data is: " + errorData)
	fileOpen_6 = open("retrievedErrorDataInServer.txt","w")
	fileOpen_6.write(errorData)
	fileOpen_6.close()
	print("Retrieved Error Data is saved in ""retrievedErrorDataInServer.txt"" file")
	print()

	#compare two files original data and error data
	if(originalData != errorData):
		print("Original Data is- " + originalData)
		print("Invalid Error Data is- " + errorData)
		print()
		print("They are not identical")
		print("Surely there is an Error")
	else:
		print("Incorrect Voltage Stream")
		print("Please check the voltage levels")
		print("Surely there will be two consecutive positive levels or negative levels for a single data")

	client.send("Thank You for connecting".encode())
	
	client.close()
	exit()