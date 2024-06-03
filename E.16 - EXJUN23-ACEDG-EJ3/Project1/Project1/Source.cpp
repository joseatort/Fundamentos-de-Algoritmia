// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool es_completable(const vector<int>& marcaje, const vector<int>& maximos, int i)
{
    return marcaje[i] <= maximos[i];
}

bool es_final(int k, int E, int proyectos_validos, int P)
{
    return k == E - 1 && proyectos_validos == P;
}

bool es_mejorable(const vector<int>& estimacion, int salario_actual, int salario_minimo, int k)
{
    return estimacion[k + 1] + salario_actual < salario_minimo;
}

void VueltaAtras(int E, int P, int k, int salario_actual, int &salario_minimo, const vector<int> &equipos, const vector<int> &minimos,
                 const vector<int>& maximos, const vector<int>& sueldos, vector<int> &sol, vector<int> &marcaje, int proyectos_validos, const vector<int> &estimacion)
{
    
    for (int i = 0; i < P; i++)
    {
        sol[k] = i;
        salario_actual += equipos[k] * sueldos[i];

        if (marcaje[i] < minimos[i] && marcaje[i] + equipos[k] >= minimos[i] && marcaje[i] + equipos[k] <= maximos[i])
            proyectos_validos++;

        marcaje[i] += equipos[k];

        if (es_completable(marcaje, maximos, i))
        {
            if (es_final(k, E, proyectos_validos, P))
                salario_minimo = min(salario_minimo, salario_actual);
            else if (k < E - 1 && es_mejorable(estimacion, salario_actual, salario_minimo, k))
                VueltaAtras(E, P, k + 1, salario_actual, salario_minimo, equipos, minimos, maximos, sueldos, sol, marcaje, proyectos_validos, estimacion);

        }

        marcaje[i] -= equipos[k];

        if (marcaje[i] < minimos[i] && marcaje[i] + equipos[k] >= minimos[i] && marcaje[i] + equipos[k] <= maximos[i])
            proyectos_validos--;

        salario_actual -= equipos[k] * sueldos[i];
        sol[k] = -1;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int E, P;
    cin >> E >> P;

    vector<int> equipos(E);
    for (int i = 0; i < E; i++)
        cin >> equipos[i];

    vector<int> minimos(P);
    vector<int> maximos(P);
    vector<int> sueldos(P);

    int sueldo_estimado = numeric_limits<int>::max();

    for (int i = 0; i < P; i++)
        cin >> minimos[i];
    for (int i = 0; i < P; i++)
        cin >> maximos[i];
    for (int i = 0; i < P; i++)
    {
        cin >> sueldos[i];
        sueldo_estimado = min(sueldo_estimado, sueldos[i]);
    }
    //Calculo estimacion a partir del menor sueldo directamente, en vez de hacer dentro de la poda
    vector<int> estimacion = equipos;
    estimacion.push_back(0);
    for (int i = E - 1; i >= 0; i--)
        estimacion[i] = (estimacion[i] * sueldo_estimado) + estimacion[i + 1];

    vector<int> sol(E, -1);
    vector<int> marcaje(P, 0);
    vector<bool> marca_proyectos(P, false);
    int salario_minimo = numeric_limits<int>::max();
    VueltaAtras(E, P, 0, 0, salario_minimo, equipos, minimos, maximos, sueldos, sol, marcaje, 0, estimacion);
    
    if (salario_minimo == numeric_limits<int>::max())
        cout << "NO";
    else
        cout << salario_minimo;
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