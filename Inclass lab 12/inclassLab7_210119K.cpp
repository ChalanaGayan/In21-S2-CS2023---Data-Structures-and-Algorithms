#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int source) {
    int n = graph.size();

    vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        
        if (dist > distance[u]) {
            continue;
        }

       
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

           
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

int main() {
    int NumOfCities = 6;
    int numOfEdges = 8;
    int source;

    vector<vector<pii>> graph(NumOfCities);

    // adjacency matrix representation of cities
    vector<vector<int>> adjacencyMatrix = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    cout << "Enter the source node: ";
    cin >> source;

    
    for (int i = 0; i < NumOfCities; ++i) {
        for (int j = 0; j < NumOfCities; ++j) {
            int weight = adjacencyMatrix[i][j];
            if (weight != 0) {
                graph[i].push_back({j, weight});
            }
        }
    }

    vector<int> shortestDistances = dijkstra(graph, source);

    cout << "Shortest distances from node " << source << ":" << endl;
    for (int i = 0; i < NumOfCities; ++i) {
        cout << "City: " << i << " Distance: " << shortestDistances[i] << endl;
    }

    return 0;
}
