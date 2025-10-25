#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char direction;
int s[4][4] = {0};
void show(int a[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}
void wmove(int a[4][4])
{
    int i, j, h;
    for (h = 0; h < 3; h++) // 移动
        for (i = 1; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (a[i - 1][j] == 0)
                {
                    a[i - 1][j] = a[i][j];
                    a[i][j] = 0;
                }
    for (i = 1; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i - 1][j] == a[i][j]) // 合并
            {
                a[i - 1][j] = 2 * a[i][j];
                a[i][j] = 0;
            }
    for (h = 0; h < 3; h++) // 移动
        for (i = 1; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (a[i - 1][j] == 0)
                {
                    a[i - 1][j] = a[i][j];
                    a[i][j] = 0;
                }
}
void smove(int a[4][4])
{
    int i, j, h;
    for (h = 0; h < 3; h++) // 移动
        for (i = 0; i < 3; i++)
            for (j = 0; j < 4; j++)
                if (a[i + 1][j] == 0)
                {
                    a[i + 1][j] = a[i][j];
                    a[i][j] = 0;
                }
    for (i = 1; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i + 1][j] == a[i][j]) // 合并
            {
                a[i + 1][j] = 2 * a[i][j];
                a[i][j] = 0;
            }
    for (h = 0; h < 3; h++) // 移动
        for (i = 1; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (a[i + 1][j] == 0)
                {
                    a[i + 1][j] = a[i][j];
                    a[i][j] = 0;
                }
}
void amove(int a[4][4])
{
    int i, j, h;
    for (h = 0; h < 3; h++) // 移动
        for (i = 0; i < 4; i++)
            for (j = 1; j < 4; j++)
                if (a[i][j - 1] == 0)
                {
                    a[i][j - 1] = a[i][j];
                    a[i][j] = 0;
                }
    for (i = 1; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i][j - 1] == a[i][j]) // 合并
            {
                a[i][j - 1] = 2 * a[i][j];
                a[i][j] = 0;
            }
    for (h = 0; h < 3; h++) // 移动
        for (i = 1; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (a[i][j - 1] == 0)
                {
                    a[i][j - 1] = a[i][j];
                    a[i][j] = 0;
                }
}
void dmove(int a[4][4])
{
    int i, j, h;
    for (h = 0; h < 3; h++) // 移动
        for (i = 0; i < 4; i++)
            for (j = 0; j < 3; j++)
                if (a[i][j + 1] == 0)
                {
                    a[i][j + 1] = a[i][j];
                    a[i][j] = 0;
                }
    for (i = 1; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i][j + 1] == a[i][j]) // 合并
            {
                a[i][j + 1] = 2 * a[i][j];
                a[i][j] = 0;
            }
    for (h = 0; h < 3; h++) // 移动
        for (i = 1; i < 4; i++)
            for (j = 0; j < 4; j++)
                if (a[i][j + 1] == 0)
                {
                    a[i][j + 1] = a[i][j];
                    a[i][j] = 0;
                }
}
void create(int a[4][4])
{
    int i, j, x, n;
    for (n = 0; n < 2; n++)
    {
        do
        {
            i = rand() % 4;
            j = rand() % 4;
        } while (a[i][j] != 0);
        x = rand() % 2 + 1;
        a[i][j] = 2 * x;
    }
}
int judje(int a[4][4]) // win=1 lose=0 continue 2
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == 2048)
                return 1;
            if (a[i][j] == 0)
                return 2;
        }
    }
    return 0;
}
int main(void)
{
    srand(time(0));
start:
    create(s);             // 创建新数字
    show(s);               // 显示
    direction = getchar(); // 输入方向
    while (getchar() != '\n')
        ;
    switch (direction) // 移动
    {
    case 'w':
        wmove(s);
        break;
    case 's':
        smove(s);
        break;
    case 'a':
        amove(s);
        break;
    case 'd':
        dmove(s);
        break;
    }
    if (judje(s) == 0) // 判断输赢
    {
        printf("you lose!");
        getchar();
        return 0;
    }
    if (judje(s) == 1)
    {
        printf("you win!");
        getchar();
        return 0;
    }
    if (judje(s) == 2)
    {
        printf("________________\n");
        goto start;
    }
}