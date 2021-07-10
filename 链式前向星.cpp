//链式前向星 

#include<iostream>
using namespace std;

struct e{
	int to,v,next; 
}Edge;

struct e edge[10005];
int tot = 1,head[1005]; 

void build(int u, int v , int w ){
	edge[tot].v = v;
	edge[tot].to = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void display(){
	for(int i = 0;i<1005;i++){
		for(int j = head[i];~j;j = edge[j].next){
			 cout << i << "->" << edge[j].to << ":" << edge[j].v << " "; 
		}
	}
}

int main(){
	int m,n;
	int u,v,w;
	for(int i = 0;i<1005;i++){
		head[i] = -1;
	}
	cout << "输入节点数和边的数量：" << endl;
	cin >> n >> m;
	cout << "输入" << m << "条边:" << endl;
	for(int i=1 ; i<=m ; i++){
		cin >> u >> w >> v ;
		build(u,v,w); 
	}
	display();
	return 0;
} 
