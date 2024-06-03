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
    N es igual al numero de elementos del vector
    K es igual a la posicion de "division"

    ESPECIFIACION FORMAL
    ------------- ------
    P = {0 < N ^ 0 <= K < N}
    fun bool resolver(vector<int> v, int k) dev b
    Q = {b = ParaTodo i, j: 0 <= i <= k ^ k < j <= N : v[i] < v[j]}

    //K+1 < N => (max i : 0 <= i <= K : v[i]) < (min j : K < j < N : v[j])

    COSTE
    -----
    El coste del algoritmo es O(n), donde N es igual al numero de elementos del vector
*/



// función que resuelve el problema
bool resolver(vector<int> v, int k) 
{
    int maximo_iz = v.front();

    for (int i = 1; i < v.size(); i++)
    {
        if (i <= k)
            maximo_iz = max(maximo_iz, v[i]);
        else if (maximo_iz >= v[i])
            return false;
    }
        
    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int N, k;
    cin >> N;
    cin >> k;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];


    if (resolver(v, k))
        cout << "SI\n";
    else
        cout << "NO\n";
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