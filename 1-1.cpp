#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> input1,vector<int> input2)
{
    int index1 = 0 ,index2 = 0;
    vector<int> combine;
    while (index1 < input1.size() && index2 < input2.size())
    {
        if(input2[index2] < input1[index1])
        {
            combine.push_back(input2[index2]);
            index2++;
        }
        else{
            combine.push_back(input1[index1]);
            index1++;
        }
    }
    while (index1 < input1.size())
    {
        combine.push_back(input1[index1]);
        index1++;
    }
    while (index2 < input2.size())
    {
        combine.push_back(input2[index2]);
        index2++;
    }
    return combine;
}

vector<int> mergesort(vector<int> input)
{
    if(input.size() == 1)
        return input;
    vector<int> a,b;
    for(int i = 0;i < input.size();i++)
    {
        if(i < input.size()/2)
            a.push_back(input[i]);
        else
            b.push_back(input[i]);
    }
    a = mergesort(a);
    b = mergesort(b);
    return merge(a,b);
}

int main()
{
    int num;
    vector<int> arr;
    while(cin >> num)
        arr.push_back(num);
    arr = mergesort(arr);
    for(auto it : arr)
        cout << it << " ";
    cout << endl;
    return 0;
}