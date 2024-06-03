// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int buscarIz(vector<int> &v, int Altura, int ini, int fin)
{
    if (v[ini] == Altura)
        return ini;
    else if (ini == fin)
        return -1;
    else
    {
        int M = (ini + fin) / 2;

        if (v[M] > Altura)
            return buscarIz(v, Altura, ini, M);
        else if(v[M] < Altura)
            return buscarIz(v, Altura, M + 1, fin);
        else if (v[M] == Altura)
            return buscarIz(v, Altura, ini, M);

    }
    
}

int buscarDr(vector<int>& v, int Altura, int ini, int fin)
{
    if (v[fin] == Altura)
        return fin;
    else if (v[ini] == Altura && ini == fin - 1)
        return ini;
    else if (ini == fin)
        return -1;
    else
    {
        int M = (ini + fin) / 2;

        if (v[M] > Altura)
            return buscarDr(v, Altura, ini, M);
        else if (v[M] < Altura)
            return buscarDr(v, Altura, M + 1, fin);
        else if (v[M] == Altura)
            return buscarDr(v, Altura, M, fin);
        
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int N, A;
    cin >> N >> A;
    if (! std::cin)
        return false;
    
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int inicio = buscarIz(v, A, 0, N - 1);
    int fin = buscarDr(v, A, 0, N - 1);

    if (inicio == -1)
        cout << "NO EXISTE\n";
    else if (inicio == fin || fin == -1)
        cout << inicio << "\n";
    else
        cout << inicio << " " << fin << "\n";

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