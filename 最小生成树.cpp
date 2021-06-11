#include<bits/stdc++.h>
using namespace std;

#define maxn 5005
#define maxm 200005
#define INF 0x7fffffff

int i,j;                   //循环变量 
int n,m;                   //点数和路径数 
int mp[maxn][maxn];        //邻接矩阵 
bool vis[maxn];            //记录是否访问过 
int dis[maxn];             //记录各点的最短路 

int prim(){
	for(i = 0;i < n;i++) dis[i] = INF;
	dis[1] = 0;
	vis[1] = 1;
	int now = 1;
	for(i = 0;i < n;i++){
		dis[i] = min(dis[i],mp[now][i]);
	}
	int tot = 0;
	while(tot < n-1){
		int minpath = INF;
		for(i = 0;i<n;i++){
			if(vis[i]!=0){
				minpath = min(dis[i],minpath);
			}
				
		}
		if(minpath==INF) return -1;
	}
}

int main(){
	int u,v,w;
	cin >> n >> m;
	for(i = 0;i<n;i++){
		for(j = 0;j<n;j++){
			mp[i][j] = INF;
		}
	}
	for(i = 0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v] = min(mp[u][v],w);
		mp[v][u] = min(mp[u][v],w);
	}
	int ans = prim();
	if(ans == -1)
		cout << "orz";
	else
		cout << ans;
	return 0;
}
