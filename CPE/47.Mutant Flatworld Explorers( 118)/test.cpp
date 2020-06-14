#include<cstdio>
#include<cstring>
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, dr[4] = {'N', 'E', 'S', 'W'};

int main()
{
    bool lostpos[51][51] = {0};
    int x, y, w, h, len, dir, i;
    bool ok;
    char s[101], c;
    scanf("%d%d", &w, &h);
    while (~scanf("%d%d %c\n", &x, &y, &c))
    {
        ok = true;
        switch (c)// 初始化机器人方向
        {
        case 'N':
            dir = 0;
            break;
        case 'E':
            dir = 1;
            break;
        case 'S':
            dir = 2;
            break;
        case 'W':
            dir = 3;
            break;
        }
        gets(s);
        len = strlen(s);
        for (i = 0; i < len && ok; ++i)
        {
            switch (s[i])
            {
            case 'R'://右转
                dir = (dir + 1) % 4;
                break;
            case 'L'://左转
                dir = (dir + 3) % 4;
                break;
            case 'F'://向前走
                if ((x + dx[dir] > w) || (y + dy[dir] > h) || (x + dx[dir] < 0) || (y + dy[dir] < 0))
                {
                    if (!lostpos[x][y])//出界
                    {
                        printf("%d %d %c LOST\n", x, y, dr[dir]);
                        ok = false, lostpos[x][y] = true;
                    }
                }
                else
                    x += dx[dir], y += dy[dir];
                break;
            }
        }
        if (ok)
            printf("%d %d %c\n", x, y, dr[dir]);
    }
    return 0;
}
