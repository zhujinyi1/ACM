#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int m,n,r,c,p[10005], x;
    int t[2][10005];
    cin >> x;
    int i;
    for (i = 0; i < x; i++)
    {
        cin >> m >> n >> r >> c;
        p[i] = max(fabs(m+n-r-c),fabs(m+1-r-c));
        p[i] = max(int(fabs(2-r-c)),p[i]);
        p[i] = max(int(fabs(n+1-r-c)),p[i]);
    }
    for(i = 0;i<x;i++){
        cout << p[i] << endl;
    }
    return 0;
}
