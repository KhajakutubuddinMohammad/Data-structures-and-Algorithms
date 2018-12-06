#include<iostream>
using namespace std;

int binary_search(int *a,int l,int r,int key)
{
   if(l<=r)                     //this is not necessary as mid value does not go less than low and l always be <=r so l<=r;
   {
     int mid;
     mid=(l+r)/2;
     if(a[mid]==key)
         return mid;
     if(a[mid]>key)
         return binary_search(a,l,mid-1,key);
     else
         return binary_search(a,mid+1,r,key);
   }
}
int main()
{
    int a[]={1,1,1,1,1};
    int c=binary_search(a,0,4,1);
    cout<<c<<endl;
    return 0;
}
