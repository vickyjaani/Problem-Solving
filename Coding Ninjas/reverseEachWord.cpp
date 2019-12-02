#include <iostream>

using namespace std;

void reverseEachWord(char input[]) 
{
    int i = 0,k=0;
    do
    {
        
        if(input[i] == ' ' || input[i+1] ==  '\0') 
        {
            if(input[i+1] ==  '\0')
                i = i+1;
            
            for(int j = k ; j < (i+k)/2 ; j++)
            {
                char temp = input[j];
                input[j] = input[i-j+k-1];
                input[i-j+k-1] = temp;
            }
            k = i+1;
        }
        
        i++;
    }while(input[i] != '\0');
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseEachWord(input);
    cout << input << endl;
}
