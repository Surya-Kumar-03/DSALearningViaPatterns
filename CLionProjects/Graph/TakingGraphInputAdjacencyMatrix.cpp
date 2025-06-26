#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nodes, edges;
    int source, destination, weight;
    vector<vector<int> > adjacencyMatrix;

    /*
6 5
1 2
2 3
3 4
3 5
3 6
     */

    cin >> nodes >> edges;
    adjacencyMatrix.resize(nodes + 1, vector<int>(nodes + 1, false));
    for (int i = 0; i < edges; i++) {
        // For Directed / Undirected Graph
        // cin >> source >> destination;

        // For Weighted Graph
        cin >> source >> destination >> weight;

        // For Undirected Graph
        // adjacencyMatrix[source][destination] = true;
        // adjacencyMatrix[destination][source] = true;

        // For Directed Graph
        // adjacencyMatrix[source][destination] = true;

        // For Weighted Graph
        adjacencyMatrix[source][destination] = weight;
    }

    for (int i = 1; i <= nodes; i++) {
        for (int j = 1; j <= nodes; j++) {
            if (adjacencyMatrix[i][j] > 0) {
                cout << i << " --- " << j << " --- " << adjacencyMatrix[i][j] << endl;
            }
        }
    }

    return 0;
}
