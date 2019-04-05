#include<bits/stdc++.h>

using namespace std;

class Screen {
    public:
    char tela[12][12] = {
        {'+','-','-','-','-','-','-','-','-','-','-','+'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'+','-','-','-','-','-','-','-','-','-','-','+'}};
    int l, c;
    bool insert_mode;

    Screen() {
        l = 0;
        c = 0;
        insert_mode = false;
    }

    public bool leia_sequecia() {
        char ch;
        cin >> ch;
    }

    public void mostrar_tela() {

    }

    public void reseta_tela() {
        l = 0;
        c = 0;
        insert_mode = false;

    }
};

int main () {
    int n;
    Screen visor;
    for (int i=1;;i++) {
        cin >> n;
        if (n == 0)
            break;
        cout << "Case " << i;
        for (int j=0; j<n; j++) {
            visor.leia_sequecia();
        }
        visor.mostrar_tela();
        visor.reseta_tela();
    }
    return 0;
}