#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge (target_node, weight)
struct Edge {
    int to;
    int weight;
};

// Function to run Dijkstra's Algorithm
void dijkstra(int source, int num_vertices, const vector<vector<Edge>>& adj_list) {
    // Distance vector initialized to infinity
    vector<int> dist(num_vertices, INT_MAX);
    
    // Min-heap priority queue storing pairs of (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize source node
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we found a shorter path to u already, skip it
        if (d > dist[u]) continue;

        // Explore neighbors
        for (const auto& edge : adj_list[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the results
    cout << "Shortest distances from Source Node " << source << ":\n";
    for (int i = 0; i < num_vertices; ++i) {
        cout << "  To Node " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "Unreachable\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    cout << "-----------------------------------\n";
}

int main() {
    int num_vertices = 6;
    vector<vector<Edge>> adj_list(num_vertices);

    // Hardcoding the graph structure from the image
    // Node 0 edges
    adj_list[0].push_back({1, 4});
    adj_list[0].push_back({2, 9});
    adj_list[0].push_back({4, 2});

    // Node 1 edges
    adj_list[1].push_back({2, 2});
    adj_list[1].push_back({3, 1});

    // Node 2 edges
    adj_list[2].push_back({3, 7});
    adj_list[2].push_back({5, 4});

    // Node 3 edges
    adj_list[3].push_back({5, 1});

    // Node 4 edges
    adj_list[4].push_back({2, 3});
    adj_list[4].push_back({5, 8});

    // Node 5 has no outgoing edges

    // Task 1: Run Dijkstra starting from Node 0
    dijkstra(0, num_vertices, adj_list);

    // Task 2: Run Dijkstra starting from Node 1
    dijkstra(1, num_vertices, adj_list);

    return 0;
}// Implement main program.
