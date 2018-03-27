#pragma once
#include <queue>
#include <math.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

using namespace std;

//size of the map
const int n = 60;
const int m = 60;
static int map[n][m];
static int closed_nodes_map[n][m]; //nodes that have been tried
static int open_nodes_map[n][m]; //nodes not yet tried
static int dir_map[n][m];

const int dir = 4; //directions
static int dx[dir] = { 1, 0, -1, 0 };
static int dy[dir] = { 0, 1, 0, -1 };

class Node
{
public:
	Node() {};
	Node(int x, int y, int d, int p);
	~Node() {};

	//get/set methods
	int getXPos() const { return xPos; }
	int getYPos() const { return yPos; }
	int getLevel() const { return level; }
	int getPriority() const { return priority; }

	void UpdatePriority(const int & xDest, const int & yDest);
	const int & Estimate(const int & xDest, const int & yDest) const;


private:
	//Current Position
	int xPos;
	int yPos;

	//keeps track of distance travalled
	int level;

	int priority;
};

bool operator< (const Node & a, const Node & b);

static string FindPath(const int & xStart, const int & yStart, const int & xFinish, const int & yFinish)
{
	static priority_queue<Node> pq[2]; //list of open nodes
	static int pqIndex;
	static Node* n0;
	static Node* m0;
	static int i, j, x, y, xdx, ydy;
	static char c;
	pqIndex = 0;

	//Reset Node Maps
	for (y = 0; y < m; y++)
	{
		for (x = 0; x < n; x++)
		{
			closed_nodes_map[x][y] = 0;
			open_nodes_map[x][y] = 0;
		}
	}

	//create start node and add to list of open nodes
	n0 = new Node(xStart, yStart, 0, 0);
	n0->UpdatePriority(xFinish, yFinish);
	pq[pqIndex].push(*n0);
	open_nodes_map[x][y] = n0->getPriority();

	//A* search
	while (!pq[pqIndex].empty())
	{
		//get the current node with highest priority
		n0 = new Node(pq[pqIndex].top().getXPos(), pq[pqIndex].top().getYPos(),
			pq[pqIndex].top().getLevel(), pq[pqIndex].top().getPriority());

		x = n0->getXPos();
		y = n0->getYPos();

		pq[pqIndex].pop(); //remove node from open list
		open_nodes_map[x][y] = 0;
		closed_nodes_map[x][y] = 1;

		//quit searching when ggoal is reached
		if (x == xFinish && y == yFinish)
		{
			//generate path
			string path = "";

			while (!(x == xStart && y == yStart))
			{
				j = dir_map[x][y];
				c = '0' + (j + dir / 2) % dir;
				path = c + path;
				x += dx[j];
				y += dy[j];
			}

			//clean up
			delete n0;

			//empty leftover nodes
			while (!pq[pqIndex].empty())
			{
				pq[pqIndex].pop();
			}

			return path;
		}

		//generate moves
		for (i = 0; i < dir; i++)
		{
			xdx = x + dx[i];
			ydy = y + dy[i];

			if (!(xdx < 0 || xdx > n - 1 || ydy < 0 || ydy > m - 1 || map[xdx][ydy] == 1
				|| closed_nodes_map[xdx][ydy] == 1))
			{
				//generate node
				m0 = new Node(xdx, ydy, n0->getLevel(), n0->getPriority());
				m0->UpdatePriority(xFinish, yFinish);

				//if not in open list, add to list
				if (open_nodes_map[xdx][ydy] == 0)
				{
					open_nodes_map[xdx][ydy] = m0->getPriority();
					pq[pqIndex].push(*m0);
					//mark its parent node direction
					dir_map[xdx][ydy] = (i + dir / 2) % dir;
				}
				else if (open_nodes_map[xdx][ydy] == 0)
				{
					//update priority info
					open_nodes_map[xdx][ydy] = m0->getPriority();

					//update direction info
					dir_map[xdx][ydy] = (i + dir / 2) % dir;

					//replace node
					while (!pq[pqIndex].top().getXPos() == xdx &&
						pq[pqIndex].top().getYPos() == ydy)
					{
						pq[1 - pqIndex].push(pq[pqIndex].top());
						pq[pqIndex].pop();
					}
					pq[pqIndex].pop(); //remove the wanted node

									   //empty the larger size pq to smaller one
					if (pq[pqIndex].size() > pq[1 - pqIndex].size())
					{
						pqIndex = 1 - pqIndex;
					}

					while (!pq[pqIndex].empty())
					{
						pq[1 - pqIndex].push(pq[pqIndex].top());
						pq[pqIndex].pop();
					}
					pqIndex = 1 - pqIndex;
					pq[pqIndex].push(*m0);
				}
				else delete m0; //clean up
			}
		}
		delete n0; //clean up
	}
	return ""; //no path found
}