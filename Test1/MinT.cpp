//克鲁斯卡尔算法
//洛谷 3366
#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 5005
#define maxm 200005

int n,m;
int f[maxn];
struct edge{
    int u,v,w;
}e[maxn];

bool cmp(edge x,edge y){
    return x.w<y.w;
}

int find(int x){
    if(x==f[x]) return f[x];
    return f[x] = find(f[x]);
}

int main(){
    cin >> n,m;
    int i;
    for(i = 1;i<=n;i++){
        f[i] = i;
    }
    int tot = 0;
    long long ans = 0;
    for(i = 1;i<=m;i++){
        int u = e[i].u,v = e[i].v;
        int fu = find(u),fv = find(v);
        if(fu = fv) continue;
        tot++;
        f[fv] = fu;
        ans+=e[i].w;
        if(tot == n-1) break;
    }
    if(tot!=n-1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}