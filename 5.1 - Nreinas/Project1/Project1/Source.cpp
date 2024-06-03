// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

bool no_ataca(vector<int>& sol, int k, vector<bool>& cols, vector<bool>& diagonal_asc,
              vector<bool>& diagonal_des, int N)
{
    return !cols[sol[k]] && !diagonal_asc[k + sol[k]] && !diagonal_des[(k - sol[k]) + N - 1];
}

bool es_solucion(vector<int>& sol, int k, vector<bool>& cols, vector<bool>& diagonal_asc,
                 vector<bool>& diagonal_des, int N)
{
    return k == N - 1 && no_ataca(sol, k, cols, diagonal_asc, diagonal_des, N);
}

bool es_completable(vector<int>& sol, int k, vector<bool>& cols, vector<bool>& diagonal_asc,
                    vector<bool>& diagonal_des, int N)
{
    return k < N - 1 && no_ataca(sol, k, cols, diagonal_asc, diagonal_des, N);
}

// función que resuelve el problema
void VueltaAtras(vector<int> &sol, int k, vector<bool> & cols, vector<bool>& diagonal_asc, 
                 vector<bool>& diagonal_des, int N, int &num_sol)
{
    for (int f = 0; f < N; f++)
    {
        sol[k] = f;
        if (es_solucion(sol, k, cols, diagonal_asc, diagonal_des, N))
            num_sol++;
        else if (es_completable(sol, k, cols, diagonal_asc, diagonal_des, N))
        {
            cols[f] = true;
            diagonal_asc[k + f] = true;
            diagonal_des[(k - f) + N - 1] = true;

            VueltaAtras(sol, k + 1, cols, diagonal_asc, diagonal_des, N, num_sol);

            sol[f] = 0;
            cols[f] = false;
            diagonal_asc[k + f] = false;
            diagonal_des[(k - f) + N - 1] = false;
        }



    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int N;
    cin >> N;
    vector<int> sol(N, 0);
    vector<bool> cols(N, false);
    vector<bool> diagonal_asc(2*N - 1, false);
    vector<bool> diagonal_des(2*N - 1, false);
    int num_sol = 0;
    VueltaAtras(sol, 0, cols, diagonal_asc, diagonal_des, N, num_sol);
    cout << num_sol << "\n";
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