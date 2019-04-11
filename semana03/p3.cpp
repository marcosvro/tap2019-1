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
void dijkstra(vector< vector<int> > graph, int src, int len, int op)
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
        for (int v = 0; v < len; v++)
        // Update dist[v] only if is not in sptSet, there is an edge from  
        // u to v, and total weight of path from src to  v through u is  
        // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] != -1 && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
    
    // print the constructed distance array 
    //printSolution(dist, len);
    if (op == -1) {
        dist_jovem.resize(len);
        for (int i=0; i<len; i++)
            dist_jovem[i] = dist[i];
    } else {
        dist_adulto.resize(len);
        for (int i=0; i<len; i++)
            dist_adulto[i] = dist[i];
    }
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
    while (1) {
        int op, id_jovem_pos, id_adulto_pos;
        char JOVEM_POS, ADULTO_POS;

        cin >> op;
        map<char, int> tradutor = {};
        map<int, char> decodificador = {};
        vector< vector<int> > m_adjacente_jovem;
        vector< vector<int> > m_adjacente_adulto;

        if(op == 0)
            break;
        int max_len = 2*op + 2;
        int len = 1;
        m_adjacente_jovem.resize(max_len);
        m_adjacente_adulto.resize(max_len);
        for (int i=0; i<max_len; i++) {
            m_adjacente_jovem[i].resize(max_len, -1);
            m_adjacente_adulto[i].resize(max_len, -1);
        }

        for(int i=0; i<op; i++) {
            char I, T, P1, P2;
            int w, op = 0, p1, p2;

            cin >> I;
            if (I == 'Y') {
                op = -1; //pista jovem
            } else {
                op = 1; //pista adulta
            }

            cin >> T;
            cin >> P1;
            cin >> P2;
            cin >> w;

            if (c == 802) {
                cout << I << " " << T << " " << P1 << " " << P2 << " " << w << endl;
            }
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

            if (T == 'U') { //unilateral
                if (op == -1)
                    m_adjacente_jovem[p1][p2] = w;
                else
                    m_adjacente_adulto[p1][p2] = w;
            } else { //bilateral
                if (op == -1) {
                    m_adjacente_jovem[p1][p2] = w;
                    m_adjacente_jovem[p2][p1] = w;
                } else {
                    m_adjacente_adulto[p1][p2] = w;
                    m_adjacente_adulto[p2][p1] = w;
                }
            }
        }
        cin >> JOVEM_POS;
        cin >> ADULTO_POS;

        //if (c == 802)
        //cout << JOVEM_POS << " " << ADULTO_POS << endl;

        if (tradutor[JOVEM_POS] == 0) {
            tradutor[JOVEM_POS] = len;
            decodificador[len] = JOVEM_POS;
            id_jovem_pos = len-1;
            len++;
        } else {
            id_jovem_pos = tradutor[JOVEM_POS]-1;
        }
        if (tradutor[ADULTO_POS] == 0) {
            tradutor[ADULTO_POS] = len;
            decodificador[len] = ADULTO_POS;
            id_adulto_pos = len-1;
            len++;
        } else {
            id_adulto_pos = tradutor[ADULTO_POS]-1;
        }

        //cout << tradutor[JOVEM_POS] << " " << tradutor[ADULTO_POS] << " " << len << endl;

        dijkstra(m_adjacente_jovem, id_jovem_pos, len-1, -1);
        dijkstra(m_adjacente_adulto, id_adulto_pos, len-1, 1);


        int ind_menor_lugar;
        int menor_custo = INT_MAX;
        int soma_acumulada[len-1];
        int max = INT_MAX;
        
        
        for(int i=0; i<len-1; i++) {
            int soma;
            
            if (dist_jovem[i] == max || dist_adulto[i] == max)
                soma = soma_acumulada[i] = max;
            else
                soma = soma_acumulada[i] = dist_adulto[i]+dist_jovem[i];
            
            if (soma < menor_custo)
                menor_custo = soma, ind_menor_lugar=i;
        }

        if (menor_custo == max) {
            cout << "You will never meet." << endl;
            continue;
        }
                
        list <char> lista_final;
        for (int i=0; i<len-1; i++) {
            if (soma_acumulada[i] == menor_custo) {
                lista_final.push_back(decodificador[i+1]);
            }
        }
        lista_final.sort();
        cout << menor_custo;
        showlist(lista_final);
        cout << endl;
        c++;
    }
    return 0;
}