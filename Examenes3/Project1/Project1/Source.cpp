// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;


typedef struct
{
    int diferencia_minima;
    int formas;

}tSolucion;

/*
*   ESPACIO DE SOLUCIONES
*   ------- -- ----------
*   El arbol de exploracion tendría una profundidad en N, siendo N el numero 
*   de moneadas y una anchura por piso de 2, siendo 2 el numero de piratas,
*   quedando de la siguiente forma 2^N
* 
*   MARCADORES
*   ----------
*   marcaje_numero = corresponde a un vector de enteros en el que se guardan 
*                    numero de monedas asignadas por pirata
* 
*   marcaje_cantidad = corresponde a un vector de enteros en el que se guardan 
*                      los valores totales de las monedas asignadas a cada pirata
* 
* 
*/



bool es_mejorable()
{
    return true;
}

bool es_final(const int k, const int N)
{
    return k == N -1;
}

bool esValida(const vector<int>& marcaje_numero, const int N, const int k, const int c)
{
    if (marcaje_numero[0] + (N - k - 1) >= c && marcaje_numero[1] + (N - k - 1) >= c)
        return true;
    else
        return false;
}

// función que resuelve el problema
void VueltaAtras(int N, int c, int k, vector<int> &sol, vector<int> & marcaje_cantidad, vector<int>& marcaje_numero, const vector<int> &v, tSolucion &mejor)
{
    for (int i = 0; i < 2; i++)
    {
        sol[k] = i;
        marcaje_cantidad[i] += v[k];
        marcaje_numero[i]++;
        if (esValida(marcaje_numero, N, k, c))
        {
            if (es_final(k, N))
            {
                if (abs(marcaje_cantidad[0] - marcaje_cantidad[1]) < mejor.diferencia_minima)
                {
                    mejor.diferencia_minima = abs(marcaje_cantidad[0] - marcaje_cantidad[1]);
                    mejor.formas = 1;
                }
                else if (abs(marcaje_cantidad[0] - marcaje_cantidad[1]) == mejor.diferencia_minima)
                    mejor.formas++;
            }
            else if (es_mejorable())
                VueltaAtras(N, c, k + 1, sol, marcaje_cantidad, marcaje_numero, v, mejor);

        }
        marcaje_numero[i]--;
        marcaje_cantidad[i] -= v[k];
        sol[k] = -1;

    }

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == -1)
        return false;
    
    int min;
    cin >> min;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    tSolucion mejorsol;

    mejorsol.diferencia_minima = numeric_limits<int>::max();
    mejorsol.formas = 0;

    vector<int> sol(N, -1);
    vector<int> marcaje_cantidad(2, 0);
    vector<int> marcaje_numero(2, 0);
    VueltaAtras(N, min, 0, sol, marcaje_cantidad, marcaje_numero, v, mejorsol);
    
    cout << mejorsol.diferencia_minima << " " << mejorsol.formas << "\n";
    
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
