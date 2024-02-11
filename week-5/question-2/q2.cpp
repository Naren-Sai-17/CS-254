#include<bits/stdc++.h>
using namespace std; 

inline pair<int,int> get_cell(int num, int n)
{
    --num; 
    int x = num/n; 
    int y; 
    if(x%2 == 0) y = num%n; 
    else y = n-1-(num%n); 
    x = n-1-x; 
    return make_pair(x,y); 
}

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size(); 
    queue<int> q; 
    vector<int> dist(n*n + 1, -1); 
    dist[1] = 0; 
    q.push(1); 
    while(!q.empty())
    {
        auto v = q.front(); 
        q.pop(); 
        auto cords = get_cell(v,n); 
        for(int del = 1; del <= 6 && v + del <= n*n; del++)
        {
            int location = v + del;
            auto cords = get_cell(location,n); 
            if(board[cords.first][cords.second] != -1)
            {
                location = board[cords.first][cords.second]; 
                cords = get_cell(location,n); 
            }
            if(dist[location] == -1)
            {
                dist[location] = dist[v] + 1; 
                q.push(location); 
            }
        }
    } 
    return dist[n*n];    
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n; 
        vector<vector<int>> board(n,vector<int>(n)); 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>board[i][j]; 
            }
        }
        cout<<snakesAndLadders(board)<<"\n";
    }
}