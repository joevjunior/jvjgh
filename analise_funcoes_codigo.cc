#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;

//Problema F (InterFatecs)

int main()
{
    int d,c,i, v, x, y;
    set<int> dom;
    set<int> c_dom;
    set<int>::iterator itx, ity;
    bool func;

    while(true){
        //leitura dos valores d, c e i
        cin >> d >> c >> i;
        //caso de parada
        if(d == 0 && c == 0 && i == 0)
            break;
        //dominio
        for(int j = 0; j<d; j++){
            cin >> v;
            dom.insert(v);
        }

        for(int j = 0; j<c; j++){
            cin >> v;
            c_dom.insert(v);
        }

        // vector(quantidade, valor_inicial)
        vector<int> aux_dom(dom.size(), 0);
        vector<int> aux_c_dom(c_dom.size(), 0);

        //pares x,y --> [y = f(x)]
        func = true;
        for(int j = 0; j<i; j++){
            cin >> x >> y;
            itx = dom.find(x);
            ity = c_dom.find(y);
            if(itx == dom.end() || ity == dom.end())
                func = false;
            else{
                aux_dom[std::distance(dom.begin(), itx)]++;
                aux_c_dom[std::distance(c_dom.begin(), ity)]++;
            }
        }

        sort(aux_dom.begin(), aux_dom.end());
        sort(aux_c_dom.begin(), aux_c_dom.end());

        if(!func || aux_dom[aux_dom.size() - 1] > 1)
            cout << "nf" << endl;
        else if(aux_dom[0] == 1 && aux_c_dom[0] == 1 && aux_dom[aux_dom.size() - 1] == 1 && aux_c_dom[aux_c_dom.size() - 1] == 1)
            cout << "bi" << endl;
        else if(aux_dom[aux_dom.size() - 1] == 1 && aux_c_dom[aux_c_dom.size() - 1] == 1)
            cout << "in" << endl;
        else if(aux_dom[aux_dom.size() - 1] == 1 && aux_c_dom[aux_c_dom.size() - 1] > 1)
            cout << "so" << endl;
        else
            cout << "fu" << endl;
    }
    return 0;
}
