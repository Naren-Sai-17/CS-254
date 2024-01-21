// Time complexity : O(n*n*log(n)) 
// Space complexity : O(1)   

#include<bits/stdc++.h>
using namespace std;

void inplace_merge(vector<int> &arr, int start, int m, int n)
{
    int it1 = 0, it2 = m;
    int l = 0, r = 0;
    while(l!=m && r!=n)
    {
        if(arr[start + it1] <= arr[start + it2])
        {
            l++; 
            it1++; 
        }
        else
        {
            r++; 
            int key = arr[start + it2]; 
            for(int i = it2; i > l + r - 1; i--)
            {
                arr[start + i] = arr[start + i-1]; 
            }
            arr[start + l+r-1] = key; 
            it1++; 
            it2++; 
        }
    }
}

void merge_sort(vector<int> &arr, int l, int r)
{
    if(r-l <= 1) return;
    int mid = l + (r-l)/2; 
    merge_sort(arr,l,mid); 
    merge_sort(arr,mid,r); 
    inplace_merge(arr,l,mid-l,r-mid); 
}

int main()
{
    freopen("input3.txt", "r", stdin); 
    freopen("output3.txt", "w", stdout); 

    int n; cin>>n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i]; 
    }
    merge_sort(arr,0,n); 
    cout<<"Sorted array is: "; 
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" "; 
    }
    cout<<"\n"; 
}