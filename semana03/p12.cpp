#include <bits/stdc++.h>
#include <list>

using namespace std;

map< pair< string, string >, int > encoder;
vector< list< int > > graph; // Adjacency list
list < int > notVisited;
vector < int > parent;

int n, m;            // Number of vertices and edges
string buff = "";

int inputRead()
{
	string first_name, second_names;
	char test;
	int num_auth = 1;

	notVisited.clear();
	encoder.clear();
	graph.resize( n*10 );

	encoder[make_pair("Erdos","P.")] = num_auth;
	num_auth++;

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

	for (int i = 0; i < count; ++i)
	{
		/* code */
	}
	

	
	for (int i = 0; i < n; ++i)
	{
		graph[i].clear();
		parent[i] = -2;
		notVisited.push_back(i);
	}

	while(true)
	{
		cin >> top;
		if (cin.fail()){
			buff = "";
			return 1;
		}
		if (top.length() == 1) { //leu o primeiro caractere do proximo caso
			buff = top;
			return 1;
		}

		int from, to;
		from = ((int)top.front())-65;
		to = ((int)top.back())-65;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	parent.resize( n );
}


void bfs( int source )
{
	queue< int > q;

	q.push( source );
	parent[source] = -1;

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
			}
		}
	}
} // end of bfs()

int main() {
	int num_cases;
	cin >> num_cases;

	for (int i = 0; i < num_cases; ++i)
	{
		inputRead();

		cout << calc_maximals() << endl;;

		if (i != num_cases-1)
			cout << endl;
	}
	return 0;
}