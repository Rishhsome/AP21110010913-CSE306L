#include <iostream>
#include <string>
using namespace std;

int main()
{
    int state = 0;
    char current;
    string input;
    cout << "Enter input string :";
    getline(cin, input);
    for(int i=0;i<input.length();i++)
    {
        if(i == 0)
            state = 1;
        else{
            if(input[i] == input[i-1])
                state = 0;
            else    
                state = 1;
        }
    }
    if (state == 0)
        cout<<"\nString accepted\n\n";
    else
        cout<<"\nString not accepted\n\n";
    
    return 0;
}