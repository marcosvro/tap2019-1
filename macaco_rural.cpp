#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, maior;
    while(true) {
        maior = 0;
        cin >> n;
        if (n == 0)
            break;
        vector<int> vec (n);
        for (int i=0; i<n; i++) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        for(int inc=0, dec=n-1; inc<(int)(n/2); inc++, dec--) {
            int aux = vec[inc] + vec[dec];
            if (aux > maior)
                maior = aux;
        }
        cout << maior << endl;
    }
    return 0;
}