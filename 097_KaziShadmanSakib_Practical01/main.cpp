/*Kazi Shadman Sakib*/
/*Roll- 097*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<< "What would you like to do?" << endl;
	cout<< "01. Encode" <<endl;
	cout<< "02. Decode" <<endl;
	cout<< "Enter your command: ";
	int command1;
	cin>>command1;
	cout<<endl;
	if(command1 == 1){
		cout<< "In which scheme would you like to Encode the bitstream?" <<endl;
		cout<< "01. NRZ-L" <<endl;
		cout<< "02. NRZ-I" <<endl;
		cout<< "Enter your command: ";
		int command2;
		cin>>command2;
		cout<<endl;
		if(command2 == 1){
			ifstream inputFile("encode.txt"); /*Reading input from the file encode.txt*/
			string input;
			if(inputFile){
				ostringstream s;
				s<< inputFile.rdbuf(); /*Getting the data of encode.txt from buffer in String input*/
				input = s.str();
			}
			cout<<"Input is taken from ""encode.txt"" file"<<endl;
			cout<<endl;
			cout<< "Input: " << input<<endl;
			cout<<endl;
			ofstream outputFile;
			outputFile.open("NRZ-L_Encoded.txt"); /*Pushing the output in NRZ-L_Encoded.txt file*/
			for(int i=0;i<input.size();i++){      /*Taking 0 as positive and 1 as negative*/
				if(input[i] == '0'){
					if(i==input.size()-1){
  						outputFile << "+5V";
					}
					else{
  						outputFile << "+5V ";
					}
				}
				else{
					if(i==input.size()-1){
  						outputFile << "-5V";
					}
					else{
  						outputFile << "-5V ";
					}
				}
			}
			outputFile.close();
			string output;
			ifstream outputFileFinalResult("NRZ-L_Encoded.txt");  /*Reading output from the file NRZ-L_Encoded.txt*/
			if(outputFileFinalResult){
				ostringstream s;
				s<< outputFileFinalResult.rdbuf();   /*Getting the data of NRZ-L_Encoded.txt from buffer in String output*/
				output = s.str();
			}
			cout<< "Output: "<<output<<endl;
			cout<<endl;
			cout<< "Output is saved in file NRZ-L_Encoded.txt"<<endl;
		}
		if(command2 == 2){
			ifstream inputFile("encode.txt");  /*Reading input from the file encode.txt*/
			string input;
			if(inputFile){
				ostringstream s;
				s << inputFile.rdbuf(); /*Getting the data of encode.txt from buffer in String input*/
				input = s.str();
			}
			cout<<"Input is taken from ""encode.txt"" file"<<endl;
			cout<<endl;
			cout<< "Input: " << input<<endl;
			cout<<endl;
			ofstream outputFile;
			outputFile.open("NRZ-I_Encoded.txt");  /*Pushing the output in NRZ-I_Encoded.txt file*/
			string prevVoltage = "+5V";		  /*Guessing that previous voltage is positive (+5v) */
			for(int i=0;i<input.size();i++){		/*Taking 0 as no change and 1 as change in voltage*/	
				if(input[i] == '1' && prevVoltage == "+5V"){
					if(i==input.size()-1){
						outputFile << "-5V";
						prevVoltage = "-5V";
					}
					else{
						outputFile << "-5V ";
						prevVoltage = "-5V";
					}
				}
				else if(input[i] == '1' && prevVoltage == "-5V"){
					if(i==input.size()-1){
						outputFile << "+5V";
						prevVoltage = "+5V";
					}
					else{
						outputFile << "+5V ";
						prevVoltage = "+5V";
					}
				}
				else{
					if(i==input.size()-1){
						outputFile << prevVoltage;
					}
					else{
						outputFile << prevVoltage << " ";
					}
				}
			}
			outputFile.close();
			string output;
			ifstream outputFileFinalResult("NRZ-I_Encoded.txt");   /*Reading output from the file NRZ-I_Encoded.txt*/
			if(outputFileFinalResult){
				ostringstream s;
				s << outputFileFinalResult.rdbuf();		/*Getting the data of NRZ-I_Encoded.txt from buffer in String output*/
				output = s.str();
			}
			cout<< "Output: "<<output<<endl;
			cout<<endl;
			cout<< "Output is saved in file NRZ-I_Encoded.txt"<<endl;
		}
	}
	if(command1 == 2){
		cout<< "In which scheme would you like to Decode the bitstream?" <<endl;
		cout<< "01. NRZ-L" <<endl;
		cout<< "02. NRZ-I" <<endl;
		cout<< "Enter your command: ";
		int command2;
		cin>>command2;
		cout<<endl;
		if(command2 == 1){
			ifstream inputFile("decode.txt");		/*Reading input from the file decode.txt*/
			string input;
			if(inputFile){
				ostringstream s;
				s << inputFile.rdbuf();		/*Getting the data of decode.txt from buffer in String input*/
				input = s.str();
			}
			cout<<"Input is taken from ""decode.txt"" file"<<endl;
			cout<<endl;
			cout<< "Input: " << input<<endl;
			cout<<endl;
			ofstream outputFile;
			outputFile.open("NRZ-L_Decoded.txt");	/*Pushing the output in NRZ-L_Decoded.txt file*/
			for(int i=0;i<input.size();i++){	/*Taking +5V as 0 and -5V as 1*/
				if(input[i] == ' ' || input[i] == '5' || input[i] == 'V' || input[i] == 'v'){
					continue;
				}
				else if(input[i] == '+'){
					outputFile<<'0';
				}
				else if(input[i] == '-'){
					outputFile<<'1';
				}
				else{
					outputFile<< "Error!! Can not decode the input for this particular scheme"<<endl; 	/*Giving Error message when there is any other voltage rather than +5V or -5V*/
					outputFile<< "Please use only +5V or -5V to decode for this particular scheme"<<endl;
					break;
				}
			}
			outputFile.close();
			string output;
			ifstream outputFileFinalResult("NRZ-L_Decoded.txt");  /*Reading output from the file NRZ-L_Decoded.txt*/
			if(outputFileFinalResult){
				ostringstream s;
				s << outputFileFinalResult.rdbuf();		/*Getting the data of NRZ-L_Decoded.txt from buffer in String output*/
				output = s.str();
			}
			cout<< "Output: "<<output<<endl;
			cout<<endl;
			cout<< "Output is saved in file NRZ-L_Decoded.txt"<<endl;
		}
		if(command2 == 2){
			ifstream inputFile("decode.txt");	/*Reading input from the file decode.txt*/
			string input;
			if(inputFile){
				ostringstream s;
				s << inputFile.rdbuf();		/*Getting the data of decode.txt from buffer in String input*/
				input = s.str();
			}
			cout<<"Input is taken from ""decode.txt"" file"<<endl;
			cout<<endl;
			cout<< "Input: " << input<<endl;
			cout<<endl;
			ofstream outputFile;
			outputFile.open("NRZ-I_Decoded.txt");		/*Pushing the output in NRZ-I_Decoded.txt file*/
			string prevVoltage = "+";				/*Guessing that previous voltage is positive (+5v) */
			for(int i=0;i<input.size();i++){ 	/*Taking 0 as no change and 1 as change in voltage*/
				if(input[i] == ' ' || input[i] == '5' || input[i] == 'V' || input[i] == 'v'){
					continue;
				}
				else if(input[i] == '+' && prevVoltage == "+"){
					outputFile<<'0';
					prevVoltage = "+";
				}
				else if(input[i] == '-' && prevVoltage == "-"){
					outputFile<<'0';
					prevVoltage = "-";
				}
				else if(input[i] == '+' && prevVoltage == "-"){
					outputFile<<'1';
					prevVoltage = "+";
				}
				else if(input[i] == '-' && prevVoltage == "+"){
					outputFile<<'1';
					prevVoltage = "-";
				}
				else{
					outputFile<< "Error!! Can not decode the input for this particular scheme"<<endl;		/*Giving Error message when there is any other voltage rather than +5V or -5V*/
					outputFile<< "Please use only +5V or -5V to decode for this particular scheme"<<endl;
					break;
				}
			}
			outputFile.close();
			string output;
			ifstream outputFileFinalResult("NRZ-I_Decoded.txt");	/*Reading output from the file NRZ-I_Decoded.txt*/
			if(outputFileFinalResult){
				ostringstream s;
				s << outputFileFinalResult.rdbuf();		/*Getting the data of NRZ-I_Decoded.txt from buffer in String output*/
				output = s.str();
			}
			cout<< "Output: "<<output<<endl;
			cout<<endl;
			cout<< "Output is saved in file NRZ-I_Decoded.txt"<<endl;
		}
	}
	return 0;
}