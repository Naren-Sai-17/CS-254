// Time complexity : O(n^2 * 2^n) NP-hard problem 
// Space complexity : O(n * 2^n)
// Concept : Bitmask DP 
// Input format : 
/*
number of test cases 

for each test case: 
    number of cities
    distance matrix 
*/

#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9; 

void solve()
{
    int num_cities; cin>>num_cities; 
    int dist[num_cities][num_cities]; 
    for(int i = 0; i < num_cities; i++)
    {
        for(int j = 0; j < num_cities; j++)
        {
            cin>>dist[i][j]; 
        }
    }
    
    int dp[1 << num_cities][num_cities]; 
    for(int i = 0; i < (1<<num_cities); i++)
    {
        for(int j = 0; j < num_cities; j++)
        {
            dp[i][j] = inf; 
        }
    }

    dp[1][0] = 0; 
    for(int mask = 1; mask < (1<<num_cities); ++mask)
    {
        for(int end_point = 0; end_point < num_cities; end_point++)
        {
            if((mask & (1<<end_point)) != 0)
            {
                for(int intermediate = 0; intermediate < num_cities; ++intermediate)
                {
                    if(((mask & (1<<intermediate)) != 0) && intermediate != end_point)
                    {
                        dp[mask][end_point] = min(dp[mask][end_point], dp[mask ^ (1<<end_point)][intermediate] + dist[intermediate][end_point]); 
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int end = 0; end < num_cities; end++)
    {
        ans = min(ans, dp[(1<<num_cities) - 1][end] + dist[end][0]); 
    }

    cout<<ans<<"\n"; 
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input3.txt", "r", stdin); 
    freopen("output3.txt", "w", stdout); 
    
    int test_cases; 
    cin>>test_cases; 
    for(int test_case = 1; test_case <= test_cases; test_case++)
    {
        cout<<"Test "<<test_case<<": "; 
        solve(); 
    }
}