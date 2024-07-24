#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void interleaveQueue(queue<int> &q)
{
    queue<int> st1;
    queue<int> st2;
    int n = q.size();
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        st1.push(q.front());
        q.pop();
    }
    for (int i = mid; i < n; i++)
    {
        st2.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            q.push(st1.front());
            st1.pop();
        }
        else
        {
            q.push(st2.front());
            st2.pop();
        }
    }
}
bool isBipartite(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (color[i] != 0)
            continue;
        color[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (auto &x : graph[t])
            {
                if (color[x] == 0)
                {
                    color[x] = -color[t];
                    q.push(x);
                }
                else if (color[x] == color[t])
                    return false;
            }
        }
    }
    return true;
}
void bfs(vector<vector<int>> graph, int start)
{
    int numVertices = graph.size();
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    queue<int> myQueue;
    bool isFirst = true;
    visited[start] = true;
    myQueue.push(start);

    while (!myQueue.empty())
    {
        start = myQueue.front();
        if (isFirst)
        {
            cout << start;
            isFirst = false;
        }
        else
            cout << " " << start;
        myQueue.pop();

        int outDegree = graph[start].size();
        for (int j = 0; j < outDegree; ++j)
        {
            int temp = graph[start][j];
            if (!visited[temp])
            {
                visited[temp] = true;
                myQueue.push(temp);
            }
        }
    }
    delete[] visited;
}

long long nthNiceNumber(int n)
{
    queue<long long> q;
    q.push(2);
    q.push(5);
    while (--n)
    {
        long long x = q.front();
        q.pop();
        q.push(x * 10 + 2);
        q.push(x * 10 + 5);
    }
    return q.front();
}

int secondsToBeRotten(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int colums = grid[0].size();
    int seconds = 0;
    queue<pair<int, int>> rotten;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            if (grid[i][j] == 2)
            {
                rotten.push({i, j});
            }
        }
    }

    while (!rotten.empty())
    {
        int size = rotten.size();
        for (int i = 0; i < size; i++)
        {
            pair<int, int> current = rotten.front();
            rotten.pop();

            int x = current.first;
            int y = current.second;

            if (x + 1 < rows && grid[x + 1][y] == 1)
            {
                grid[x + 1][y] = 2;
                rotten.push({x + 1, y});
            }
            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                grid[x - 1][y] = 2;
                rotten.push({x - 1, y});
            }
            if (y + 1 < colums && grid[x][y + 1] == 1)
            {
                grid[x][y + 1] = 2;
                rotten.push({x, y + 1});
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                grid[x][y - 1] = 2;
                rotten.push({x, y - 1});
            }
        }
        if (!rotten.empty())
        {
            seconds++;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return seconds;
}

// int sumOfMaxSubarray(vector<int> &nums, int k)
// {
//     // STUDENT ANSWER
//     int n = nums.size();
//     int sum = 0;
//     int max = 0;
//     for (int i = 0; i < k; i++)
//     {
//         sum += nums[i];
//     }
//     for (int i = k; i < n; i++)
//     {
//         int temp = sum - nums[i - k] + nums[i];
//         if (temp > sum)
//         {
//             max = temp;
//         }
//         sum = temp;
//     }
//     return max;
// }
int sumOfMaxSubarray(vector<int>& nums, int k) {
    deque<int> dq;
    int sum = 0, max_q = 0, vec_size = nums.size();
    for (int i = 0; i < k; i++) {
        if (dq.empty()) dq.push_back(i);
        else {
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
    }
    sum = nums[dq.front()];

    for (int i = k; i < vec_size; i++) {
        if (i - k + 1 > dq.front()) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        sum += nums[dq.front()];
    }

    return sum;
}
int main(){
    #ifndef ONLINE_JUDGE;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    return 0;
}