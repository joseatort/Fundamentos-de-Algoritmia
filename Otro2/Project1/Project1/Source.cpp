// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

bool es_mejorable()
{
    return true;
}

bool es_final()
{
    return true;
}

bool es_valido()
{
    return true;
}

void VueltaAtras(const int E, const int T, int k, vector<int> &marcaje, vector<int>& sol, const vector<int> & equipos, const vector<int>& minimo, const vector<int>& maximo, const vector<int>& sueldo, int& sueldo_minimo, int sueldo_actual)
{
    
    for (int i = 0; i < T; i++)
    {
        sol[i] = k;
        marcaje[i] += equipos[k];
        if (es_valido())
        {
            if (es_final())
            {

            }
            else if (es_mejorable())
                VueltaAtras(E, T, k + 1, sol, marcaje, equipos, minimo, maximo, sueldo, sueldo_minimo, sueldo_actual);

        }

    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int E, T;
    cin >> E >> T;
    
    vector<int> equipos(E);
    for (int i = 0; i < E; i++)
        cin >> equipos[i];

    vector<int> minimo(T);
    vector<int> maximo(T);
    vector<int> sueldo(T);
    for (int i = 0; i < T; i++)
        cin >> minimo[i];

    for (int i = 0; i < T; i++)
        cin >> maximo[i];

    for (int i = 0; i < T; i++)
        cin >> sueldo[i];

    vector<int> sol(T, -1);
    int sueldo_minimo = numeric_limits<int>::max();
    VueltaAtras(E, T, 0, sol, equipos, minimo, maximo, sueldo, sueldo_minimo, 0);

    if (sueldo_minimo == numeric_limits<int>::max())
        cout << "NO";
    else
        cout << sueldo_minimo;
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