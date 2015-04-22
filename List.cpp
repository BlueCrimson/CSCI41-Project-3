#include "stdafx.h"
#include "List.h"
#include <stdexcept>

List::List() 
{
	head = 0;
}

void List::InsertAfter(Node* after, Node* node) 
{
   if (after == 0)
	   throw runtime_error("Invalid node pointer.");

   Node *tmpNext = after->GetNext();    // Remember next
   after->SetNext(node);    // this -- node -- ?
   node->SetNext(tmpNext); // this -- node -- next
}

void List::RemoveNode(Node* nodeToRemove)
{
	if (nodeToRemove == 0)
		throw runtime_error("Invalid node pointer.");

	Node* temp = head;

	while (temp != 0)
	{
		if (temp->GetNext() == nodeToRemove)
		{
			temp->SetNext(nodeToRemove->GetNext());
			delete nodeToRemove;
			break;
		}
		temp = temp->GetNext();
	}
}

void List::InsertInOrder(Node* node) 
{
	if (node == 0)
		throw runtime_error("Invalid node pointer.");

	if (head == 0)
	{
		head = node;
		return;
	}
    if (head->GetValue() > node->GetValue()) 
	{
		InsertAfter(head, node);
        return;
    }

    Node* curr = head;

    while (curr != 0) 
	{ //otherwise, insert after
        if(curr->GetNext() == 0 || curr->GetNext()->GetValue() > node->GetValue()) 
		{
            InsertAfter(curr, node); // this will be consistent with the textbook InsertAfter() function
            break;
		}
        curr = curr->GetNext();
    }
}

bool isEqual(double i, double j)
{
    const double dEpsilon = 0.0005;
	double x = fabs(i - j);
	double y = dEpsilon * fabs(i);
	if (x <= y)
		return true;
	else
		return false;
}

Node* List::Search(double match)
{
	Node* searchNode = head;
	while (searchNode != 0)
	{
		if (isEqual(searchNode->GetValue(), match))
			return searchNode;
		searchNode = searchNode->GetNext();
	}
	return 0;
}