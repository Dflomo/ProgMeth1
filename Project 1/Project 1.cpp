/************************************
*	Author Name	: Derek Florimonte
*	G++ (V 4.9.3)
*************************************/

/************************************
* Program includes a simple file system, giving the user
* the ability to define the file name as they see fit
*************************************/

#include <fstream>
#include <iostream>

using namespace std;

//DISPLAYMENU - Prompts the user, returns nothing
void displayMenu();

//SELECTION - Requires a users integer input, return the integer input
int selection();

//FILESELECTION - Requires the user to input two string inputs, returns a concatenated string
string fileSelection();


int main(){
	
	int userOption = 3;
	string fileName;
	ifstream inStream;
	ofstream outStream;

	displayMenu();
	userOption = selection();

	while(userOption != 0){
		
		fileName = fileSelection();


		//READ OPTION - User wants to read from file
		if(userOption == 1){			
			char nextChar;

			inStream.open(fileName.c_str());
			if(inStream.fail()){
				cout << endl << "File open failed. " << endl;
			}
			else{

			cout << endl <<"------- FILE " << fileName << " BEGIN -------" << endl;
			while(!inStream.eof()){
			inStream.get(nextChar);
			cout << nextChar;

			}
			cout << endl << "------- FILE " << fileName << " END -------" << endl;
			inStream.close();
			}
		}


		//WRITE OPTION - User wants to write to a file
		else if(userOption == 2){

			outStream.setf(ios::fixed);
			outStream.setf(ios::showpoint);
			outStream.precision(2);

			outStream.open(fileName.c_str(), ios::app);
			if(outStream.fail()){
				cout << endl << "File open failed." << endl;
			}
			else{
			string category;
			double value;
			cout << endl << "Enter a category and then a value: ";
			cin >> category >> value;
			outStream << category << " " << value << endl;
			outStream.close();
			}
		}

		//RE-PROMPT- Takes another user selection input, offering to exit the program
		displayMenu();
		userOption = selection();


	}


	return 0;
}



/*********************FUNCTION LIST***********************/

//DISPLAYMENU - Self Explanatory 
void displayMenu(){
	cout << "1. Read from File" << endl 
	<< "2. Write to a File" << endl
	<< "0. EXIT" << endl;
}

//SELECTION - This requires the user to input an integer between 0 and 2
int selection(){
	int tempInput;
	cout << "Enter selection: ";
	cin >> tempInput;

	if(tempInput != 2 && tempInput != 1 && tempInput != 0){
			cout << "****ERROR****" << endl
			<< "Please only type a number 0 though 2!" << endl;
			cout << "Enter selection: ";
			cin >> tempInput;
		}

	return tempInput;
}

//FILESELECTION - This requires the user to input two integer, first being the month, next being the year
string fileSelection(){
	string monthInput;
	string yearInput;
	string comboInput;

	cout << "Enter month then year:";
	cin >> monthInput >> yearInput;

	return comboInput = monthInput + "_" + yearInput + ".txt";
}
