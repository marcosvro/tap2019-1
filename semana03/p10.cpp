#include <bits/stdc++.h>
#include <list>

using namespace std;


vector< list< int > > graph; // Adjacency list
list < int > notVisited;
vector < int > parent;

int n, m;            // Number of vertices and edges
string buff = "";

int inputRead()
{
	string top;

	if (buff.length() == 0){
		cin >> top;
		if (cin.fail())
			return 0;
	}
	else
		top = buff;

	n = ((int) top.front())-64;

	graph.resize( n );
	parent.resize( n );
	notVisited.clear();

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

int calc_maximals() {
	int max_cout = 0;
	while (notVisited.size() != 0) {
		int v = notVisited.front();
		notVisited.pop_front();

		if (parent[v] != -2)
			continue;

		max_cout++;
		bfs(v);
	}
	return max_cout;
}

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