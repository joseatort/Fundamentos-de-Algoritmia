// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema

typedef struct
{
    int resultado;
    int mayor;
    bool par;
}TSolucion;

TSolucion resolver(int N, int menor) {
    
    if (N < 10)
        return{N * 3 + menor, N , false};
    else
    {
        TSolucion aux = resolver(N / 10, min(N % 10, menor));

        if (!aux.par)
            aux.resultado += (N % 10) * 2 + aux.mayor;
        else
            aux.resultado += (N % 10) * 3 + menor;

        return{ aux.resultado, max(N % 10, aux.mayor), !aux.par };
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;

    cout << resolver(N, N%10).resultado << "\n";
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