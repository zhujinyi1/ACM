#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff
#define maxn 5005
#define maxm 200005
int M, N;
int mp[maxn][maxn];
int vis[maxn];
int dis[maxn];

int prim()
{
    int i, j, now = 1;
    for(i = 1;i<=N;i++){
        dis[i] = INF;
        vis[i] = 0;
    }
    vis[1] = 1;
    int minlength = INF;
    for (i = 1; i <= N; i++)
    {
        dis[i] = min(mp[now][i], dis[i]);
    }
    int tot = 0;
    int minl = 0;
    while (tot < N - 1)
    {
        minlength = INF;
        for (i = 1; i <= N; i++)
        {
            if (!vis[i] && dis[i] < minlength)
            {
                minlength = dis[i];
                now = i;
            }
        }
        if(minlength ==INF){
            return -1;
        }
        vis[now] = 1;
        minl += minlength;
        tot++;
        for (i = 1; i <= N; i++)
        {
            if (mp[now][i] != INF && !vis[i])
            {
                dis[i] = min(dis[i], mp[now][i]);
            }
        }
    }
    return minl;
}

int main()
{
    int i,j, a, b, c;
    cin >> N >> M;
    for(i = 1;i<=N;i++){
        for(j = 1;j<=N;j++){
            mp[i][j] = INF;
        }
    }
    for (i = 1; i <= M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        mp[a][b] = min(mp[a][b], c);
        mp[b][a] = min(mp[b][a], c);
    }
    int p = prim();
    if (p == -1)
    {
        cout << "orz" << endl;
    }
    else
    {
        cout << p << endl;
    }
    return 0;
}