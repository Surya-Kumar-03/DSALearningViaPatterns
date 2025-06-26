//
// Created by Surya on 26-06-2025.
//
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int nodes, edges;
    int source, destination, weight;
    vector<vector<pair<int, int> > > adjacencyList;

    cin >> nodes >> edges;
    adjacencyList.resize(nodes + 1, vector<pair<int, int> >());

    for (int i = 0; i < edges; i++) {
        // For Directed and Undirected Graphs
        // cin >> source >> destination;

        // For Weighted Graphs
        cin >> source >> destination >> weight;

        // For Undirected Graph
        // adjacencyList[source].push_back(destination);
        // adjacencyList[destination].push_back(source);

        // For Directed Graph
        // adjacencyList[source].push_back(destination);

        // For Weighted Graph
        adjacencyList[source].push_back({destination, weight});
    }

    for (int node = 1; node <= nodes; node++) {
        for (auto [neighbour, weight]: adjacencyList[node]) { // C++ 17 and Above (Structured Bindings)
            cout << node << " --- " << neighbour << " --- " << weight << endl;
        }
    }

    return 0;
}
