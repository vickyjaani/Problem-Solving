#include <iostream>
using namespace std;
#include<string>
void interleaving(char* first, char* second, string str = "") {
    
	if(first[0] == '\0' && second[0] == '\0')
    {
        cout << str << "\n";
        return ;
    }
    if(first[0] != '\0' && second[0] != '\0')
    {
        interleaving(first+1, second, str+first[0] );
        interleaving(first, second+1, str+second[0]);
    }
    else if(first[0] != '\0')
    {
        interleaving(first + 1, second, str+first[0] );
    }
    else if(second[0] != '\0')
    {
        interleaving(first, second+1, str+second[0]);
    }

}

int main() {
    char *a = new char[1000];
    char *b = new char[1000];
    cin >> a;
    cin >> b;
    interleaving(a, b);
}
