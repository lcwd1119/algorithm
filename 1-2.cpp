#include <iostream>
#include <vector>
using namespace std;

int FindMaxCrossingSubarray(vector<int> inputleft,vector<int> inputright)
{
    int sum = 0,leftsum = -99999,rightsum = -99999;
    for(int i = inputleft.size() - 1;i >= 0 ;i--)
    {
        sum += inputleft[i];
        if(sum > leftsum)
            leftsum = sum;
    }
    sum = 0;
    for(int i = 0;i < inputright.size();i++)
    {
        sum += inputright[i];
        if(sum > rightsum)
            rightsum = sum;
    }
    return leftsum + rightsum;
}

int FindMaximunSubarr(vector<int> input)
{
    if(input.size() == 1)
        return input[0];
    vector<int> leftv,rightv;
    for(int i = 0;i < input.size();i++)
    {
        if(i < input.size()/2)
            leftv.push_back(input[i]);
        else
            rightv.push_back(input[i]);
    }
    int leftsum = FindMaximunSubarr(leftv);
    int rightsum = FindMaximunSubarr(rightv);
    int crossingsum = FindMaxCrossingSubarray(leftv,rightv);
    if(leftsum >= rightsum && leftsum >= crossingsum)
        return leftsum;
    else if(rightsum >= leftsum && rightsum >= crossingsum)
        return rightsum;
    else
        return crossingsum;
}

int main()
{
    vector<int> input;
    int tmp;
    while (cin >> tmp)
        input.push_back(tmp);
    cout << FindMaximunSubarr(input) << endl;
    return 0;
}