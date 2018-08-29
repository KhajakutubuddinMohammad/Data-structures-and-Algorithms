# Data-structures-and-Algorithms
Data structures and Algorithms
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    int sum=0,max1=INT_MIN,size,k;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>k;
        a.push_back(k);
    }
    for(int i=0;i<a.size();i++)
    {
         sum=max(a[i],a[i]+sum);
         if(sum > max1)
                max1=sum;
    }
    cout<<"max sum of subarray is:"<<max1<<endl;
}
