// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


/*
    ESPECIFICACION FORMAL
    -------------- ------
    P = {N < n < M; N < 0 ; M > 0}
    fun int resolver(int &dato) dev d
    Q = {d = n * 2}


    COSTE
    -----
    El coste de este algoritmo sería O(1), ya que los datos unicamente reciben una operacion
*/


// función que resuelve el problema
int resolver(int &dato) {
    
    return dato * 2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int dato;
    cin >> dato;

    if (dato == 0)
        return false;
    
    cout << resolver(dato) << "\n";
    
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
