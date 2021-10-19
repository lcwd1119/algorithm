#include <iostream>
#include <queue>
#include <stack>

using namespace std;
struct axis{
    int x;
    int y;
};

axis def_direction[8] = {{0,1},
                         {1,1},
                         {1,0},
                         {1,-1},
                         {0,-1},
                         {-1,-1},
                         {-1,0},
                         {-1,1}};

struct maze_node{
    int road;
    int step;
    axis last;
};

int main()
{
    axis size, start, goal;
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    size = {tmp1,tmp2};
    cin >> tmp1 >> tmp2;
    start = {tmp1,tmp2};
    cin >> tmp1 >> tmp2;
    goal = {tmp1,tmp2};

    //maze
    maze_node **maze = new maze_node*[size.x];
    for(int i = 0;i < size.x;i++)
        maze[i] = new maze_node[size.y];

    //input maze
    for(int i = 0;i < size.x;i++)
    {
        string tmps;
        cin >> tmps;
        for(int  j = 0;j < size.y;j++) {
            maze[i][j].road = tmps[j] - '0';
            maze[i][j].step = 999999;
        }
    }

    //bfs
    axis now = {start.x - 1,start.y - 1};
    maze[start.x-1][start.y-1].step = 0;
    queue<axis> valid_route;
    valid_route.push(now);
    while (!valid_route.empty())
    {
        now = valid_route.front();
        valid_route.pop();

        for(int i = 0;i < 8;i++)
        {
            if(now.x + def_direction[i].x < 0 || now.x + def_direction[i].x == size.x)
                continue;
            if(now.y + def_direction[i].y < 0 || now.y + def_direction[i].y == size.y)
                continue;
            if(maze[now.x + def_direction[i].x][now.y + def_direction[i].y].road)
                continue;

            if(maze[now.x + def_direction[i].x][now.y + def_direction[i].y].step > maze[now.x][now.y].step + 1) {
                valid_route.push({now.x + def_direction[i].x,now.y + def_direction[i].y});
                maze[now.x + def_direction[i].x][now.y + def_direction[i].y].step = maze[now.x][now.y].step + 1;
                maze[now.x + def_direction[i].x][now.y + def_direction[i].y].last = {now.x, now.y};
            }
        }
    }

    //output
    now = {goal.x-1,goal.y-1};
    stack<axis> result;
    result.push(now);
    while (now.x != start.x - 1 || now.y != start.y - 1)
    {
        now = maze[now.x][now.y].last;
        result.push(now);
    }
    cout << maze[goal.x-1][goal.y-1].step + 1 << endl;
    while (!result.empty())
    {
        cout << "(" << result.top().x + 1 << "," << result.top().y + 1 << ")" << endl;
        result.pop();
    }
    return 0;
}