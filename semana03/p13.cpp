#include <bits/stdc++.h>
using namespace std;

typedef pair< int, int > pi;
const int INF = 1000000001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		int n, m;
		vector< list< int > > graph; // Adjacency list
		vector< char > visited;        // Control vector

		//read input
		cin >> n >> m;
		if (cin.fail() || n == 0)
			return 0;

		visited.resize( n, 0 );
		graph.resize( n );

		for (int i = 0; i < m; i++)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back( to );
			graph[to].push_back( from );
		}
		//end of read input

		queue< int > q;
		q.push( 0 );
		visited[0] = 1; //atribui cor 1 para o vertice raiz
		bool bicolorable = true;

		//start of bfs
		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			list< int >::iterator it;
			// Enqueue all adjacent of v and mark them visited
			for (it = graph[v].begin(); it != graph[v].end(); ++it)
			{
				if (visited[v] != visited[*it])
				{
					if (visited[*it] == 0){
						visited[*it] = (visited[v] == 1)? 2: 1;
						q.push(*it);
					}
				} else {
					bicolorable = false;
					break;
				}
			}
		}
		// end of bfs()

		if (bicolorable)
			cout << "BICOLORABLE." << "\n";
		else
			cout << "NOT BICOLORABLE." << "\n";
	}
	return 0;
}