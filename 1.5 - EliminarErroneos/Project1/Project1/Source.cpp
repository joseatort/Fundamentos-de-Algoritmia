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
    P = {0 < N ^ ParaTodo i: 0 <= i < N; -2^63 < v[i] < 2^63 ^ v = W}
    fun int resolver(vector<int> &v, int eliminar) dev tam
    Q = {ParaTodo i: 0 <= i < tam ^ Existe j : 0 <= j < N: v[i] = W[j] != eliminar}

    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/

int resolver(vector<int> &v, int eliminar) 
{
    int actual = 0;
    int contador = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == eliminar)   
            contador++;
        else
        {
            v[actual] = v[i];
            actual++;
        }
    }

    v.resize(v.size() - contador);

    return v.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
   
    int N, eliminar;
    vector<int> v;

    cin >> N;
    cin >> eliminar;

    int aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        v.push_back(aux);
    }
   
    int sol = resolver(v, eliminar);

    cout << sol << "\n";
    
    for (int y = 0; y < v.size(); y++)
        cout << v[y] << " ";

    cout << "\n";    
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