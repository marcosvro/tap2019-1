#include <bits/stdc++.h>

// #include <list>
// #include <queue>
// #include <vector>
// #include <iomanip>
// #include <math.h>


using namespace std;

typedef pair< int, int > pi;

const int INF = 1000000001;

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