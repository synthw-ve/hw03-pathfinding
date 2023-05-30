#include "pathfinding.h"
#include <ctime>
#include <cmath>
using namespace std;

bool pathfinding::random_value() {
	// Random number 0-100, if <PROBABILITY return true (PROBABILITY%)
	return (rand() % 100) < PROBABILITY;
}

// TODO: Set obstacles to 1, everything else stays 0
pathfinding::pathfinding() {
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			_generation[i][j] = random_value();

	cout << "Start X: "; cin >> x;
	cout << "Start Y: "; cin >> y;
	cout << "End X: "; cin >> end_x;
	cout << "End Y: "; cin >> end_y;
}

float pathfinding::get_dist(int x, int y) {
	return (sqrt(pow((end_x - x), 2) + pow((end_y - y), 2)));
}

short pathfinding::next_generation() {
	float min_dist = ROWS*COLS; // Default: pretty fucking huge
	int inc_x = 0; // Increment of X
	int inc_y = 0; // Increment of Y
	int res_x = 0; // Reserve X (to get unstuck)
	int res_y = 0; // Reserve Y (to get unstuck)

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) {
			if (   !((x == 0)    && (i == -1)) // OOB check rows
				&& !((x == ROWS) && (i == 1))
				&& !((y == 0)    && (j == -1)) // OOB check cols
				&& !((y == COLS) && (j == 1))) {
					float curr_dist = get_dist(x+i, y+j);
					if (!_generation[x + i][y + j] // If not an obstacle
						&& curr_dist < min_dist) {
							min_dist = curr_dist;
							inc_x = i;
							inc_y = j;
					}
			}
		}

	if (!((inc_x == 0) && (inc_y == 0))) { // If a path exists
		x += inc_x;
		y += inc_y;
	}
	else
		return 2;

	if (x == end_x && y == end_y) // If the end has been reached
		return 1;
	else
		return 0;
}

void pathfinding::draw() {
	system("cls");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			if (i == x && j == y)
				cout << 'O';
			else if (i == end_x && j == end_y)
				cout << 'X';
			else if (_generation[i][j])
				cout << '*';
			else
				cout << '-';
		cout << endl;
	}
}