// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
* 
*   ACLARACION
*   ----------
*   N es igual al numero de elementos del vector
* 
*   F. RECURSIVA
*   ------------
*          {c0              si N == 1   }
*   T(N) = {                            }
*          {T(N / 2) + c1   en otro caso}
* 
*   
*   COSTE
*   -----
*   Por el teorema de la division, podemos deducir que a = 1, b = 2 y k = 0;
*   ....
*   
*   El coste del algoritmo en el peor de los casos es O(log N)
* 
* 
*/


bool resolver(int ini, int fin, const vector<int> &v, const int primero, const int ultimo) 
{
    if (ini == fin - 1)
        return false;
    else
    {
        int M = (ini + fin) / 2;

        if (v[M] != primero && v[M] != ultimo)
            return true;
        else if (v[M] == ultimo)
            resolver(ini, M, v, primero, ultimo);
        else 
            resolver(M, fin, v, primero, ultimo);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == -1)
        return false;
    
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int primero = v[0];
    int ultimo = v[N - 1];
    bool sol = resolver(0, v.size(), v, primero, ultimo);

    if (sol)
        cout << "SI";
    else
        cout << "NO";
    cout << "\n";
    
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
