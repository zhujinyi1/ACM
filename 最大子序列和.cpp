#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,a[maxn];
int sum = -1;
int m = 0;

int main(){
	cin >> n;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i<=n;i++){
		m+=a[i];
		if(m>sum){
			sum = m;
		}
		if(m<0){
			m = 0;
		}
	}
	cout << sum << endl;
} 
