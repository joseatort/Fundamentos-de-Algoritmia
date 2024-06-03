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
*   N corresponde al numero de edificios
*   T corresponde a la altura del transporte
* 
*   ESPECIFICACION
*   --------------
*   P = {0 < N ^ Existe i: 0 <= i < N: v[i] > T}
*   pair<int,int> resolver(const vector<int> &v, int T) dev {int inicio_max, int fin_max }
*   Q = {max i,j: 0 <= i <= j < N: intervalo(i, j, v, N, T): j - i + 1}
* 
*   intervalo(i, j, v, N, T) <=> {ParaTodo w: i <= w <= j: v[w] > T}
*   
*   INVARIANTE
*   ----------
*   0 <= i <= N ^
*   inicio_max = i ^
*   inicio = i ^
*   fin_max = i;
* 
* 
*   FUNCION COTA
*   ------- ----
*   N - i
*   C >= 0 al empezar el bucle
*   C decrece por cada iteraccion del bucle
* 
*   COSTE
*   -----
*   El coste del algoritmo en el caso peor es de O(N), siendo N el numero de edificios,
*   ya que recorremos todos los edificios buscando el intervalo de mayor tamaño, 
*   en el que todos sus elementos sean mayores estrictamente de T
* 
*/



// función que resuelve el problema
pair<int,int> resolver(const vector<int> &v, int T) 
{
    int inicio_max = -1, fin_max = -1;
    int inicio = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= T)
            inicio = i + 1;

        if (inicio_max == -1 || (fin_max - inicio_max + 1) < (i - inicio + 1))
        {
            fin_max = i;
            inicio_max = inicio;
        }
    }
    
    return { inicio_max, fin_max };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int N, T;
    cin >> N >> T;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    pair<int,int> sol = resolver(v, T);
    cout << sol.first << " " << sol.second << "\n";
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