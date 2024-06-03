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
    int unos;
    int ceros;
    int equilibrado;
}tDatos;


// función que resuelve el problema
tDatos resolver(const vector<vector<int>> &v, int filaini, int filafin, int colini, int colfin)
{
    if (filaini == filafin && colini == colfin)
    {
        if(v[filaini][colini] == 0)
            return {0, 1, true };
        else
            return {1, 0, true };
    }
    else
    {
        int M1 = (filaini + filafin) / 2;
        int M2 = (colini + colfin) / 2;

        tDatos sol1_1 = resolver(v, filaini, M1, colini, M2); 
        tDatos sol1_2 = resolver(v, filaini, M1, M2 + 1 , colfin);
        tDatos sol2_1 = resolver(v, M1 + 1, filafin, colini, M2);
        tDatos sol2_2 = resolver(v, M1 + 1, filafin, M2 + 1, colfin);



        if (sol1_1.equilibrado && sol1_2.equilibrado && sol2_1.equilibrado && sol2_2.equilibrado)
        {
            int labranza = sol1_1.unos + sol1_2.unos + sol2_1.unos + sol2_2.unos;
            int pasto = sol1_1.ceros + sol1_2.ceros + sol2_1.ceros + sol2_2.ceros;

            int N = (filafin - filaini + 1) * (filafin - filaini + 1);

            int parcela_mayor = max({ sol1_1.unos, sol1_2.unos, sol2_1.unos, sol2_2.unos });
            int parcela_menor = min({ sol1_1.unos, sol1_2.unos, sol2_1.unos, sol2_2.unos });

            if((abs(parcela_mayor - parcela_menor) <= 2) && ((N / 4) - 1 <= labranza && labranza <= (3 * N) / 4))
                return { labranza, pasto, true };

        }

        return {0, 0, false};

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int y = 0; y < N; y++)
            cin >> v[i][y];

    cout << (resolver(v, 0, N - 1, 0, N - 1).equilibrado ? "SI" : "NO") << "\n";
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