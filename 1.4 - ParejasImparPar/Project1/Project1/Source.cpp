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
    P = {0 < N <= 50000 ^ ParaTodo i, j: 0 <= i < N ^ 0 <= j < N: v[i] != v[j] ^ 0 < v[i] < 10^6}
    fun int resolver(const vector<int>& v) dev acumulador
    Q = {acumulador = # i,j : 0 <= i < j < N: pareja(v,i,j)}
    pareja(v,i,j) = v[i] % 2 = 1 ^ v[j] % 2 = 2)

    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/

int resolver(const vector<int>& v) 
{
    int acumulador = 0;
    int aumento = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
            acumulador += aumento;
        else
            aumento++;
        
    }

    return acumulador;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int N;
    vector<int> v;

    cin >> N;

    int aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }
        
    cout << resolver(v) << "\n";
    
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