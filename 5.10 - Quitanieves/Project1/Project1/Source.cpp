#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using matriz = vector<vector<int>>;

bool es_mejorable(int calidad_actual, int mayor_calidad, const vector<int> & estimacion, int k)
{
    return calidad_actual + estimacion[k] > mayor_calidad;
}

bool es_valida(const vector<int>& carros, const vector<int>& carreteras, vector<bool>& marcas, int k, int i)
{
    return carros[k] <= carreteras[i] && !marcas[i];
}

bool es_final(int k, int Carros)
{
    return k == Carros - 1;
}

// función que resuelve el problema
void VueltaAtras(int Carros, int Carreteras, const vector<int> &carros, const vector<int> &carreteras, const matriz &calidades,
                 vector<bool> &marcas, int k, vector<int> &sol, int calidad_actual, int &mayor_calidad, const vector<int> &estimacion)
{
    
    for (int i = 0; i < Carreteras; i++)
    {
        sol[k] = i;
        calidad_actual += calidades[k][i];
        
        if (es_valida(carros, carreteras, marcas, k, i))
        {
            if (es_final(k, Carros))
                mayor_calidad = max(mayor_calidad, calidad_actual);
            else if (k + 1 < Carros && es_mejorable(calidad_actual, mayor_calidad, estimacion, k + 1))
            {
                marcas[i] = true;

                VueltaAtras(Carros, Carreteras, carros, carreteras, calidades, marcas, k + 1, sol, calidad_actual, mayor_calidad, estimacion);

                marcas[i] = false;
            }

        }
        sol[k] = -1;
        calidad_actual -= calidades[k][i];
    }

    //Probamos a no usar ese carro
    if (es_final(k, Carros))
        mayor_calidad = max(mayor_calidad, calidad_actual);
    else if (k + 1 < Carros && es_mejorable(calidad_actual, mayor_calidad, estimacion, k + 1))
        VueltaAtras(Carros, Carreteras, carros, carreteras, calidades, marcas, k + 1, sol, calidad_actual, mayor_calidad, estimacion);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int Carros, Carreteras;
    cin >> Carros >> Carreteras;

    vector<int> carros(Carros);
    for (int i = 0; i < Carros; i++)
        cin >> carros[i];

    vector<int> carreteras(Carreteras);
    for (int i = 0; i < Carreteras; i++)
        cin >> carreteras[i];

    matriz calidades(Carros, vector<int>(Carreteras));
    vector<int> estimacion(Carros, -1);
    for (int i = 0; i < Carros; i++)
        for (int j = 0; j < Carreteras; j++)
        {
            cin >> calidades[i][j];

            estimacion[i] = max(estimacion[i], calidades[i][j]);
        }
    
    
    for (int i = estimacion.size() - 2; i >= 0; i--)
        estimacion[i] += estimacion[i + 1];

    vector<bool> marcas(Carreteras, false);
    vector<int> sol(Carros, -1);
    int mayor_calidad = 0;

    if(Carros > 0)
        VueltaAtras(Carros, Carreteras, carros, carreteras, calidades, marcas, 0, sol, 0, mayor_calidad, estimacion);

    cout << mayor_calidad << "\n";
    
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