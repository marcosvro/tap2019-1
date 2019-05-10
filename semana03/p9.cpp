#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > pi;
typedef pair < int, pi > ppi;

const int INF = 1000000001;

vector < pi > conj_disj (50000);

vector < ppi > edges (100000); // Edges of the graph
vector < int > respostas (100000);
vector < list < int > > conj_ids_consultas (50000);

/*
template<typename T>
std::list<T> intersection_of(const std::list<T>& a, const std::list<T>& b){
    std::list<T> rtn;
    std::unordered_multiset<T> st;
    std::for_each(a.begin(), a.end(), [&st](const T& k){ st.insert(k); });
    std::for_each(b.begin(), b.end(),
        [&st, &rtn](const T& k){
            auto iter = st.find(k);
            if(iter != st.end()){
                rtn.push_back(k);
                st.erase(iter);
            }
        }
    );
    return rtn;
}*/

int findSet(int x) {
	if (x != conj_disj[x].first)
		conj_disj[x].first = findSet(conj_disj[x].first);
	return conj_disj[x].first;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	int peloMenosCaso = 0;

	while (true) {
		//input read
		// edges; // Edges of the graph
		//vector < int > respostas;
		vector < list < int > > conj_ids_consultas;
		int n, m, Q; // Number of vertices and edges
		
		cin >> n >> m;
		
		//cout << n << " " << m << "\n";
		if (cin.fail())
			return 0;
		if (peloMenosCaso)
			cout << "\n";

		//edges.resize( m );
		conj_ids_consultas.resize( n );
		//conj_disj.resize( n );

		for (int i = 0; i < m; i++)
		{
			int from , to , weight;

			cin >> from >> to >> weight;

			//edges[i] = ( {weight , {from , to}} );
			edges[i] = make_pair ( weight , make_pair ( from-1 , to-1 ) );
		}
		cin >> Q;
		//respostas.resize( Q );

		for (int i = 0; i < Q; i++) {
			int from, to;

			cin >> from >> to;

			conj_ids_consultas[from-1].push_back(i);
			conj_ids_consultas[to-1].push_back(i);
		}

		for (int i = 0; i < n; ++i)
		{
			conj_ids_consultas[i].sort();
		}
		//end of input read

		//kruskal
		// Sort edges in increasing order by weight
		vector < ppi >::iterator final_edges = edges.begin()+m;
		sort(edges.begin (), final_edges);
		
		// Create a disjoint set to each vertex
		for (int i=0; i<n; i++) {
			conj_disj[i] = make_pair( i, 0 );
		}

		int c = 1;

		vector < ppi >:: iterator it;
		// Iterate through all sorted edges
		for (it = edges.begin (); c < n; it ++)
		{
			int u = it->second.first;
			int v = it->second.second;
			int weight = it ->first;

			int set_u = findSet( u );
			int set_v = findSet( v );

			if (set_u != set_v)
			{
				// Union of sets of u and v
				if (conj_disj[set_u].second > conj_disj[set_v].second) {
					conj_disj[set_v].first = set_u;
					
					list < int >::iterator u_it = conj_ids_consultas[set_u].begin();
					list < int >::iterator v_it = conj_ids_consultas[set_v].begin();
					while(v_it != conj_ids_consultas[set_v].end()) {
						if (u_it == conj_ids_consultas[set_u].end() || *v_it < *u_it) {
							conj_ids_consultas[set_u].insert(u_it, *v_it);
							advance(v_it, 1);
						} else if (*v_it == *u_it) {
							respostas[*u_it] = weight;
							u_it = conj_ids_consultas[set_u].erase(u_it);
							advance(v_it, 1);
						} else {
							advance(u_it, 1);
						}
					}
					//conj_ids_consultas[set_u].splice(conj_ids_consultas[set_u].begin(), conj_ids_consultas[set_v]);
				} else {
					conj_disj[set_u].first = set_v;
					
					list < int >::iterator u_it = conj_ids_consultas[set_u].begin();
					list < int >::iterator v_it = conj_ids_consultas[set_v].begin();
					while(u_it != conj_ids_consultas[set_u].end()) {
						if (v_it == conj_ids_consultas[set_v].end() || *u_it < *v_it) {
							conj_ids_consultas[set_v].insert(v_it, *u_it);
							advance(u_it, 1);
						} else if (*v_it == *u_it) {
							respostas[*u_it] = weight;
							v_it = conj_ids_consultas[set_v].erase(v_it);
							advance(u_it, 1);
						} else {
							advance(v_it, 1);
						}
					}
					//conj_ids_consultas[set_v].splice(conj_ids_consultas[set_v].begin(), conj_ids_consultas[set_u]);
					if (conj_disj[set_u].second == conj_disj[set_v].second)
						conj_disj[set_v].second++;
				}
				//cout << c << "/" << n << "\n";
				c++;
			}
		}
		//end of kruskal
		//cout << "aqui !!" << "\n";

		for (int i=0; i< Q; i++)
			cout << respostas[i] << "\n";

		peloMenosCaso = 1;
	}

	return 0;
}