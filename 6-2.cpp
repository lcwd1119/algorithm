#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n,s;
    cin >> n >> s;
    vector<int> list;
    int tmp;
    for(int i = 0;i < n;i++)
    {
        cin >> tmp;
        list.push_back(tmp);
    }

    int length = INT_MAX, sum = 0,j = 0;
    for(int i = 0;i < list.size();i++)
    {
        sum += list[i];
        for (; j <= i && sum >= s; j++) {
            sum -= list[j];
            length = min(length,i - j + 1);
        }
    }
    if(length == INT_MAX)
        length = 0;
    cout << length << endl;
    return 0;
}