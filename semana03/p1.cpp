#include<bits/stdc++.h>
//#include <stdio.h> 
//#include <limits.h>

using namespace std;


void show_min_path (int * de_onde, int meu_pai, int src){
	if (meu_pai == src) {
		cout << meu_pai;
	} else {
		int pai_do_meu_pai = de_onde[meu_pai];
		show_min_path(de_onde, pai_do_meu_pai, src);
		cout << " " << meu_pai;
	}
}

class Grafo
{
private:
	int V; // número de vértices

	// ponteiro para um array contendo as listas de adjacências
	list<pair<int, int> > * adj;

public:

	// construtor
	Grafo(int V)
	{
		this->V = V; // atribui o número de vértices

		/*
			cria as listas onde cada lista é uma lista de pairs
			onde cada pair é formado pelo vértice destino e o custo
		*/
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de v1 à v2
	void addAresta(int v1, int v2, int custo)
	{
		list<pair <int,int> >::iterator exist = get_cost(v1,v2);
		
		if (exist != adj[v1].end()) 
			if((*exist).second > custo)
				(*exist).second = custo;
			else
				return;
		else {
			adj[v1].push_back(make_pair(v2, custo));
		}
		//bool even(const pair<int,int>& value) { return (value.first == v2 && value.second > ); }
		//adj[v1].remove_if(even);
		
	}

	list<pair <int , int> >::iterator get_cost(int v1, int v2) {
		list<pair<int, int> >::iterator it = adj[v1].begin();
		
		int i = 0;
		while (it != adj[v1].end()) {
			if ((*it).first == v2)
			{
				return it;
			}
			i++;
			++it;
		}
		return it;
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest)
	{
		// vetor de distâncias
		int dist[V];
		int de_onde[V];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++)
		{
			de_onde[i] = -1;
			dist[i] = INT_MAX;
			visitados[i] = false;
		}

		// a distância de orig para orig é 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						de_onde[v] = u;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		if (dist[dest] == INT_MAX)
			return -1;
		else {
			show_min_path(de_onde, dest, orig);
			return dist[dest];
		}
	}
};



int main() {
    long num_inter = 0, contador = 1;
    cin >> num_inter;

    while(num_inter != 0) {
    	Grafo g(num_inter+1);
    	for (int i = 1; i <= num_inter; ++i)
    	{
    		int num_arestas;
    		cin >> num_arestas;
    		for (int k = 1; k <= num_arestas; ++k)
    		{
    			int to, W;
    			cin >> to;
    			cin >> W;

    			g.addAresta(i, to, W);
    		}
    	}

        int S, T;
        cin >> S;
        cin >> T;

        cout << "Case " << contador  << ": Path = ";
        int menor = g.dijkstra(S, T);
        cout << "; " << menor << " second delay" << endl;

        cin >> num_inter; 
        contador++;
    }
    
    
    
    return 0;
}