#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "Node.h"
#include "Rectangle.h"

using namespace std;

class RectNode: public Node
{
public:
	RectNode(const Rectangle &_rect);
	void PrintNodeData();
	double GetValue();
private:
	Rectangle rect;
};