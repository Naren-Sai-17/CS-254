// time complexity : O(log(min(n,m))) 
// space complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &arr1, vector<int> &arr2)
{
    if (arr1.size() > arr2.size())
        return findMedian(arr2, arr1);
    int total = arr1.size() + arr2.size();  
    int partition_size = total/2; 
    double median; 
    int l = 0;    
    int r = arr1.size(); 
    while(r-l >= 0)
    {
        int mid1 = l + (r-l)/2; 
        int mid2 = partition_size - mid1; 
        int left1, right1, left2, right2; 
        if(mid1 > 0) left1 = arr1[mid1 - 1]; 
        else left1 = INT_MIN; 
        if(mid2 > 0) left2 = arr2[mid2 - 1]; 
        else left2 = INT_MIN; 
        if(mid1 < arr1.size()) right1 = arr1[mid1];  
        else right1 = INT_MAX; 
        if(mid2 < arr2.size()) right2 = arr2[mid2]; 
        else right2 = INT_MAX; 
        if(max(left1,left2) <= min(right1,right2))
        {
            if(total % 2 == 0)
            {
                median = (max(left1,left2) + min(right1,right2))/2.0; 
            }
            else
            {
                median = min(right1,right2); 
            }
            break; 
        }
        else if(left1 > right2) 
        {
            r = mid1 - 1;
        }
        else if(left2 > right1)
        {
            l = mid1 + 1; 
        }
    }   
    return median; 
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 

    int m,n; cin>>m>>n;
    vector<int> arr1(m); 
    vector<int> arr2(n); 
    for(int i = 0; i < m; i++) 
    {
        cin>>arr1[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin>>arr2[i]; 
    }
    cout<<fixed<<findMedian(arr1,arr2);
}