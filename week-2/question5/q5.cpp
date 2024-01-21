// Time complexity : O(n) 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input5.txt","r",stdin); 
    freopen("output5.txt","w",stdout); 
    
    int n; cin>>n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i]; 
    }
    int mn1 = INT_MAX, mn2 = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(mn1 > arr[i])
        {
            mn2 = mn1;
            mn1 = arr[i]; 
        }
        else if(mn2 > arr[i])
        {
            mn2 = arr[i]; 
        }
    }
    cout<<"Two smallest elements are: "; 
    cout<<mn1<<" "<<mn2<<"\n";
}