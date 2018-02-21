#include <stdio.h>
#include <stdlib.h>

struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
};

typedef struct tree treenode;
typedef	struct tree *b_tree;

b_tree create(int *data, int len)
{
	int i;
	b_tree root = NULL;
	
	for(i = 1; i <= len; ++i)
		root = insert(root, data[i]);
	
	return root;
}

b_tree insert(b_tree root, int node)
{
	b_tree newnode;
	b_tree currentnode;
	b_tree parentnode;
	
	newnode = (b_tree)malloc(sizeof(treenode));
	newnode->left = NULL;
	newnode->data = node;
	newnode->right = NULL;
	
	if(root == NULL)
		return newnode;
	else
	{
		currentnode = root;
		while(currentnode != NULL)
		{
			parentnode = currentnode;
			if(currentnode->data > node)
				currentnode = currentnode->left;
			else
				currentnode = currentnode->right;
		}
		
		if(parentnode->data > node)
			parentnode->left = newnode;
		else
			parentnode->right = newnode;
	}
	return root;
}

void print(b_tree root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		print(root->left);
		print(root->right);
	}
}


int main(int argc, char *argv[])
{
	
}
