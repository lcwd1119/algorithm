#include <iostream>
#include <vector>
using namespace std;

int bottom_up_cut_rod(vector<int> table,int length)
{
    vector<int> r;
    r.push_back(0);
    for(int i = 1;i <= length;i++)
    {
        int tmp = -1;
        for(int j = 1;j <= i;j++)
            tmp = max(tmp,table[j-1] + r[i-j]);
        r.push_back(tmp);
    }
    return r[length];
}

int main()
{
    int length,tmp1,tmp2;
    cin >> length;
    vector<int> table;
    for(int i = 0;i < length;i++)
    {
        if(tmp1)
            cin >> tmp1 >> tmp2;
        table.push_back(tmp2);
    }
    int rr = bottom_up_cut_rod(table,length);
    cout << rr << endl;
    return 0;
}