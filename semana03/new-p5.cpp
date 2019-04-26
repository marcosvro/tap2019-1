#include<bits/stdc++.h>
//#include <stdio.h> 
//#include <limits.h>

using namespace std;


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
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		if (dist[dest] == INT_MAX)
			return -1;
		else
			return dist[dest];
	}
};



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


        map<int, int> tradutor = {};
        Grafo g(n+1);


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
            

            g.addAresta(p1, p2, W);
            
            g.addAresta(p2, p1, W);
            
        }

        
        cout << "Case #" << d+1 << ": ";
        if ((tradutor[S] == 0 || tradutor[T] == 0) && S != T ) {
            cout << "unreachable" << endl;
            continue;
        }
        int menor;
        menor = g.dijkstra(tradutor[S]-1, tradutor[T]-1);
        
        if (menor == -1)
        	cout << "unreachable" << endl;
        else
        	cout << menor << endl;

    }
    
    
    
    return 0;
}