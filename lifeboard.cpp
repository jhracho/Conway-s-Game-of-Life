#include <iostream>
#include <iomanip>

using namespace std;
#include "lifeboard.h"

Cell::Cell()
{
  for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++){
			mainboard[i][j] = BLANK;
			tempboard[i][j] = BLANK;
		}
}

Cell::~Cell()
{}

void Cell::display()
{
	cout << "+" << setfill('-') << setw(SIZE + 1) << "+" << endl;
	for (int i = 0; i < SIZE; i++){
		cout << "|";
		for (int j = 0; j < SIZE; j++)
			cout << mainboard[i][j];
		cout << "|";
		cout << endl;
	}
	cout << "+" << setfill('-') << setw(SIZE + 1) << "+" << endl;
}

bool Cell::isAlive(int x, int y)
{return (mainboard[x][y] == ALIVE);}

bool Cell::inBounds(int x, int y)
{return ((x>=0 && x < SIZE) && (y>=0 && y < SIZE));}

bool Cell::isEmpty(int x, int y)
{return (mainboard[x][y] == BLANK);}

bool Cell::boardFull(){
  for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (mainboard[i][j] == BLANK)
				return false;
	
	return true;
}

void Cell::addCellMain(int x, int y)
{mainboard[x][y] = ALIVE;}

void Cell::removeCellMain(int x, int y)
{mainboard[x][y] = BLANK;}

void Cell::create(int x, int y)
{tempboard[x][y] = ALIVE;}

void Cell::kill(int x, int y)
{tempboard[x][y] = BLANK;}

void Cell::addCell(int x, int y)
{
  if (isEmpty(x,y) && inBounds(x,y)){
    addCellMain(x,y);
    cout << "Cell added at " << x << "," << y << "." << endl;
	}

	else if (!isEmpty(x,y))
		cout << "Position already has a live cell in it." << endl;

	else if (!inBounds(x,y))
		cout << "Point is out of range, try again." << endl;
	
	else{
    cout << "Unknown error." << endl;
		
	}
}

void Cell::removeCell(int x, int y)
{
  if (!isEmpty(x,y) && inBounds(x,y)){
    removeCellMain(x,y);
    cout << "Cell removed at " << x << "," << y << "." << endl;
	}

	else if (isEmpty(x,y))
		cout << "Position is empty." << endl;

	else if (!inBounds(x,y))
		cout << "Point is out of range, try again." << endl;
	
	else{
    cout << "Unknown error." << endl;
		
	}
}
void Cell::screenUpdate()
{
	cout << "+" << setfill('-') << setw(SIZE + 1) << "+" << endl;
	for (int i = 0; i < SIZE; i++){
		cout << "|";
		for (int j = 0; j < SIZE; j++)
			cout << tempboard[i][j];
		cout << "|";
		cout << endl;
	}
	cout << "+" << setfill('-') << setw(SIZE + 1) << "+" << endl;
}

int Cell::getNeighbors(int x, int y)
{
	int neighs;

//Checks the eight surrounding cells to see if they are alive
  if (isAlive(x+1, y+1) && inBounds(x+1, y+1))
		neighs++;

  if (isAlive(x-1, y+1) && inBounds(x-1, y+1))
		neighs++;

  if (isAlive(x+1, y) && inBounds(x+1, y))
 		neighs++;

  if (isAlive(x, y+1) && inBounds(x, y+1))
		neighs++;

  if (isAlive(x-1, y) && inBounds(x-1, y))
		neighs++;

  if (isAlive(x, y-1) && inBounds(x, y-1))
		neighs++;

  if (isAlive(x+1, y-1) && inBounds(x+1, y-1))
		neighs++;

  if (isAlive(x-1, y-1) && inBounds(x-1, y-1))
		neighs++;

  return neighs;
}
// Copies tempboard over to mainboard
void Cell::advance()
{
	int neighs;

  for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++){
      neighs = getNeighbors(i,j);
			if (isEmpty(i,j) && neighs == 3)
				create(i,j);
			else if (isAlive(i,j) && (neighs == 3 || neighs == 2))
				create(i,j);
		}

  for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++){
      neighs = getNeighbors(i,j);
			if (!isAlive(i,j) && !(neighs == 3 || neighs == 2))
				kill(i,j);
		}

	
// Copies the temp board onto the main board
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			mainboard[i][j] = tempboard[i][j];

// Clears temp board
  for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			tempboard[i][j] = BLANK;
}



