#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

typedef pair< int, int > pi;
typedef pair< float, int > pfi;

const int INF = 1000000001;
// Be carefull with this value!
vector< list< pi > > graph; // Adjacency list
vector< list< pi > > mst; // Adjacency list
vector< int > key;            // Keys associated do vertices
vector< int > parent;        // Store the MST
vector< bool > inMST;        // Control vector
int n, m;
// Number of vertices and edges


int inputRead()
{
	cin >> n >> m;
	if (cin.fail())
		return 0;

	key.resize( n, -1 );
	parent.resize( n, -1 );
	inMST.resize( n, false );
	graph.resize( n );
	mst.resize( n );

	for (int i = 0, x, y; i<n; i++)
	{
		key[i] = INF;
		parent[i] = -1;
		inMST[i] = false;
		graph[i].clear();
		mst[i].clear();
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, weight;

		cin >> from >> to >> weight;
		if (from == to)
			continue;
		graph[from-1].push_back( make_pair( weight, to-1 ) );
		graph[to-1].push_back( make_pair( weight, from-1 ) );

	}
	return 1;
}

void prim_modificado( int source )
{
	// Min heap to store vertices already in the MST,
	// where: first = key, second = vertex
	priority_queue < pi, vector< pi >, greater< pi > > pq;
	pq.push( make_pair( 0, source ) );

	key[source] = 0;

	while (!pq.empty())
	{
		//pega visinho de alguem que já foi marcado
		int u = pq.top().second;
		pq.pop();

		inMST[u] = true; // Include vertex in MST
		list< pi >::iterator it;

		for (it = graph[u].begin(); it != graph[u].end(); ++it)
		{
			// Get label and weight of the vertex adjacent to u.
			int weight = it->first;
			int v = it->second;

			// v is not in MST and weight of (u,v) is smaller
			// than current key of v?
			if ((inMST[v] == false) && (key[v] > weight))
			{
				key[v] = weight;
				parent[v] = u;
				pq.push( make_pair( key[v], v ) );
			}
		}
	}

	for (int p1=0, p2; p1<n; p1++) {
		if (p1 == source)
			continue;
		p2 = parent[p1];
		mst[p1].push_back( make_pair( key[p1], p2 ) );
		mst[p2].push_back( make_pair( key[p1], p1 ) );
	}
} // end of prim()

int search_better_in_path(int from, int to, int atual, int anterior){
	if (atual == to) // cheguei no nó objetivo
		return 0;
	if (mst[atual].size() == 1 && from != atual) // nó folha sem ser o atual
		return -1;

	list< pi >::iterator it;
	for (it = mst[atual].begin(); it!=mst[atual].end(); ++it)
	{
		int weight = it->first;
		int v = it->second;
		int ret;

		if (v != anterior){
			ret = search_better_in_path(from, to, v, atual);
			if (ret != -1)
				return (ret > weight)?ret : weight;
		}
	}
	return -1;
}

int show_better_in_path(int from, int to) {
	if (from == to)
		return 0;
	int maior_from = 0, maior_to = 0, pai_from = from, pai_to = to;

	for (pai_from = from; pai_from != -1; pai_from=parent[pai_from]) {
		pai_to = to;
		maior_to = 0;
		for (pai_to = to; pai_to != -1; pai_to=parent[pai_to]){
			
			if (pai_from == pai_to){
				return (maior_from > maior_to)?maior_from : maior_to;
			}

			if (key[pai_to] > maior_to){
				maior_to = key[pai_to];
			}
		}

		if (key[pai_from] > maior_from){
			maior_from = key[pai_from];
		}
	}
}
int main() {
	while (inputRead()) {
		prim_modificado(0);
		int num_queues;
		cin >> num_queues;

		for (int i=0; i<num_queues; i++) {
			int from, to;
			cin >> from >> to;
			//cout << show_better_in_path(from-1, to-1) << endl;
			cout << search_better_in_path(from-1, to-1, from-1, -1) << endl;
		}
		cout << endl;
	}
	return 0;
}