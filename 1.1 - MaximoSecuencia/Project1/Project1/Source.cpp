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
    N es el numero de puntuaciones

    ESPECIFICACION FORMAL
    -------------- ------

    P = {0 < N & ParaTodo p : 0 <= p < N : v[p] > 0}
    fun pair<int, int> resolver(vector<int> &v) dev<maxi, veces>
    Q = {maxi = max i: 0 <= i < N : v[i] & veces = #i : 0 <= i < N : v[i] = maxi}


    COSTE
    -----
    El coste del algoritmo sera de O(n) siendo n, el numero de puntuaciones
*/







// función que resuelve el problema
pair<int, int> resolver(vector<int> &v) {
    
    int maximo = v.front();
    int veces = 1;


    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > maximo)
        {
            maximo = v[i];
            veces = 1;
        }
        else if (v[i] == maximo)
            veces++;
    }

    return { maximo, veces };
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int aux;
    vector<int> v;

    cin >> aux;
    while (aux != 0)
    {
        v.push_back(aux);
        cin >> aux;
    }

    pair<int, int> resultado = resolver(v);

    cout << resultado.first << " " << resultado.second << "\n";
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