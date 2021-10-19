#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int drivers_num,hours_limit_per_driver,bonus;
    while (cin >> drivers_num >> hours_limit_per_driver >> bonus)
    {
        if(drivers_num == 0)
            break;

        int sum = 0;
        vector<int> morning,evening;
        for(int j = 0,tmp;j < drivers_num;j++)
        {
            cin >> tmp;
            morning.push_back(tmp);
        }
        sort(morning.begin(), morning.end());
        for(int j = 0,tmp;j < drivers_num;j++)
        {
            cin >> tmp;
            evening.push_back(tmp);
        }
        sort(evening.rbegin(), evening.rend());
        for(int j = 0,tmp;j < drivers_num;j++) {
            tmp = (morning[j] + evening[j] - hours_limit_per_driver) * bonus;
            if(tmp >= 0)
                sum += tmp;
        }
        cout << sum << endl;
    }
    return 0;
}