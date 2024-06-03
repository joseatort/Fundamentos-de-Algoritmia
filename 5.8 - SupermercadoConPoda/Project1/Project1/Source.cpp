// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

using matriz = vector<vector<int>>;

bool es_completable(int k, int P, int coste_actual, int coste_minimo, vector<int>& marcajes, int i, vector<bool>& marcas)
{
    return k < P - 1 && coste_actual < coste_minimo && marcajes[i] < 3 && !marcas[k];
}

bool es_final(int k, int P, int coste_actual, int coste_minimo, vector<int>& marcajes, int i, vector<bool>& marcas)
{
    return k == P - 1 && coste_actual < coste_minimo && marcajes[i] < 3 && !marcas[k];
}


bool es_favorable(int coste_minimo, int coste_actual, const vector<int>& estimaciones, int k)
{
    return coste_actual + estimaciones[k + 1] < coste_minimo;
}


// función que resuelve el problema
void VueltaAtras(int S, int P, matriz& datos, int k, vector<int> &sol, vector<bool> &marcas,
                 vector<int>& marcajes, int coste_actual, int &coste_minimo, const vector<int> &estimaciones)
{
    for (int i = 0; i < S; i++)
    {
        sol[k] = i;
        coste_actual += datos[i][k];
        if (es_final(k, P, coste_actual, coste_minimo, marcajes, i, marcas))
            coste_minimo = min(coste_actual, coste_minimo);
        else if (es_completable(k, P, coste_actual, coste_minimo, marcajes, i, marcas) && es_favorable(coste_minimo, coste_actual, estimaciones, k))
        {
            marcajes[i]++;
            marcas[k] = true;
            VueltaAtras(S, P, datos, k + 1, sol, marcas, marcajes, coste_actual, coste_minimo, estimaciones);
            marcas[k] = false;
            marcajes[i]--;
        }

        sol[k] = 0;
        coste_actual -= datos[i][k];
    }


    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int S, P;
    cin >> S >> P;

    matriz datos(S, vector<int>(P));
    vector<int> estimaciones(P, numeric_limits<int>::max());


    for (int i = 0; i < S; i++)
        for (int j = 0; j < P; j++)
        {
            cin >> datos[i][j];
            estimaciones[j] = min(estimaciones[j], datos[i][j]);

        }
            
    for (int i = P - 2; i >= 0; i--)
        estimaciones[i] += estimaciones[i + 1];
    
    vector<int> sol(P, 0);
    vector<bool> marcas(P, false);
    vector<int> marcajes(S, 0);

    
    vector<int> aux_minimos_precios(P, -1);

    int coste_minimo = numeric_limits<int>::max();
    VueltaAtras(S, P, datos, 0, sol, marcas, marcajes, 0, coste_minimo, estimaciones);
    
    if (P == 0)
        cout << 0;
    else if (coste_minimo == numeric_limits<int>::max())
        cout << "Sin solucion factible";
    else 
        cout << coste_minimo;
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