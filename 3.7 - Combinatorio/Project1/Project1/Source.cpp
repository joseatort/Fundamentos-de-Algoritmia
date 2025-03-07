// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(int A, int B, vector<vector<int>> & v) 
{
    if (B == 0)
        return 1;
    else if (A == B)
        return 1;
    else if (v[A - 1][B - 1] != -1)
        return v[A - 1][B - 1];
    else
    {
        v[A - 1][B - 1] = resolver(A - 1, B - 1, v) + resolver(A - 1, B, v);
        return v[A - 1][B - 1];
    }
        
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int A, B;
    cin >> A >> B;
    if (! std::cin)
        return false;
    
    vector<vector<int>> v(A, vector<int>(B , -1));

    cout << resolver(A, B, v) << "\n";
    
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