// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(const vector<int> &v, int D, int ini, int fin) 
{
    if (ini == fin - 1)
        return abs(v[ini] - v[fin]) >= D;
    else if (ini >= fin)
        return true;
    else
    {
        int M = (ini + fin) / 2;

        if (abs(v[ini] - v[fin]) >= D)
        {
            bool x = resolver(v, D, ini, M);
            bool y = resolver(v, D, M + 1, fin);

            return x && y;
        }
        else
            return false;


        
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int N, D;
    cin >> N >> D;
    if (! std::cin)
        return false;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    
    if (resolver(v, D, 0, N - 1))
        cout << "SI\n";
    else
        cout << "NO\n";
   
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