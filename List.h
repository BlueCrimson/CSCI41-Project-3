#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "Node.h"

using namespace std;

class List
{
public:
    List();
    void InsertAfter(Node* after, Node* node);
    void RemoveNode(Node* node);
    void InsertInOrder(Node* node);
    Node* Search(double match);
	Node *head;
};