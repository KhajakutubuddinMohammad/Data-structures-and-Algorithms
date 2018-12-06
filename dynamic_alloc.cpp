#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{

    int a[26];
    //int *a=new int[26];
    string c="khaja";
    cout<<"hii"<<c[3]-'a'<<endl;
    for(int i=0;i<26;i++)
        a[i]=0;
    a[c.charAt(3)]=2;
    //cout<<"hello"<<endl;
    for(int i=0;i<26;i++)
        cout<<a[i]<<" "<<endl;
}
/*notes:
1.we can use int a[some_size]; when we exactly the size of the array at compile time;
2.But when we use dynamic memory allocation ,we can use new operator and the new operator returns us a pointer of that particular type
   eg:int *a=new int[26];
   new operator returns an int pointer so we can receive using int *a but not int a[] as a[] cannot receive a pointer;
3.In java,int a[]=new int[26];
4.In cpp,int *a=new int[26];
5.Arrays are simple form of pointers and the array variable will store the starting address of the array;
*/
