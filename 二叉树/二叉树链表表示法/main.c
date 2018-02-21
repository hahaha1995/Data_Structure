#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree treeNode;
typedef struct tree *b_tree;

b_tree insert(b_tree root, int node);
b_tree create(int *data, int len);
void print(b_tree root);

int main(int argc, char *argv[])
{
    freopen("linktree.in", "r", stdin);
    freopen("linktree.out", "w", stdout);
    int i, n;
    scanf("%d", &n);
    int node[n + 1];
    b_tree root = NULL;

    for (i = 1; i <= n; ++i)
        scanf("%d", &node[i]);
    root = create(node, n);

    print(root);
    return EXIT_SUCCESS;
}

b_tree create(int *data, int len)
{
    int i;
    b_tree root = NULL;

    for (i = 1; i <= len; ++i)
        root = insert(root, data[i]); //根节点和要插入的数值

    return root;
}

b_tree insert(b_tree root, int node)
{
    b_tree newNode, currentNode, parentNode;

    newNode = (b_tree)malloc(sizeof(treeNode));
    newNode->data = node;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
        return newNode;
    else
    {
        currentNode = root;
        while (currentNode != NULL)
        {
            parentNode = currentNode;
            if (currentNode->data > node)
                currentNode = currentNode->left;
            else
                currentNode = currentNode->right;
        }
        if (parentNode->data > node)
            parentNode->left = newNode;
        else
            parentNode->right = newNode;
    }
    return root;
}

void print(b_tree root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        print(root->left);
        print(root->right);
    }
}