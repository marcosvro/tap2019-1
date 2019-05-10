#include<bits/stdc++.h>


using namespace std;
const int max_weigth = 1000000000;

int main () {

	srand (time(NULL));
	for (int i = 0; i < 1; ++i)
	{
		int n, m, q, cont_time_ligado = 1;
		//n = rand() % 49999 + 2;
		//m = rand() % (100001-(n-1));
		//q = rand() % 100000 + 1;
		n = 50000;
		m = 50001;
		q = 100000;
		cout << n << " " << m+(n-1) << "\n";

		//making connected graph
		for (int i = 2, j; i <= n; ++i)
		{
			j = rand() % (i-1) + 1;
			cout << j << " " << i << " " << rand()%(max_weigth+1) << "\n";
		}

		for (int i = 0, from, to, weigth; i < m; ++i)
		{
			from = rand()%n + 1;
			to = rand()%n + 1;
			weigth = rand()%(max_weigth+1);

			cout << from << " " << to << " " << weigth << "\n";
		}

		cout << q << "\n";
		for (int i = 0, from, to; i < q; ++i)
		{
			from = rand()%n + 1;
			to = rand()%n + 1;

			cout << from << " " << to << "\n";	
		}

		cout << "\n";
	}

	return 0;
}