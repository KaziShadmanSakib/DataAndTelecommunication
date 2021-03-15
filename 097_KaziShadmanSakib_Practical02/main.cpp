/*Kazi Shadman Sakib*/
/*Roll - 097*/

#include<bits/stdc++.h>
using namespace std;

void biPhaseManchesterEncoded(){
	ifstream inputFile("encodeInput.txt"); /*Reading input from the file encodeInput.txt*/
	string input;
	if(inputFile){
		ostringstream s;
		s<< inputFile.rdbuf(); /*Getting the data of encodeInput.txt from buffer in String input*/
		input = s.str();
	}
	cout<<"Input is taken from ""encodeInput.txt"" file"<<endl;
	cout<<endl;
	cout<< "Input: " << input<<endl;
	cout<<endl;
	ofstream outputFile;
	outputFile.open("ManchesterEncoded.txt"); /*Pushing the output in ManchesterEncoded.txt file*/
	/*Taking 0 as positive (+5 -5) and 1 (-5 +5) as negative*/
	for(int i=0;i<input.size();i++){
		if(input[i] == '0'){
			if(i == input.size()-1){
				outputFile << "(+5V, -5V)";
			}
			else{
				outputFile << "(+5V, -5V) ";
			}
		}
		else{
			if(i == input.size()-1){
				outputFile << "(-5V, +5V)";
			}
			else{
				outputFile << "(-5V, +5V) ";
			}
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("ManchesterEncoded.txt"); /*Reading output from the file ManchesterEncoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();
		output = s.str();
	}
	cout << "Output: " << output << endl;
	cout << endl;
	cout<< "Output is saved in file ManchesterEncoded.txt" << endl;
}

void biPhaseDiffManchesterEncoded(){
	ifstream inputFile("encodeInput.txt"); /*Reading input from the file encodeInput.txt*/
	string input;
	if(inputFile){
		ostringstream s;
		s << inputFile.rdbuf(); /*Getting the data of encodeInput.txt from buffer in String input*/
		input = s.str();
		cout<<"Input is taken from ""encodeInput.txt"" file"<<endl;
		cout<<endl;
		cout<< "Input: " << input<<endl;
		cout<<endl;
		ofstream outputFile;
		outputFile.open("DiffManchesterEncoded.txt"); /*Pushing the output in DiffManchesterEncoded.txt file*/
		string prevVoltage = "+5V"; /*Guessing that previous voltage is positive (+5V) */
		for(int i=0;i<input.size();i++){
			if(input[i] == '0' && prevVoltage == "+5V"){
				if(i == input.size()-1){
					outputFile << "(-5V, +5V)";
					prevVoltage = "+5V";
				}
				else{
					outputFile << "(-5V, +5V) ";
					prevVoltage = "+5V";
				}
			}
			else if(input[i] == '0' && prevVoltage == "-5V"){
				if(i == input.size()-1){
					outputFile << "(+5V, -5V)";
					prevVoltage = "-5V";
				}
				else{
					outputFile << "(+5V, -5V) ";
					prevVoltage = "-5V";
				}
			}
			else if(input[i] == '1' && prevVoltage == "+5V"){
				if(i == input.size()-1){
					outputFile << "(+5V, -5V)";
					prevVoltage = "-5V";
				}
				else{
					outputFile << "(+5V, -5V) ";
					prevVoltage = "-5V";
				}
			}
			else if(input[i] == '1' && prevVoltage == "-5V"){
				if(i == input.size()-1){
					outputFile << "(-5V, +5V)";
					prevVoltage = "+5V";
				}
				else{
					outputFile << "(-5V, +5V) ";
					prevVoltage = "+5V";
				}
			}
		}
		outputFile.close();
		string output;
		ifstream outputFileFinalResult("DiffManchesterEncoded.txt");   /*Reading output from the file DiffManchesterEncoded.txt*/
		if(outputFileFinalResult){
			ostringstream s;
			s << outputFileFinalResult.rdbuf();		/*Getting the data of DiffManchesterEncoded.txt from buffer in String output*/
			output = s.str();
		}
		cout<< "Output: "<<output<<endl;
		cout<<endl;
		cout<< "Output is saved in file DiffManchesterEncoded.txt"<<endl;
	}
}

void AMIEncoded(){
	ifstream inputFile("encodeInput.txt"); /*Reading input from the file encodeInput.txt*/
	string input;
	if(inputFile){
		ostringstream s;
		s << inputFile.rdbuf(); /*Getting the data of encodeInput.txt from buffer in String input*/
		input = s.str();
	}
	cout<<"Input is taken from ""encodeInput.txt"" file"<<endl;
	cout<<endl;
	cout<< "Input: " << input<<endl;
	cout<<endl;
	ofstream outputFile;
	outputFile.open("AMIEncoded.txt"); /*Pushing the output in AMIEncoded.txt file*/
	/*If 0 bit is found then it is 0V*/
	/*If 1 bit is found then voltage will be inverse of the previous voltage of bit 1*/
	string previVoltage = "-5V";
	for(int i=0;i<input.size();i++){
		if(input[i] == '0'){
			if(i == input.size()-1){
				outputFile << "0V";
			}
			else{
				outputFile << "0V ";
			}
		}
		else if(input[i] == '1' && previVoltage == "-5V"){
			if( i == input.size()-1){
				outputFile << "+5V";
				previVoltage = "+5V";
			}
			else{
				outputFile << "+5V ";
				previVoltage = "+5V";
			}
		}
		else if(input[i] == '1' && previVoltage == "+5V"){
			if(i == input.size()-1){
				outputFile << "-5V";
				previVoltage = "-5V";
			}
			else{
				outputFile << "-5V ";
				previVoltage = "-5V";
			}
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("AMIEncoded.txt"); /*Reading output from the file AMIEncoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();
		output = s.str();
	}
	cout<< "Output: "<<output<<endl;
	cout<<endl;
	cout<< "Output is saved in file AMIEncoded.txt"<<endl;
}

void biPhaseManchesterDecoded(){
	ifstream inputFile("decodeInput.txt"); /*Reading input from the file decodeInput.txt*/
	string input;
	if(inputFile){
		ostringstream s;
		s << inputFile.rdbuf(); /*Getting the data of decodeInput.txt from buffer in String input*/
		input = s.str();
	}
	cout<<"Input is taken from ""decodeInput.txt"" file"<<endl;
	cout<<endl;
	cout<< "Input: " << input<<endl;
	cout<<endl;
	ofstream outputFile;
	outputFile.open("ManchesterDecoded.txt");	/*Pushing the output in ManchesterDecoded.txt file*/
	/*if first voltage is -ve and second voltage is +ve then the bit is 1*/
	/*if first voltage is +ve and second voltage is -ve then the bit is 0*/
	string sign = " ";
	for(int i=0;i<input.size();i++){
		if(input[i] == ',' || input[i] == '(' || input[i] == ' ' || input[i] == '5' || input[i] == 'V' || input[i] == 'v' ){
			continue;
		}
		else if(input[i] == '+'){
			sign = "+";
		}
		else if(input[i] == '-'){
			sign = "-";
		}
		else if(input[i] == ')' && sign == "+"){
			outputFile << '1';
		}
		else if(input[i] == ')' && sign == "-"){
			outputFile << '0';
		}
		else{
			outputFile << "Error!! Can not decode the input for this particular scheme"<<endl; 	/*Giving Error message when there is any other voltage rather than +5V or -5V*/
			outputFile << "Please use only +5V or -5V to decode for this particular scheme"<<endl;
			break;
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("ManchesterDecoded.txt");  /*Reading output from the file ManchesterDecoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();		/*Getting the data of ManchesterDecoded.txt from buffer in String output*/
		output = s.str();
	}
	cout<< "Output: "<<output<<endl;
	cout<<endl;
	cout<< "Output is saved in file ManchesterDecoded.txt"<<endl;
}

void biPhaseDiffManchesterDecoded(){
	ifstream inputFile("decodeInput.txt"); /*Reading input from the file decodeInput.txt*/
	string input;
	if(inputFile){
		ostringstream s;
		s << inputFile.rdbuf(); /*Getting the data of decodeInput.txt from buffer in String input*/
		input = s.str();
	}
	cout<<"Input is taken from ""decodeInput.txt"" file"<<endl;
	cout<<endl;
	cout<< "Input: " << input<<endl;
	cout<<endl;
	ofstream outputFile;
	outputFile.open("DiffManchesterDecoded.txt");	/*Pushing the output in DiffManchesterDecoded.txt file*/
	/*if first voltage is -ve and second voltage is +ve then the bit is 1*/
	/*if first voltage is +ve and second voltage is -ve then the bit is 0*/
	string sign = " ";
	string previousSign = "+"; //taking previous voltage as +ve
	for(int i=0;i<input.size();i++){
		if(input[i] == ',' || input[i] == '(' || input[i] == ' ' || input[i] == '5' || input[i] == 'V' || input[i] == 'v' ){
			continue;
		}
		else if(input[i] == '+'){
			sign = "+";
		}
		else if(input[i] == '-'){
			sign = "-";
		}
		else if(input[i] == ')' && sign == "+" && previousSign == "+"){
			outputFile << '0';
			previousSign = "+";
		}
		else if(input[i] == ')' && sign == "-" && previousSign == "-"){
			outputFile << '0';
			previousSign = "-";
		}
		else if(input[i] == ')' && sign == "+" && previousSign == "-"){
			outputFile << '1';
			previousSign = "+";
		}
		else if(input[i] == ')' && sign == "-" && previousSign == "+"){
			outputFile << '1';
			previousSign = "-";
		}
		else{
			outputFile << "Error!! Can not decode the input for this particular scheme"<<endl; 	/*Giving Error message when there is any other voltage rather than +5V or -5V*/
			outputFile << "Please use only +5V or -5V to decode for this particular scheme"<<endl;
			break;
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("DiffManchesterDecoded.txt");  /*Reading output from the file DiffManchesterDecoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();		/*Getting the data of DiffManchesterDecoded.txt from buffer in String output*/
		output = s.str();
	}
	cout<< "Output: "<<output<<endl;
	cout<<endl;
	cout<< "Output is saved in file DiffManchesterDecoded.txt"<<endl;
}

void AMIDecoded(){
	ifstream inputFile("decodeInput.txt"); /*Reading input from the file decodeInput.txt*/
	string input;
	if(inputFile){
		ostringstream s;
		s << inputFile.rdbuf();		/*Getting the data of decodeInput.txt from buffer in String input*/
		input = s.str();
	}
	cout<<"Input is taken from ""decodeInput.txt"" file"<<endl;
	cout<<endl;
	cout<< "Input: " << input<<endl;
	cout<<endl;
	ofstream outputFile;
	outputFile.open("AMIDecoded.txt");
	/*If 0V is found then it is 0 bit*/
	/*If +5V is found and if its previous voltage is -5V then it is 1 bit and vise versa*/
	/*If +5V is found and if its previous voltage is +5V then it will give error and vise versa for -5V */
	string previSign = "-";
	for(int i=0;i<input.size();i++){
		if(input[i] == ' ' || input[i] == 'V' || input[i] =='v' || input[i] == '5'){
			continue;
		}
		else if(input[i] == '0'){
			outputFile << '0';
		}
		else if(input[i] == '+' && previSign == "-"){
			outputFile << '1';
			previSign = "+";
		}
		else if(input[i] == '-' && previSign == "+"){
			outputFile << '1';
			previSign = "-";
		}
		else{
			outputFile<< "Error!! Can not decode the input for this particular scheme"<<endl;		/*Giving Error message when there is any other voltage rather than +5V or -5V*/
			outputFile<< "Please use only +5V or -5V to decode for this particular scheme"<<endl;
			break;
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("AMIDecoded.txt");  /*Reading output from the file AMIDecoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();		/*Getting the data of AMIDecoded.txt from buffer in String output*/
		output = s.str();
	}
	cout<< "Output: "<<output<<endl;
	cout<<endl;
	cout<< "Output is saved in file AMIDecoded.txt"<<endl;
}

int main()
{	
	while(1){
		cout<< "What would you like to do?" << endl;
		cout<< "01. Encode" << endl;
		cout<< "02. Decode" << endl;
		cout<< "00. Exit" << endl;
		cout<< "Enter your command: ";
		int command1;
		cin>> command1;
		cout<< endl;
		if(command1 == 0){
			break;
		}
		switch (command1){
			case 1:
				cout<< "In which scheme would you like to Encode the bitstream?" <<endl;
				cout<< "01. Biphase" << endl;
				cout<< "02. AMI" << endl;
				cout<< "Enter your command: ";
				int command2;
				cin>> command2;
				cout<< endl;
				switch(command2){
					case 1:
						cout<< "In which type of Biphase?" << endl;
						cout<< "01. Manchester" << endl;
						cout<< "02. Differential Manchester" << endl;
						cout<< "Enter your command: ";
						int command3;
						cin>> command3;
						cout<< endl;
						switch(command3){
							case 1:
								biPhaseManchesterEncoded();
								break;
							case 2:
								biPhaseDiffManchesterEncoded();
								break;
						}
						break;
					case 2:
						AMIEncoded();
						break;
				}
				break;	
			case 2:
				cout<< "In which scheme would you like to Decode the voltage levels?" <<endl;
				cout<< "01. Biphase" << endl;
				cout<< "02. AMI" << endl;
				cout<< "Enter your command: ";
				int command4;
				cin>> command4;
				cout<< endl;
				switch(command4){
					case 1:
						cout<< "In which type of Biphase?" << endl;
						cout<< "01. Manchester" << endl;
						cout<< "02. Differential Manchester" << endl;
						cout<< "Enter your command: ";
						int command5;
						cin>> command5;
						cout<< endl;
						switch(command5){
							case 1:
								biPhaseManchesterDecoded();
								break;
							case 2:
								biPhaseDiffManchesterDecoded();
								break;
						}
						break;
					case 2:
						AMIDecoded();
						break;
				}
				break;
			}
			cout<< "***************************" << endl;
		}
	return 0;
}