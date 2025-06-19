#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> listaAdyacencia; // Lista de adyacencia para representar el grafo
vector<int> estadoDFS;                          // Vector para almacenar el estado de cada nodo (visitado o no)

/*
Esta función realiza una búsqueda en profundidad (DFS) en el grafo y, durante el proceso, genera un orden topológico de los nodos.
El orden topológico es útil para algoritmos como el cálculo del camino más largo en un DAG.
*/
void dfs(int nodo)
{
    cout << " " << nodo;  // Imprimir el nodo actual
    estadoDFS[nodo] = -2; // Marcar el nodo como visitado (VISITADO = -2)
    for (auto &[vecino, peso] : listaAdyacencia[nodo])
    { // Iterar sobre los vecinos del nodo actual
        if (estadoDFS[vecino] == -1)
        {                // Si el vecino no ha sido visitado (NO_VISITADO = -1)
            dfs(vecino); // Llamar recursivamente a DFS para el vecino
        }
    }
}

/**
Función modificada de DFS para encontrar y almacenar los nodos de un componente conexo.
Esta versión de DFS no solo visita los nodos del grafo, sino que además guarda todos los nodos
conectados a un nodo de inicio, formando un componente conexo completo.
Funcionamiento:
La función `dfs2` inicia marcando el nodo actual como visitado. Luego, agrega el nodo al componente 
actual (pasado por referencia) y recorre sus vecinos. Si alguno de los vecinos no ha sido visitado, 
la función realiza una llamada recursiva para explorar ese vecino y seguir el recorrido DFS. De esta manera, 
se recorren todos los nodos conectados al nodo de inicio, hasta completar el componente conexo.
 *
Ejemplo de uso:
Imaginemos que tenemos un grafo con los siguientes nodos y conexiones:
0 - 1
1 - 2
3 - 4
4 - 5
Si iniciamos un DFS desde el nodo 0, la función `dfs2` irá explorando todos los nodos conectados al 0.
En este caso, formará el componente conexo {0, 1, 2}.
 *
La función `dfs2` es útil cuando se requiere encontrar todos los nodos que forman parte de un componente
conexo específico dentro de un grafo no dirigido.
 */
void dfs2(int nodo, vector<int>& componente)
{
    estadoDFS[nodo] = 1;  // Marcar el nodo como visitado
    componente.push_back(nodo);  // Agregar el nodo al componente
    for (auto &[vecino, peso]  : listaAdyacencia[nodo]) {
        if (estadoDFS[vecino] == -1) {  // Si el vecino no ha sido visitado
            dfs2(vecino, componente);  // Llamar recursivamente al DFS
        }
    }
}

/**
Función para leer la entrada y llenar la lista de adyacencia.
Esta función lee la cantidad de nodos, luego para cada nodo, lee sus vecinos y el peso de las aristas que lo conectan.
 
Ejemplo de entrada:
Si tenemos un grafo con 4 nodos (numerados de 0 a 3), con las siguientes conexiones:
 *
Nodo 0: Conectado con nodo 1 (peso 5) y nodo 2 (peso 3)
Nodo 1: Conectado con nodo 3 (peso 2)
Nodo 2: Conectado con nodo 3 (peso 1)
Nodo 3: Sin vecinos.
 *
La entrada sería:
5
2 4 10 1 1
1 2 1
1 3 1
1 4 1
0
Funcionamiento:
La función recorre cada nodo del grafo, lee la cantidad de vecinos del nodo y luego lee cada uno de esos vecinos,
incluyendo el peso de la arista que conecta al nodo con el vecino. Luego, agrega el vecino y el peso a la lista de adyacencia
de dicho nodo.
 */
void llenarListaAdyacencia(int numNodos)
{
    listaAdyacencia.assign(numNodos, vector<pair<int, int>>()); // Inicializar lista de adyacencia

    for (int u = 0; u < numNodos; ++u)
    {
        int numVecinos;
        cin >> numVecinos; // Leer la cantidad de vecinos del nodo `u`

        while (numVecinos--)
        {
            int vecino, peso;
            cin >> vecino >> peso;                         // Leer el vecino y el peso de la arista
            listaAdyacencia[u].emplace_back(vecino, peso); // Agregar el vecino a la lista de `u`
        }
    }
}

/**
Función para llenar la lista de adyacencia de un grafo cuando se conoce el número de aristas.
Esta función toma las aristas directamente como entrada e inserta cada una de ellas en la lista de adyacencia.
Si el grafo es no dirigido, también agrega la arista inversa, de modo que el grafo sea representado bidireccionalmente.

Funcionamiento:
La función `llenarListaAdyacenciaConAristas` comienza inicializando la lista de adyacencia con la cantidad de nodos proporcionados. Luego, lee cada una de las aristas, incluyendo los nodos conectados y el peso de la arista entre ellos. 
En caso de un grafo no dirigido, la función agrega la arista tanto de u a v como de v a u para garantizar la simetría de la conexión.

Ejemplo de uso:
Si se tiene un grafo con 4 nodos (0, 1, 2, 3) y 3 aristas con pesos, el input podría ser el siguiente:

Entrada:
4 3
0 1 10
1 2 20
2 3 30

Si el grafo fuera dirigido, solo se agregarían las aristas de u a v, pero si es no dirigido, se agregarían las dos aristas para representar la simetría de la conexión.
 */
void llenarListaAdyacenciaConAristas(int numNodos, int numAristas)
{
    listaAdyacencia.assign(numNodos, vector<pair<int, int>>()); // Inicializar la lista de adyacencia

    // Leer las aristas
    for (int i = 0; i < numAristas; ++i)
    {
        int u, v, peso;
        cin >> u >> v >> peso; // Leer los nodos u, v y el peso de la arista (u, v, peso)

        // Agregar la arista (u, v) con el peso a la lista de adyacencia de u
        listaAdyacencia[u].emplace_back(v, peso);
        // Si el grafo es no dirigido, también agregamos la arista (v, u)
        listaAdyacencia[v].emplace_back(u, peso);
    }
}

/**
Función para llenar la lista de adyacencia cuando se conoce el número de aristas.
Esta función recibe el número total de nodos y el número de aristas, luego lee cada arista
con su peso y la agrega a la lista de adyacencia de los nodos correspondientes.
Ejemplo de entrada:
Si tenemos un grafo con 4 nodos (numerados de 0 a 3) y 5 aristas con los siguientes detalles:
 *
Arista 1: Conecta nodo 0 con nodo 1 (peso 5)
Arista 2: Conecta nodo 0 con nodo 2 (peso 3)
Arista 3: Conecta nodo 1 con nodo 2 (peso 2)
Arista 4: Conecta nodo 2 con nodo 3 (peso 4)
Arista 5: Conecta nodo 3 con nodo 0 (peso 1)
 *
La entrada sería:
4 5
0 1 5
0 2 3
1 2 2
2 3 4
3 0 1
 *
La salida sería la lista de adyacencia representada por el siguiente arreglo de listas de vecinos y pesos:
 *
listaAdyacencia = [
    [(1, 5), (2, 3), (3, 1)],  // Nodo 0 conecta con Nodo 1 (peso 5), Nodo 2 (peso 3) y Nodo 3 (peso 1)
    [(0, 5), (2, 2)],          // Nodo 1 conecta con Nodo 0 (peso 5) y Nodo 2 (peso 2)
    [(0, 3), (1, 2), (3, 4)],  // Nodo 2 conecta con Nodo 0 (peso 3), Nodo 1 (peso 2) y Nodo 3 (peso 4)
    [(2, 4), (0, 1)]           // Nodo 3 conecta con Nodo 2 (peso 4) y Nodo 0 (peso 1)
]
 *
Funcionamiento:
La función recorre todas las aristas y para cada una, agrega la arista a las listas de adyacencia de los nodos
correspondientes. Si el grafo es no dirigido, la arista se agrega en ambos sentidos, es decir, también se agrega
la arista inversa (v, u) en la lista de adyacencia de v.
 */
int encontrarComponentesConexos(int numNodos)
{
    int numComponentesConexos = 0; // Contador para los componentes conexos
    for (int u = 0; u < numNodos; ++u)
    { // Iterar sobre cada nodo
        if (estadoDFS[u] == -1)
        {                                                                   // Si el nodo no ha sido visitado
            cout << "Componente conexo " << ++numComponentesConexos << ":"; // Incrementar el número de componentes
            dfs(u);                                                         // Realizar DFS desde este nodo
            cout << "\n";
        }
    }
    return numComponentesConexos;
}

/**
Función para encontrar los componentes conexos en el grafo utilizando DFS.
Esta función recorre todos los nodos del grafo y encuentra todos los componentes conexos,
es decir, los grupos de nodos que están interconectados entre sí, ya sea directa o indirectamente.
Ejemplo de entrada:
Imaginemos un grafo con 6 nodos y las siguientes aristas:
0 - 1
1 - 2
3 - 4
 *
La entrada podría ser:
numNodos = 6
 *
Los componentes conexos encontrados serían:
Componente conexo 1: 0 1 2
Componente conexo 2: 3 4
Componente conexo 3: 5
 *
La salida sería un vector de vectores, como sigue:
componentesConexos = [
    [0, 1, 2],  // Componente conexo 1
    [3, 4],     // Componente conexo 2
    [5]         // Componente conexo 3
]
 *
Funcionamiento:
La función inicia recorriendo todos los nodos del grafo. Si un nodo no ha sido visitado, inicia un DFS
a partir de ese nodo para encontrar todos los nodos conectados a él, formando así un componente conexo.
Cada vez que un componente es encontrado, se almacena en el vector `componentesConexos` y se imprime
en la consola. Al final, la función devuelve la lista completa de componentes conexos.
 */
vector<vector<int>> encontrarComponentesConexos2(int numNodos)
{
    vector<vector<int>> componentesConexos;  // Vector para almacenar los componentes conexos
    for (int u = 0; u < numNodos; ++u) {    // Iterar sobre cada nodo
        if (estadoDFS[u] == -1) {  // Si el nodo no ha sido visitado
            vector<int> componente;  // Lista para almacenar los nodos del componente conexo
            cout << "Componente conexo " << componentesConexos.size() + 1 << ": "; // Mostrar número del componente
            dfs2(u, componente);  // Realizar DFS desde este nodo y almacenar los nodos en 'componente'
            componentesConexos.push_back(componente);  // Agregar el componente a la lista de componentes
            cout << "\n";
        }
    }
    return componentesConexos;  // Devolver todos los componentes conexos encontrados
}

/*
Qué hace la función: Esta función implementa el algoritmo de Dijkstra para encontrar el camino más corto entre dos nodos
start y end en un grafo con pesos no negativos en las aristas. La función devuelve la distancia más corta desde el nodo de
inicio hasta el nodo de destino.

Grafos dirigidos: Funciona correctamente, ya que Dijkstra es aplicable a grafos dirigidos siempre que no haya aristas con pesos negativos.
Este algoritmo encuentra la ruta más corta considerando las direcciones de las aristas.

Grafos no dirigidos: También funciona para grafos no dirigidos, pero se debe tener en cuenta que las aristas se añaden como si fueran dirigidas
en ambas direcciones, por lo que el comportamiento es equivalente a un grafo dirigido donde las aristas se consideran en ambas direcciones.
Este comportamiento está manejado en la lista de adyacencia, donde para cada arista `(u, v)`, se almacenan ambas direcciones de la conexión.

Condiciones del grafo: El grafo debe tener aristas con pesos no negativos, ya que Dijkstra no es adecuado para grafos con pesos negativos,
pues no garantiza resultados correctos en esos casos.
*/
int dijkstra(int start, int end, int numNodos)
{
    vector<int> distancia(numNodos, numeric_limits<int>::max());                        // Inicializar todas las distancias como "infinito"
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Cola de prioridad (min-heap)

    distancia[start] = 0; // La distancia desde el nodo `start` a sí mismo es 0
    pq.push({0, start});  // Insertar el nodo de inicio en la cola de prioridad

    while (!pq.empty())
    {
        int d = pq.top().first;  // Distancia actual al nodo `u`
        int u = pq.top().second; // Nodo actual `u`
        pq.pop();

        if (u == end)
            return d; // Si hemos llegado al nodo de destino, devolver la distancia

        if (d > distancia[u])
            continue; // Si la distancia actual no es óptima, ignorarla

        for (auto &[vecino, peso] : listaAdyacencia[u])
        { // Para cada vecino del nodo actual
            if (distancia[u] + peso < distancia[vecino])
            {                                            // Si encontramos una distancia menor
                distancia[vecino] = distancia[u] + peso; // Actualizar la distancia
                pq.push({distancia[vecino], vecino});    // Agregar el vecino a la cola de prioridad
            }
        }
    }
    return -1; // Si no hay camino entre `start` y `end`, retornar -1
}

/*
Qué hace la función: Esta función implementa el algoritmo de Dijkstra para encontrar el camino más corto entre dos nodos
start y end en un grafo con pesos no negativos en las aristas. También devuelve el camino más corto desde el nodo de inicio
 hasta el nodo de destino.
Grafos dirigidos: Funciona correctamente, ya que Dijkstra es aplicable a grafos dirigidos siempre que no haya aristas con pesos negativos.
Grafos no dirigidos: También funciona, pero debes tener en cuenta que las aristas deben añadirse en ambas direcciones.
                     Esto es manejado en el código para grafos no dirigidos, lo que asegura que se traten como si fueran dirigidas en ambas direcciones
*/
pair<int, vector<int>> dijkstra2(int start, int end, int numNodos)
{
    vector<int> distancia(numNodos, numeric_limits<int>::max());                        // Inicializar todas las distancias como "infinito"
    vector<int> predecesor(numNodos, -1);                                               // Vector para almacenar el nodo previo en el camino más corto
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Cola de prioridad (min-heap)

    distancia[start] = 0; // La distancia desde el nodo `start` a sí mismo es 0
    pq.push({0, start});  // Insertar el nodo de inicio en la cola de prioridad

    while (!pq.empty())
    {
        int d = pq.top().first;  // Distancia actual al nodo `u`
        int u = pq.top().second; // Nodo actual `u`
        pq.pop();

        if (u == end)
            break; // Si hemos llegado al nodo de destino, detener la búsqueda

        if (d > distancia[u])
            continue; // Si la distancia actual no es óptima, ignorarla

        for (auto &[vecino, peso] : listaAdyacencia[u])
        { // Para cada vecino del nodo actual
            if (distancia[u] + peso < distancia[vecino])
            {                                            // Si encontramos una distancia menor
                distancia[vecino] = distancia[u] + peso; // Actualizar la distancia
                predecesor[vecino] = u;                  // Almacenar el predecesor de `vecino`
                pq.push({distancia[vecino], vecino});    // Agregar el vecino a la cola de prioridad
            }
        }
    }

    // Reconstruir el camino desde `start` a `end`
    vector<int> camino;
    if (distancia[end] != numeric_limits<int>::max())
    { // Si hay un camino hacia `end`
        for (int at = end; at != -1; at = predecesor[at])
        {
            camino.push_back(at);
        }
        reverse(camino.begin(), camino.end()); // Invertir el camino para que sea de `start` a `end`
    }
    return {distancia[end], camino};
}

// Función para realizar DFS y ordenar los nodos topológicamente
void dfsTopologico(int nodo, vector<bool> &visitado, stack<int> &ordenTopologico)
{
    visitado[nodo] = true;
    for (auto &[vecino, peso] : listaAdyacencia[nodo])
    {
        if (!visitado[vecino])
        {
            dfsTopologico(vecino, visitado, ordenTopologico);
        }
    }
    ordenTopologico.push(nodo); // Después de visitar todos los vecinos, agregar al orden topológico
}

/*
 Esta función calcula el camino más largo en un grafo dirigido acíclico (DAG). Utiliza un orden topológico para recorrer los nodos
 y calcular la distancia más larga desde el nodo start hasta el nodo end.
 Grafos dirigidos acíclicos (DAG): Esta función solo puede ser usada en un grafo dirigido acíclico (DAG), porque utiliza el orden topológico
                                   para recorrer el grafo y calcular el camino más largo. El orden topológico solo es posible en un grafo que
                                   no tenga ciclos (es decir, un DAG).
 Grafos no dirigidos o con ciclos: No funciona en estos casos porque el orden topológico no puede existir en un grafo con ciclos. Los ciclos
                                   crean problemas ya que el algoritmo podría quedarse atrapado en un ciclo infinito.
*/
pair<int, vector<int>> caminoMasLargoDAG(int start, int end, int numNodos)
{
    vector<int> distancia(numNodos, numeric_limits<int>::min()); // Inicializar distancias con un valor muy bajo
    vector<int> predecesor(numNodos, -1);                        // Vector para almacenar el predecesor en el camino más largo
    stack<int> ordenTopologico;
    vector<bool> visitado(numNodos, false);

    // Realizar DFS para obtener el orden topológico de los nodos
    for (int i = 0; i < numNodos; ++i)
    {
        if (!visitado[i])
        {
            dfsTopologico(i, visitado, ordenTopologico);
        }
    }

    // Inicializar la distancia del nodo de inicio
    distancia[start] = 0;

    // Procesar los nodos en orden topológico
    while (!ordenTopologico.empty())
    {
        int u = ordenTopologico.top();
        ordenTopologico.pop();

        // Si la distancia al nodo u es válida, intentar relajación de las aristas
        if (distancia[u] != numeric_limits<int>::min())
        {
            for (auto &[vecino, peso] : listaAdyacencia[u])
            {
                if (distancia[u] + peso > distancia[vecino])
                { // Si encontramos un camino más largo
                    distancia[vecino] = distancia[u] + peso;
                    predecesor[vecino] = u;
                }
            }
        }
    }

    // Reconstruir el camino más largo desde start hasta end
    vector<int> camino;
    if (distancia[end] != numeric_limits<int>::min())
    { // Si hay un camino desde start a end
        for (int at = end; at != -1; at = predecesor[at])
        {
            camino.push_back(at);
        }
        reverse(camino.begin(), camino.end()); // Invertir el camino para que sea desde start a end
    }

    return {distancia[end], camino};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int numNodos;
    cin >> numNodos;

    // Llenar la lista de adyacencia usando la función auxiliar
    llenarListaAdyacencia(numNodos);
    estadoDFS.assign(numNodos, -1); // Inicializar el estado de todos los nodos como no visitados

    int totalComponentesConexos = encontrarComponentesConexos(numNodos);

    // Mostrar el número total de componentes conexos en el grafo
    cout << "Hay " << totalComponentesConexos << " componentes conexos en el grafo\n";

    int start = 0, end = 4;

    /*
    int distanciaMinima = dijkstra(start, end, numNodos);
    if (distanciaMinima != -1)
    {
        cout << "La distancia más corta de " << start << " a " << end << " es " << distanciaMinima << endl;
    }
    else
    {
        cout << "No hay camino de " << start << " a " << end << endl;
    }
    */

    auto [distanciaMinima, camino] = dijkstra2(start, end, numNodos);
    if (distanciaMinima != numeric_limits<int>::max())
    {
        cout << "La distancia mas corta de " << start << " a " << end << " es " << distanciaMinima << endl;
        cout << "El camino es: ";
        for (int nodo : camino)
        {
            cout << nodo << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No hay camino de " << start << " a " << end << endl;
    }

    // ---------------------------------------
    cout << "CAMINO MAS LARGO \n";

    auto [distanciaMasLarga, caminoMasLargo] = caminoMasLargoDAG(start, end, numNodos);

    if (distanciaMasLarga != numeric_limits<int>::min())
    {
        cout << "La distancia mas larga de " << start << " a " << end << " es " << distanciaMasLarga << endl;
        cout << "El camino mas largo es: ";
        for (int nodo : caminoMasLargo)
        {
            cout << nodo << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No hay camino de " << start << " a " << end << endl;
    }
    return 0;
}