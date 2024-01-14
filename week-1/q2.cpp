// Time complexity - O(num_items * max_weight) 
// Space complexity - O(max_weight) 

// Input format 

/*
number of test cases 

for each test case :
    number of items 
    weight list 
    value list 
    knapsack weight 
*/

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int num_items; 
    cin>>num_items; 
    vector<int> weights(num_items) , values(num_items); 
    for(int i = 0; i < num_items; i++)
    {
        cin>>weights[i]; 
    }
    for(int i = 0; i < num_items; i++)
    {
        cin>>values[i]; 
    }
    int max_weight; cin>>max_weight; 

    int dp[max_weight+1]; 
    memset(dp,0,sizeof(dp)); 
    for(int i = 0; i < num_items; i++)
    {
        for(int j = max_weight; j >= 0; j--)
        {
            if(j - weights[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]); 
            }
        }
    }
    cout<<dp[max_weight]<<"\n"; 
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input2.txt", "r", stdin); 
    freopen("output2.txt", "w", stdout); 

    int test_cases; 
    cin>>test_cases;
    for(int test_case = 1; test_case <= test_cases; test_case++)
    {
        cout<<"Test "<<test_case<<": "; 
        solve(); 
    }
}
