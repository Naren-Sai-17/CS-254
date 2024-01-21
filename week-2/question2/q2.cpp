// Time complexity : O(n*n) 
// Space complexity : O(1)  

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);

    int m, n;
    cin >> m >> n;
    vector<int> arr(m + n);
    for (int i = 0; i < m + n; i++)
    {
        cin >> arr[i];
    }
    int it1 = 0, it2 = m;
    int l = 0, r = 0;
    while(l!=m && r!=n)
    {
        if(arr[it1] <= arr[it2])
        {
            l++; 
            it1++; 
        }
        else
        {
            r++; 
            int key = arr[it2]; 
            for(int i = it2; i > l + r - 1; i--)
            {
                arr[i] = arr[i-1]; 
            }
            arr[l+r-1] = key; 
            it1++; 
            it2++; 
        }
    }
    cout << "Merged array is: ";
    for (int &element : arr)
    {
        cout << element << " ";
    }
    cout << "\n";
}