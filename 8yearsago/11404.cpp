#include <iostream>
#define MAX 101
#define INF 999999999999999999
using namespace std;

int n, m;
long long dp[MAX][MAX];

void InData()
{
    cin >> n;
    cin >> m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j)
                dp[i][j] = INF;
        }
    }

    int from, to, cost;
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to >> cost;
        if(dp[from][to] > cost)
            dp[from][to] = cost;
    }
}

int main()
{
    InData();

    for(int k = 1; k <= n; k++)  // pass stop
    {
        for(int i = 1; i <= n; i++)  // from
        {
            for(int j = 1; j <= n; j++)  // to
            {
                if(dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dp[i][j] == INF) dp[i][j] = 0;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
