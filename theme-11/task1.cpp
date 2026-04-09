#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) : n(vertices) {
        adjMatrix.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int w) {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    void printAdjMatrix() const {
        cout << "Adjacency matrix:\n";
        cout << setw(4) << " ";
        for (int i = 0; i < n; i++) {
            cout << setw(4) << i + 1;
        }
        cout << "\n";

        for (int i = 0; i < n; i++) {
            cout << setw(4) << i + 1;
            for (int j = 0; j < n; j++) {
                cout << setw(4) << adjMatrix[i][j];
            }
            cout << "\n";
        }
        cout << endl;
    }

    void printAdjList() const {
        cout << "Adjacency list:\n";
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ": ";
            bool hasNeighbors = false;
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] != 0) {
                    cout << "(" << j + 1 << ", w=" << adjMatrix[i][j] << ") ";
                    hasNeighbors = true;
                }
            }
            if (!hasNeighbors) {
                cout << "no neighbors";
            }
            cout << "\n";
        }
        cout << endl;
    }

    int countEdges() const {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (adjMatrix[i][j] != 0) {
                    count++;
                }
            }
        }
        return count;
    }

    int degree(int v) const {
        int deg = 0;
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] != 0) {
                deg++;
            }
        }
        return deg;
    }

    void findMinMaxDegreeVertices() const {
        int minDegree = degree(0);
        int maxDegree = degree(0);

        for (int i = 1; i < n; i++) {
            int d = degree(i);
            if (d < minDegree) minDegree = d;
            if (d > maxDegree) maxDegree = d;
        }

        cout << "Vertices with minimum degree (" << minDegree << "): ";
        for (int i = 0; i < n; i++) {
            if (degree(i) == minDegree) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";

        cout << "Vertices with maximum degree (" << maxDegree << "): ";
        for (int i = 0; i < n; i++) {
            if (degree(i) == maxDegree) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n\n";
    }

    void findEqualDegreeVertices() const {
        map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[degree(i)].push_back(i + 1);
        }

        bool found = false;
        cout << "Vertices with equal number of connections:\n";
        for (const auto& group : groups) {
            if (group.second.size() > 1) {
                found = true;
                cout << "Degree " << group.first << ": ";
                for (int vertex : group.second) {
                    cout << vertex << " ";
                }
                cout << "\n";
            }
        }

        if (!found) {
            cout << "No such vertices found.\n";
        }
        cout << endl;
    }

    void findThreeVerticesWithMinimumDistanceSum() const {
        int minSum = -1;
        int a = -1, b = -1, c = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int sum = 0;
                    bool valid = true;

                    if (adjMatrix[i][j] != 0) sum += adjMatrix[i][j];
                    else valid = false;

                    if (adjMatrix[i][k] != 0) sum += adjMatrix[i][k];
                    else valid = false;

                    if (adjMatrix[j][k] != 0) sum += adjMatrix[j][k];
                    else valid = false;

                    if (valid && (minSum == -1 || sum < minSum)) {
                        minSum = sum;
                        a = i;
                        b = j;
                        c = k;
                    }
                }
            }
        }

        if (minSum == -1) {
            cout << "There are no three vertices where every pair is directly connected.\n\n";
            return;
        }

        cout << "Three vertices with minimum sum of distances: ";
        cout << a + 1 << ", " << b + 1 << ", " << c + 1 << "\n";
        cout << "Minimum sum of distances: " << minSum << "\n\n";
    }

    void findLongestEdge() const {
        int maxWeight = -1;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (adjMatrix[i][j] > maxWeight) {
                    maxWeight = adjMatrix[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (maxWeight == -1) {
            cout << "The graph has no edges.\n";
            return;
        }

        cout << "Longest edge: (" << u + 1 << ", " << v + 1 << ")";
        cout << " with weight " << maxWeight << "\n";
    }
};

int main() {
    Graph g(6);

    // Edges from the task figure:
    // 4-2 (1), 5-3 (2), 3-1 (3), 4-3 (5), 3-2 (6), 3-6 (8)
    g.addEdge(3, 1, 1); // 4 - 2
    g.addEdge(4, 2, 2); // 5 - 3
    g.addEdge(2, 0, 3); // 3 - 1
    g.addEdge(3, 2, 5); // 4 - 3
    g.addEdge(2, 1, 6); // 3 - 2
    g.addEdge(2, 5, 8); // 3 - 6

    g.printAdjMatrix();
    g.printAdjList();

    cout << "Total number of edges in the graph: " << g.countEdges() << "\n\n";

    g.findMinMaxDegreeVertices();
    g.findEqualDegreeVertices();
    g.findThreeVerticesWithMinimumDistanceSum();
    g.findLongestEdge();

    return 0;
}