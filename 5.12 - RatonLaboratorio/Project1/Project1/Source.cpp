#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

using matriz = vector<vector<int>>;

bool es_valida(int C, int castigo_actual)
{
    return castigo_actual <= C;
}

bool es_final(int M, int k)
{
    return k == M;
}

bool es_mejorable(int recompensa_actual, int maxima_recompensa, int estimacion_recompensas)
{
    return recompensa_actual + estimacion_recompensas > maxima_recompensa;
}

// función que resuelve el problema
void VueltaAtras(int N, int M, int C, const matriz &datos, int &maxima_recompensa, int recompensa_actual,
                 int k, int castigo_actual, int linea_a_buscar, int recompensa_maxima)
{
    for (int i = 0; i < N; i++)
    {
        if (linea_a_buscar != -1)
        {
            if (datos[linea_a_buscar][i] >= 0)
                recompensa_actual += datos[linea_a_buscar][i];
            else
                castigo_actual += (datos[linea_a_buscar][i] * -1);
        }

        k++;
        if (es_valida(C, castigo_actual))
        {

            if (es_final(M, k))
                maxima_recompensa = max(maxima_recompensa, recompensa_actual);
            else if (es_mejorable(recompensa_actual, maxima_recompensa, recompensa_maxima * (M - k)))
                VueltaAtras(N, M, C, datos, maxima_recompensa, recompensa_actual, k, castigo_actual, i, recompensa_maxima);
        }

        if (linea_a_buscar != -1)
        {
            if (datos[linea_a_buscar][i] >= 0)
                recompensa_actual -= datos[linea_a_buscar][i];
            else
                castigo_actual -= (datos[linea_a_buscar][i] * -1);
        }
        k--;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int N, M, C;
    cin >> N >> M >> C;

    matriz datos (N, vector<int> (N));
    int recompensa_maxima = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> datos[i][j];
            recompensa_maxima = max(recompensa_maxima, datos[i][j]);
        }
            
    
    int maxima_recompensa = 0;

    
    //Busco el maximo comenzando por cada una de las lineas de la matriz
    if (N > 0)
    {
        maxima_recompensa = -1;
        VueltaAtras(N, M, C, datos, maxima_recompensa, 0, 0, 0, -1, recompensa_maxima); //k equivale a las pulsaciones
    }

    
    if (maxima_recompensa == -1)
        cout << "NO";
    else
        cout << maxima_recompensa;
    cout << "\n";
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