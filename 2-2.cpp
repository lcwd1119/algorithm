#include <iostream>
#include <vector>
using namespace std;

struct obj
{
    int value;
    int weight;
    double density;
};

 int compareobj(const void* tmp1,const void* tmp2)
 {
     obj a = *((obj *)tmp1);
     obj b = *((obj *)tmp2);
     if(a.density > b.density)
         return -1;
     else if(a.density == b.density)
         return 0;
     else
         return 1;
 }

int main()
{
    int capacity;
    cin >> capacity;
    int tmp1,tmp2;
    vector<obj> list;
    while (cin >> tmp1 >> tmp2)
        list.push_back({tmp1,tmp2,(double)tmp1/tmp2});
    qsort(&list[0],list.size(),sizeof(obj), compareobj);
    int totalweightleft = capacity,ind = 0;
    double totalvalue = 0;
    while (totalweightleft > 0)
    {
        if(totalweightleft - list[ind].weight < 0)
        {
            totalvalue += (double)totalweightleft/list[ind].weight*list[ind].value;
            printf("%lf\n",totalvalue);
            break;
        }
        totalweightleft -= list[ind].weight;
        totalvalue += list[ind].value;
        ind++;
    }
    return 0;
}