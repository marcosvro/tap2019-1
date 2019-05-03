#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pi;
typedef pair < int, pi > ppi;

const int INF = 1000000001;

vector < ppi > edges; // Edges of the graph
//priority_queue < ppi, vector< ppi >, less< ppi > > edges;
vector < ppi > mst; // Edges of the MST
vector < int > respostas;
vector < list < int > > conj_ids_consultas;
vector < int > conj_disj;
int n, m, Q; // Number of vertices and edges


void inputRead ()
{
	cin >> n >> m;
	if (cin.fail())
		return 0;
	edges.reserve( m );
	mst.reserve( n - 1 );
	conj_ids_consultas.reserve(n);
	conj_disj.reserve(n);

	for (int i = 0; i < m; i++)
	{
		int from , to , weight;

		cin >> from >> to >> weight;

		// C++11 : edges.push_back( {weight , {from , to}} );
		edges.push_back ( make_pair ( weight , make_pair ( from-1 , to-1 ) ) );
	}
	cin >> Q;
	respostas.reserve(Q);

	for (int i = 0; i < Q; i++) {
		int from, to;

		cin >> from >> to;

		conj_ids_consultas[from-1].push_back(i);
		conj_ids_consultas[to-1].push_back(i);
	}
}

void kruskal ()
{
	// Sort edges in increasing order by weight
	sort(edges.begin (), edges.end ());
	// Create a disjoint set to each vertex
	//disjointSets ds( n );
	for (int i=0; i<n; i++) {
		conj_disj[i] = i;
	}



	int c = 1;

	vector < ppi >:: iterator it;
	// Iterate through all sorted edges
	for (it = edges.begin (); c < n; it ++)
	{
		int u = it ->second.first;
		int v = it ->second.second;
		int weight = it ->first;

		int set_u = ds.find( u );
		int set_v = ds.find( v );

		if (set_u != set_v)
		{
			// Current edge belongs to the MST
			//mst.push_back ( make_pair ( it ->first , make_pair ( u, v ) ) );

			for (list < int >::iterator uit = conj_ids_consultas[u].begin(); uit != conj_ids_consultas[u].end(); uit++) {
				bool erased = false;
				for (list < int >::iterator vit = conj_ids_consultas[v].begin(); vit != conj_ids_consultas[v].end() && uit != conj_ids_consultas[u].end(); vit++) {
					if (*uit == *vit) {
						erased = true;
						conj_ids_consultas[u].erase(*uit);
						conj_ids_consultas[v].erase(*vit);
						continue;
					}
					vit++;
				}
				if (!erased)
					uit++;
			}
			ds.merge( set_u , set_v ); // Union of sets of u and v
			c++;
		}
	}
} // end of kruskal()


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool consecutive_blocks = false;
	while (true) {
		int n, m;
		vector< list< pi > > graph; // Adjacency list
		vector< list< pi > > mst; // Adjacency list
		vector< int > key;            // Keys associated do vertices
		vector< bool > inMST;        // Control vector
		vector< int > parent;

		cin >> n >> m;
		if (cin.fail())
			return 0;

		if(consecutive_blocks)
			cout << "\n";

		key.resize( n, INF );
		inMST.resize( n, false );
		parent.resize( n, -1 );
		graph.resize( n );
		mst.resize ( n );

		for (int i = 0; i < m; i++)
		{
			int from, to, weight;

			cin >> from >> to >> weight;
			if (from == to)
				continue;
			graph[from-1].push_back( make_pair( weight, to-1 ) );
			graph[to-1].push_back( make_pair( weight, from-1 ) );
		}
		//end of read input

		//prim modificado
		int source = 0;
		priority_queue < pi, vector< pi >, greater< pi > > pq;
		pq.push( make_pair( 0, source ) );
		key[source] = 0;

		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();

			inMST[u] = true;
			list< pi >::iterator it;

			
			for (it = graph[u].begin(); it != graph[u].end(); ++it)
			{
				int weight = it->first;
				int v = it->second;

				if ((inMST[v] == false) && (key[v] > weight))
				{
					key[v] = weight;
					parent[v] = u;
					pq.push( make_pair( key[v], v ) );
				}
			}
			if (u != source) {
				mst[u].push_back( make_pair( key[u], parent[u] ) );
				mst[parent[u]].push_back( make_pair( key[u], u ) );
			}
		}
		//end of prim modificado

		//queue's
		int num_queues;
		cin >> num_queues;


		for (int i=0; i<num_queues; i++) {
			int from, to;
			cin >> from >> to;
			from--;
			to--;
			//cout << show_better_in_path(from-1, to-1) << "\n";


			//bfs
			queue< int > q;
			vector< int > dist_to_parent;
			dist_to_parent.resize( n, -1 );

			q.push( from );
			dist_to_parent[from] = 0;

			while (!q.empty())
			{
				int v = q.front();
				q.pop();

				list< pi >::iterator it;
				// Enqueue all adjacent of v and mark them visited
				for (it = mst[v].begin(); it != mst[v].end(); ++it)
				{
					int weight = it->first;
					int vis = it->second;

					if (dist_to_parent[vis] == -1)
					{
						dist_to_parent[vis] = (dist_to_parent[v] > weight)? dist_to_parent[v] : weight;
						if (vis == to){
							break;
						}else
							q.push( vis );
					}
				}
			}
			// end of bfs()

			cout << dist_to_parent[to] << "\n";
			consecutive_blocks = true;
		}
	}
	return 0;
}