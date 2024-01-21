// Average Time complexity : O(n)
// Worst case time complexity : O(n*n)  

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[r]; 
    int j = l;
    for (int i = l; i < r; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    swap(arr[j], arr[r]);
    return j;
}

int random_partition(vector<int> &arr, int l, int r)
{
    int n = r - l + 1; 
    int pivot = rand()%n; 
    swap(arr[l + pivot], arr[r]); 
    return partition(arr,l,r); 
}

int find_kth_smallest(vector<int> &arr, int l, int r, int k)
{
    int d = random_partition(arr,l,r);
    if(d+1-l == k) return arr[d]; 
    else if(d+1-l > k)
    {
        return find_kth_smallest(arr,l,d-1,k); 
    }
    else
    {
        return find_kth_smallest(arr,d+1,r,k-(d+1-l)); 
    }
}

int main()
{
    freopen("input4.txt", "r", stdin); 
    freopen("output4.txt", "w", stdout); 
    int n; cin>>n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i]; 
    }
    cout<<"Median element is: ";
    if(n%2 == 1)
    {
        cout<<find_kth_smallest(arr,0,n-1,(n+1)/2); 
    }
    else
    {
        cout<<(find_kth_smallest(arr,0,n-1,n/2) + find_kth_smallest(arr,0,n-1,n/2+1))/2.0; 
    }
}