#include "Node.h"

Node::Node(int x, int y, int d, int p) :
	xPos(x), yPos(y), level(d), priority(p)
{

}

void Node::UpdatePriority(const int & xDest, const int & yDest)
{
	priority = level + Estimate(xDest, yDest);
}

const int & Node::Estimate(const int & xDest, const int & yDest) const
{
	static int xd, yd, d;
	xd = xDest - xPos;
	yd = yDest - yPos;

	//Euclidian Distance
	//d = (int)(sqrt(xd*xd + yd*yd));

	//Manhattan Distance
	d = abs(xd) + abs(yd);

	//Chebyshev Distance
	//d = max(abs(xd), abs(yd));

	return d;
}

bool operator< (const Node & a, const Node & b)
{
	return a.getPriority() > b.getPriority();
}