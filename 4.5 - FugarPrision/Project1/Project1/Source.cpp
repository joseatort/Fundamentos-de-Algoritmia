#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// función que resuelve el problema
char resolver(vector<char> const &v, int ini, int fin) 
{
    if (ini >= fin - 1)
        return v[ini] + 1;
    else
    {
        int M = (ini + fin) / 2;

        if(v[M] - v[ini] >= (M - ini + 1))
            return resolver(v, ini, M);
        else
            return resolver(v, M, fin);
    }

    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    char ini, fin;
    cin >> ini >> fin;

    vector<char> v(fin - ini);
    for (int i = 0; i < fin - ini; i++)
        cin >> v[i];

    if (v[0] != ini)
        cout << ini;
    else if (v[v.size() - 1] != fin)
        cout << fin;
    else
        cout << resolver(v, 0, fin - ini - 1);
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