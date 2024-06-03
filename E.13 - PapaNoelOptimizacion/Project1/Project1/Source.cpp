// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool es_final(int k, int N)
{
    return k == N - 1;
}

bool es_valida(const vector<bool>& marcador, int i)
{
    return !marcador[i];
}

// función que resuelve el problema
void VueltaAtras(int N, int J, int k, int sast_actual, int &sast_maxima, vector<bool> &marcador, vector<int>& sol, const vector<vector<int>> &datos) 
{
    
    for (int i = 0; i < J; i++)
    {
        sol[k] = i;
        sast_actual += datos[k][i];
        if (es_valida(marcador, i))
        {
            if (es_final(k, N))
                sast_maxima = max(sast_actual, sast_maxima);
            else /*if (es_completable())*/
            {
                marcador[i] = true;
                VueltaAtras(N, J, k + 1, sast_actual, sast_maxima, marcador, sol, datos);
                marcador[i] = false;
            }

        }
        sast_actual -= datos[k][i];
        sol[k] = -1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int J, N;
    cin >> J >> N;
    if (!std::cin)
        return false;
    
    vector<vector<int>> datos(N, vector<int>(J));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < J; j++)
            cin >> datos[i][j];

    vector<bool> marcador(J, false);
    vector<int> sol(N, -1);
    int sast_maxima = numeric_limits<int>::min();

    VueltaAtras(N, J, 0, 0, sast_maxima, marcador, sol, datos);
    cout << sast_maxima << "\n";

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