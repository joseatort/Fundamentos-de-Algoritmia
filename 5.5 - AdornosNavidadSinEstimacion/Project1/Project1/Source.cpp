// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
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
        else if (es_completable(coste_actual, P, N, k))
            VueltaAtras(N, P, v, k + 1, superficie_maxima, superficie_actual, coste_actual, sol);


        if (sol[k] == 1)
        {
            coste_actual -= v[k].coste;
            superficie_actual -= v[k].superficie;
        }

    }
    
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
       
    int superficie_maxima = 0;
    vector<int> sol(N, 0);
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