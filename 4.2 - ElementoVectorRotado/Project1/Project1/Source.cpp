// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema
bool resolver(const vector<int> &v, int B, int ini, int fin) 
{
    if (ini == fin - 1)
        return (v[ini] == B || v[fin] == B) ? true : false;
    else if (ini > fin)
        return false;
    else
    {
        int M = (ini + fin) / 2;
        
        if (v[M] == B)
            return true;

        // Caso 1: La mitad izquierda está ordenada
        if (v[ini] <= v[M]) {
            // Verificar si el valor está en la mitad ordenada
            if (v[ini] <= B && B <= v[M])
                return resolver(v, B, ini, M - 1);
            else
                // El valor debe estar en la mitad no ordenada
                return resolver(v, B, M + 1, fin);
        }

        // Caso 2: La mitad derecha está ordenada
        if (v[M] <= B && B <= v[fin])
            return resolver(v, B, M + 1, fin);
        else
            // El valor debe estar en la mitad no ordenada
            return resolver(v, B, ini, M - 1);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, B;
    cin >> N >> B;
    if (N == -1)
        return false;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    if (resolver(v, B, 0, N - 1))
        cout << "SI";
    else
        cout << "NO";
    cout << "\n";
    
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
