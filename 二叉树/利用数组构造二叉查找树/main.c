#include <stdio.h>
#include <stdlib.h>
#define MAXN 32768

int tree[MAXN];

int create(int _tree[], int _node[], int len)
{
    int i, MAX = 1;

    _tree[1] = _node[1]; //设定根节点

    int level = 1; //父节点在数组中的位置（从1开始）

    for (i = 2; i <= len; ++i)
    {
        level = 1;
        while (_tree[level] != 0)
        {
            if (_node[i] < _tree[level])
                level = level * 2;
            else
                level = level * 2 + 1;

            if (MAX < level) //结点平铺在数组中的最大范围
                MAX = level;
        }
        _tree[level] = _node[i];
    }
    return MAX;
}

int main(int argc, char *argv[])
{
    freopen("arraytree.in", "r", stdin);
    freopen("arraytree.out", "w", stdout);
    int i, n, num;
    scanf("%d", &n);
    int node[n + 1];

    for (i = 1; i <= n; ++i)
        scanf("%d", &node[i]);

    num = create(tree, node, n);

    for (i = 1; i <= num; ++i)
        printf("%d ", tree[i]);

    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}