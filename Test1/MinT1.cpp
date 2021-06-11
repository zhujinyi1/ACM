//prim算法
//P3366 【模板】最小生成树 prim 邻接矩阵
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 5005
#define maxm 200005
#define INF 0x7fffffff
int n, m;
int mp[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int prim()
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[1] = 1;
    vis[1] = 1;
    int now = 1;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = min(dis[i], mp[now][i]);
    }
    int tot = 0;
    int sum = 0;
    while (tot < n - 1)
    {
        int minPath = INF;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dis[i] < minPath)
            {
                now = i;
                minPath = dis[i];
            }
        }
        if (minPath == INF)
            return -1;
        tot++;
        sum += minPath;
        vis[now] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (mp[now][i] != INF && !vis[i])
            {
                dis[i] = min(dis[i], mp[now][i]);
            }
        }
    }
    return sum;
}
int main()
{
    cin >> n >> m;
    int i, j, u, v, w;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            mp[i][j] = INF;
        }
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        mp[u][v] = min(mp[u][v], w);
        mp[v][u] = min(mp[v][u], w);
    }
    int ans = prim();
    if (ans == -1)
        cout << "orz";
    else
        cout << ans;
    return 0;
}