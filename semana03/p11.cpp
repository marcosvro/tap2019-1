#include <bits/stdc++.h>
#include <list>

using namespace std;

typedef pair< int, pair< int, int > > ppi;

vector< vector< vector< int > > > cube;


int l, r, c;           // Number of vertices and edges
int x = -1, y = -1, z = -1;   		   // Start position

int inputRead()
{
	cin >> l >> r >> c;

	if (l+r+c == 0 || cin.fail())
		return 0;

	char cell;

	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			for (int k = 0; k < c; ++k)
			{
				cin >> cell;

				if (cell == 'S'){
					cube[i][j][k] = -3;
					x = i;
					y = j;
					z = k;
				}else if (cell == '#')
					cube[i][j][k] = -1;
				else if (cell == '.')
					cube[i][j][k] = -2;
				else if (cell == 'E')
					cube[i][j][k] = -4;
			}
		}
	}

	return 1;
}


int bfs_modificado()
{
	if (x == -1)
		return 0;

	queue< ppi > q;

	q.push( make_pair( x, make_pair( y, z ) ) );
	//parent[source] = -1;
	cube[x][y][z] = 0;

	while (!q.empty())
	{
		ppi v = q.front();
		int x_ = v.first, y_ = v.second.first, z_ = v.second.second;
		q.pop();

		//up
		if (x_+1 <= l-1 && cube[x_+1][y_][z_] == -2) {
			q.push( make_pair( x_+1, make_pair( y_, z_ ) ) );
			cube[x_+1][y_][z_] = cube[x_][y_][z_] + 1;
		} else if (x_+1 <= l-1 && cube[x_+1][y_][z_] == -4)
			return (int)(cube[x_][y_][z_]) + 1;
		//down
		if (x_-1 >= 0 && cube[x_-1][y_][z_] == -2) {
			q.push( make_pair( x_-1, make_pair( y_, z_ ) ) );
			cube[x_-1][y_][z_] = cube[x_][y_][z_] + 1;
		} else if (x_-1 >= 0 && cube[x_-1][y_][z_] == -4)
			return (int)(cube[x_][y_][z_]) + 1;
		//north
		if (y_+1 <= r-1 && cube[x_][y_+1][z_] == -2) {
			q.push( make_pair( x_, make_pair( y_+1, z_ ) ) );
			cube[x_][y_+1][z_] = cube[x_][y_][z_] + 1;
		} else if (y_+1 <= r-1 && cube[x_][y_+1][z_] == -4)
			return (int)(cube[x_][y_][z_]) + 1;
		//south
		if (y_-1 >= 0 && cube[x_][y_-1][z_] == -2) {
			q.push( make_pair( x_, make_pair( y_-1, z_ ) ) );
			cube[x_][y_-1][z_] = cube[x_][y_][z_] + 1;
		} else if (y_-1 >= 0 && cube[x_][y_-1][z_] == -4)
			return (int)(cube[x_][y_][z_]) + 1;
		//east
		if (z_+1 <= c-1 && cube[x_][y_][z_+1] == -2) {
			q.push( make_pair( x_, make_pair( y_, z_+1 ) ) );
			cube[x_][y_][z_+1] = cube[x_][y_][z_] + 1;
		} else if (z_+1 <= c-1 && cube[x_][y_][z_+1] == -4)
			return (int)(cube[x_][y_][z_]) + 1;
		//west
		if (z_-1 >= 0 && cube[x_][y_][z_-1] == -2) {
			q.push( make_pair( x_, make_pair( y_, z_-1 ) ) );
			cube[x_][y_][z_-1] = cube[x_][y_][z_] + 1;
		} else if (z_-1 >= 0 && cube[x_][y_][z_-1] == -4)
			return (int)(cube[x_][y_][z_]) + 1;
	}
	return -1;
} // end of bfs()


int main() {
	cube.resize( 30 );
	for (int i = 0; i < 30; ++i)
	{
		cube[i].resize( 30 );
		for (int j = 0; j < 30; ++j)
		{
			cube[i][j].resize( 30, -1 );
		}
	}

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (inputRead()) {
		int t = bfs_modificado();
		if (t == -1)
			cout << "Trapped!" << "\n";
		else
			cout << "Escaped in " << t << " minute(s)." << "\n";
	}
	return 0;
}