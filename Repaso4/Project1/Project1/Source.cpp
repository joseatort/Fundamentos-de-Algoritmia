// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
* 
*   ESPACIO DE SOLUCIONES
*   ------- -- ----------
*   El espacio de soluciones es de O(3 ^ H), siendo H el tamaño de la torre
* 
* 
*/


bool es_valida(const vector<int>& sol, const vector<int>& restantes, const vector<int>& marcaje, int k, int i)
{
    if (restantes[i] < 0)
        return false;
    else if (k > 0 && sol[k] == sol[k - 1] && sol[k] == 2)
        return false;
    else if (marcaje[2] > marcaje[0])
        return false;
    else if (sol[0] != 1)
        return false;
    else
        return true;

}

bool es_final(const int N, const int k, const vector<int>& marcaje)
{
    if (k == N - 1 && marcaje[1] > marcaje[0] + marcaje[2])
        return true;
    else
        return false;
}

void mostrar(const vector<int>& sol)
{
    for (int i = 0; i < sol.size(); i++)
    {
        if (sol[i] == 0)
            cout << "azul ";
        else if (sol[i] == 1)
            cout << "rojo ";
        else if (sol[i] == 2)
            cout << "verde ";
    }
    cout << "\n";
}

void VueltaAtras(const int N, int k, vector<int> &sol, vector<int>& restantes, vector<int> &marcaje, bool &nulo)
{
    
    for (int i = 0; i < 3; i++)
    {
        sol[k] = i;
        marcaje[i]++;
        restantes[i]--;

        if (es_valida(sol, restantes, marcaje, k, i))
        {

            if (es_final(N, k, marcaje))
            {
                mostrar(sol);
                nulo = true;
            }
            else if (k < N - 1)
                VueltaAtras(N, k + 1, sol, restantes, marcaje, nulo);

        }

        marcaje[i]--;
        restantes[i]++;
        sol[k] = -1;

    }
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int N, A, R, V;
    cin >> N >> A >> R >> V;
    if (N == 0 && A == 0 && R == 0 && V == 0)
        return false;
    
    vector<int> restantes(3);

    restantes[0] = A;
    restantes[1] = R;
    restantes[2] = V;
    vector<int> sol(N, -1);
    vector<int> marcaje(3, 0);
    bool nulo = false;
    VueltaAtras(N, 0, sol, restantes, marcaje, nulo);

    if (!nulo)
        cout << "SIN SOLUCION\n";

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
