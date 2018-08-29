# Data-structures-and-Algorithms
Data structures and Algorithms
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> a={-1,-2,-3,2,6,-4,5,7,-1,-8,15};
    int sum=0,max1=INT_MIN;
    for(int i=0;i<a.size();i++)
    {
         sum=max(a[i],a[i]+sum);
         if(sum > max1)
                max1=sum;
    }
    cout<<"max sum of subarray is:"<<max1<<endl;
}
