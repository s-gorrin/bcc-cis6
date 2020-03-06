#ifndef WORLD_H
#define WORLD_H

class World {
	private:
		std::vector<std::vector<int> > grid;
		int worldSize;

	public:
		World(int);
		void drawMap(int, int);
		void putBeeper(int, int);
		bool pickBeeper(int, int);

};

#endif
