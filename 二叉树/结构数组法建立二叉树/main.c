#include <stdio.h>
#include <stdlib.h>
#define MAXN 32768

int n;
typedef struct tree
{
    int Left;
    int Data;
    int Right;
} treenode;
treenode b_tree[MAXN];

void create(int *node, int len)
{
    int i;
    int level, position;

    for (i = 1; i <= len; ++i)
    {
        b_tree[i].Data = node[i];
        level = 0;
        position = 0;
        while (position == 0) //记录左右子树
        {
            if (node[i] > b_tree[level].Data) //右子树
            {
                if (b_tree[level].Right != -1)
                    level = b_tree[level].Right;
                else
                    position = -1;
            }
            else //左子树
            {
                if (b_tree[level].Left != -1)
                    level = b_tree[level].Left;
                else
                    position = 1;
            }
        }
        if (position == 1)
            b_tree[level].Left = i;
        else
            b_tree[level].Right = i;
    }
}

void print()
{
    int i;

    for (i = 1; i <= n; ++i)
        printf("%d %d %d\n", b_tree[i].Left, b_tree[i].Data, b_tree[i].Right);
}

int main(int argc, char *argv[])
{
    freopen("arraytree.in", "r", stdin);
    freopen("arraytree.out","w", stdout);

    int i;
    scanf("%d", &n);
    int node[n+1];

    for(i = 1;i<=n;++i)
        scanf("%d",&node[i]);
    
    for(i = 0; i < MAXN;++i)
    {
        b_tree[i].Left = -1;
        b_tree[i].Data = 0;
        b_tree[i].Right = -1;
    }
    create(node, n);
    print();
    return EXIT_SUCCESS;
}