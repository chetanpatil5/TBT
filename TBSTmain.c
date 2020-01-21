#include<stdio.h>
#include<stdbool.h>
#include "TBST.h"

int main()
{
	TBST* Root = NULL;

	Root = InsertNewNode(Root, 25);
	Root = InsertNewNode(Root, 13);
	Root = InsertNewNode(Root, 5);
	Root = InsertNewNode(Root, 7);
	Root = InsertNewNode(Root, 50);
	Root = InsertNewNode(Root, 35);
	Root = InsertNewNode(Root, 18);
	
	DisplayInorder(Root);
	return 0;
}