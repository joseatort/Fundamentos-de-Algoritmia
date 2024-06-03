// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
pair<int, bool> resolver(const vector<int> &v, int ini, int fin) 
{
    if (ini == fin)
    {
        if (v[ini] % 2 == 0)
            return { 1, true };
        else
            return { 0, true };
    }
    else
    {
        int M = (ini + fin) / 2;
        pair<int, bool> izq = resolver(v, ini, M);
        pair<int, bool> der = resolver(v, M + 1, fin);

        
        if (izq.second && der.second && abs(izq.first - der.first) <= 2)
            return { izq.first + der.first, true };
        else
            return { 0, false };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    cout << (resolver(v, 0, N - 1).second ? "SI" : "NO") << "\n";
        
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
