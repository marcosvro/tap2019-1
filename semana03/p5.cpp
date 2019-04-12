#include<bits/stdc++.h>
//#include <stdio.h> 
//#include <limits.h>

using namespace std;

vector <int> dist_jovem;
vector <int> dist_adulto;

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[], int len)
{
   // Initialize min value 
   int min = INT_MAX, min_index;
   
   for (int v = 0; v < len; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
}

// A utility function to print the constructed distance array 
int printSolution(int dist[], int n) 
{ 
   printf("Vertex   Distance from Source\n"); 
   for (int i = 0; i < n; i++) 
      printf("%d tt %d\n", i, dist[i]); 
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
long dijkstra(vector< vector<int> > graph, int src, int len, int to)
{

    int dist[len];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
    bool sptSet[len]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
     // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < len; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
    // Distance of source vertex from itself is always 0 
    dist[src] = 0;
    
    // Find shortest path for all vertices 
    for (int count = 0; count < len-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 

        int u = minDistance(dist, sptSet, len); 
   
       // Mark the picked vertex as processed 
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < len; v++){
        // Update dist[v] only if is not in sptSet, there is an edge from  
        // u to v, and total weight of path from src to  v through u is  
        // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] != -1 && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    //cout << "Aqui 223" << endl;
    if (dist[to] == INT_MAX)
        return -1;
    else
        return dist[to];
}

//function for printing the elements in a list 
void showlist(list <char> g) 
{ 
    list <char> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << " " << *it;
}

//function for printing the elements in a list 
void showlistInt(int *g, int len) 
{ 
     
    for(int it = 0; it < len; ++it) 
        cout << " " << g[it];
}

void showMat(vector < vector<int> > m, int l) {
    for (int i=0; i<l; i++) {
        for (int j=0; j<l; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int c = 0;
    int num_cases;
    cin >> num_cases;

    for (int d=0; d<num_cases; d++) {
        int n, m, S, T, len = 1;
        cin >> n;
        cin >> m;
        cin >> S;
        cin >> T;
        vector< vector<int> > m_adjacente_tempo;
        m_adjacente_tempo.resize(m+1);

        map<int, int> tradutor = {};
        map<int, int> decodificador = {};

        for (int i=0; i<m+1; i++) {
            m_adjacente_tempo[i].resize(m+1, -1);
        }

        for (int f = 0; f<m; f++) {
            int P1, P2, p1, p2, W;

            cin >> P1;
            cin >> P2;
            cin >> W;

            if (tradutor[P1] == 0) {
                tradutor[P1] = len;
                decodificador[len] = P1;
                p1 = len-1;
                len++;
            } else {
                p1 = tradutor[P1]-1;
            }
            if (tradutor[P2] == 0) {
                tradutor[P2] = len;
                decodificador[len] = P2;
                p2 = len-1;
                len++;
            } else {
                p2 = tradutor[P2]-1;
            }

            m_adjacente_tempo[p1][p2] = m_adjacente_tempo[p2][p1] = W;
        }

        if (d == 27)
            cout << "aqui" << endl << tradutor[S] << " " << tradutor[T] << " " << len << endl;
        int menor = dijkstra(m_adjacente_tempo, tradutor[S]-1, len-1, tradutor[T]-1);

        cout << "Case #" << d+1 << ": ";
        if (menor == -1 || ((tradutor[S] == 0 || tradutor[T] == 0) && S != T ))
            cout << "unreachable" << endl;
        else
            cout << menor << endl;

    }
    
    
    
    return 0;
}