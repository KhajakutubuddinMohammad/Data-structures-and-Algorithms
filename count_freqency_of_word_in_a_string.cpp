#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s="khaja is a good boy and khaja is also a bad boy";
    stringstream ss(s);
    unordered_map<string ,int> umap;
    string word;
    while(ss >> word)
        umap[word]++;
    unordered_map<string ,int> :: iterator it;
    for(it=umap.begin();it!=umap.end();it++)
        cout<<it->first<<"-->"<<it->second<<endl;

}
