#include <iostream>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

int n;
set<long long> visited;

typedef struct Grid
{
    int data[8][8];
}grid;


void flip(grid& G, int a, int b)
{
    if(G.data[a][b] == 1) G.data[a][b] = 0;
    else G.data[a][b] = 1;
}

void chgRow(grid& G, int r)
{
    for (int i = 0; i < n; i++)
    {
        if(G.data[r][i] == 1) G.data[r][i] = 0;
        else G.data[r][i] = 1;
    }
}

void chgCol(grid& G, int c)
{
    for (int i = 0; i < n; i++)
    {
        if(G.data[i][c] == 1) G.data[i][c] = 0;
        else G.data[i][c] = 1;
    }
}

bool isEnd(grid G)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(G.data[i][j] == 0) return false;
        } 
    }
    return true;
}

long long gridToBit(grid& G)
{
    long long tmp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(G.data[i][j] == 1) tmp |= (1 << (i * n + j));
        }
    }
    return tmp;
}

bool hasVisited(grid& G)
{
    long long tmp = gridToBit(G);
    if(visited.find(tmp) != visited.end()) return true;
    return false;
}

// void print()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << grid[i][j] << " ";
//         } 
//         cout << "\n";
//     }
//     cout << "\n";
// }

int solution(grid Start)
{
    queue<grid> q;

    q.push(Start);

    int cnt = 0;
    while(!q.empty())
    {
        int qsize = q.size();
        for (int qs = 0; qs < qsize; qs++)
        {
            grid cur = q.front();
            q.pop();

            if(isEnd(cur)) return cnt;
            if(hasVisited(cur))
            
            grid ng;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    flip(cur, i, j);
                    if(!hasVisited(cur))
                    {
                        ng = cur;
                        q.push(cur);
                    }
                    flip(cur, i, j);
                }
            }

            for (int i = 0; i < n; i++)
            {
                chgCol(cur, i);
                if(!hasVisited(cur)) q.push(cur);
                chgCol(cur, i);

                chgRow(cur, i);
                if(!hasVisited(cur)) q.push(cur);
                chgRow(cur, i);
            }
        }
        cnt++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    grid G;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G.data[i][j];
        }
    }

    cout << solution(G) << "\n";
}