#include <iostream>
using namespace std;

//改遞迴比較快

int main()
{
    int cases;
    cin >> cases;
    int depth,nball;
    for(int i = 0;i < cases;i++)
    {
        cin >> depth >> nball;
        int position = 1,j = 1;
        while (j < depth)
        {
            if(nball % 2 == 0)
                position = position * 2 + 1;
            else
                position = position * 2;
            if(nball > 1)
            {
                if(nball % 2 == 0)
                    nball /= 2;
                else
                    nball = nball/2+1;
            }
            j++;
        }
        cout << position << endl;
    }
    cin >> cases;
    return 0;
}