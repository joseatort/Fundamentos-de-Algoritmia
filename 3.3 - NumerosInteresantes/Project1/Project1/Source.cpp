// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
pair<int, bool> resolver(int N, int suma)
{
    if (N % 10 == 0)
        return { 0, false };


    if (N < 10)
    {
        return { N, suma % N == 0};
    }
    else
    {
        if ((suma % (N % 10)) == 0 || suma == 0)
        {
            pair<int, bool> sol = resolver(N / 10, suma + N % 10);

            if (sol.first % (N % 10) == 0 && sol.second)
                return { sol.first + (N % 10), true };
            else
                return { 0, false };
        }
        else
            return { 0, false };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (resolver(N, 0).second)
        cout << "SI\n";
    else
        cout << "NO\n";
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