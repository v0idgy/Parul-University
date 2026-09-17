#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1. GRAPH USING ADJACENCY MATRIX
class GraphMatrix
{
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

    // Helper for Recursive DFS
    void dfsUtil(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < numVertices; ++i)
        {
            if (adjMatrix[vertex][i] == 1 && !visited[i])
            {
                dfsUtil(i, visited);
            }
        }
    }

public:
    GraphMatrix(int vertices) : numVertices(vertices)
    {
        adjMatrix.assign(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v, bool isDirected = false)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            adjMatrix[u][v] = 1;
            if (!isDirected)
            {
                adjMatrix[v][u] = 1; // For undirected graph
            }
        }
    }

    void printMatrix()
    {
        cout << "\nAdjacency Matrix:\n  ";
        for (int i = 0; i < numVertices; ++i)
            cout << i << " ";
        cout << "\n";
        for (int i = 0; i < numVertices; ++i)
        {
            cout << i << " ";
            for (int j = 0; j < numVertices; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // BFS Traversal
    void bfs(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Matrix BFS Starting from " << startVertex << ": ";
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int i = 0; i < numVertices; ++i)
            {
                if (adjMatrix[curr][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << "\n";
    }

    // DFS Traversal
    void dfs(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        cout << "Matrix DFS Starting from " << startVertex << ": ";
        dfsUtil(startVertex, visited);
        cout << "\n";
    }
};

// 2. GRAPH USING ADJACENCY LIST
class GraphList
{
private:
    int numVertices;
    vector<vector<int>> adjList;

    // Helper for Recursive DFS
    void dfsUtil(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex])
        {
            if (!visited[neighbor])
            {
                dfsUtil(neighbor, visited);
            }
        }
    }

public:
    GraphList(int vertices) : numVertices(vertices)
    {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v, bool isDirected = false)
    {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices)
        {
            adjList[u].push_back(v);
            if (!isDirected)
            {
                adjList[v].push_back(u); // For undirected graph
            }
        }
    }

    void printList()
    {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < numVertices; ++i)
        {
            cout << i << " -> ";
            for (int neighbor : adjList[i])
            {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }

    // BFS Traversal
    void bfs(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "List BFS Starting from " << startVertex << ": ";
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int neighbor : adjList[curr])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << "\n";
    }

    // DFS Traversal
    void dfs(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        cout << "List DFS Starting from " << startVertex << ": ";
        dfsUtil(startVertex, visited);
        cout << "\n";
    }
};

int main()
{
    int vertices = 5;

    // Initialize both representations
    GraphMatrix gMatrix(vertices);
    GraphList gList(vertices);

    /* Graph Structure:
           0 --- 1
           | \   |
           |  \  |
           2 --- 3 --- 4
    */

    // Adding Edges (Undirected)
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}, {3, 4}};
    for (auto edge : edges)
    {
        gMatrix.addEdge(edge.first, edge.second);
        gList.addEdge(edge.first, edge.second);
    }

    // 1. Matrix Demonstrations
    cout << "=== ADJACENCY MATRIX REPRESENTATION ===";
    gMatrix.printMatrix();
    gMatrix.bfs(0);
    gMatrix.dfs(0);

    cout << "\n=======================================\n";

    // 2. List Demonstrations
    cout << "=== ADJACENCY LIST REPRESENTATION ===";
    gList.printList();
    gList.bfs(0);
    gList.dfs(0);

    return 0;
}