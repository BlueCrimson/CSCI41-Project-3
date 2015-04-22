#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "Node.h"
#include "Triangle.h"

using namespace std;

class TrglNode: public Node
{
public:
	TrglNode(const Triangle &_trgl);
	void PrintNodeData();
	double GetValue();
private:
	Triangle trgl;
};