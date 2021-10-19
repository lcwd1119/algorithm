#include <iostream>
#include <vector>
using namespace std;

class minspanning
{
private:
    struct edge
    {
        int vertex1;
        int vertex2;
        int cost;
    };
    vector<edge> edgecost;
    vector<int> adjacency_list[40000];
    vector<int> setlist;
    int maxnum;
public:

    minspanning()
    {
        maxnum = 0;
    }

    void add(edge input)
    {
        edgecost.push_back(input);
        adjacency_list[input.vertex1].push_back(input.vertex2);
        adjacency_list[input.vertex2].push_back(input.vertex1);
        maxnum = max(max(input.vertex1,input.vertex2),maxnum);
    }

    static int comparecost(const void* tmp1,const void* tmp2)
    {
        edge a = *((edge *)tmp1);
        edge b = *((edge *)tmp2);
        if(a.cost < b.cost)
            return -1;
        else if(a.cost == b.cost)
            return 0;
        else
            return 1;
    }

    void findmincost()
    {
        cout << endl << "minimum spanning tree:" << endl;
        for(int i = 0;i <= maxnum;i++) setlist.push_back(-1);
        qsort(&edgecost[0],edgecost.size(),sizeof(edge),comparecost);
        int mincost = 0;
        for(int i = 0,count = 0;i < edgecost.size();i++)
        {
            if(count == maxnum)
                break;

            if(find(edgecost[i].vertex1) == find(edgecost[i].vertex2))
                continue;

            setunion(edgecost[i].vertex1,edgecost[i].vertex2);
            count++;
            mincost += edgecost[i].cost;
            cout << count << ": <" << edgecost[i].vertex1 << "," << edgecost[i].vertex2
                << ">" << endl;
        }
        cout << endl << "The cost of minimum spanning tree: " << mincost << endl;
    }

    int find(int vertex)
    {
        if(setlist[vertex] == -1)
            return vertex;
        find(setlist[vertex]);
    }

    int setunion(int vertex1,int vertex2)
    {
        if(find(vertex1) < find(vertex2))
            setlist[find(vertex2)] = vertex1;
        else
            setlist[find(vertex1)] = vertex2;
    }

    void printlist()
    {
        cout << "Adjacency list:" << endl;
        for(int i = 0;i <= maxnum;i++)
        {
            cout << i << ": ";
            for(int j = 0;j < adjacency_list[i].size();j++)
                cout << adjacency_list[i][j] << " -> ";
            cout << "end" << endl;
        }
    }
};

int main()
{
    minspanning tree;
    int input1,input2,input3;
    while (cin >> input1 >> input2 >> input3)
        tree.add({input1, input2, input3});
    tree.printlist();
    tree.findmincost();
    return 0;
}