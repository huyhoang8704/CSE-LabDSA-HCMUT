void dfs(int start, vector<vector<int>>& edges, vector<bool>& visited) {
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            for (int neighbor : edges[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
    }

int connectedComponents(vector<vector<int>>& edges) {
    // STUDENT ANSWER
    int n = edges.size();
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, edges, visited);
                components++;
            }
        }

        return components;
}