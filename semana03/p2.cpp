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
long dijkstra(vector< vector<long> > graph, int src, int len)
{

    int dist[len];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
    bool sptSet[len]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   long maior = 0;
   int id = 0;
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
                if (dist[v] > maior || id == v) {
                    maior = dist[v];
                    id = v;
                }
            }
        }
    }
    return maior;
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
    int num_processors;
    cin >> num_processors;

    vector< vector<long> > m_adjacente_tempo;

    m_adjacente_tempo.resize(num_processors);
    for (int i=0; i<num_processors; i++) {
        m_adjacente_tempo[i].resize(num_processors, -1);
    }
    m_adjacente_tempo[0][0] = 0;

    for (int l=1; l<num_processors; l++) {
        m_adjacente_tempo[l][l] = 0;
        for (int c=0; c<l; c++) {
            string value_str;
            long value;
            cin >> value_str;
            if (value_str == "x") {
                value = -1;
            } else if (value_str[0] != '\0'){
                value = atoi(value_str.c_str());
            }
            m_adjacente_tempo[l][c] = value;
            m_adjacente_tempo[c][l] = value;
        }
    }
    
    long minimo = dijkstra(m_adjacente_tempo, 0, num_processors);
    cout << minimo << endl;
    return 0;
}