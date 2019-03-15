#include<bits/stdc++.h>

using namespace std;

int main() {
    int n_tests, n_aero;
    for (int i=1;;i++) {
        bool jafoi1 = false;
        int maior = 0;
        
        cin >> n_aero >> n_tests;
        if (n_aero == 0)
            break;

        cout << "Teste " << i << endl;
        vector<int> vec_cont (n_aero, 0);
        for(int i=0; i<n_tests; i++) {
            int a1, a2;
            cin >> a1 >> a2;
            vec_cont[a1-1] += 1;
            vec_cont[a2-1] += 1;
            maior = vec_cont[a1-1] > maior ? vec_cont[a1-1]:maior;
            maior = vec_cont[a2-1] > maior ? vec_cont[a2-1]:maior;
        }
        for (vector<int>::iterator it = vec_cont.begin(); it != vec_cont.end(); it++) {
            if (*it == maior){
                if (jafoi1)
                    cout << " ";
                else
                    jafoi1 = true;
                cout << it-vec_cont.begin()+1;
            }
        }
        cout << endl << endl;
    }
    return 0;
}