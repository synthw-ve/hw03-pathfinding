#include <iostream>
#include <chrono>
#include <thread>
#include "pathfinding.h"
using namespace std;

int main() {
	srand(time(nullptr));
	pathfinding demo;
	
	short again;
	do {
		demo.draw();
		again = demo.next_generation();
		this_thread::sleep_for(chrono::milliseconds(200));
	} while (!again);
	demo.draw(); // Finished!
	if (again == 2)
		cout << "Stuck! :<";

	return 0;
}