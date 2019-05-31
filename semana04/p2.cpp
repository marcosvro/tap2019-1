#include<bits/stdc++.h>
#define MAX 1000000

using namespace std;

typedef list < int > li;
typedef vector < int > vi;

int main() {

    while (true) {
        int N, D, fuck_n = 0;

        cin >> N >> D;

        if (N == D and N == 0)
            break;

        if (N == 1) {
            cout << N << " " << D << " 1\n";
            continue;
        }


        vi fuck (MAX);
        fuck[1] = 0;
        for (int i = 2; i <= N; i++) {
            if (i < D) {
                fuck[i] = (fuck[i-1]+D)%i;
            } else {
                int n_ = i - ((int)(i/D));
                fuck[i] = (int)( ( D*( ( (fuck[n_]-i) %D ) %n_ ) ) / (D-1) );
            }
        }

        cout << N << " " << D << " " << fuck[N] << "\n";




        // vi fuck (N);
        // int i = 1;
        // for (li::iterator it = fuck.begin(); it != fuck.end(); it++, i++) {
        //     *it = i;
        // }

        // li::iterator it = fuck.begin();
        // int idx = 0;
        
        // for (int i=N; i > 1; i--) {
        //     long sorted = (idx+(D-1))%i;
        //     it = fuck.begin();
        //     advance(it,sorted);
        //     idx=sorted;
        //     it = fuck.erase(it);
        //     if (it == fuck.end()) {
        //         it = fuck.begin();
        //         idx = 0;
        //     }
        // }

        //cout << N << " " << D << " " << *it << "\n";
    }

    return 0;
}