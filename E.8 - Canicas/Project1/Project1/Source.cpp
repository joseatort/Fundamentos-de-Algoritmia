// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
pair<string, int> resolver(int ini, int fin, const vector<pair<string, int>> &jugadores) {
    
    if (ini == fin)
    {
        return jugadores[ini];
    }
    else
    {
        int m = (ini + fin) / 2;
        pair<string, int> izq = resolver(ini, m, jugadores);
        pair<string, int> der = resolver(m + 1, fin, jugadores);

        pair<string, int> ganador;

        if (izq.second >= der.second) 
        {
            ganador.first = izq.first;
            ganador.second = izq.second + (der.second / 2);
        }
        else
        {
            ganador.first = der.first;
            ganador.second = der.second + (izq.second / 2);
        }
            
        return ganador;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (! std::cin)
        return false;
    
    vector<pair<string, int>> jugadores(N);
    string aux1;
    int aux2;
    for (int i = 0; i < N; i++)
    {
        cin >> aux1 >> aux2;
        jugadores[i] = { aux1, aux2 };
    }
        
    pair<string, int> sol = resolver(0, jugadores.size() - 1,jugadores);

    cout << sol.first << " " << sol.second << "\n";
    
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