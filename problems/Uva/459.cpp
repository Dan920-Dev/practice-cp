#include <bits/stdc++.h>

using namespace std;

// Ruta mas corta para un grafo no ponderado con MA
vector<int> bfsShortestPath(int start, int end, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<int> dist(n, -1);   // Distancias, -1 significa no visitado
    vector<int> parent(n, -1); // Para reconstruir el camino
    queue<int> q;

    dist[start] = 0; // El nodo inicial tiene distancia 0
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < n; ++i)
        {
            if (matrix[node][i] == 1 && dist[i] == -1) // Si el nodo i es adyacente y no ha sido visitado
            {
                dist[i] = dist[node] + 1;
                parent[i] = node; // Guardamos el nodo anterior para reconstruir el camino
                q.push(i);

                if (i == end) // Si llegamos al nodo final, terminamos
                    break;
            }
        }
    }

    // Si el nodo final es alcanzable, reconstruimos el camino
    vector<int> path;
    if (dist[end] != -1)
    {
        for (int v = end; v != -1; v = parent[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(), path.end()); // El camino se reconstruye de atrás hacia adelante
    }

    return path;
}

// Ruta mas larga para un grafo no ponderado con MA
int dfsLongestPath(int node, vector<vector<int>> &matrix, vector<bool> &visited, int length)
{
    visited[node] = true;
    int maxLength = length;

    for (int i = 0; i < matrix.size(); ++i)
    {
        if (matrix[node][i] == 1 && !visited[i])  // Si el nodo i es adyacente y no ha sido visitado
        {
            maxLength = max(maxLength, dfsLongestPath(i, matrix, visited, length + 1));
        }
    }

    visited[node] = false;  // Desmarcar el nodo para otras llamadas de DFS
    return maxLength;
}

void dfsMA(int numNodes, vector<vector<int>> matrix, vector<bool> *visited)
{
    visited->at(numNodes) = true;

    for (int i = 0; i < matrix.size(); ++i)
    {
        if (matrix[numNodes][i] == 1 && !visited->at(i))
        {
            dfsMA(i, matrix, visited);
        }
    }
}

int findComponents(int numNodes, vector<vector<int>> matrix, vector<bool> *visited)
{
    int count = 0;

    for (int i = 0; i < numNodes; i++)
    {
        if (!(visited->at(i)))
        {
            count++;
            dfsMA(i, matrix, visited);
        }
    }

    return count;
}

vector<vector<int>> fillMatrix(int n, vector<string> *conexs)
{
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int sz = (int)(conexs->size());
    string line = "";

    for (int i = 0; i < sz; ++i)
    {
        line = conexs->at(i);

        // [u][v]
        // [v][u]
        matrix[line[0] - 'A'][line[1] - 'A'] = 1;
        matrix[line[1] - 'A'][line[0] - 'A'] = 1;
    }

    return matrix;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code

    vector<string> v = {"AB", "CE", "DB", "EC"};

    vector<vector<int>> MA = fillMatrix('E' - 'A' + 1, &v);

    vector<bool> visited('E' - 'A' + 1, false);

    cout << "res: " << findComponents('E' - 'A' + 1, MA, &visited);

    return 0;
}
