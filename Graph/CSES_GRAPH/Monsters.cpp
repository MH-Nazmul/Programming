// MH_Nazmul
// Let it be as simple

#include <bits/stdc++.h>
using namespace std;
//=====================================Definition==============================
const int M = 1e9 + 7;
const int N = 2e3 + 10;
#define pb push_back
#define int long long int
#define fi first
#define sc second
#define nl cout << '\n'
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define cin(vec, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> vec[i];          \
    }
#define efficient()               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};
//=====================================LETS BEGIN==============================
vector<vector<char>> grid(1000, vector<char>(1000));
vector<vector<int>> sourse(1000, vector<int>(1000, N));
int row, col;
pair<int, int> suru;
map<pair<int, int>, pair<int, int>> _par;
bool isvalid(int x, int y)
{
    return (x >= 0 and x < row and y < col and y >= 0);
}

void monstars_path()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
            }
        }
    }
    q.push(suru);
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (grid[x][y] == 'A' && (x == 0 or y == 0 or y == col - 1 or x == row - 1))
        {
            pair<int, int> tmp = {x, y};
            vector<pair<int, int>> path;
            while (tmp != suru)
            {
                path.push_back({tmp.first, tmp.second});
                tmp = _par[tmp];
            }
            cout << "YES\n";
            cout << path.size() << "\n";
            path.push_back(suru);
            reverse(all(path));
            for (int i = 1; i < (int)path.size(); i++)
            {
                if (path[i - 1].first - path[i].first == 1)
                    cout << 'U';
                else if (path[i - 1].first - path[i].first == -1)
                    cout << 'D';
                else if (path[i - 1].second - path[i].second == 1)
                    cout << 'L';
                else if (path[i - 1].second - path[i].second == -1)
                    cout << 'R';
            }
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (isvalid(xx, yy))
            {
                if ((grid[xx][yy] == '.'))
                {
                    grid[xx][yy] = grid[x][y];
                    if (grid[xx][yy] == 'A')
                        _par[{xx, yy}] = {x, y};
                    q.push({xx, yy});
                }
            }
        }
    }
    cout << "NO";
}

void MH(void)
{

    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                suru.first = i;
                suru.second = j;
            }
        }
    }
    vector<vector<bool>> vis(1000, vector<bool>(1000, false));

    monstars_path();
}
signed main()
{
    // cout << fixed << showpoint << setprecision(0);
    efficient();
    int t = 1, Test;
    // cin >> t;
    for (Test = 1; Test <= t; Test++)
    {
        // cout << "Case " << Test << ": ";
        MH();
    }
    return 0;
}