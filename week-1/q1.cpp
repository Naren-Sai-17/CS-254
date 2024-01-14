// Time complexity - O(n) 
// Space complexity - O(1)

/*
Input format: 
number of test cases 

for each test case: 
    size of array 
    elements of array 
*/
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int list_size; 
    cin>>list_size; 
    vector<int> list(list_size); 
    for(int &element: list) cin>>element; 
    int max1 = INT_MIN, max2 = INT_MIN; 
    for(int &element: list)
    {
        if(element > max1)
        {
            max2 = max1; 
            max1 = element; 
        }
        else if(element > max2)
        {
            max2 = element; 
        }
    }
    cout<<max1 + max2<<"\n"; 
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input1.txt","r",stdin); 
    freopen("output1.txt","w",stdout); 
    
    int test_cases; 
    cin>>test_cases; 
    for(int test_case = 1; test_case <= test_cases; test_case++)
    {
        cout<<"Test "<<test_case<<": "; 
        solve(); 
    }
}