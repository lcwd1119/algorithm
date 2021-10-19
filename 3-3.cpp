#include <iostream>
#include <vector>
using namespace std;

struct node{
    int num;
    int weight;
    int value;
};

int main()
{
    int bag_size;
    cin >> bag_size;
    vector<node> item;
    int tmp1, tmp2, tmp3;
    while (cin >> tmp1 >> tmp2 >> tmp3)
    {
        if(tmp1 == -1)
            break;
        item.push_back({tmp1,tmp2,tmp3});
    }
    int** item_table = new int*[item.size()+1];
    int** value_table = new int*[item.size()+1];
    for(int i = 0;i <= item.size();i++)
    {
        item_table[i] = new int[bag_size+1];
        value_table[i] = new int[bag_size+1];
        for(int j = 0;j <= bag_size;j++)
            item_table[i][j] = 0;
    }
    for(int i = 0;i <= item.size();i++)
        value_table[0][i] = 0;
    /* value_table item.size()+1 行  bagsize +1 列
     * item_table  item.size()+1 行  bagsize +1 列
     */
    for(int i = 0;i < item.size();i++)
    {
        for(int j = 0;j <= bag_size;j++)
        {
            if(item[i].weight > j)
                value_table[i+1][j] = value_table[i][j];
            else {
                if (value_table[i][j - item[i].weight] + item[i].value > value_table[i][j]) {
                    value_table[i + 1][j] = value_table[i][j - item[i].weight] + item[i].value;
                    item_table[i][j] = 1;
                }
                else
                    value_table[i+1][j] = value_table[i][j];
            }
        }
    }

    for(int i = item.size(), tmp = bag_size;i >= 0;i--)
    {
        if(item_table[i][tmp] == 1) {
            cout << item[i].num << " ";
            tmp -= item[i].weight;
        }
    }
    cout << endl << value_table[item.size()][bag_size] << endl;
    return 0;
}