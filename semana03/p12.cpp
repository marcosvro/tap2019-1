#include <bits/stdc++.h>
#include <list>

using namespace std;


const int INF = 0x3f3f3f3f;

//map< pair< string, string >, int > encoder;
//vector< list< int > > graph; // Adjacency list
vector < int > parent;
//vector < int > dist;



int main() {
	long num_cases;
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	cin >> num_cases;

	for (int i = 0; i < num_cases; ++i)
	{
		map< pair< string, string >, int > encoder;
		vector< list< int > > graph; // Adjacency list
		vector < int > dist;
		int n;            // Number of vertices and edges
		int p, qn;

		cout << "Scenario " << i+1 << "\n";

		//start input
		string first_name, second_names;
		char test;
		long num_auth = 1;

		cin >> p >> qn;

		graph.resize( p*5 + 1 );

		encoder[make_pair("Erdos","P.")] = num_auth;
		num_auth++;

		for (int l = 0; l < p; ++l)
		{
			list < int > autores_ids;
			do {
				cin >> first_name >> second_names;
				if (cin.fail())
					return 0;
				if (first_name.front() == ':')
					break;
				test = second_names.back();
				second_names.pop_back();
				first_name.pop_back();
				pair < string,string > autor = make_pair(first_name, second_names);

				if (encoder[autor] == 0){ // não existe esse autor no DB 
					encoder[autor] = num_auth;
					num_auth++;
					if (num_auth >= p*5) {
						graph.resize( num_auth );
					}
				}
				autores_ids.push_back( encoder[autor]-1 );
			} while (test != ':');

			for (list<int>::iterator it1 = autores_ids.begin(); it1 != autores_ids.end(); ++it1)
			{
				for (list<int>::iterator it2 = autores_ids.begin(); it2 != autores_ids.end(); ++it2)
				{
					if (*it1 != *it2)
						graph[*it1].push_back(*it2);
				}
			}

			getline(cin, first_name);
		}

		n = num_auth-1;

		dist.resize( n , INF );


		//end input

		//start bfs
		int source = 0;
		queue< int > q;

		q.push( source );
		dist[source] = 0; 

		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			list< int >::iterator it;
			// Enqueue all adjacent of v and mark them visited
			for (it = graph[v].begin(); it != graph[v].end(); ++it)
			{
				if (dist[*it] == INF)
				{
					q.push( *it );
					dist[*it] = dist[v] + 1;
				}
			}
		}
		//end bfs

		for (int j = 0; j < qn; ++j)
		{
			cin >> first_name >> second_names;
			first_name.pop_back();
			pair < string, string > aux = make_pair(first_name, second_names);
			if (encoder[aux] == 0) {
				cout << first_name << ", " << second_names << " infinity" << "\n";
			} else {
				if (dist[encoder[aux]-1] == INF)
					cout << first_name << ", " << second_names << " infinity" << "\n";
				else
					cout << first_name << ", " << second_names << " " << dist[encoder[aux]-1] << "\n";
			}
		}
	}
	return 0;
}