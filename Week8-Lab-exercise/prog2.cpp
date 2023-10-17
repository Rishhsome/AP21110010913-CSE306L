#include <iostream>
#include <cctype>
using namespace std;

bool E();
bool E_prime();
bool T();
bool T_prime();
bool F();

string input;
int pos = 0;

int main()
{
    cout << "Enter an expression: ";
    cin >> input;
    bool success = E();

    if (success && pos == input.length())
        cout << "Valid expression!" << endl;
    else
        cout << "Invalid expression!" << endl;

    return 0;
}

bool E()
{
    if (T())
        return E_prime();
    return false;
}

bool E_prime()
{
    if (pos < input.length() && (input[pos] == '+' || input[pos] == '-'))
    {
        pos++;
        if (T())
            return E_prime();
        return false;
    }
    return true;
}

bool T()
{
    if (F())
        return T_prime();
    return false;
}

bool T_prime()
{
    if (pos < input.length() && (input[pos] == '*' || input[pos] == '/'))
    {
        pos++;
        if (F())
            return T_prime();
        return false;
    }
    return true;
}

bool F()
{
    if (pos < input.length())
    {
        if (input[pos] == '(')
        {
            pos++;
            if (E())
            {
                if (pos < input.length() && input[pos] == ')')
                {
                    pos++;
                    return true;
                }
            }
        }
        else if (isdigit(input[pos]))
        {
            pos++;
            return true;
        }
    }
    return false;
}
