#include <iostream>
#include <vector>

using namespace std;

struct item{
    int no;
    int weight;
    int value;
    float density;
};

vector<item> merge(vector<item> input1,vector<item> input2)
{
    int index1 = 0 ,index2 = 0;
    vector<item> combine;
    while (index1 < input1.size() && index2 < input2.size())
    {
        if(input2[index2].density > input1[index1].density)
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

vector<item> mergesort(vector<item> input)
{
    if(input.size() == 1)
        return input;
    vector<item> a,b;
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

vector<item> backpack;
int capacity;
void maximizetotal(vector<item> &list, int index, int capacityleft,int totalweight, int &maxvalue,int totalvalue,vector<item> selected)
{
    if(totalweight > capacity)
        return;
    if(index >= list.size())
        return;
    if(totalvalue > maxvalue)
    {
        maxvalue = totalvalue;
        backpack = selected;
    }
    if(capacityleft <= 0)
        return;
    int countcapacity = 0;
    int tmpvalue = totalvalue;
    for(int i = index;i < list.size();i++)
    {
        countcapacity += list[i].weight;

        if(countcapacity > capacityleft)
        {
            int unit = list[i].weight - (countcapacity - capacityleft);
            tmpvalue += list[i].density * unit;
            break;
        }
        tmpvalue += list[i].value;
    }
    if(tmpvalue <= totalvalue)
        return;

    vector<item> select = selected;
    select.push_back(list[index]);

    maximizetotal(list,index + 1,capacityleft - list[index].weight,totalweight + list[index].weight,maxvalue,totalvalue + list[index].value,select);
    maximizetotal(list,index + 1,capacityleft,totalweight,maxvalue,totalvalue,selected);
}

int main()
{
    cin >> capacity;
    vector<item> list;
    int no,weight,value;
    while (cin >> no >> weight >> value) {
        if(no == -1)
            break;
        list.push_back({no, weight, value,(float) value/weight});
    }
    vector<item> sorted = mergesort(list);
    int total = 0;
    maximizetotal(sorted,0,capacity,0,total,0,backpack);
    for(int i = 0;i < backpack.size();i++)
        cout << backpack[i].no << " ";
    cout << endl << total << endl;
    return 0;
}