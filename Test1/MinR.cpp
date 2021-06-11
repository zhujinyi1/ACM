//P4779 【模板】单源最短路径（标准版） 堆优化


#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 100005
#define maxm 200005
#define INF 0x7fffffff
int n, m, s;
long long dis[maxn];
bool vis[maxn];
int head[maxn], cnt = 0;
struct edge
{
    int v, next;
    long long w;
} e[maxm];
void add(int u, int v, long long w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
struct node
{
    int id;
    long long dis;
    bool operator<(const node &tem) const
    {
        if (this->dis == tem.dis)
            return this->id < tem.id;
        return this->dis > tem.dis;
    }
};
priority_queue<node> q;       //优先队列
void dijkstra()
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    q.push(node{s, dis[s]});
    while (q.size())
    {
        int now = q.top().id;
        q.pop();
        if (vis[now])
            continue;
        vis[now] = 1;
        for (int i = head[now]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (vis[v])
                continue;
            if (dis[now] + e[i].w < dis[v])
            {
                dis[v] = dis[now] + e[i].w;
                q.push(node{v, dis[v]});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> s;
    int u, v;
    long long w;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}