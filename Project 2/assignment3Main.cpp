/*
/ Author Name   : Derek Florimonte
/ G++(V 4.9.3)
*/
#include <fstream>
#include <iostream>

using namespace std;

//STRUCT DECLARATIONS
struct MapItem{

	char type;

};

struct Map{

int size;
MapItem * items; 

};
//GAMERUN - Begin Program, Returns True (1)
bool gameRun();

//DISPLAYMENU - Prompts the user, returns nothing
void displayMenu();

//SELECTION - Requires a users integer input, return the integer input
int selection();

//CREATE_NEW_GAME - Requires the user to input a size integer used to format the map
void create_new_game(Map & map);

//PRINT_MAP - Requires a map variable passed by reference, and prints the type of mapItem consisting within
void print_map(Map & map);

//BUILD - Requires the user to input an x and y coordinate, correlated to the position on the map,
//		  and requires the user to input a buildCode char, changing a value on the map
void build(Map & map);


//ENUM DECLARATIONS
enum MenuOptions{INIT, NEW_GAME, PRINT_MAP, BUILD, EXIT_PROGRAM};





//********************************MAIN BEGIN********************************
int main(){

	return gameRun();
	
}
//********************************MAIN END********************************



/********************************FUNCTION LIST********************************/

//DISPLAYMENU - Self Explanatory 
void displayMenu(){
	cout << endl << "1. New Game" << endl 
	<< "2. Print Map" << endl
	<< "3. Build Something" << endl
	<< "4. Exit" << endl;
}

//SELECTION - This requires the user to input an integer between 0 and 2
int selection(){
	int tempInput;
	cout << "Enter your selection: ";
	cin >> tempInput;

	if(tempInput < 1 || tempInput > 4){
		tempInput = 1;
			cout << "****ERROR****" << endl
			<< "Please only type a number 1 though 4!" << endl;
			cout << "Enter your selection: ";
			cin >> tempInput;
		}

	return tempInput;
}


//CREATE_NEW_GAME - Requires the user to input a size integer used to format the map
void create_new_game(Map & map){

	cout << "What size map would you like? ";
	cin >> map.size;

	map.items = new MapItem [(map.size*map.size)];
	for (int i = 0; i < (map.size*map.size); i++){
		map.items[i].type = 'E';
	}

};


//PRINT_MAP - Requires a map variable passed by reference, and prints the type of mapItem consisting within
void print_map(Map & map){
	int count = 0;
	if(map.size <= 0){

	}
	else{
		for (int i = 0; i < (map.size*map.size); i++){

			cout << map.items[i].type << " ";

			//Holy Shit a Modulus
			if(((i+1) % map.size) == 0){
				cout << endl;
			}
		}	
		cout << endl;
	}
};


//BUILD - Requires the user to input an x and y coordinate, correlated to the position on the map,
//		  and requires the user to input a buildCode char, changing a value on the map
void build(Map & map){

	int xCoord;
	int yCoord;
	char buildCode;

	cout << "Enter x and y coordinates: ";
	cin >> xCoord;
	cin >> yCoord;

	cout << "Enter a building code: ";
	cin >> buildCode;

	map.items[(map.size*(yCoord)) + (xCoord)].type = buildCode;
	
};

//GAMERUN - Program Begins, returns (1)
bool gameRun(){

	bool wantsToQuit = false;

	Map map;
	map.size = 0;

	while(!wantsToQuit){

		displayMenu();

			switch (selection()){
				
				//Option 1
				case NEW_GAME:
				create_new_game(map);
				break;
				
				//Option 2
				case PRINT_MAP:
				print_map(map);
				break;
				
				//Option 3
				case BUILD:
				build(map);
				int count;
				count = 0;
				break;

				//Option 4
				case EXIT_PROGRAM:
				wantsToQuit = true;
				break;

				default:
				break;
			}
	}
	delete map.items;
	return true;
};