// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
*   ACLARACION
*   ----------
*   N es igual al numero de elementos del vector
*   c valor entero usado para buscar el tramo
* 
*   ESPECIFICACION
*   --------------
*   P = {c > 0 ^ 0 <= n <= 1000000 ^ ParaTodo i: 0 <= i < N: v[i] > 0}
*   bool resolver(const vector<int> &v, const int c) dev encontrado
*   Q = {Existe i,j: 0 <= i <= j < N: suma_intervalos(i, j, v) == c }
* 
*   Predicados auxiliares
*   suma_intervalos(i, j, v) <=> {Sumatorio k: i <= k <= j: v[k]}
* 
*   INVARIANTE
*   ----------
*   0 <= i <= N ^ 
*   0 <= primer_elemento <= N ^
*   0 <= acumulador < c ^
*   encontrado = {Existe i,j: 0 <= i <= j < N: suma_intervalos(i, j, v) == c}
* 
*   FUNCION COTA
*   ------- ----
*   C = N - i
*   C >= 0 al comenzar el bucle
*   C decrece por cada iteraccion que realiza bucle
* 
*   COSTE
*   -----
*   El coste del algoritmo en el peor de los casos es O(N) siendo N el numero de 
*   elementos del vector, ya que recorremos todos los elementos del vector, buscando 
*   el intervalo cuya suma igual a c
* 
*/


bool resolver(const vector<int> &v, const int c) 
{
    bool encontrado = false;
    int acumulador = 0;

    int primer_elemento = 0;
    for (int i = 0; i < v.size() && !encontrado; i++)
    {
        if (acumulador + v[i] > c)
        {
            acumulador -= v[primer_elemento];
            primer_elemento++;
            i--;
        }
        else if (acumulador + v[i] < c)
            acumulador += v[i];
        else if (acumulador + v[i] == c)
            encontrado = true;
    }

    return encontrado;
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

    int c;
    cin >> c;

    if (resolver(v, c))
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
