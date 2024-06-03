// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int coste;
    int superficie;
}Adornos;

bool es_final(int coste, int P, int N, int k)
{
    return (k == N - 1 && coste < P) || coste == P;
}

bool es_completable(int coste, int P, int N, int k)
{
    return coste < P && k < N - 1;
}

bool es_prometedora(const int superficie_maxima, const vector<Adornos>& v, const int superficie_actual, const int coste_actual, const int k, const int Presupuesto)
{
    int coste = coste_actual;
    int superficie = superficie_actual;
    int contador = k + 1;

    while (contador < v.size() && coste < Presupuesto)
    {
        superficie += v[contador].superficie;
        coste += v[contador].coste;
        contador++;
    }
    
    if (coste > Presupuesto)
        superficie -= v[contador - 1].superficie * (coste - Presupuesto) / v[contador - 1].coste;

    return superficie > superficie_maxima;
}

// función que resuelve el problema
void VueltaAtras(int N, int P, const vector<Adornos>& v, int k,
                int& superficie_maxima, int superficie_actual, int coste_actual, vector<int> &sol)
{

    for (int i = 1; i >= 0; i--)
    {
        sol[k] = i;

        if (sol[k] == 1)
        {
            coste_actual += v[k].coste;
            superficie_actual += v[k].superficie;
        }

        if (es_final(coste_actual, P, N, k))
            superficie_maxima = max(superficie_maxima, superficie_actual);
        else if (es_completable(coste_actual, P, N, k) && es_prometedora(superficie_maxima, v, superficie_actual, coste_actual, k, P))
            VueltaAtras(N, P, v, k + 1, superficie_maxima, superficie_actual, coste_actual, sol);

        if (sol[k] == 1)
        {
            coste_actual -= v[k].coste;
            superficie_actual -= v[k].superficie;
        }

    }
    
}

int calculo_estimacion(const vector<Adornos> &v, int Presupuesto)
{

    int estimacion = 0;
    int coste = 0;
    int contador = 0;

    while (contador < v.size() && coste < Presupuesto)
    {
        estimacion += v[contador].superficie;
        coste += v[contador].coste;
        contador++;
    }
    
    if(coste > Presupuesto)
        estimacion -= v[contador - 1].superficie;

    return estimacion;
}

bool compare(const Adornos& a, const Adornos& b)
{
    return ((float)a.coste / a.superficie) < ((float)b.coste / b.superficie);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int N, P;
    cin >> N >> P;
    if (! std::cin)
        return false;
    
    vector<Adornos> v(N);

    int c, s;
    for (int i = 0; i < N; i++)
    {
        cin >> c >> s;
        v[i] = {c, s};
    }
       
    int superficie_maxima;
    vector<int> sol(N, 0);

    sort(v.begin(), v.end(), compare);

    int estimacion = calculo_estimacion(v, P);
    superficie_maxima = estimacion;

    VueltaAtras(N, P, v, 0, superficie_maxima, 0, 0, sol);
    
    cout << superficie_maxima << "\n";
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