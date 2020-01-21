#include<stdio.h>
#include<stdbool.h>
#include "TBST.h"

TBST *CreateNewNode(int val)
{
	TBST* NewNode = (TBST *)malloc(sizeof(TBST));
	if (NewNode)
	{
		NewNode->data = val;
		NewNode->left = NewNode->right = NULL;
		NewNode->lflag = NewNode->rflag = true;
	}
	else
	{
		printf("\nNo Memory Allocated\n");
	}
	return NewNode;
}

//TBST *InorderSuccessor(TBST *temp)
//{
//	if (temp->rflag == true)
//		return temp->left;
//	while (temp->lflag == false)
//	{
//		temp = temp->right;
//	}
//	return temp;
//}
void DisplayInorder(TBST *root)
{
	if (root == NULL)
	{
		printf("\nTree is Empty ");
	}
	else
	{
		TBST* temp = root;
		while (temp->lflag == false)
		{
			temp = temp->left;
		}
		while (temp != NULL)
		{
			printf("%d-> ", temp->data);
			
			if (temp->rflag == true)
			{
				temp = temp->right;
				printf("%d-> ", temp->data);
			}
				
			temp = temp->right;

			while (temp != NULL && temp->lflag == false)
				temp = temp->left;
		}

	}
	
}

TBST *InsertNewNode(TBST* root,int val)
{
	if (root == NULL)
	{
		return CreateNewNode(val);
	}
	else
	{
		TBST *curr = root;
		TBST *parent = NULL;
		while (curr !=NULL)
		{
			if (curr->data == val)
			{
				printf("\nDuplicate Value......\n");
				return root;
			}
			parent = curr;//parent box ad1  25 13 5
			//moving on left subtree
			if (curr->data > val)
			{
				if (curr->lflag == false)
				{
					curr = curr->left;
				}
				else 
				{
					break;
				}
			}
			//moving on right subtree
			else
			{
				if (curr->rflag == false)
				{
					curr = curr->right;
				}
				else
				{
					break;
				}
			}

		}//End of while loop
		TBST* NewNode = CreateNewNode(val);
		//NewNode->lflag = NewNode->rflag = true;
		 if (parent->data > val)
		{
			NewNode->left = parent->left;
			NewNode->right = parent;
			parent->lflag = false;
			parent->left = NewNode;
		}
		else
		{
			NewNode->right = parent->right;
			parent->right = NewNode;
			parent->rflag = false;
			NewNode->left = parent;
		}
	}
	return root;
}