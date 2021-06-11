//P3366 【模板】最小生成树 prim 链式前向星
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 5005
#define maxm 200005
#define INF 0x7fffffff
int n, m;
bool vis[maxn];
int dis[maxn];
int head[maxn], cnt;
struct edge
{
    int v, w, next;
} e[maxm << 1];
void add(int u, int v, int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
int prim()
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[1] = 0;
    vis[1] = 1;
    int sum = 0, now = 1;
    int tot = 0;
    for (int i = head[now]; i; i = e[i].next)
    {
        int v = e[i].v;
        dis[v] = min(dis[v], e[i].w);
    }
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
        vis[now] = 1;
        sum += minPath;
        tot++;
        for (int i = head[now]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (vis[v])
                continue;
            dis[v] = min(dis[v], e[i].w);
        }
    }
    return sum;
}
int main()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    int ans = prim();
    if (ans == -1)
        cout << "orz";
    else
        cout << ans;
    return 0;
}