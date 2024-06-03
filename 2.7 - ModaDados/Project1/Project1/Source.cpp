// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;
/*
    ACLARACIONES
    ------------
    N es el numero de elementos del vector
    C numero maximo de caras

    ESPECIFICACION FORMAL
    -------------- ------
    P = {1 <= N < 200.000 ^ C <= 10000}
    pair<int, vector<int>> resolver(const vector<int>& valores, int maxvalor) dev { max_repes, resultado }
    Q = { }


    ¿?

    maximo_veces(v, N) = max i : 0 <= i < N : v[i]



    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/
pair<int, vector<int>> resolver(const vector<int>& valores, int maxvalor) 
{
    vector<int> resultado(maxvalor + 1, 0);
    int max_repes = 0;

    for (int i = 0; i < valores.size(); i++)
    {
        resultado[valores[i]]++;
        max_repes = max(max_repes, resultado[valores[i]]);
    }

    return{ max_repes, resultado };  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int N, maxvalor;
    cin >> N;

    if (N == -1)
        return false;

    cin >> maxvalor;

    vector<int> valores;

    int aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        valores.push_back(aux);
    }


    pair<int, vector<int>> sol = resolver(valores, maxvalor);

    for (int i = maxvalor; i >= 0; i--)
    {
        if (sol.second[i] == sol.first)
            cout << i << " ";
    }
       
    cout << "\n";


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
