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
vector< list< pfi > > graph; // Adjacency list
vector< float > key;            // Keys associated do vertices
vector< int > parent;        // Store the MST
vector< bool > inMST;        // Control vector
vector< pi > points;
int n, m;
double cost_total = 0;
// Number of vertices and edges

float dist_euclidiana(pi p1, pi p2)
{
	return sqrt( (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second) );
}

int inputRead()
{
	cin >> n;
	if (cin.fail())
		return 0;

	key.resize( n, INF );
	parent.resize( n, -1 );
	inMST.resize( n, false );
	graph.resize( n );
	points.resize( n );
	cost_total = 0.0;

	for (int i = 0, x, y; i<n; i++)
	{
		cin >> x >> y;
		points[i] = make_pair (x, y);
		key[i] = INF;
		parent[i] = -1;
		inMST[i] = false;
		graph[i].clear();
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, weight = 0.0;

		cin >> from >> to;
		graph[from-1].push_back( make_pair( weight, to-1 ) );
		graph[to-1].push_back( make_pair( weight, from-1 ) );
	}
	return 1;
}

void prim_modificado( int source )
{
	// Min heap to store vertices already in the MST,
	// where: first = key, second = vertex
	int i = 0;
	priority_queue < pfi, vector< pfi >, greater< pfi > > pq;
	pq.push( make_pair( 0.0, source ) );
	list <int> nodesInMST;

	key[source] = 0.0;
	

	while (!pq.empty() || i < n)
	{
		int u;
		if (!pq.empty()) {
			//pega visinho de alguem que já foi marcado
			u = pq.top().second;
			pq.pop();
		} else {
			//pega o ponto mais proximo não marcado (busca quadratica)
			float menor_dist = (float)INF;
			int de, para;
			for (list <int>::iterator ite = nodesInMST.begin(); ite != nodesInMST.end(); ite++) 
			{
				for (int j=0; j<n; j++) {
					if (!inMST[j]) {
						float dist = dist_euclidiana(points[*ite], points[j]);
						if (menor_dist > dist) {
							menor_dist = dist;
							para = j;
							de = *ite;
						}
					}
				}
			}

			if (menor_dist == (float)INF) //acho que isso nunca vai acontecer
				return;

			key[para] = menor_dist;
			parent[para] = de;
			cost_total += menor_dist;
			u = para;
		}
		

		inMST[u] = true; // Include vertex in MST
		nodesInMST.push_back(u);
		list< pfi >::iterator it;

		for (it = graph[u].begin(); it != graph[u].end(); ++it)
		{
			// Get label and weight of the vertex adjacent to u.
			float weight = it->first;
			int v = it->second;

			// v is not in MST and weight of (u,v) is smaller
			// than current key of v?
			if ((inMST[v] == false) && (key[v] > weight))
			{
				key[v]     = weight;
				parent[v] = u;
				pq.push( make_pair( key[v], v ) );
			}
		}

		i++;
	}
} // end of prim()

int main() {

	cout << fixed;
    cout << setprecision(2);
	while (inputRead()) {
		prim_modificado(0);

		//cost_total = roundf(cost_total * 100) / 100;
		cout << cost_total << endl;
	}
	return 0;
}