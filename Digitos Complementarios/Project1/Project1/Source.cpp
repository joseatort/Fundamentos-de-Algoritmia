// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// función que resuelve el problema

long long int complementario(long long int N)
{
    if (N < 10)
    {
        return 9 - N;
    }
    else
    {
        return complementario(N / 10) * 10 + 9 - N % 10;
    }

    
}

pair<long long int, int> complementario_inverso(long long int N)
{
    if (N < 10)
    {
        return { 9 - N, 1};
    }
    else
    {
        pair<int, int> sol = complementario_inverso(N / 10);
        return {((9 - N % 10) * pow(10, sol.second)) + sol.first, sol.second + 1 };
    }
}

pair<int, int> resolver(int N) {

    return{ complementario(N) ,  complementario_inverso(N).first};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;

    pair<int, int> sol = resolver(N);

    // escribir sol
    cout << sol.first << " " << sol.second << "\n";
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