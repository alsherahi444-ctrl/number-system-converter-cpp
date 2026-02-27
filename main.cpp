#include <iostream>
#include <string>

using namespace std;





#include <stdexcept>

unsigned long long fromBase(string n, int source)
{
    unsigned long long result = 0;

    for (int i = 0; i < n.length(); i++)
    {
        char c = n[i];
        int digit = 0;

        if (c >= '0' && c <= '9')
        {
            digit = c - '0';
        }
        else if (c >= 'A' && c <= 'F')
        {
            digit = c - 'A' + 10;
        }
        else if (c >= 'a' && c <= 'f')
        {
            digit = c - 'a' + 10;
        }
        else
        {
            throw invalid_argument("Invalid character in input.");
        }

        if (digit >= source)
        {
            throw invalid_argument("Digit not valid for this base.");
        }

        result = result * source + digit;
    }

    return result;
}



string toBase(unsigned long long n, int target)
{
    string result;

    int remainder = 0;
    char digitChar;

    if (n == 0)
    return "0";

    while(n > 0)
    {
        remainder = n % target;

        if(remainder < 10)
        {
            digitChar = '0' + remainder;
        }
        else
        {
            digitChar = 'A' + (remainder - 10);
        }

        result = digitChar + result;


        n = n / target;
    }

    return result;
}







int main(){

    int source = 0;
    int target = 0;
    string number;
    unsigned long long decimalValue;
    string finalResult;


    cout << "Choose source base: " << "\n";
    cout << "1) Decimal " << "\n";
    cout << "2) Binary " << "\n";
    cout << "3) Octal" << "\n";
    cout << "4) Hex" << "\n";

    cin >> source ;

    cout << "Choose target base: " << "\n";
    cout << "1) Decimal " << "\n";
    cout << "2) Binary " << "\n";
    cout << "3) Octal" << "\n";
    cout << "4) Hex" << "\n";
    cin >> target;

    cout << "Enter number: " << "\n";
    cin >> number;



    if(source == 1) source = 10;
    if(source == 2) source = 2;
    if(source == 3) source = 8;
    if(source == 4) source = 16;

    if(target == 1) target = 10;
    if(target == 2) target = 2;
    if(target == 3) target = 8;
    if(target == 4) target = 16;

    decimalValue = fromBase(number, source);
    finalResult = toBase(decimalValue, target);

    cout <<  finalResult;


    return 0;
}





