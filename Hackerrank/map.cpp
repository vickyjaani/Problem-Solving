#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string,int> contact;
    string name;
    int num,n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cin>>name>>num;
        contact[name]=num;
    }
    while(cin>>name)
    {
        if(contact.find(name)!=contact.end())
        {
            cout<< name<<"="<<contact[name]<<endl;
        }
        else
            cout<<"Not found"<<endl;
    }
    return 0;
}
