#include <iostream>

using namespace std;
struct node{
    double numerator;
    double denominator;
};

int main()
{
    node input;
    while (cin >> input.numerator >> input.denominator)
    {
        if(input.numerator == input.denominator && input.numerator == 1)
            break;
        node Lweight = {0,1},Rweight = {1,0};
        node M = {1,1};
        while (1)
        {
            if(input.numerator == M.numerator
                && input.denominator == M.denominator)
            {
                break;
            }
            if (input.numerator / input.denominator
                < M.numerator / M.denominator)
            {

                M.numerator += Lweight.numerator;
                M.denominator += Lweight.denominator;
                Rweight.numerator += Lweight.numerator;
                Rweight.denominator += Lweight.denominator;
                cout << "L";
            }
            else
            {
                M.numerator += Rweight.numerator;
                M.denominator += Rweight.denominator;
                Lweight.numerator += Rweight.numerator;
                Lweight.denominator +=Rweight.denominator;
                cout << "R";
            }
        }
        cout << endl;
    }
    return 0;
}