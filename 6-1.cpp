//Longest Increasing Subsequence
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> list;
    int tmp,len;
    cin >> len;
    for(int i = 0;i < len;i++)
    {
        cin >> tmp;
        list.push_back(tmp);
    }

    vector<int> subseq;
    subseq.push_back(list[0]);
    for(int i = 1;i < list.size();i++)
    {
        if(list[i] > subseq[subseq.size()-1])
            subseq.push_back(list[i]);
        else
            *lower_bound(subseq.begin(),subseq.end(),list[i]) = list[i];
    }
    cout << subseq.size() << endl;
    return 0;
}