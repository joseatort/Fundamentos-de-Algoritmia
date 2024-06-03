// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


/*
    ACLARACIONES
    ------------
    N es el numero de viajeros

    ESPECIFICACION FORMAL
    -------------- ------
    P = {0 <= N < 150000 ^ ParaTodo i: 0 <= i < N: v[i] > 0 ^ v = V}
    int resolver(vector<pair<string, int>> &v, int altura_min) dev p
    Q = {v existe Perm(V) ^ ParaTodo i : 0 <= i < p: v[i] <= altura_min ^ ParaTodo j : q <= j < N: v[j] > altura_min}

    FUNCION DE COTA
    ------- -- ----
    C = q - p
    C >= 0, al comenzar el bucle, ya que el predicado, 0 <= N < 150000
    C decrece cada vez que se ejecuta el bucle


    INVARIANTE
    ----------
    v existe Perm(V) ^ 
    0 <= p <= q <= N ^
    ParaTodo i: 0 <= i < p: v[i] <= altura_min ^
    ParaTodo i: p <= i < N: v[i] > altura_min


    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/


int resolver(vector<pair<string, int>> &datos, int altura_min) 
{
    int p = 0;
    int q = datos.size() - 1;

    while (p <= q)
    {
        if (datos[p].second <= altura_min)
            p++;
        else
        {
            if (datos[q].second > altura_min)
                q--;
            else
            {
                swap(datos[p], datos[q]);
                p++;
                q--;
            }
        }

    }

    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int N, minimo_altura;
    cin >> N >> minimo_altura;
    if (! std::cin)
        return false;
    
    vector<pair<string, int>> datos;

    string aux1;
    int aux2;
    for (int i = 0; i < N; i++)
    {
        cin >> aux1 >> aux2;
        datos.push_back({ aux1, aux2 });
    }


    int sol = resolver(datos, minimo_altura);
    
    sort(datos.begin(), datos.begin() + sol);
    sort(datos.begin() + sol, datos.end());
   

    cout << "Bajos: ";
    for (int i = 0; i < sol; i++)
        cout << datos[i].first << " ";

    cout << "\nAltos: ";
    for (int i = sol; i < datos.size(); i++)
        cout << datos[i].first << " ";

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