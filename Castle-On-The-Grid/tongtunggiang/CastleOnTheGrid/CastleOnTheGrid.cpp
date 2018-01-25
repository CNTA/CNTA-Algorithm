#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define ALLOWED   '.'
#define FORBIDDEN 'X'
#define MAX_N 100

#define IN_RANGE(index, size) (index >= 0 && index < size)


struct Point2D
{
	Point2D(int x, int y) : x(x), y(y) {}
	Point2D() : Point2D(0, 0) { }

	int x, y;
};


/**
* @brief Overload equal operation for convenient comparing two points
*
*/
bool operator==(const Point2D &a, const Point2D &b)
{
	return (a.x == b.x) && (a.y == b.y);
}

/**
* @brief Overload less than operator for efficient storing in dictionary/map.
*
*/
bool operator<(const Point2D &a, const Point2D &b)
{
	return (a.x * MAX_N + a.y) < (b.x * MAX_N + b.y);
}


vector<Point2D> getNeighbours(const vector<string>& grid, Point2D point)
{
	int row = point.x;
	int col = point.y;

	if (grid[row][col] == FORBIDDEN)
		return vector<Point2D>();

	int size = grid.size();
	vector<Point2D> neighbours;
	for (int otherRow = row; otherRow < size; otherRow++)
	{
		if (otherRow == row)
			continue;

		if (grid[otherRow][col] == FORBIDDEN)
			break;

		neighbours.push_back(Point2D(otherRow, col));
	}

	for (int otherRow = row; otherRow >= 0; otherRow--)
	{
		if (otherRow == row)
			continue;

		if (grid[otherRow][col] == FORBIDDEN)
			break;

		neighbours.push_back(Point2D(otherRow, col));
	}

	for (int otherCol = col; otherCol < size; otherCol++)
	{
		if (otherCol == col)
			continue;

		if (grid[row][otherCol] == FORBIDDEN)
			break;

		neighbours.push_back(Point2D(row, otherCol));
	}

	for (int otherCol = col; otherCol >= 0; otherCol--)
	{
		if (otherCol == col)
			continue;

		if (grid[row][otherCol] == FORBIDDEN)
			break;

		neighbours.push_back(Point2D(row, otherCol));
	}

	return neighbours;
}


/**
* @brief Get how long it takes to travel from the start point to this state.
*
*/
int calculatePathLength(Point2D state, const map<Point2D, Point2D>& meta)
{
	int length = 0;
	while (state.x != -1 && state.y != -1)
	{
		length++;
		state = meta.at(state);
	}

	return length - 1;
}

/**
* @brief Find minimum moves from start position to goal position
*
* This function is modified BFS algorithm:
* https://en.wikipedia.org/wiki/Breadth-first_search
*
* A bit of modification: instead of a set/array to store fully visited nodes (aka close set),
* I use a two-dimensional array of boolean values to indicate whether the node (x, y) has
* been closed or not. This is more efficient than using an array or a set, as the operation takes
* O(1), not O(n) or O(logn).
*/
int minimumMoves(const vector<string>& grid, int startX, int startY, int goalX, int goalY)
{
	if (startX == goalX && startY == goalY)
		return 0;

	//  # a FIFO open_set
	//	open_set = Queue()
	//	open_set.enqueue(start)
	std::vector<Point2D> openSet;
	openSet.push_back(Point2D(startX, startY));

	//	# an empty set to maintain visited nodes
	//	closed_set = set()
	vector<vector<bool>> closeSet(grid.size());
	for (vector<vector<bool>>::iterator it = closeSet.begin(); it != closeSet.end(); it++)
	{
		*it = vector<bool>(grid.size());
	}

	// meta = dict()  # key -> (parent state, action to reach child)
	// meta[start] = (None, None)
	map<Point2D, Point2D> meta;
	meta[Point2D(startX, startY)] = Point2D(-1, -1);

	Point2D parent = Point2D(0, 0);
	//	while not open_set.is_empty() :
	while (!openSet.empty())
	{
		// parent_state = open_set.dequeue()
		parent = openSet.front();
		openSet.erase(openSet.begin());

		if (parent.x == goalX && parent.y == goalY)
			return calculatePathLength(parent, meta);

		// for (child_state, action) in problem.get_successors(parent_state):
		const vector<Point2D>& neighbors = getNeighbours(grid, parent);
		for (vector<Point2D>::const_iterator it = neighbors.begin(); it != neighbors.end(); it++)
		{
			// if child_state in closed_set:
			//     continue
			Point2D child = *it;
			if (closeSet[child.x][child.y])
				continue;

			if (find(openSet.begin(), openSet.end(), child) == openSet.end())
			{
				meta[child] = parent;
				openSet.push_back(child);
			}
		}

		closeSet[parent.x][parent.y] = true;
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<string> grid(n);
	for (int grid_i = 0; grid_i < n; grid_i++)
	{
		cin >> grid[grid_i];
	}

	int startX;
	int startY;
	int goalX;
	int goalY;
	cin >> startX >> startY >> goalX >> goalY;

	int result = minimumMoves(grid, startX, startY, goalX, goalY);
	cout << result << endl;

	return 0;
}
