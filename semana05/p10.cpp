#include<bits/stdc++.h>
#define MAX 1000001

using namespace std;

typedef list < int > li;
typedef vector < char > vc;

char PROX = 'A', OUTRO = 'B';
vc quem_ganha (MAX);
li request;


int main() {
    //input
    int K, L, m;
    cin >> K >> L >> m;
    request.clear();
    for(int j=0; j<m; j++) {
        int ni;
        cin >> ni;
        request.push_back(ni);
    }

    //algoritimo
    quem_ganha[0] = OUTRO;
    int i;
    for (i=1; i<K; i++)
        quem_ganha[i] = PROX;

    quem_ganha[i] = OUTRO;
    i++;

    for (;i <= MAX; i++) {
        if (quem_ganha[i-L] == OUTRO || quem_ganha[i-K] == OUTRO || quem_ganha[i-1] == OUTRO)
            quem_ganha[i] = PROX;
        else
            quem_ganha[i] = OUTRO;
    }

    li::iterator it = request.begin();
    for (;it != request.end(); it++)
        cout << quem_ganha[*it];
    cout << endl;

    return 0;
}