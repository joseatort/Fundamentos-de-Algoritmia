// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
pair<bool, int> resolver(const vector <int> &v, int ini, int fin, int B) 
{
    if (ini == fin)
    {   
        if(v[ini] == B + ini)
            return { true, v[ini] };
        else
            return { false, -1};
    }
    else
    {
        int M = (ini + fin) / 2;

        if(B + M < v[M])
            return resolver(v, ini, M, B);
        else if(B + M > v[M])
            return resolver(v, M + 1, fin, B);
        else
            return { true, v[M]};
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N, B;
    cin >> N >> B;
    vector <int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    pair<bool, int> sol = resolver(v, 0, N - 1, B);
    if (sol.first)
        cout << sol.second;
    else
        cout << "NO";
    cout << "\n";
    // escribir sol
    
    
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