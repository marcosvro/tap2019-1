#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

typedef pair< int, int > pi;
typedef pair< float, int > pfi;

const int INF = 0x3f3f3f3f;
// Be carefull with this value!
vector< list< pi > > graph; // Adjacency list
vector< int > key;            // Keys associated do vertices
vector< int > parent;        // Store the MST
vector< bool > inMST;        // Control vector
vector< pi > points;
int n, m;
int minimum_capacity;
// Number of vertices and edges

float dist_euclidiana(pi p1, pi p2)
{
	return sqrt( (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second) );
}

int inputRead()
{
	cin >> n >> m;
	if (cin.fail())
		return 0;

	key.resize( n, -1 );
	parent.resize( n, -1 );
	inMST.resize( n, false );
	graph.resize( n );
	points.resize( n );
	minimum_capacity = INF;

	for (int i = 0, x, y; i<n; i++)
	{
		points[i] = make_pair (x, y);
		key[i] = -1;
		parent[i] = -1;
		inMST[i] = false;
		graph[i].clear();
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, weight;

		cin >> from >> to >> weight;
		if (from == to)
			continue;

		graph[from].push_back( make_pair( weight, to ) );
		graph[to].push_back( make_pair( weight, from ) );

	}
	return 1;
}

void prim_modificado( int source )
{
	// Min heap to store vertices already in the MST,
	// where: first = key, second = vertex
	priority_queue < pi, vector< pi >, less< pi > > pq;
	pq.push( make_pair( INF, source ) );

	key[source] = INF;

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
			float weight = it->first;
			int v = it->second;

			// v is not in MST and weight of (u,v) is smaller
			// than current key of v?
			if ((inMST[v] == false) && (key[v] < weight))
			{
				key[v] = weight;
				parent[v] = u;
				pq.push( make_pair( key[v], v ) );
			}
		}

	}
	vector< int >::iterator it;
	for (it = key.begin(); it != key.end(); it++) 
		if (*it != -1 && *it < minimum_capacity)
			minimum_capacity = *it;
} // end of prim()

int main() {

	int num_cases;
    cin >> num_cases;

	for (int i=0; i<num_cases; i++) {
		inputRead();
		prim_modificado(0);

		cout << "Case #" << i+1 << ": " << minimum_capacity << endl;
	}
	return 0;
}