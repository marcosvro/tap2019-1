#include <bits/stdc++.h>
#include <list>

using namespace std;


const int INF = 0x3f3f3f3f;

//map< pair< string, string >, int > encoder;
//vector< list< int > > graph; // Adjacency list
vector < int > parent;
//vector < int > dist;

int n;            // Number of vertices and edges
int p, qn;

/*
int inputRead()
{
	string first_name, second_names;
	char test;
	int num_auth = 1;

	cin >> p >> qn;

	encoder.clear();
	graph.resize( p*5 );
	

	for (int l = 0; l < p*5; ++l)
	{
		graph[l].clear();
	}

	encoder[make_pair("Erdos","P.")] = num_auth;
	num_auth++;

	for (int l = 0; l < p; ++l)
	{
		list < int > autores_ids;

		do
		{
			cin >> first_name >> second_names;
			test = second_names.back();
			second_names.pop_back();
			first_name.pop_back();
			pair < string,string > autor = make_pair(first_name, second_names);

			if (encoder[autor] == 0){ // não existe esse autor no DB 
				encoder[autor] = num_auth;
				num_auth++;
			}

			autores_ids.push_back( encoder[autor]-1 );
		} while (test != ':');

		for (list<int>::iterator i = autores_ids.begin(); i != autores_ids.end(); ++i)
		{
			for (list<int>::iterator j = autores_ids.begin(); j != autores_ids.end(); ++j)
			{
				if (i != j)
					graph[*i].push_back(*j);
			}
		}
		
		getline(cin, first_name);	
	}

	n = num_auth-1;

	parent.resize( n );
	dist.resize( n );

	for (int l = 0; l < n; ++l)
	{
		dist[l] = INF;
		parent[l] = -2;
	}
}


void bfs( int source )
{
	queue< int > q;

	q.push( source );
	parent[source] = -1;
	dist[source] = 0; 

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		list< int >::iterator it;
		// Enqueue all adjacent of v and mark them visited
		for (it = graph[v].begin(); it != graph[v].end(); ++it)
		{
			if (parent[*it] == -2)
			{
				q.push( *it );
				parent[*it] = v;
				dist[*it] = dist[v] + 1;
			}
		}
	}
} // end of bfs()
*/

int main() {
	long num_cases;
	std::ios_base::sync_with_stdio(false);
	cin >> num_cases;

	for (int i = 0; i < num_cases; ++i)
	{
		map< pair< string, string >, int > encoder;
		vector< list< int > > graph; // Adjacency list
		vector < int > dist;

		cout << "Scenario " << i+1 << endl;



		//start input
		string first_name, second_names;
		char test;
		int num_auth = 1;

		cin >> p >> qn;

		graph.resize( p*5 );

		encoder[make_pair("Erdos","P.")] = num_auth;
		num_auth++;

		for (int l = 0; l < p; ++l)
		{
			list < int > autores_ids;

			do
			{
				cin >> first_name >> second_names;
				test = second_names.back();
				second_names.pop_back();
				first_name.pop_back();
				pair < string,string > autor = make_pair(first_name, second_names);

				if (encoder[autor] == 0){ // não existe esse autor no DB 
					encoder[autor] = num_auth;
					num_auth++;
					if (num_auth > p*5) {
						graph.resize( num_auth );
					}
				}

				autores_ids.push_back( encoder[autor]-1 );
			} while (test != ':');


			for (list<int>::iterator i = autores_ids.begin(); i != autores_ids.end(); ++i)
			{
				for (list<int>::iterator j = autores_ids.begin(); j != autores_ids.end(); ++j)
				{
					if (i != j)
						graph[*i].push_back(*j);
				}
			}

			getline(cin, first_name);	
		}

		n = num_auth-1;

		dist.resize( n , INF);


		//end input

		//start bfs
		int source = 0;
		queue< int > q;

		q.push( source );
		//parent[source] = -1;
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
				cout << first_name << ", " << second_names << " " << "infinity" << endl;
			} else {
				if (dist[encoder[aux]-1] == INF)
					cout << first_name << ", " << second_names << " " << "infinity" << endl;
				else
					cout << first_name << ", " << second_names << " " << dist[encoder[aux]-1] << endl;
			}
		}
	}
	return 0;
}