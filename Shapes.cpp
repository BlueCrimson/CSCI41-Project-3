//----------------------------------------------------------------------------------------//
// Programmer: Kevin Ngo
// Class: CSCI 41
// Instructor: Dr. Ming Li
// Project 3: Linked Lists, Exception Handling, Pointers
//----------------------------------------------------------------------------------------//

#include "stdafx.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "RectNode.h"
#include "TrglNode.h"
#include "List.h"

using namespace std;

List* RectList = new List();
List* TrglList = new List();

void PrintRectArea()
{
	Node* curr = RectList->head;
	while (curr != 0)
	{
		curr->PrintNodeData();
		curr = curr->GetNext();
	}
}

void PromptRectArea()
{
	double area; 
	cout << "Select an area value to delete: ";
	cin >> area;
	Node* node = RectList->Search(area);
	try
	{
		RectList->RemoveNode(node);
		cout << "Area found and deleted." << endl;
	}
	catch(runtime_error &err)
	{
		cout << "Area not found." << endl;
	}
}

void ReadRectData()
{
	if (RectList->head != 0)
		return;

	ifstream inFileRect;
	inFileRect.open("C:\\Rsides.txt");

	if (inFileRect.fail())
		throw runtime_error("Error opening file.");

	Rectangle rect;
	int w, h;
	while (true)
	{
		w = 0; h = 0;
		inFileRect >> w >> h;
		rect.SetSides(w, h);
		try 
		{ 
			rect.CheckValidity();
			RectNode* node = new RectNode(rect);
			if (RectList->head == 0)
				RectList->head = node;
			else 
				RectList->InsertInOrder(node);
		}
		catch(runtime_error &err)
		{
			cout << err.what() << endl;
		}
		if (inFileRect.eof())
			break;
	}
}

void PrintTrglArea()
{
	Node* curr = TrglList->head;
	while (curr != 0)
	{
		curr->PrintNodeData();
		curr = curr->GetNext();
	}
}

void PromptTrglArea()
{
	double area;
	cout << "Select an area value to delete: ";
	cin >> area;
	Node* node = TrglList->Search(area);
	try
	{
		TrglList->RemoveNode(node);
		cout << "Area found and deleted." << endl;
	}
	catch(runtime_error &err)
	{
		cout << "Area not found." << endl;
	}

}

void ReadTrglData()
{
	if (TrglList->head != 0)
		return;

	ifstream inFileTrgl;
	inFileTrgl.open("C:\\Tsides.txt");

	if (inFileTrgl.fail())
		throw runtime_error("Error opening file.");

	Triangle trgl;
	int a, b, c;
	while (true)
	{
		a = 0; b = 0; c = 0;
		inFileTrgl >> a >> b >> c;
		trgl.SetSides(a, b, c);
		try 
		{ 
			trgl.CheckValidity();
			TrglNode* node = new TrglNode(trgl);
			if (TrglList->head == 0)
				TrglList->head = node;
			else 
				TrglList->InsertInOrder(node);
		}
		catch(runtime_error &err)
		{
			cout << err.what() << endl;
		}
		if (inFileTrgl.eof())
			break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	

	char option = '0';
	while(option != '3')
	{
		cout << "Select one of the following options to search area values: " << endl;
		cout << "		1. Rectangle" << endl;
		cout << "		2. Triangle" << endl;
		cout << "		3. Quit" << endl;

		cin >> option;
		if(option == '1')
		{
			try
			{
				ReadRectData();
			}
			catch (runtime_error &err)
			{
				cout << err.what() << endl;
				system("PAUSE");
				exit(1);
			}
			PrintRectArea();
			PromptRectArea();
		}
		else if(option == '2')
		{
			try
			{
				ReadTrglData();
			}
			catch (runtime_error &err)
			{
				cout << err.what() << endl;
				system("PAUSE");
				exit(1);
			}
			PrintTrglArea();
			PromptTrglArea();
		}
		else if(option == '3')
		{
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Invalid option." << endl;
		}
	}
	system("PAUSE");
	return 0;
}

