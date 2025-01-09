#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int BIT[N][N];
bool vis[N][N];
void update(int x, int y, int val)
{
    for (int i = x; i <= 1001; i += (i & -i))
    {
        for (int j = y; j <= 1001; j += (j & -j))
        {
            BIT[i][j] += val;
        }
    }
}
long long sum(int x, int y)
{
    long long sum = 0;
    for (int i = x; i > 0; i -= (i & -i))
    {
        for (int j = y; j > 0; j -= (j & -j))
        {
            sum += BIT[i][j];
        }
    }
    return sum;
}
void reset(){
    memset(BIT,0,sizeof(BIT));
    memset(vis,false,sizeof(vis));
}
void solve()
{
    reset();
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int x, y;
            cin >> x >> y;
            ++x;++y;
            if (!vis[x][y])
            {
                update(x, y, 1);
                vis[x][y] = true;
            }
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ++x1;++x2;++y1;++y2;
            cout << sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1) << '\n';
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tst;
    cin >> tst;
    for (int t = 1; t <= tst; ++t)
    {
        cout << "Case " << t << ":\n";
        solve();
    }
}