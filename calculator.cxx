#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
repeat:
    int r;
    float a, b;
    char op;
    cout << "ENTER THE FIRST VALUE : ";
    cin >> a;
    cout << "ENTER THE SECOND VALUE : ";
    cin >> b;
    cout << "ENTER THE OPERATER(+,-,/,*) : ";
    cin >> op;
    switch (op)
    {
    case '+':
        cout << a + b << endl;
        break;
    case '-':
        cout << a - b << endl;
        break;
    case '/':
        if (b == 0)
        {
            cout << "Can't divide by zero" << endl;
        }
        else
        {
            cout << a / b << endl;
        }
        break;
    case '*':
        cout << a * b << endl;
        break;
    default:
        cout << "Please enter valid operator" << endl;
    }
    cout << "PRESS 1 FOR REPEAT : ";
    cin >> r;
    if (r == 1)
    {
        goto repeat;
    }
    else{
        cout<<"THANK YOU FOR CHOSSING US"<<endl<<"CODE IS WRITTEN BY PRINCE DAKSH";
        }    
    return 0;
}