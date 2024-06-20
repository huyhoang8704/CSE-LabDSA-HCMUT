#include<iostream>
#include<vector>
#include<deque>
#include<queue>

using namespace std;

int sumOfMaxSubArray(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k <= 0 || k > n) return 0;

    deque<int> dq;

    for (int i=0; i<k; i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    int sum = nums[dq.front()];

    for (int i=k; i<n; i++) {
        while (!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
        sum += nums[dq.front()];
    }

    return sum;
}

long long nthNiceNumber(int n) {
    queue<long long> q;

    q.push(2);
    q.push(5);

    long long front;

    for (int i = 1; i <= n; i++) {
        front = q.front();
        q.pop();

        q.push(front*10 + 2);
        q.push(front*10 + 5);
    }

    return front;
}
// Biểu diễn đồ thị bằng ma trận kề
void bfsByAdjList(vector<vector<int>> graph, int start) {
    int n = graph.size();
    queue<int> vertices;
    vector<bool> visited(n, false);

    vertices.push(start);
    visited[start] = true;

    while (!vertices.empty()) {
        int vertex = vertices.front();
        vertices.pop();
        cout << vertex << " ";

        for (unsigned int i = 0; i<n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                vertices.push(i);
                visited[i] = true;
            }
        }
    }
}

//Biểu diễn đồ thị bằng danh sách kề
void bfs(vector<vector<int>> graph, int start) {
    int n = graph.size();
    queue<int> vertices;
    vector<bool> visited(n, false);

    vertices.push(start);
    visited[start] = true;

    while (!vertices.empty()) {
        int vertex = vertices.front();
        vertices.pop();
        if (vertex == start) cout << vertex;
        else cout << " " << vertex;

        for (unsigned i=0; i<graph[vertex].size(); i++) {
            if (!visited[graph[vertex][i]]) {
                vertices.push(graph[vertex][i]);
                visited[graph[vertex][i]] = true;
            }
        }
    }
}

bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    queue<int> V;

    vector<int> colour(n, -1);

    for (int i=0; i<n; i++) {
        if (colour[i] == -1) {
            V.push(i);
            colour[i] = 0;
            
            while (!V.empty()) {
                int vertex = V.front();
                V.pop();

                for (int v : graph[vertex]) {
                    if (v == vertex) return 0;

                    if (colour[v] == colour[vertex]) return 0;

                    if (colour[v] == -1) {
                        colour[v] = 1 - colour[vertex];
                        V.push(v);
                    }
                }
            }
        }
    }

    return true;
}

int secondsToBeRotten(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<vector<int>> q;
    int beforeRotten = 0;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == 1) {
                beforeRotten += 1;
            }
            else if (grid[i][j] == 2) {
                vector<int> info = {i, j, 0};
                q.push(info);
            }
        }
    }

    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};
    int afterRotten = 0;
    int sec = 0;

    while (!q.empty()) {
        vector<int> orange = q.front();
        q.pop();
        int nthSec = orange[2];
        sec = (sec>nthSec)?sec:nthSec;

        for (int i=0; i<4; i++) {
            int row = orange[0] + dRow[i];
            int col = orange[1] + dCol[i];

            if (row >= 0 && row < m && col >= 0 && col < n) {
                if (grid[row][col] == 1) {
                    afterRotten += 1;
                    grid[row][col] = 2;
                    vector<int> info = {row, col, nthSec + 1};
                    q.push(info);
                }
            }
        }
    }

    return beforeRotten == afterRotten ? sec : -1;
}

int numberOfTheWinner(int N, int k) {
    queue<int> q;
    for (int i=1; i<=N; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        for (int i=1; i<k; i++) {
            int front = q.front();
            q.pop();

            q.push(front);
        }

        q.pop();
    }

    int front = q.front();
    q.pop();
    return front;
}

vector<int> topologicalSorting(vector<vector<int>> graph) {
    int n = graph.size(); // Number of nodes in the graph
    vector<int> inDegree(n, 0); // Initialize in-degrees of all nodes to 0
    vector<int> result; // To store the topological order
    queue<int> q; // Queue for nodes with in-degree 0

    // Calculate in-degrees of all nodes
    for (int i = 0; i < n; i++) {
        for (int neighbor : graph[i]) {
            inDegree[neighbor]++;
        }
    }

    // Initialize the queue with nodes having in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Decrease the in-degree of adjacent nodes
        for (int neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If the result size is less than n, it means there's a cycle, so return an empty vector.
    int resSize = result.size();
    if (resSize < n) {
        return vector<int>();
    }

    return result;
}

int main() {

    // cout << nthNiceNumber(10000);

	// bfs(graph, 0);

    // cout << isBipartite(graph);

    cout << numberOfTheWinner(5, 2);

    return 0;
}