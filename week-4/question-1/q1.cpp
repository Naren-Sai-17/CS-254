// time complexity - nlog(n)
// space complexity - nlog(n)

#include<bits/stdc++.h>
using namespace std;

using i64 = long long; 

i64 merge(vector<int> &arr, int l, int mid, int r)
{
    i64 inversions = 0; 
    vector<int> left(mid - l); 
    vector<int> right(r - mid); 
    for(int i = l; i < mid; i++)
    {
        left[i-l] = arr[i]; 
    }
    for(int i = mid; i < r; i++)
    {
        right[i-mid] = arr[i]; 
    }
    int it1 = 0; 
    int it2 = 0; 
    int it = l; 
    while(it1 != left.size() && it2 != right.size())
    {
        if(left[it1] <= right[it2]) 
        {
            arr[it++] = left[it1++]; 
        }
        else
        {
            inversions += (left.size() - it1); 
            arr[it++] = right[it2++]; 
        }
    }
    while(it1 != left.size())
    {
        arr[it++] = left[it1++]; 
    }
    while(it2 != right.size())
    {
        inversions += (left.size() - it1); 
        arr[it++] = right[it2++]; 
    }
    return inversions; 
}

// l inclusive r exclusive
// returns number of inversions 
i64 merge_sort(vector<int> &arr, int l, int r)
{

    // base case -> 0 inversions 
    if(r-l == 1) return 0; 
    i64 inversions = 0; 
    int mid = (l+r)/2; 
    inversions += merge_sort(arr,l,mid); 
    inversions += merge_sort(arr,mid,r); 
    inversions += merge(arr,l,mid,r); 
    return inversions; 
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 

    int n; cin>>n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i]; 
    }
    cout<<merge_sort(arr,0,n)<<"\n"; 
}