#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


void find_max_black(int current_node,int *current_nodes_color,int *best_result,int &max_black_count, vector<int> points[],int biggest_node)
{
    int current_black[301];
    memcpy(current_black,current_nodes_color, sizeof(current_black));
    current_black[current_node] = 1;

    int paint_nodes = 0;
    for(int i = 0;i < points[current_node].size();i++)
    {
        if(current_black[ points[current_node][i] ] == -1)
        {
            current_black[points[current_node][i]] = 0;
            paint_nodes++;
        }
    }

    if(paint_nodes + current_node < biggest_node)
    {
        int next_node = 1;
        while (next_node <= biggest_node){
            next_node++;
            if(current_black[next_node] == -1)
                break;
        }
        find_max_black(next_node,current_black,best_result,max_black_count,points,biggest_node);
    }else
    {
        int count_black = 0;
        for(int i = 0;i <= biggest_node;i++) {
            if (current_black[i] == 1)
                count_black++;
        }
        if(count_black > max_black_count)
        {
            max_black_count = count_black;
            memcpy(best_result,current_black,sizeof(current_black));
        }
    }


    int current_white[301];
    memcpy(current_white,current_nodes_color, sizeof(current_white));
    current_white[current_node] = 0;

    if(current_node < biggest_node)
    {
        int next_node = 1;
        while (next_node <= biggest_node){
            next_node++;
            if(current_white[next_node] == -1)
                break;
        }
        find_max_black(next_node,current_white,best_result,max_black_count,points,biggest_node);
    }else
    {
        int count_black = 0;
        for(int i = 0;i <= biggest_node;i++) {
            if (current_white[i] == 1)
                count_black++;
        }
        if(count_black > max_black_count)
        {
            max_black_count = count_black;
            memcpy(best_result,current_white,sizeof(current_black));
        }
    }
}

int main()
{
    int input_size, biggest_node, edges;
    cin >> input_size;
    for(int i = 0; i < input_size;i++)
    {
        cin >> biggest_node >> edges;
        if(edges == 0)
        {
            cout << biggest_node << endl;
            cout << 1;
            for(int j = 2;j <= biggest_node;j++)
                cout << " " << j;
            cout << endl;
            continue;
        }

        vector<int> points[301];
        int vertex1, vertex2;
        for(int j = 0;j < edges;j++)
        {
            cin >> vertex1 >> vertex2;
            points[vertex1].push_back(vertex2);
            points[vertex2].push_back(vertex1);
            biggest_node = max(biggest_node, max(vertex1,vertex2));
        }

        //1 = black, 0 = white, -1 = null
        int current_nodes_color[301];
        int best_result[301];
        memset(current_nodes_color, -1, sizeof(current_nodes_color));
        memset(best_result,-1,sizeof(best_result));
        int max_black_count = 0;
        find_max_black(1,current_nodes_color,best_result,max_black_count,points,biggest_node);


        cout << max_black_count << endl;
        int tmp = max_black_count;
        for(int current_node = 1;tmp > 0;current_node++)
        {
            if(best_result[current_node] == 1)
            {
                cout << current_node;
                tmp--;
                if(tmp != 0)
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}