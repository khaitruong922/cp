#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int src, vector<vector<pii>> &graph)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &adj : graph[u])
        {
            int v = adj.second;
            int w = adj.first;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << dist[i] << " ";
    }
}
// driver program to test above function
int main()
{

    vector<vector<int>> matrix = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                  {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                  {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                  {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                  {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                  {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                  {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                  {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                  {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    int n = matrix.size();
    vector<vector<pii>> graph(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] == 0)
                continue;
            graph[i].push_back({matrix[i][j], j});
        }
    }
    dijkstra(0, graph);
}
