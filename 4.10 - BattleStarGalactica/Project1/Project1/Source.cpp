
// NOMBRE Y APELLIDOS

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


pair<int, vector<int>> recursiva(vector<int>& vct, int ini, int fin)
{
    if (ini == fin)
    {
        vector<int> x;
        x.push_back(vct[ini]);
        return{ 0, x };
    }
    else
    {
        int m = (ini + fin) / 2;

        pair<int, vector<int>> iz = recursiva(vct, ini, m);
        pair<int, vector<int>> der = recursiva(vct, m + 1, fin);

        int cont = iz.first + der.first;

        int i = 0;
        int j = 0;
        
        vector<int> aux1 = iz.second;
        vector<int> aux2 = der.second;

        vector<int> sol;

        while (i < aux1.size() && j < aux2.size())
        {

            if (aux1[i] < aux2[j])
            {
                cont += sol.size() - i;
                sol.push_back(aux1[i]);
                i++;
            }
            else
            {
                sol.push_back(aux2[j]);
                j++;
            }
        }

        while (i < aux1.size())
        {
            cont += sol.size() - i;
            sol.push_back(aux1[i]);
            i++;
        }

        while (j < aux2.size())
        {
            sol.push_back(aux2[j]);
            j++;
        }


        return {cont, sol};
    }



}







bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int numero;
    cin >> numero;
    if (!std::cin)
        return false;

    vector<int> vct(numero);

    for (int i = 0; i < numero; i++)
        cin >> vct[i];


    cout << recursiva(vct, 0, numero - 1).first << endl;
    //Resolver problema
    //Escribir resultado
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}