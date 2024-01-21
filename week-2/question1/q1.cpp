// Time complexity : O(n+m) 

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, vector<int> &b)
{
    int m = a.size(); 
    int n = b.size(); 
    int it1 = 0, it2 = 0; 
    int it = 0; 
    while(it1 != m && it2 != n)
    {
        if(a[it1] <= b[it2])
        {
            cout<<a[it1++]<<" "; 
        }
        else
        {
            cout<<b[it2++]<<" "; 
        }
    }
    while(it1 != m)
    {
        cout<<a[it1++]<<" "; 
    }
    while(it2 != n)
    {
        cout<<b[it2++]<<" "; 
    }
    cout<<"\n"; 
}

void union_arrays(vector<int> &a, vector<int> &b)
{
    int m = a.size(); 
    int n = b.size(); 
    int prev = INT_MIN;
    int printed = false; 
    int it1 = 0, it2 = 0;
    while(it1 != m && it2 != n)
    {
        int val; 
        if(a[it1] <= b[it2])
        {
            val = a[it1++]; 
        }
        else
        {
            val = b[it2++]; 
        }
        if(val != prev)
        {
            cout<<val<<" "; 
            prev = val; 
        }
    }
    while(it1 != m)
    {
        int val = a[it1++]; 
        if(val != prev)
        {
            cout<<val<<" "; 
            prev = val; 
        }
    }
    while(it2 != n)
    {
        int val = b[it2++]; 
        if(val != prev)
        {
            cout<<val<<" "; 
            prev = val; 
        }
    }
    cout<<"\n"; 
}

void intersection_arrays(vector<int> &a, vector<int> &b)
{
    int it = 0;
    for(int i = 0; i < a.size() && it != b.size(); i++)
    {
        if(a[i] < b[it])
        {
            continue; 
        }
        if(a[i] == b[it])
        {
            cout<<a[i]<<" "; 
        }
        // update int it to point to bigger value of b 
        do
        {
            it++; 
        }
        while(it!=a.size() && b[it-1] == b[it]); 
    }
    cout<<"\n";
}

int main()
{
    freopen("input1.txt", "r", stdin); 
    freopen("output1.txt", "w", stdout); 

    int m,n; cin>>m>>n;
    vector<int> a(m), b(n); 
    for(int i = 0; i < m; i++)
    {
        cin>>a[i]; 
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i]; 
    }
    cout<<"Merged array is: \n"; 
    merge(a,b); 
    cout<<"Union array is: \n"; 
    union_arrays(a,b); 
    cout<<"Intersection array is: \n"; 
    intersection_arrays(a,b);  
}