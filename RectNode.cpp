#include "stdafx.h"
#include "RectNode.h"

RectNode::RectNode(const Rectangle &_rect)
{
	rect = _rect;
}

void RectNode::PrintNodeData()
{
	cout << GetValue() << endl;
}

double RectNode::GetValue()
{
	return rect.GetArea();
}