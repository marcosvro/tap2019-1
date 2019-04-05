#include<bits/stdc++.h>
//#include <stdio.h> 
//#include <limits.h>

using namespace std;

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
int* dijkstra(vector< vector<int> > graph, int src, int len, vector< vector<int> > idade, int op)
{
     int *dist = (int*) malloc(sizeof(int)*(len-1));     // The output array.  dist[i] will hold the shortest 
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
         if (!sptSet[v] && graph[u][v] && idade[u][v] == op && dist[u] != INT_MAX  
                                       && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
   
     // print the constructed distance array 
     //printSolution(dist, len);
     return dist;
     
}

//function for printing the elements in a list 
void showlist(list <char> g) 
{ 
    list <char> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << " " << *it;
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
    while (1) {
        int op, id_jovem_pos, id_adulto_pos;
        char JOVEM_POS, ADULTO_POS;

        cin >> op;
        map<char, int> tradutor = {};
        map<int, char> decodificador = {};
        vector< vector<int> > m_adjacente;
        vector< vector<int> > m_idade;

        if(op == 0)
            break;
        int max_len = 2*op;
        int len = 1;
        m_adjacente.resize(max_len);
        m_idade.resize(max_len);
        for (int i=0; i<max_len; i++) {
            m_adjacente[i].resize(max_len, 0);
            m_idade[i].resize(max_len, 0);
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
                m_adjacente[p1][p2] = w;
                m_idade[p1][p2] = op;
            } else { //bilateral
                m_adjacente[p1][p2] = w;
                m_adjacente[p2][p1] = w;
                m_idade[p1][p2] = op;
                m_idade[p2][p1] = op;
            }
        }
        cin >> JOVEM_POS;
        cin >> ADULTO_POS;

        if (tradutor[JOVEM_POS == 0]) {
            tradutor[JOVEM_POS] = len;
            id_jovem_pos = len-1;
            len++;
        } else {
            id_jovem_pos = tradutor[JOVEM_POS]-1;
        }
        if (tradutor[ADULTO_POS == 0]) {
            tradutor[ADULTO_POS] = len;
            id_adulto_pos = len-1;
            len++;
        } else {
            id_adulto_pos = tradutor[ADULTO_POS]-1;
        }

        int *dist_jovem = dijkstra(m_adjacente, id_jovem_pos, len-1, m_idade, -1);
        int *dist_adulto = dijkstra(m_adjacente, id_adulto_pos, len-1, m_idade, 1);

        int ind_menor_lugar;
        int menor_custo = INT_MAX;
        int soma_acumulada[len-1];


        for(int i=0; i<len-1; i++) {
            int soma;
            
            if (dist_jovem[i] == INT_MAX || dist_adulto[i] == INT_MAX)
                soma = soma_acumulada[i] = INT_MAX;
            else
                soma = soma_acumulada[i] = dist_adulto[i]+dist_jovem[i];
            
            //cout << "Aqui !!" << endl;
            if (soma < menor_custo)
                menor_custo = soma, ind_menor_lugar=i;
        }

        if (menor_custo == INT_MAX) {
            cout << "You will never meet." << endl;
            break;
        }


        list <char> lista_final;
        for (int i=0; i<len-1; i++) {
            if (soma_acumulada[i] == menor_custo) {
                lista_final.push_back(decodificador[i+1]);
            }
        }

        lista_final.sort();
        cout << menor_custo << " ";
        showlist(lista_final);
        cout << endl;

        free(dist_jovem);
        free(dist_adulto);
    }
    return 0;
}