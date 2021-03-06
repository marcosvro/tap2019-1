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
int dijkstra(vector< vector<int> > graph, vector< vector<int> > graph_dist, int src, int len, int to, int* resp)
{

    int tempo[len];
    int dist[len];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
    bool sptSet[len]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < len; i++) 
        dist[i] = INT_MAX, tempo[i] = INT_MAX, sptSet[i] = false; 
   
    // Distance of source vertex from itself is always 0 
    dist[src] = 0;
    tempo[src] = 0;
    
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
            if (!sptSet[v] && graph[u][v] != -1 && dist[u] != INT_MAX && (dist[u]+graph[u][v] < dist[v] or (dist[u]+graph[u][v] == dist[v] and tempo[u]+graph_dist[u][v] < tempo[v]))) {
                dist[v] = dist[u] + graph[u][v];
                tempo[v] = tempo[u]+graph_dist[u][v];
            }
        }
    }
    //printSolution(tempo, len);
    if (dist[to] != INT_MAX) {
        resp[0] = dist[to]; //tempo
        resp[1] = tempo[to]; //dist
        return 1;
    }
    return -1;
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
    int num_blocks;
    cin >> num_blocks;
    for (int l=0; l<num_blocks; l++) {
        int num_cidades, num_estradas;
        cin >> num_cidades;
        cin >> num_estradas;

        map<long, int> tradutor = {};
        map<int, long> decodificador = {};
        vector< vector<int> > m_adjacente_tempo;
        vector< vector<int> > m_adjacente_dist;

        int max_len = 25;
        int len = num_cidades != 0? 1: 0;
        m_adjacente_tempo.resize(max_len);
        m_adjacente_dist.resize(max_len);
        for (int i=0; i<max_len; i++) {
            m_adjacente_tempo[i].resize(max_len, -1);
            m_adjacente_dist[i].resize(max_len, -1);
        }

        for(int i=0; i<num_estradas; i++) {
            long L, T, P1, P2;
            int p1, p2;

            cin >> P1;
            cin >> P2;
            cin >> T;
            cin >> L;

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
            if (m_adjacente_dist[p1][p2] == -1 || m_adjacente_tempo[p1][p2] == -1 || m_adjacente_tempo[p1][p2] > T || (m_adjacente_tempo[p1][p2] == T && m_adjacente_dist[p1][p2] > L)) {
                m_adjacente_tempo[p1][p2] = m_adjacente_tempo[p2][p1] = T;
                m_adjacente_dist[p1][p2] = m_adjacente_dist[p2][p1] = L;
            }
        }
        int num_queries;
        cin >> num_queries;
        for (int k=0; k<num_queries; k++) {
            int fim1, fim2;
            cin >> fim1;
            cin >> fim2;
            int resp[2];

            if ((tradutor[fim1] == 0 || tradutor[fim2] == 0) && fim1 != fim2) { //ainda n apareceu na lista de caminhos
                cout << "No Path." << endl;
                continue;
            } else if (fim1 == fim2) {
                cout << "Distance and time to reach destination is 0 & 0." << endl;
                continue;
            }

            int foi = dijkstra(m_adjacente_tempo, m_adjacente_dist, tradutor[fim1]-1, len, tradutor[fim2]-1, resp);

            if (foi == -1) {
                cout << "No Path." << endl;
            } else {
                cout << "Distance and time to reach destination is " << resp[1] << " & " << resp[0] << "." << endl;
            }
        }
        if (l != num_blocks-1)
            cout << endl;
    }
    return 0;
}