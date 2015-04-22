#include "stdafx.h"
#include "TrglNode.h"
#include <iomanip>

TrglNode::TrglNode(const Triangle &_trgl)
{
	trgl = _trgl;
}

void TrglNode::PrintNodeData()
{
	cout << std::setprecision(4) << GetValue() << endl;
}

double TrglNode::GetValue()
{
	return trgl.GetArea();
}