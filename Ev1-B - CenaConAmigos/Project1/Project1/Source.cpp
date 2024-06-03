/*
*
*   Alvaro Velasco Garcia F97
*   Jose Antonio Tortosa Aranda F91
*
*/


/*
*
*
*   Aclaraciones
*   ------------
*   N es igual al numero de elementos del vector
*
*   Especificacion
*   --------------
*   P = {1 <= N ^ Existe i: 0 <= i < N: v[i] > 0}
*   Solucion resolver(const vector <int> &v) dev {int maximodef, int iniciodef,int longitud_maximo}
*   Q = {maximo_def = max i,j: 0 <= i <= j <= N: suma_intervalos(v, i, j) ^
         longitud_maximo = minima_longitud(v, i, j, maximo_def) ^
         iniciodef = i}
*
*   Predicado auxiliar...
*
*   suma_intervalos(v, i ,j) <=> (Sumatorio w: i <= w <= j: v[w])
*   minima_longitud(v, i, j, maximo) <=> (min i,j: 0 <= i <= j <= N ^ suma_intervalos(v, i ,j) == maximo: j - i + 1)
*
*   Invariante
*   ----------
*   0 <= i <= N ^
*   valor_actual, maximo_def = max i,j: 0 <= i <= j <= N: suma_intervalos(v, i, j) ^
*   longitud_actual, longitud_maximo = minima_longitud(v, i, j, maximo_def) ^
*   inicio_actual, iniciodef = i
*
*   Funcion de cota
*   ------- -- ----
*   C = N - 1
*   C >= 0 al comenzar el bucle
*   C decrece por cada iteracion que realiza el bucle
*
*   Coste
*   -----
*   El coste del algoritmo utilizado sería O(N), siendo N el numero de elementos del vector, ya que siempre
*   recorremos todos los elementos buscando el intervalo con valor maximo y este podría estar al final del vector,
*   por ejemplo, en una secuencia de 6 elementos como esta -3 2 1 -1 1 10, deberíamos recorrerlo entero hasta encontrar
*   el 10 que se encuentra al final de este y pertenecería al intervalo.
*
*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef struct
{
    int maximo;
    int inicio;
    int longitud;

}Solucion;


// función que resuelve el problema
Solucion resolver(const vector <int>& v)
{
    int valor_actual = 0, maximodef = 0;
    int inicio_actual = 0, iniciodef = 0;
    int longitud_actual = 0, longitud_maximo = v.size() + 1;

    for (int i = 0; i < v.size(); i++)
    {
        valor_actual += v[i];
        longitud_actual++;

        if (maximodef < valor_actual)
        {
            maximodef = valor_actual;
            iniciodef = inicio_actual;
            longitud_maximo = longitud_actual;
        }

        if (maximodef == valor_actual && longitud_actual < longitud_maximo)
        {
            iniciodef = inicio_actual;
            longitud_maximo = longitud_actual;
        }

        if (valor_actual <= 0)
        {
            valor_actual = 0;
            inicio_actual = i + 1;
            longitud_actual = 0;
        }
    }

    return { maximodef, iniciodef, longitud_maximo };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)
        return false;

    vector <int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];


    Solucion sol = resolver(v);

    // escribir sol
    cout << sol.maximo << " " << sol.inicio << " " << sol.longitud << "\n";

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