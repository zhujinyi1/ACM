//马拦过河卒

/*
    1.递归算法，当n，m>=15时必定超时，所以不能使用递归
#include<iostream>
using namespace std;
#define maxn 25
int n = 0;
int x1,y1,x2,y2;

void search(int x0,int y0){
    if(x0==x1&&y0==y1){
        n++;
        return;
    }
    if(x0>x1||y0>y1){
        return;
    }
    if(((x0==x2-1||x0==x2+1)&&(y0==y2+2||y0==y2-2))||((x0==x2-2||x0==x2+2)&&(y0==y2-1||y0==y2+1))||(x0==x2&&y0==y2)){
        return;
    }
    search(x0+1,y0);
    search(x0,y0+1);
}

int main(){
    int x0,y0;
    x0 = y0 = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    search(x0,y0);
    cout << n << endl;
    return 0;
}
*/

/*
    思想：x[i][j] = x[i-1][j]+x[i][j-1];
        令到达马可以触及到的点的路径为0
*/
#include <iostream>
using namespace std;
#define maxn 100
bool b[maxn][maxn];
long long a[maxn][maxn];
int m, n, x, y;

int main()
{
    int i, j;
    cin >> m >> n >> x >> y;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (((i == x - 2 || i == x + 2) && (j == y - 1 || j == y + 1)) || ((i == x - 1 || i == x + 1) && (j == y - 2 || j == y + 2)) || (i == x && j == y))
            {
                b[i][j] = 1;
                a[i][j] = 0;
            }
            else
            {
                b[i][j] = 0;
                if (!b[i][0])
                {
                    a[i][0] = 1;
                }
                if (!b[0][j])
                {
                    a[0][j] = 1;
                }
            }
        }
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(b[i][j]){
                a[i][j] = 0;
            }
            if(!b[i][j]){
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
    }
    cout << a[m][n] << endl;
    return 0;
}