#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set <int> s;
    set <int> t;
    unordered_multiset <int> u;
    s.insert(20);
    s.insert(21);
    s.insert(21);
    t.insert(30);
    t.insert(60);
    t.insert(85);
    t.insert(30);
    u.insert(50);
    u.insert(45);
    u.insert(45);
    u.insert(51);
    set <int> :: iterator it1;
    unordered_set <int> :: iterator it2;
    unordered_multiset <int> :: iterator it3;
    cout<<"elements in set are"<<endl;
    for(it1=t.begin();it1!=t.end();it1++)
    {
        cout<<*it1<<endl;
    }
    cout<<"elements in unordered set are"<<endl;
    for(it2=s.begin();it2!=s.end();it2++)
    {
        cout<<*it2<<endl;
    }
    cout<<"elements in unordered multiset are"<<endl;
    for(it3=u.begin();it3!=u.end();it3++)
    {
        cout<<*it3<<endl;
    }
    return 0;
}
