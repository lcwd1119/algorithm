#include <iostream>
#include <vector>
using namespace std;
struct event
{
    int no;
    int startime;
    int endtime;
};
int main()
{
    vector<event> data;
    int tmp1,tmp2,tmp3;
    while (cin >> tmp1 >> tmp2 >> tmp3)
        data.push_back({tmp1,tmp2,tmp3});
    int now = 0;
    for(int i = 0;i < data.size();i++)
    {
        if(now <= data[i].startime)
        {
            cout << data[i].no << " ";
            now = data[i].endtime;
        }
    }
    cout << endl;
    return 0;
}
