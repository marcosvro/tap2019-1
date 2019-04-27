#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <iomanip>
#include <math.h>

using namespace std;

typedef pair< int, int > pi;
typedef pair< float, int > pfi;
typedef pair< float, float > pf;

const int INF = 0x3f3f3f3f;
// Be carefull with this value!
vector< list< pfi > > graph; // Adjacency list
vector< double > key;            // Keys associated do vertices
vector< int > parent;        // Store the MST
vector< bool > inMST;        // Control vector
vector< pf > points;
int n, m;
double cost_total = 0;
// Number of vertices and edges



double dist_euclidiana(pf p1, pf p2)
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


	for (int i = 0; i<n; i++)
	{
		float x, y;
		cin >> x >> y;
		points[i] = make_pair (x, y);
		key[i] = INF;
		parent[i] = -1;
		inMST[i] = false;
		graph[i].clear();
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
			double menor_dist = (double)INF;
			int de, para;
			for (list <int>::iterator ite = nodesInMST.begin(); ite != nodesInMST.end(); ite++) 
			{
				for (int j=0; j<n; j++) {
					if (!inMST[j]) {
						double dist = dist_euclidiana(points[*ite], points[j]);
						if (menor_dist > dist) {
							menor_dist = dist;
							para = j;
							de = *ite;
						}
					}
				}
			}

			if (menor_dist == (double)INF) //acho que isso nunca vai acontecer
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
    int num_cases;
    cin >> num_cases;
	for (int i =0; i<num_cases; i++) {
		inputRead();
		prim_modificado(0);

		//cost_total = roundf(cost_total * 100) / 100;
		cout << cost_total << endl;
		if (i != num_cases-1)
			cout << endl;
	}
	return 0;
}