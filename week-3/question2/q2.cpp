// Assumption : empty subarray is not considered, if we need to consider empty 
// subarray, then base case should return {0,0,0,arr[l]} when arr[l] < 0

#include<bits/stdc++.h>
using namespace std;

struct array_data
{
    long long max_subarray_sum; 
    long long max_prefix; 
    long long max_suffix; 
    long long sum; 
}; 

array_data get_max_subarray(vector<int> &arr, int l, int r)
{
    // base case
    if(r-l == 1) 
    {
        return {arr[l],arr[l],arr[l],arr[l]}; 
    }
    int mid = l + (r-l)/2; 
    array_data left_data = get_max_subarray(arr,l,mid); 
    array_data right_data = get_max_subarray(arr,mid,r); 
    array_data result;  
    result.max_subarray_sum = max({left_data.max_subarray_sum, right_data.max_subarray_sum, left_data.max_suffix + right_data.max_prefix}); 
    result.max_prefix = max({left_data.max_prefix, left_data.sum + right_data.max_prefix}); 
    result.max_suffix = max({right_data.max_suffix, right_data.sum + left_data.max_suffix}); 
    result.sum = left_data.sum + right_data.sum;  
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  

    int n; cin>>n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i]; 
    }
    array_data result = get_max_subarray(arr,0,n); 
    cout<<"Max subarray sum is: "; 
    cout<<result.max_subarray_sum<<"\n";  
}