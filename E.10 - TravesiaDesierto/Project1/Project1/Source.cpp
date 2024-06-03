// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
    int resolver(int ini, int fin, int P, const vector<int>& v) 
    {
        if (ini > fin)
            return -1;
        else if (v[ini] < static_cast<int>(v.size() - ini) * P)
            return ini;
        else
        {
            int M = (ini + fin) / 2;

            if(v[M] < static_cast<int>(v.size() - M) * P)
                return resolver(ini, M, P, v);
            else
                return resolver(M + 1, fin, P, v);
        }

    
    }

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N, P;
    cin >> N >> P;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
    
    int sol = resolver(0, N - 1, P, v);
    
    if (sol == -1)
        cout << "SIN RACIONAMIENTO";
    else
        cout << sol;

    cout << "\n";


    
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