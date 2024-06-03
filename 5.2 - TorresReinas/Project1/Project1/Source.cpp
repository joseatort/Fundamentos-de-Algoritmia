// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

bool no_ataca(int f, int k, vector<bool>& filas, vector<bool>& diagonal_asc,
              vector<bool>& diagonal_des, int N, vector<vector<bool>>& excepciones)
{
    return !filas[f] && !diagonal_asc[k + f] && !diagonal_des[(k - f) + N - 1] && !excepciones[k][f];
}

bool es_solucion(int k, int N)
{
     return k == N - 1;
}

bool es_completable(int k, int N)
{
     return k < N - 1;
}

void VueltaAtras(vector<int> &sol, int k, vector<bool> &filas, vector<bool>& diagonal_asc, 
                 vector<bool>& diagonal_des, vector<bool>& diagonal_asc_torre, vector<bool>& diagonal_des_torre,
                 int N, int& T, int &R, vector<vector<bool>>& excepciones, int &num_sol)
{
    for (int f = 0; f < N; f++)
    {
        if (no_ataca(f, k, filas, diagonal_asc, diagonal_des, N, excepciones))
        {
            sol[k] = f;
            if (R > 0)
            {
                R--;
                if (es_solucion(k, N) && !diagonal_asc_torre[k + f] && !diagonal_des_torre[(k - f) + N - 1])
                    num_sol++;
                else if (es_completable(k, N) && !diagonal_asc_torre[k + f] && !diagonal_des_torre[(k - f) + N - 1])
                {
                    diagonal_asc[k + f] = true;
                    diagonal_des[(k - f) + N - 1] = true;
                    filas[f] = true;
                    VueltaAtras(sol, k + 1, filas, diagonal_asc, diagonal_des, diagonal_asc_torre, 
                                diagonal_des_torre, N, T, R, excepciones, num_sol);

                    diagonal_asc[k + f] = false;
                    diagonal_des[(k - f) + N - 1] = false;
                    filas[f] = false;
                }
                R++;
            }
            if (T > 0)
            {
                T--;
                if (es_solucion(k, N))
                    num_sol++;
                else if (es_completable(k, N)) 
                {
                    filas[f] = true;

                    bool asc_torre = diagonal_asc_torre[k + f], des_torre = diagonal_des_torre[(k - f) + N - 1];
                    diagonal_asc_torre[k + f] = true;
                    diagonal_des_torre[(k - f) + N - 1] = true;

                    VueltaAtras(sol, k + 1, filas, diagonal_asc, diagonal_des, diagonal_asc_torre,
                                diagonal_des_torre, N, T, R, excepciones, num_sol);
                    
                    filas[f] = false;
                    diagonal_asc_torre[k + f] = asc_torre;
                    diagonal_des_torre[(k - f) + N - 1] = des_torre;
                }
                T++;
            }
        }
        

    }

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int T, R, E;
    cin >> T >> R >> E;

    if (!cin)
        return false;
    
    int N = T + R;

    if (N == 0)
    {
        cout <<0<< "\n";
        return false;
    }

    vector<vector<bool>> excepciones(N, vector<bool>(N , false));
   
    int x , y;
    for (int i = 0; i < E; i++)
    {
        cin >> x >> y;
        excepciones[y - 1][x - 1] = true;
    }

    vector<int> sol(N, 0);
    vector<bool> filas(N, false);
    vector<bool> diagonal_asc(2*N - 1, false);
    vector<bool> diagonal_des(2*N - 1, false);
    vector<bool> diagonal_asc_torre(2 * N - 1, false);
    vector<bool> diagonal_des_torre(2 * N - 1, false);

    int num_sol = 0;
    VueltaAtras(sol, 0, filas, diagonal_asc, diagonal_des, diagonal_asc_torre, diagonal_des_torre, N, T, R, excepciones, num_sol);
    cout << num_sol << "\n";
    
    
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
