// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

/*
    ACLARACIONES
    ------------
    N es el numero de elementos del vector
    t es la altura del transporte

    ESPECIFICACION FORMAL
    -------------- ------
    P = {0 < N ^ ParaTodo i: 0 <= i < N : vct[i] >= 0 ^ Existe i: 0 <= i < N: v[i] > t}
    pair<int, int> resolver(const vector <int>& vct, int t) dev { pos_ini_def, pos_fin_def }
    Q = {max i,j : ParaTodo i, j:  0 <= i < j < N : v[i] > t ^ v[j] > t}

    //Como seria el que este situado mas a la izquierda

    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/

pair<int, int> resolver(const vector <int>& vct, int minimo)
{
    int pos_ini_def = -1, pos_fin_def = -1;
    int pos_ini_aux = -1, pos_fin_aux = -1;

    bool encontrado = false;

    for (int i = 0; i < vct.size(); i++)
    {
        if (!encontrado && vct[i] > minimo)
        {
            pos_ini_aux = i;
            pos_fin_aux = i;
            encontrado = true;
        }
        else if (encontrado && ((vct[i - 1] > minimo && vct[i] <= minimo) || (i == vct.size() - 1)))
        {
            encontrado = false;

            if (i == vct.size() - 1 && vct[i] > minimo)
                pos_fin_aux = i;
            else
                pos_fin_aux = i - 1;

            if ((pos_fin_aux - pos_ini_aux) > (pos_fin_def - pos_ini_def))
            {
                pos_ini_def = pos_ini_aux;
                pos_fin_def = pos_fin_aux;
            }

        }


        if (pos_ini_def == -1 && pos_fin_def == -1)
        {
            pos_ini_def = pos_ini_aux;
            pos_fin_def = pos_fin_aux;
        }

    }

    return { pos_ini_def , pos_fin_def };


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N, min;  
    cin >> N >> min;

    vector<int> v;

    int aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }

    pair<int, int> sol = resolver(v, min);
    cout << sol.first << " " << sol.second << "\n";
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}