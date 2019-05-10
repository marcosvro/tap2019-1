/*https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=995*/
#include<bits/stdc++.h>

using namespace std;
typedef pair < int, int > pi;


list < pi > arestas;

void dfs( int source )
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
} // end of dfs()

void dfs_rec(int source, )
{

}






int main () {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int m, maior_grau_vertice, maior_grau_value = 0;
        cin >> m;
        vector < list < int > > graph(m);
        vector < int > grau(50, 0);

        for (int j=0; j<m; j++) {
            int from, to;
            cin >> from >> to;
            from--;
            to--;

            grau[from]++;
            grau[to]++;
            graph[from].push_back(to);
            graph[to].push_back(from);

            if (maior_grau_value > grau[from]){
                maior_grau_value = grau[from];
                maior_grau_vertice = from;
            }
            if (maior_grau_value > grau[to]) {
                maior_grau_value = grau[to];
                maior_grau_vertice = to;
            }
        }

        int s = maior_grau_vertice;

        while(true) {
            if (graph[s].size() == 0)
                break;
            else if (graph[s].size() == 1) {
                //Apenas uma aresta bridge para escolher
                int aux = *it;
                list < int >::iterator it = graph[s].begin();
                arestas.push_back(make_pair(s, *it));
                graph[s].erase(it);
                s = aux;
            } else {
                //mais de uma aresta saindo deste vertice, escolha a aresta no-bridge
                int no_bridge_vertice;
                //itera sobre os visinhos de s até encontrar uma aresta no-bridge
                list < int >::iterator it;
                for (it = graph[s].begin(); it != graph[s].end(); ++it) {
                    no_bridge_vertice = *it, isNoBridge=false;
                    graph[s].erase(it);

                    //bfs
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



                }
            }
        }
    }


    return 0;
}