#ifndef KAREL_H
#define KAREL_H

//using namespace std;

class Karel {
	private:
		int karelRow;
		int karelColumn;
		std::string karelFacing;
		int worldSize;

	public:
		void init(int);
		void readout();
		bool move();
		void turnLeft();
		void crash(int);
		void cleanQuit();
		int get(const int);
};

#endif
