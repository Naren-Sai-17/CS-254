#include<bits/stdc++.h>
using namespace std;

int dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis, int n, int m)
{
    if(x < 0 || y < 0 || x >= n || y >= m) return 0; 
    if(vis[x][y]) return 0; 
    vis[x][y] = true;
    if(grid[x][y] == '0') return 0;  
    int ans = 1; 
    for(int del_x = -1; del_x <= 1; del_x++)
    {
        for(int del_y = -1; del_y <= 1; del_y++)
        {
            ans += dfs(x + del_x, y + del_y, grid, vis, n, m); 
        }
    }
    return ans; 
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 

    int n,m; cin>>n>>m; 
    vector<vector<char>> grid(n,vector<char>(m)); 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            cin>>grid[i][j]; 
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m)); 
    int ans = 0; 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1' && !vis[i][j])
            {
                ans = max(ans,dfs(i,j,grid,vis,n,m)); 
            }
        }
    }
    cout<<ans<<"\n"; 
}