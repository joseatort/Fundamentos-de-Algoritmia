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
*   N es el numero de elementos del vector
*   k diferencia absoulta entre emparejados
* 
*   ESPECIFICACION
*   --------------
*   P = {0 <= N <= 200000 ^ k >= 0 ^ ParaTodo i: 0 <= i < N - 1: v[i] < v[i + 1]}
*   int resolver(const vector<int> &v, const int k) dev contador
*   Q = {#i,j: 0 <= i <= j < N: v[j] - v[i] == k}
* 
*   INVARIANTE
*   ----------
*   0 <= i <= N ^
*   0 <= aux <= N ^
*   contador = {#i,j: 0 <= i <= j < N: v[j] - v[i] == k} ^
*  
* 
*   FUNCION COTA
*   ------- ----
*   C = N - i
*   C >= 0 al comenzar el bucle
*   C decrece por cada iteracion que realiza el bucle
* 
*   COSTE
*   -----
*   El coste del ...
* 
* 
*/



int resolver(const vector<int> &v, const int k) 
{
    int contador = 0;
    int aux = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] - v[aux] == k)
        {
            contador++;
            aux++;
        }
        else if (v[i] - v[aux] > k)
        {
            aux++;
            if (v[i] - v[aux] == k)
                contador++;
        }
            

    }
    
    return contador;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == -1)
        return false;
    
    int k;
    cin >> k;
    
    vector<int> v(N);
    
    for (int i = 0; i < N; i++)
        cin >> v[i];

    cout << resolver(v, k) << "\n";
    
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
