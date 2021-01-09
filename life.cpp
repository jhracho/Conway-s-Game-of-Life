#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
#include "lifeboard.h"


// Global declaration of lifeboard so it can be passed to funcs
Cell life;

// Prototype
void command(char);

int main(int argc, char *argv[])
{

int infinity = 0;
// Interactive Mode
	if (argc == 1){
  	char choice;

  	life.display();

  	cout << "COMMAND: ";
  	cin >> choice;

  	while (choice != 'q'){
  	  command(choice);
		
  		cout << "COMMAND: ";
  		cin >> choice;
	  }

  	cout << "Goodbye!" << endl;
  }

// Blocks user from enterring mroe than one file
	else if (argc > 2){
		cout << "Too many arguments. Enter one file name." << endl;
		return 1;
	}

// Batch mode
	else{
		string option;
		string x_s, y_s;
		int x, y;

		ifstream file; 
		string textFile = argv[1];
		file.open(textFile);
		
		while (!file){
			cout << "Error opening file, enter valid name: ";
			cin >> textFile;
			file.open(textFile);
		}

		while(file.peek() != EOF){
      		getline(file, option, ' ');
			getline(file, x_s, ' ');
			getline(file, y_s, '\n');

			x = stoi(x_s);
			y = stoi(y_s);
      
			if (option == "a")
				life.addCell(x,y);
			else if (option == "r")
				life.removeCell(x,y);
		}

	  life.display();
		cout << "Initializing..." << endl;
		sleep(1);
		system("clear");

		while(infinity == 0){
      		life.advance();
      		sleep(1);
			system("clear");
			life.display();
		}
	}

  return 0;
}

void command(char z){
  int x;
	int y;
	int infinity = 0;
	switch(z){
    case 'a':
		  cout << "What position? ";
			cin >> x >> y;
			cout << endl;
			life.addCell(x,y);
			sleep(1);			
			system("clear");
		  life.display();	
		  break;
		case 'r':
      cout << "What position? ";
			cin >> x >> y;
			cout << endl;
			life.removeCell(x,y);
			sleep(1);
			system("clear");
			life.display();
	  	break;
		case 'n':
			life.advance();
			cout << "Moving to next generation..." << endl;
			sleep(1);
			system("clear");
			life.display();
		  break;
		case'q':
		  break;
		case 'p':
		  while (infinity == 0){
        		life.advance();
				sleep(2);
				system("clear");
				life.display();
			}
		  break;
		default:
		  cout << "Unknown error.";
			break;
	}
}






