/*Kazi Shadman Sakib*/
/*Roll : 097*/

#include<bits/stdc++.h>
using namespace std;

void lineCoding2B1QEncoded(){
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
	outputFile.open("2B1QEncoded.txt"); /*Pushing the output in 2B1QEncoded.txt file*/
	/*Taking previVoltage as positive*/
	bool previVoltage = true;
	for(int i=0;i<input.size();i++){
		if(input[i] == ' ' || input[i] == ','){
			continue;
		}
		else if(input[i] == '0' && input[i+1] == '0' && previVoltage == true){
			if(i == input.size()-1){
				outputFile << "+1V";
				previVoltage = true;
				i++;
			}
			else{
				outputFile << "+1V ";
				previVoltage = true;
				i++;
			}
		}
		else if(input[i] == '0' && input[i+1] == '0' && previVoltage == false){
			if(i == input.size()-1){
				outputFile << "-1V";
				previVoltage = false;
				i++;
			}
			else{
				outputFile << "-1V ";
				previVoltage = false;
				i++;
			}
		}
		else if(input[i] == '0' && input[i+1] == '1' && previVoltage == true){
			if(i == input.size()-1){
				outputFile << "+3V";
				previVoltage = true;
				i++;
			}
			else{
				outputFile << "+3V ";
				previVoltage = true;
				i++;
			}
		}
		else if(input[i] == '0' && input[i+1] == '1' && previVoltage == false){
			if( i == input.size()-1){
				outputFile << "-3V";
				previVoltage = false;
				i++;
			}
			else{
				outputFile << "-3V ";
				previVoltage = false;
				i++;
			}
		}
		else if(input[i] == '1' && input[i+1] == '0' && previVoltage == true){
			if(i == input.size()-1){
				outputFile << "-1V";
				previVoltage = false;
				i++;
			}
			else{
				outputFile << "-1V ";
				previVoltage = false;
				i++;
			}
		}
		else if(input[i] == '1' && input[i+1] == '0' && previVoltage == false){
			if(i == input.size()-1){
				outputFile << "+1V";
				previVoltage = true;
				i++;
			}
			else{
				outputFile << "+1V ";
				previVoltage = true;
				i++;
			}
		}
		else if(input[i] == '1' && input[i+1] == '1' && previVoltage == true){
			if(i == input.size()-1){
				outputFile << "-3V";
				previVoltage = false;
				i++;
			}
			else{
				outputFile << "-3V ";
				previVoltage = false;
				i++;
			}
		}
		else if(input[i] == '1' && input[i+1] == '1' && previVoltage == false){
			if(i == input.size()-1){
				outputFile << "+3V";
				previVoltage = true;
				i++;
			}
			else{
				outputFile << "+3V ";
				previVoltage = true;
				i++;
			}
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("2B1QEncoded.txt");	/*Reading output from the file 2B1QEncoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();		/*Getting the data of 2B1QEncoded.txt from buffer in String output*/
		output = s.str();
	}
	cout<< "Output: "<<output<<endl;
	cout<<endl;
	cout<< "Output is saved in file 2B1QEncoded.txt"<<endl;
}

void lineCodingMLT_3Encoded(){
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
	outputFile.open("MLT-3Encoded.txt"); /*Pushing the output in MLT-3Encoded.txt file*/
	/*previVoltageSign is here negative becasue the first 1 bit always goes to positive*/
	bool previVoltageSign = false;
	int previVolt = 0;
	for(int i=0;i<input.size();i++){
		if(input[i] == ' ' || input[i] == ','){
			continue;
		}
		else if(input[i] == '0'){
			if(i == input.size()-1){
				if(previVolt>0){
					outputFile << "+" << previVolt << "V";
				}
				else if(previVolt<0){
					outputFile << previVolt << "V";	
				}
				else{
					outputFile << "0V";
				}
			}
			else{
				if(previVolt>0){
					outputFile << "+" << previVolt << "V ";
				}
				else if(previVolt<0){
					outputFile << previVolt << "V ";	
				}
				else{
					outputFile << "0V ";
				}
			}
		}
		else if(input[i] == '1' && previVolt == 0 && previVoltageSign == false){
			if(i == input.size()-1){
				previVolt = previVolt + 5;
				previVoltageSign = true;
				outputFile << "+" << previVolt << "V";
			}
			else{
				previVolt = previVolt + 5;
				previVoltageSign = true;
				outputFile << "+" << previVolt << "V ";
			}
		}
		else if(input[i] == '1' && previVolt == 0 && previVoltageSign == true){
			if(i == input.size()-1){
				previVolt = previVolt - 5;
				previVoltageSign = false;
				outputFile << previVolt << "V";
			}
			else{
				previVolt = previVolt - 5;
				previVoltageSign = false;
				outputFile << previVolt << "V ";
			}
		}
		else if(input[i] == '1' && previVolt > 0){
			if(i == input.size()-1){
				previVolt = previVolt - 5;
				outputFile << previVolt << "V";
			}
			else{
				previVolt = previVolt - 5;
				outputFile << previVolt << "V ";
			}
		}
		else if(input[i] == '1' && previVolt < 0){
			if(i == input.size()-1){
				previVolt = previVolt + 5;
				outputFile << previVolt << "V";
			}
			else{
				previVolt = previVolt + 5;
				outputFile << previVolt << "V ";
			}
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("MLT-3Encoded.txt"); /*Reading output from the file MLT-3Encoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();
		output = s.str();
	}
	cout << "Output: " << output << endl;
	cout << endl;
	cout<< "Output is saved in file MLT-3Encoded.txt" << endl;
}

#define B8ZS 1
#define HDB3 2
 
string makeOutput1(string stream){
    string output = "";
    int length = stream.length();
    for(int i=0; i< length ; i++){
        if(stream[i] == '1'){
            output += "+5V";
        }
        else if(stream[i] == '2'){
            output += "-5V";
        }
        else if(stream[i] == '0'){
            output += "0V";
        }
        else return "Error";
        if(i != length-1)
        output += " ";
    }
    return output;
}

string B8ZSEncoded(int last){
    if(last == 1)
    return "00012021";
    return "00021012";
}

string HDB3Encoded(int count1){
    if(count1 % 2 == 0)
    return "1001";
    return "0002";
}
 
int check(int flag){
    if (flag == 1) return 2;
    else return 1;
}
 
void scramblingEncoded(int type){
	/*Previous Non-Zero Voltage is Negative*/
	string input;
	ofstream outputFile;
	if(type == 1){
		ifstream inputFile("encodeInput.txt"); /*Reading input from the file encodeInput.txt*/
		if(inputFile){
			ostringstream s;
			s << inputFile.rdbuf(); /*Getting the data of encodeInput.txt from buffer in String input*/
			input = s.str();
		}
		cout<<"Input is taken from ""encodeInput.txt"" file"<<endl;
		cout<<endl;
		cout<< "Input: " << input<<endl;
		cout<<endl;
		outputFile.open("B8ZSEncoded.txt"); /*Pushing the output in B8ZSEncoded.txt file*/
	}
	if(type == 2){
		ifstream inputFile("encodeInput.txt"); /*Reading input from the file encodeInput.txt*/
		if(inputFile){
			ostringstream s;
			s << inputFile.rdbuf(); /*Getting the data of encodeInput.txt from buffer in String input*/
			input = s.str();
		}
		cout<<"Input is taken from ""encodeInput.txt"" file"<<endl;
		cout<<endl;
		cout<< "Input: " << input<<endl;
		cout<<endl;
		outputFile.open("HDB3Encoded.txt"); /*Pushing the output in HDB3Encoded.txt file*/
	}
    int flag = 2;
    int con = 0;
    int count1=0;
    string output;
    int length = input.length();
    for(int i=0; i<length ; i++){
        if(input[i] == '1'){
            count1++;
            while(con--){
                output += "0";
            }
            con =0;
            flag = check(flag);
        }
        else if(input[i] =='0'){
            con++;
            if(type == B8ZS){
                if(con > 7){
                    output += B8ZSEncoded(flag);
                    con = 0;
                }
            }
            else if(type == HDB3){
                if(con > 3){
                    output += HDB3Encoded(count1);
                    flag = check(flag);
                    con = 0;
                    if(count1 %2 == 0) count1 += 2;
                    else count1++;
                }
            }
            continue;
        }
        else if(input[i] != '\n'){
            outputFile << "Incorrect inputstream, could not execute.\n\n";
        }
 
        output += flag + '0';
 
    }
    while(con--){
        output += "0";
    }
    outputFile << makeOutput1(output);
    outputFile.close();
	string output1;
	if(type == 1){
		ifstream outputFileFinalResult("B8ZSEncoded.txt"); /*Reading output from the file B8ZSEncoded.txt*/
		if(outputFileFinalResult){
			ostringstream s;
			s << outputFileFinalResult.rdbuf();
			output1 = s.str();
		}
		cout<< "Output: "<<output1<<endl;
		cout<<endl;
		cout<< "Output is saved in file B8ZSEncoded.txt"<<endl;
	}
	if(type == 2){
		ifstream outputFileFinalResult("HDB3Encoded.txt"); /*Reading output from the file HDB3Encoded.txt*/
		if(outputFileFinalResult){
			ostringstream s;
			s << outputFileFinalResult.rdbuf();
			output1 = s.str();
		}
		cout<< "Output: "<<output1<<endl;
		cout<<endl;
		cout<< "Output is saved in file HDB3Encoded.txt"<<endl;
	}
}

string makeOutput2(string input){
    string output = "";
    int length = input.length();
    for(int i=0; i< length ; i++){
        if(input[i] == '+' && input[i+1] == '5' && input[i+2] == 'V'){
            output += "1";
            i+=2;
        }
        else if(input[i] == '-' && input[i+1] == '5' && input[i+2] == 'V'){
            output += "2";
            i+=2;
        }
        else if(input[i] == '0' && input[i+1] == 'V'){
            output += "0";
            i++;
        }
        else if(input[i] == ' ') continue;
        else return "Error";
    }
    return output;
}

void scramblingDecoded(int type){
    /*Previous Non-Zero Voltage is Negative*/
	string input;
	ofstream outputFile;
	if(type == 1){
		ifstream inputFile("decodeInput.txt"); /*Reading input from the file decodeInput.txt*/
		if(inputFile){
			ostringstream s;
			s << inputFile.rdbuf(); /*Getting the data of decodeInput.txt from buffer in String input*/
			input = s.str();
		}
		cout<<"Input is taken from ""decodeInput.txt"" file"<<endl;
		cout<<endl;
		cout<< "Input: " << input<<endl;
		cout<<endl;
		outputFile.open("B8ZSDecoded.txt"); /*Pushing the output in B8ZSDecoded.txt file*/
	}
	if(type == 2){
		ifstream inputFile("decodeInput.txt"); /*Reading input from the file decodeInput.txt*/
		if(inputFile){
			ostringstream s;
			s << inputFile.rdbuf(); /*Getting the data of decodeInput.txt from buffer in String input*/
			input = s.str();
		}
		cout<<"Input is taken from ""decodeInput.txt"" file"<<endl;
		cout<<endl;
		cout<< "Input: " << input<<endl;
		cout<<endl;
		outputFile.open("HDB3Decoded.txt"); /*Pushing the output in HDB3Decoded.txt file*/
	}
    int i, j = 0 ;
    int flag = 0;
    string output = "";
    input = makeOutput2(input);
    int length = input.length();
    for(i=0; i<length; i++){
        if(input[i] == '1' || input[i] == '2'){
            if( length - i > 2){
                if( type == HDB3  && input[i+1] == '0' && input[i+2] == '0' && input[i+3] == '1'  ){
                    output += "0000";
                    i+=3;
                }
                else if(input[i] == flag + '0') outputFile << "Incorrect inputstream, could not execute.\n\n";
                else if(input[i]=='1'){
                    flag = 1;
                    output += "1";
                }
                else if(input[i]=='2'){
                    output += "1";
                    flag =2;
                }
            }
            else if(input[i] == flag + '0'){
                outputFile << "Incorrect inputstream, could not execute.\n\n";
            }
            else{
                if(input[i]=='1') flag = 1;
                else if(input[i]=='2') flag =2;
                output += "1";
            }
 
        }
        else if(input[i] == '0'){
            if(type == HDB3 && length - i > 3){
                if(input[i+1] == '0' && input[i+2] == '0' && input[i+3] == '2'){
                    output += "0000";
                    i+=3;
                }
                else if(input[i+3] == '0') outputFile << "Incorrect inputstream, could not execute.\n\n";
                else{
                    flag =0;
                    output += "0";
                }
            }
            else if( type == B8ZS && length-i>7){
                if(input[i+1] == '0' && input[i+2] == '0'){
                    if(input[i+3] == '2'  && input[i+4] == '1' && input[i+5] == '0' && input[i+6] == '1' && input[i+7] == '2'  ){
                        output += "00000000";
                        i+=7;
                    }
                    else if(input[i+3] == '1'  && input[i+4] == '2' && input[i+5] == '0' && input[i+6] == '2' && input[i+7] == '1'  ){
                        output += "00000000";
                        i+=7;
                    }
                    else if(input[i+7] == '0') outputFile << "Incorrect inputstream, could not execute.\n\n";
                    else output += "0";
                }
                else{
                    flag =0;
                    output += "0";
                }
            }
            else{
                flag =0;
                output += "0";
            }
 
        }
        else if(input[i] == ' ' || input[i] == ',' || input[i] == '|'){
            continue;
        }
        else{
            outputFile << "Incorrect inputstream, could not execute.\n\n";
        }
 
    }
    outputFile << output;
    outputFile.close();
	string output1;
	if(type == 1){
		ifstream outputFileFinalResult("B8ZSDecoded.txt"); /*Reading output from the file B8ZSDecoded.txt*/
		if(outputFileFinalResult){
			ostringstream s;
			s << outputFileFinalResult.rdbuf();
			output1 = s.str();
		}
		cout<< "Output: "<<output1<<endl;
		cout<<endl;
		cout<< "Output is saved in file B8ZSDecoded.txt"<<endl;
	}
	if(type == 2){
		ifstream outputFileFinalResult("HDB3Decoded.txt"); /*Reading output from the file HDB3Decoded.txt*/
		if(outputFileFinalResult){
			ostringstream s;
			s << outputFileFinalResult.rdbuf();
			output1 = s.str();
		}
		cout<< "Output: "<<output1<<endl;
		cout<<endl;
		cout<< "Output is saved in file HDB3Decoded.txt"<<endl;
	}
}

void lineCoding2B1QDecoded(){
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
	outputFile.open("2B1QDecoded.txt"); /*Pushing the output in 2B1QDecoded.txt file*/
	/*taking previVoltage as positive*/
	bool previVoltage = true;
	for(int i=0;i<input.size();i++){
		if(input[i] == ',' || input[i] == ' ' || input[i] == 'v' || input[i] == 'V'){
			continue;
		}
		else if(input[i] == '+' && input[i+1] == '1' && previVoltage == true){
			if(i == input.size()-1){
				outputFile << "00";
				previVoltage = true;
			}
			else{
				outputFile << "00 ";
				previVoltage = true;
			}
		}
		else if(input[i] == '-' && input[i+1] == '1' && previVoltage == false){
			if(i == input.size()-1){
				outputFile << "00";
				previVoltage = false;
			}
			else{
				outputFile << "00 ";
				previVoltage = false;
			}
		}
		else if(input[i] == '+' && input[i+1] == '3' && previVoltage == true){
			if(i == input.size()-1){
				outputFile << "01";
				previVoltage = true;
			}
			else{
				outputFile << "01 ";
				previVoltage = true;
			}
		}
		else if(input[i] == '-' && input[i+1] == '3' && previVoltage == false){
			if(i == input.size()-1){
				outputFile << "01";
				previVoltage = false;
			}
			else{
				outputFile << "01 ";
				previVoltage = false;
			}
		}
		else if(input[i] == '-' && input[i+1] == '1' && previVoltage == true){
			if(i == input.size()-1){
				outputFile << "10";
				previVoltage = false;
			}
			else{
				outputFile << "10 ";
				previVoltage = false;
			}
		}
		else if(input[i] == '+' && input[i+1] == '1' && previVoltage == false){
			if(i == input.size()-1){
				outputFile << "10";
				previVoltage = true;
			}
			else{
				outputFile << "10 ";
				previVoltage = true;
			}
		}
		else if(input[i] == '-' && input[i+1] == '3' && previVoltage == true){
			if(i == input.size()-1){
				outputFile << "11";
				previVoltage = false;
			}
			else{
				outputFile << "11 ";
				previVoltage = false;
			}
		}
		else if(input[i] == '+' && input[i+1] == '3' && previVoltage == false){
			if(i == input.size()-1){
				outputFile << "11";
				previVoltage = true;
			}
			else{
				outputFile << "11 ";
				previVoltage = true;
			}
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("2B1QDecoded.txt");  /*Reading output from the file 2B1QDecoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();		/*Getting the data of 2B1QDecoded.txt from buffer in String output*/
		output = s.str();
	}
	cout<< "Output: "<<output<<endl;
	cout<<endl;
	cout<< "Output is saved in file 2B1QDecoded.txt"<<endl;
}

void lineCodingMLT_3Decoded(){
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
	outputFile.open("MLT-3Decoded.txt"); /*Pushing the output in MLT-3Decoded.txt*/
	string previVoltage = "0";
	for(int i=0;i<input.size();i++){
		if(input[i] == 'v' || input[i] == 'V' || input[i] == ' ' || input[i] == '5'){
			continue;
		}
		if(input[i] == '0' && previVoltage == "0"){
			if(i == input.size()-1){
				outputFile << "0";
			}
			else{
				outputFile << "0 ";
			}
		}
		else if(input[i] == '+' && previVoltage == "0"){
			if(i == input.size()-1){
				outputFile << "1";
				previVoltage = "+5";
			}
			else{
				outputFile << "1 ";
				previVoltage = "+5";
			}
		}
		else if(input[i] == '+' && previVoltage == "+5"){
			if(i == input.size()-1){
				outputFile << "0";
			}
			else{
				outputFile << "0 ";
			}
		}
		else if(input[i] == '0' && previVoltage == "+5"){
			if(i == input.size()-1){
				outputFile << "1";
				previVoltage = "0";
			}
			else{
				outputFile << "1 ";
				previVoltage = "0";
			}
		}
		else if(input[i] == '-' && previVoltage == "0"){
			if(i == input.size()-1){
				outputFile << "1";
				previVoltage = "-5";
			}
			else{
				outputFile << "1 ";
				previVoltage = "-5";
			}
		}
		else if(input[i] == '-' && previVoltage == "-5"){
			if(i == input.size()-1){
				outputFile << "0";
			}
			else{
				outputFile << "0 ";
			}
		}
		else if(input[i] == '0' && previVoltage == "-5"){
			if(i == input.size()-1){
				outputFile << "1";
				previVoltage = "0";
			}
			else{
				outputFile << "1 ";
				previVoltage = "0";
			}
		}
	}
	outputFile.close();
	string output;
	ifstream outputFileFinalResult("MLT-3Decoded.txt");  /*Reading output from the file MLT-3Decoded.txt*/
	if(outputFileFinalResult){
		ostringstream s;
		s << outputFileFinalResult.rdbuf();		/*Getting the data of MLT-3Decoded.txt from buffer in String output*/
		output = s.str();
	}
	cout<< "Output: "<<output<<endl;
	cout<<endl;
	cout<< "Output is saved in file MLT-3Decoded.txt"<<endl;
}

int main()
{
	while(1){
		cout<< "What would you like to do?" << endl;
		cout<< " 1. Encode" << endl;
		cout<< " 2. Decode" << endl;
		cout<< " 0. Exit" << endl;
		cout<< "Enter your command: ";
		int command1;
		cin>> command1;
		if(command1 == 0){
			break;
		}
		cout<< endl;
		switch(command1){
			case 1:
				cout<< "Which conversion technique would you like to use to Encode the bitstream?" <<endl;
				cout<< " 1. Line Coding" << endl;
				cout<< " 2. Scrambling" << endl;
				cout<< "Enter your command: ";
				int command2;
				cin>> command2;
				cout<< endl;
				switch(command2){
					case 1:
						cout<< "In which scheme would you like to Encode the bitstream?" <<endl;
						cout<< " 1. 2B1Q" << endl;
						cout<< " 2. MLT-3" << endl;
						cout<< "Enter your command: ";
						int command3;
						cin>> command3;
						cout<< endl;
						switch(command3){
							case 1:
								lineCoding2B1QEncoded();
								break;
							case 2:
								lineCodingMLT_3Encoded();
								break;
						}
						break;
					case 2:
						cout<< "In which scheme would you like to Encode the bitstream?" <<endl;
						cout<< " 1. B8ZS" << endl;
						cout<< " 2. HDB3" << endl;
						cout<< "Enter your command: ";
						int command4;
						cin>> command4;
						cout<< endl;
						switch(command4){
							case 1:
								scramblingEncoded(B8ZS);
								break;
							case 2:
								scramblingEncoded(HDB3);
								break;
						}
						break;
				}
				break;
			case 2:
				cout<< "Which conversion technique would you like to use to Decode the voltage levels?" <<endl;
				cout<< " 1. Line Coding" << endl;
				cout<< " 2. Scrambling" << endl;
				cout<< "Enter your command: ";
				int command5;
				cin>> command5;
				cout<< endl;
				switch(command5){
					case 1:
						cout<< "In which scheme would you like to Decode the voltage levels?" <<endl;
						cout<< " 1. 2B1Q" << endl;
						cout<< " 2. MLT-3" << endl;
						cout<< "Enter your command: ";
						int command6;
						cin>> command6;
						cout<< endl;
						switch(command6){
							case 1:
								lineCoding2B1QDecoded();
								break;
							case 2:
								lineCodingMLT_3Decoded();
								break;
						}
						break;
					case 2:
						cout<< "In which scheme would you like to Decode the voltage levels?" <<endl;
						cout<< " 1. B8ZS" << endl;
						cout<< " 2. HDB3" << endl;
						cout<< "Enter your command: ";
						int command7;
						cin>> command7;
						cout<< endl;
						switch(command7){
							case 1:
								scramblingDecoded(B8ZS);
								break;
							case 2:
								scramblingDecoded(HDB3);
								break;
						}
						break;
				}
				break;
		}
		cout<< "******************************************" << endl;
		cout<< endl;
	}
	return 0;
}