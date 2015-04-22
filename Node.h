#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

class Node
{
public:
	Node();
	Node* GetNext();
    void SetNext(Node* nodePtr);
	virtual void PrintNodeData() = 0;
	virtual double GetValue() = 0;
private:
    Node* nextNodePtr;
};