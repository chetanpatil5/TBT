#pragma once
#include<stdio.h>
#include<stdbool.h>

typedef struct TBST
{
	struct TBST* left, *right;
	int data;
	bool lflag, rflag;
}TBST;

TBST *CreateNewNode(int val);
TBST *InsertNewNode(TBST* root,int val);
void DisplayInorder(TBST *);
