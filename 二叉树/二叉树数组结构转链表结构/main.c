#include <stdio.h>
#include <stdlib.h>

struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};
typedef struct tree treeNode;
typedef struct tree *b_tree;
int N;

b_tree create(int *node, int position)
{
    b_tree newNode;
    if(node[position] == 0 || position > N) //当前位置没有子树或者越界
        return NULL;
    else
    {
        newNode = (b_tree)malloc(sizeof(treeNode));
        newNode->data = node[position];
        newNode->left = create(node, 2 * position);
        newNode->right = create(node, 2 * position + 1);
        return newNode;
    }
}

void print(b_tree root)
{
    if(root != NULL)
    {
        print(root->left);
        printf("%d ", root->data);
        print(root->right);
    }
}

int  main(int argc,char *argv[])
{
    freopen("array2link.in", "r", stdin);
    freopen("array2link.out", "w", stdout);

    int i = 1, temp;
    int node[10000];
    b_tree root = NULL;

    while(scanf("%d", &temp)!=EOF)
        node[i++] = temp;
    
    N = i - 1;

    root = create(node, 1);
    print(root);

    return EXIT_SUCCESS;
}