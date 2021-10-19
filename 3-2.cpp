#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x,y;
    cin >> x >> y;
    int **table = new int* [x.length()+1];
    for(int i = 0;i <= x.length();i++)
    {
        table[i] = new int[y.length()+1];
        table[i][0] = 0;
    }
    for(int i = 0;i <= y.length();i++)
        table[0][i] = 0;

    for(int i = 1; i <= x.length();i++)
    {
        for(int j = 1;j <= y.length();j++)
        {
            if(x[i] == y[j])
                table[i][j] = table[i-1][j-1]+1;
            else if(table[i-1][j] >= table [i][j-1])
                table[i][j] = table[i-1][j];
            else
                table[i][j] = table[i][j-1];
        }
    }
    cout << table[x.length()][y.length()] << endl;
    return 0;
}