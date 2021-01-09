const int SIZE = 40;
const char BLANK = ' ';
const char ALIVE = 'X';

class Cell{
  public:
    Cell();
		~Cell();
	  void display();
    bool inBounds(int, int);
		bool isAlive(int, int);
		bool isEmpty(int, int);
		bool boardFull();
		void addCell(int, int);
		int getNeighbors(int, int);
		void removeCell(int, int);
		void advance();
		void screenUpdate();
		bool checkBoard(int, int);
		void create(int, int);
		void kill(int, int);
		void addCellMain(int, int);
		void removeCellMain(int, int);
		
	private:
	  char mainboard[SIZE][SIZE];
		char tempboard[SIZE][SIZE];
};
