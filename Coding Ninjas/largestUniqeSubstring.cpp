#include<iostream>
#include<cstring>
using namespace std;

void findLargestUniqueSubstring(char input[], char output[])
{
    int i,j=0;
    int max_length = 0;
    int starting_index = 0;
    int map[26] = {0};
    for( i=0; input[i] != '\0' ; i++)
    {
        map[input[i] - 'a']++;
        if(map[input[i] - 'a'] > 1)
        {
            
            if(max_length < i-j)
            {
                max_length = i - j;
                starting_index = j;
            }
            while(1)
            {
                map[input[i]]--;
                if(input[i] == input[j])
                {
                    j++;
                    break;
                }
                j++;
            }
            
        }
    }
    if(max_length < i-j)
    {
        max_length = i - j;
        starting_index = j;
    }
    i = 0;
    for(j = starting_index ; j<starting_index + max_length ; j++)
    {
        output[i] = input[j];
        i++;
    }
    return;

}
int main() {
    char input[1000], output[1000];
    cin.getline(input, 1000);
    findLargestUniqueSubstring(input, output);
    cout << output << endl;
}
