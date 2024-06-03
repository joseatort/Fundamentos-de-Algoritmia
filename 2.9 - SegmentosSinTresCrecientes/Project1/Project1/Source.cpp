// Nombre del alumno Jose Antonio Tortosa Aranda
// Usuario del Juez F91


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
*   ACLARACIONES
*   ------------
*   N es el numero de elementos del vector
* 
*   ESPECIFICACIONES
*   ----------------
*   P {N >= 0}
*   int resolver(const vector<int> &v) dev maximo
*   Q {maximo = ParaTodo i,j: 0 <= i <= j < v.size: max_longitud(i,j,v)}
* 
*   max_longitud(i,j,v) <=> (max l: 0 <= l < v.size() ^ crecientes_consecutivos(i, j, v) < 3: l = j - i)
*   crecientes_consecutivos(i, j, v) <=> ( #u : Existe: i<= u <= j < v.size(): v[u] < v[u+1])
* 
*   FUNCION DE COTA
*   ------- -- ----
*   C = N - i
*   C >= 0 al inicio del bucle, dado que el predicado N >= 0
*   C decrece con cada iteracion del bucle
* 
*   INVARIANTE
*   ----------
*   0 <= i < v.size() ^
*   contador = crecientes_consecutivos(i, j, v)^
*   1 <= actual = max_longitud(i,j,v) ^
*   1 <= maximo = max_longitud(i,j,v)
* 
*   COSTE
*   -----
*   El coste del algoritmo implementado en el peor de los casosseria lineal O(N), ya que recorremos el vector
*   una unica vez.  
* 
*/




// función que resuelve el problema
int resolver(const vector<int> &v) 
{
    if (v.size() == 0)
        return 0;

    int maximo = 1;
    int actual = 1;
    int contador = 1;

    for (int i = 0; i < v.size() - 1; i++)
    {
        actual++;
        if (v[i] < v[i + 1] && contador < 3)
            contador++;
        else if (v[i] >= v[i + 1])
            contador = 1;
            

        if (contador >= 3)
        {
            maximo = max(maximo, actual - 1);
            actual = 2;
        }
    }

    maximo = max(maximo, actual);

    return maximo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
    
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