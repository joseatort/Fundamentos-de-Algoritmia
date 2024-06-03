// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    ACLARACIONES
    ------------
    N es el numero de elementos del vector

    ESPECIFICACION FORMAL
    -------------- ------
    P = {0 < N ≤ 10^6}
    bool resolver(const vector<int> & v) dev sol
    Q = {ParaTodo i: 0 <= i < N : num_minimos(v, i) < 2 }
    num_minimos(v, i) =  (min = min i: 0 <= i < N : v[i] ^ minimos = i # : 0 <= i < v.size() : v[i] == min) 

    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/

bool resolver(const vector<int> & v) 
{
    int minimo = v[0];
    int veces = 1;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < minimo)
        {
            minimo = v[i];
            veces = 1;
        }
        else if (v[i] == minimo)
            veces++;

        if (veces == 2)
            return false;
    }


    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int N;
    cin >> N;

    if (N == -1)
        return false;
    
    vector<int> v;

    int aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }

    if (resolver(v))
        cout << "SI\n";
    else
        cout << "NO\n";
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
