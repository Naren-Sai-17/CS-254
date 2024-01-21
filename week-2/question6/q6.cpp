// Average time complexity : O(n*log(n))
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
    if(d+1-l == k) return d; 
    else if(d+1-l > k)
    {
        return find_kth_smallest(arr,l,d-1,k); 
    }
    else
    {
        return find_kth_smallest(arr,d+1,r,k-(d+1-l)); 
    }
}

void quicksort(vector<int> &arr, int l, int r)
{
    if(r-l <= 1) return;
    int size = (r-l+1); 
    find_kth_smallest(arr,l,r,size/2); 
    quicksort(arr, l, l + size/2 - 1);
    quicksort(arr, l + size/2, r);
}

int main()
{
    freopen("input6.txt", "r", stdin); 
    freopen("output6.txt", "w", stdout); 
    int n; cin>>n;
    vector<int> arr(n); 
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i]; 
    }
    quicksort(arr,0,n-1); 
    cout<<"Sorted array is: "; 
    for(int &element : arr)
    {
        cout<<element<<" "; 
    }
    cout<<"\n";
}