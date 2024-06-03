// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
*
*   ACLARACION
*   ----------
*   N es igual al valor dado por entrada
* 
* 
*   FUNCION COMPLEMENTARIO
*   ------- --------------
* 
*   Recursion del coste:                { c0           si N < 10   }
*                                T(N) = {                          }
*                                       {T(N/10) + c1  en otro caso}
*   
*   COSTE
*   -----
*   Por el teorema de las diferencias el coste de este algoritmo sera O(
* 
* 
*/


pair<int, int> complementario_inverso(int N)
{
    if (N < 10)
    {
        return { 9 - N, 1 };
    }
    else
    {
        pair<int, int> aux = complementario_inverso(N / 10);
        return { (9 - N % 10) * pow(10, aux.second) + aux.first, aux.second + 1 };
    }
    
}

int complementario(int N) {

    if (N < 10)
    {
        return 9 - N;
    }
    else
    {
        int aux = complementario(N / 10);
        aux *= 10;
        aux += (9 - N % 10);
        
        return aux;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {    
    int N;
    cin >> N;

    cout << complementario(N) << " " << complementario_inverso(N).first << "\n";
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