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
long dijkstra(vector< vector<int> > graph, int src, int len, int to)
{
	/*

    int dist[len];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i 
    bool sptSet[len]; // sptSet[i] will be true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
    // Initialize all distances as INFINITE and stpSet[] as false
    priority_queue<pair<int, int> > pq; 

    for (int i = 0; i < len; i++) {
        dist[i] = INT_MAX, sptSet[i] = false;
        if (i == src)
        	pq.push(make_pair(0, i))
       	else
       		pq.push(make_pair(INT_MAX, i))
    }

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
    }*/

	if (len == 0)
    	return -1;

    vector<int> dist;
    vector<bool> vis;
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;

    dist.resize(len+1, INT_MAX);
    vis.resize(len+1, false);
    que.push({0, src});
    dist[src] = 0;

    while(!que.empty()) {
        int u = que.top().second;
        que.pop();

        if(vis[u]) continue;

        /*
        for(long i = 0; i < len; i++) {
            long vizinho = graph[u].at(i).first;
            long custo = graph[u].at(i).second;

            if(!vis[vizinho] && dist[vizinho] > dist[u] + custo) {
                dist[vizinho] = dist[u] + custo;
                que.push({dist[vizinho], vizinho});
            }
        }*/

        for (int v = 0; v < len; v++){
        // Update dist[v] only if is not in sptSet, there is an edge from  
        // u to v, and total weight of path from src to  v through u is  
        // smaller than current value of dist[v] 
            if (!vis[v] && graph[u][v] != -1 && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                que.push({dist[v], v});
            }
        }

        vis[u] = true;
    }


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
    long num_cases = 0;
    cin >> num_cases;

    for (int d=0; d<num_cases; d++) {
        int n, m, S, T, len = 1;
        cin >> n;
        cin >> m;
        cin >> S;
        cin >> T;
        if (m == 0) {
        	cout << "Case #" << d+1 << ": ";
        	cout << "unreachable" << endl;
        	continue;
        }


        vector< vector<int> > m_adjacente_tempo;

        vector <pair <int, vector< pair <int, int> > > > m_adacencia;
        m_adacencia.resize(n);

        m_adjacente_tempo.resize(n);


        map<int, int> tradutor = {};

        for (int i=0; i<n; i++) {
        	m_adjacente_tempo[i].resize(n, -1);
        }


        for (int f = 0; f<m; f++) {
        	int P1 , P2;
            int p1, p2, W;

            cin >> P1;
            cin >> P2;
            cin >> W;

            

            if (tradutor[P1] == 0) {
                tradutor[P1] = len;
                p1 = len-1;
                len++;
            } else {
                p1 = tradutor[P1]-1;
            }
            if (tradutor[P2] == 0) {
                tradutor[P2] = len;
                p2 = len-1;
                len++;
            } else {
                p2 = tradutor[P2]-1;
            }

            if (m_adjacente_tempo[p1][p2] == -1 || (m_adjacente_tempo[p1][p2] != -1 && m_adjacente_tempo[p1][p2] > W))
            	m_adjacente_tempo[p1][p2] = m_adjacente_tempo[p2][p1] = W;

        }

        
        cout << "Case #" << d+1 << ": ";
        if ((tradutor[S] == 0 || tradutor[T] == 0) && S != T ) {
            cout << "unreachable" << endl;
            continue;
        }
        int menor;
        menor = dijkstra(m_adjacente_tempo, tradutor[S]-1, len-1, tradutor[T]-1);

        
        if (menor == -1)
        	cout << "unreachable" << endl;
        else
        	cout << menor << endl;

    }
    
    
    
    return 0;
}