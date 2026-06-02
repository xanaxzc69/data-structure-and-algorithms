#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

const int INF = 1e9;

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
        cout << setw(5) << " ";
        for (int i = 0; i < n; i++) {
            cout << setw(5) << i + 1;
        }
        cout << "\n";

        for (int i = 0; i < n; i++) {
            cout << setw(5) << i + 1;
            for (int j = 0; j < n; j++) {
                cout << setw(5) << adjMatrix[i][j];
            }
            cout << "\n";
        }
        cout << endl;
    }

    bool isComplete() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && adjMatrix[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
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

    int degree(int v) const {
        int deg = 0;
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] != 0) {
                deg++;
            }
        }
        return deg;
    }

    void findIsolatedAndPendant() const {
        bool found = false;

        for (int i = 0; i < n; i++) {
            int deg = degree(i);

            if (deg == 0) {
                cout << "Vertex " << i + 1 << " is isolated.\n";
                found = true;
            } else if (deg == 1) {
                int nearestVertex = -1;
                int distance = INF;

                for (int j = 0; j < n; j++) {
                    if (adjMatrix[i][j] != 0) {
                        nearestVertex = j;
                        distance = adjMatrix[i][j];
                        break;
                    }
                }

                cout << "Vertex " << i + 1 << " is pendant. ";
                cout << "Nearest vertex: " << nearestVertex + 1;
                cout << ", distance: " << distance << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "There are no isolated or pendant vertices.\n";
        }

        cout << endl;
    }

    void countIsolatedVertices() const {
        int count = 0;
        cout << "Isolated vertices: ";

        for (int i = 0; i < n; i++) {
            if (degree(i) == 0) {
                cout << i + 1 << " ";
                count++;
            }
        }

        if (count == 0) {
            cout << "none";
        }

        cout << "\nCount of isolated vertices: " << count << "\n\n";
    }

    double averageEdgeLength() const {
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (adjMatrix[i][j] != 0) {
                    sum += adjMatrix[i][j];
                    count++;
                }
            }
        }

        if (count == 0) {
            return 0.0;
        }

        return static_cast<double>(sum) / count;
    }

    void longestRouteThroughThreeCities() const {
        int maxSum = -1;
        int city1 = -1, city2 = -1, city3 = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && adjMatrix[i][j] != 0) {
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j && adjMatrix[j][k] != 0) {
                            int currentSum = adjMatrix[i][j] + adjMatrix[j][k];
                            if (currentSum > maxSum) {
                                maxSum = currentSum;
                                city1 = i;
                                city2 = j;
                                city3 = k;
                            }
                        }
                    }
                }
            }
        }

        if (maxSum == -1) {
            cout << "No route through three cities found.\n\n";
            return;
        }

        cout << "Longest route through three cities:\n";
        cout << "(" << city1 + 1 << ") --- " << adjMatrix[city1][city2]
             << " --- (" << city2 + 1 << ") --- " << adjMatrix[city2][city3]
             << " --- (" << city3 + 1 << ")\n\n";
    }

    bool hamiltonianUtil(int current, vector<bool>& visited, int countVisited) const {
        if (countVisited == n) {
            return true;
        }

        for (int next = 0; next < n; next++) {
            if (adjMatrix[current][next] != 0 && !visited[next]) {
                visited[next] = true;
                if (hamiltonianUtil(next, visited, countVisited + 1)) {
                    return true;
                }
                visited[next] = false;
            }
        }

        return false;
    }

    bool hasHamiltonianPath() const {
        for (int start = 0; start < n; start++) {
            vector<bool> visited(n, false);
            visited[start] = true;

            if (hamiltonianUtil(start, visited, 1)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(6);

    // Graph from the task image
    g.addEdge(1, 2, 2); // 2 - 3
    g.addEdge(2, 1, 6); // 3 - 2
    g.addEdge(2, 5, 9); // 3 - 6
    g.addEdge(2, 4, 8); // 3 - 5
    g.addEdge(1, 3, 4); // 2 - 4
    g.addEdge(4, 3, 4); // 5 - 4

    g.printAdjMatrix();

    cout << "Is graph complete? ";
    cout << (g.isComplete() ? "Yes" : "No") << "\n\n";

    g.printAdjList();

    cout << "Average path length between connected cities: ";
    cout << fixed << setprecision(2) << g.averageEdgeLength() << "\n\n";

    g.findIsolatedAndPendant();

    g.countIsolatedVertices();

    g.longestRouteThroughThreeCities();

    cout << "Can all cities be visited exactly once? ";
    cout << (g.hasHamiltonianPath() ? "Yes" : "No") << "\n";

    return 0;
}