#include <iostream>
using namespace std;

int main()
{
    int state = 0, i = 0;
    char current, input[20];
    cout << "Enter input string \t :";
    cin >> input;
    while ((current = input[i++]) != '\0')
    {
        switch (state)
        {
        case 0:
            if (current == 'a')
                state = 1;
            else if (current == 'b')
                state = 2;
            else
            {
                cout<<"Invalid token";
                exit(0);
            }
            break;
        case 1:
            if (current == 'a')
                state = 0;
            else if (current == 'b')
                state = 3;
            else
            {
                cout<<"Invalid token";
                exit(0);
            }
            break;
        case 2:
            if (current == 'a')
                state = 3;
            else if (current == 'b')
                state = 0;
            else
            {
                cout<<"Invalid token";
                exit(0);
            }
            break;
        case 3:
            if (current == 'a')
                state = 2;
            else if (current == 'b')
                state = 1;
            else
            {
                cout<<"Invalid token";

                exit(0);
            }
            break;
        }
    }
    if (state == 0)
        cout<<"\n\nString accepted\n\n";
    else
        cout<<"\n\nString not accepted\n\n";
}