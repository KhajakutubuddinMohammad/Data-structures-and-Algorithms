#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    unordered_map<string,double> umap;
    umap["pi"]=3.14;
    umap["root2"]=1.414;
    umap["root3"]=1.732;
    umap.insert(make_pair("e",1));
    string key="root2";
    if(umap.find(key) == umap.end())
        cout<<key<<"is not found"<<endl;
    else
        cout<<key<<"found"<<endl;
    unordered_map<string,double> :: iterator it;
    for(it=umap.begin();it!=umap.end();it++)
       cout<<it->first<<"-->"<<it->second<<endl;

}
