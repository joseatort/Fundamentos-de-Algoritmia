// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool es_final(int N, int k)
{
    return k == N - 1;
}

bool es_valida(const vector<vector<int>>& vetos, const vector<bool>& marcas, const vector<int>& sol, int k, int i)
{
    if ((k == 0 || vetos[i][sol[k - 1]]) && !marcas[i])
        return true;
    else
        return false;
}

bool es_completable(const vector<int> & estimacion, int beneficio_actual, int beneficio_maximo, int i)
{
    return estimacion[i + 1] + beneficio_actual > beneficio_maximo;
}
// función que resuelve el problema
void VueltaAtras(int N, int k, int beneficio_actual, int & beneficio_maximo, vector<int> &sol, vector<bool> &marcas, const vector<vector<int>> & donaciones, const vector<vector<int>>& vetos, const vector<int> &estimacion)
{
    for (int i = 0; i < N; i++)
    {
        sol[k] = i; 
        beneficio_actual += donaciones[i][k];
        if (es_valida(vetos, marcas, sol, k, i))
        {
            if (es_final(N, k))
                beneficio_maximo = max(beneficio_maximo, beneficio_actual);
            else if (es_completable(estimacion, beneficio_actual, beneficio_maximo, k))
            {
                marcas[i] = true;
                VueltaAtras(N, k + 1, beneficio_actual, beneficio_maximo, sol, marcas, donaciones, vetos, estimacion);
                marcas[i] = false;
            }
        }

        beneficio_actual -= donaciones[i][k];
        sol[k] = -1;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;

    vector<vector<int>> donaciones(N, vector<int>(N));
    vector<vector<int>> vetos(N, vector<int>(N));
    
    vector<int> estimacion(N + 1, numeric_limits<int>::min());
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> donaciones[i][j];
            estimacion[j] = max(estimacion[j], donaciones[i][j]);
        }
            

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> vetos[i][j];

    for (int i = N - 2; i >= 0; i--)
        estimacion[i] += estimacion[i + 1];
    estimacion[N] = 0;

    vector<int> sol(N, -1);
    vector<bool> marcas(N, false);
    int beneficio_maximo = numeric_limits<int>::min();
    VueltaAtras(N, 0, 0, beneficio_maximo, sol, marcas, donaciones, vetos, estimacion);
    // escribir sol
    if (beneficio_maximo == numeric_limits<int>::min())
        cout << "NEGOCIA CON LOS ARTISTAS";
    else
        cout << beneficio_maximo;
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