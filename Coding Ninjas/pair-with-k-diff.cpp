#include<iostream>
using namespace std;
#include <map>
using namespace std;
void printPairs(int *input, int n, int k)
{
    map<int, int> mymap;
    for(int i=0 ; i<n ; i++)
    {
        mymap[input[i]]++;
    }
    map<int, int> :: iterator it;
    map<int, int> :: iterator it1;
    for(it = mymap.begin() ; it != mymap.end() ; it++)
    {
        it1 = mymap.find(it -> first + k);
        if(it1 != mymap.end() )
        {
            while (it -> second-- && it1 -> second-- )
            {
                cout << it-> first << " "<< it1 -> first<<"\n";
            }
        }
    }
    return;
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
