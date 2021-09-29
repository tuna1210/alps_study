#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int n, m, stuffNum, sx, sy; 
char house[51][51];
bool visited[51][51][1 << 5];
map<pair<int, int>, int> stuff;

int bfs()
{
    memset(visited, false, sizeof(visited));

    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    visited[sx][sy][0] = true;
    int cnt = 0;
    while(!q.empty())
    {
        int qsize = q.size();
        for (int qs = 0; qs < qsize; qs++)
        {
            pair<pair<int, int>, int> cur = q.front();
            q.pop();

            int cx = cur.first.first, cy = cur.first.second;
            int cStuff = cur.second;
            // cout << "( " << cx << ", " << cy << " ), " << bitset<4>(cStuff) << "\n";

            if(house[cx][cy] == 'E')
            {
                if((cStuff & ((1 << stuffNum) - 1)) == ((1 << stuffNum) - 1)) return cnt;
                else continue;
            }
            
            for (int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i], ny = cy + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || house[nx][ny] == '#') continue;

                int nStuff = cStuff;

                if(house[nx][ny] == 'X')
                {
                    nStuff |= (1 << stuff[{nx, ny}]);
                }

                if(visited[nx][ny][nStuff]) continue;

                visited[nx][ny][nStuff] = true;
                q.push({{nx, ny}, nStuff});
            }
        }
        // cout << " ------------- \n";
        cnt++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> house[i][j];
            if(house[i][j] == 'S')
            {
                sx = i; sy = j;
            }
            else if(house[i][j] == 'X')
            {
                stuff[{i, j}] = stuffNum;
                stuffNum++;
            }
        }
    }
    
    cout << bfs() << "\n";
}
