#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input6.txt", "w", stdout); 
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distrib(0, 100000);
    int n = 1e5;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = distrib(rng); 
    }
    cout<<n<<"\n"; 
    for(int x:a) cout<<x<<" "; 
    cout<<"\n";  
}