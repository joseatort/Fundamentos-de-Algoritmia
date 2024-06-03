// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool es_final()
{
    return true;
}

bool es_completable(int precio_minimo, int precio_actual, int restantes, const vector<int>& precios, int k, int suministro_restante)
{
    return precio_actual + (restantes * precios[k]) < precio_minimo && suministro_restante >= restantes;
}


// función que resuelve el problema
void VueltaAtras(int F, int D, int k, int precio_actual, int &precio_minimo, vector<int> &sol,
                 vector<int> &facultades, vector<int> &suministros, const vector<int> &precios, int facultades_servidas, 
                 int restantes, int suministro_restante)
{
    //Asigno un distribuidor a una universidad
    for (int i = 0; i < F; i++)
    {
        sol[k] = i;

        //Si la facultad no necesita distribuidor no le doy distribuidor
        if (facultades[i] != 0)
        {
            int aux;
            if (facultades[i] > suministros[k])
            {
                facultades[i] -= suministros[k];

                restantes -= suministros[k];
                suministro_restante -= suministros[k];

                precio_actual += suministros[k] * precios[k];
                aux = suministros[k];
                suministros[k] = 0;

                
            }
            else
            {
                if (facultades[i] != 0)
                    facultades_servidas++;

                suministros[k] -= facultades[i];

                restantes -= facultades[i];
                suministro_restante -= facultades[i];

                precio_actual += facultades[i] * precios[k];
                aux = facultades[i];
                facultades[i] = 0;

            }

            if (es_final() && facultades_servidas == F)
                precio_minimo = min(precio_minimo, precio_actual);
            else if (k < D - 1 && es_completable(precio_minimo, precio_actual, restantes, precios, k, suministro_restante))
                VueltaAtras(F, D, k + 1, precio_actual, precio_minimo, sol, facultades, suministros, precios, facultades_servidas, restantes, suministro_restante);

            if (facultades[i] == 0)
                facultades_servidas--;

            restantes += aux;
            suministro_restante += aux;

            precio_actual -= aux * precios[k];
            facultades[i] += aux;
            suministros[k] += aux;
        }
        

        sol[k] = -1;
    }

    //No lo asigno a ninguna
    if (k < D - 1 && es_completable(precio_minimo, precio_actual, restantes, precios, k, suministro_restante))
        VueltaAtras(F, D, k + 1, precio_actual, precio_minimo, sol, facultades, suministros, precios, facultades_servidas, restantes, suministro_restante);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int F, D;
    cin >> F >> D;

    int restantes = 0;
    vector<int> facultades(F);
    for (int i = 0; i < F; i++)
    {
        cin >> facultades[i];
        restantes += facultades[i];
    }
        

    vector<int> suministros(D);
    vector<int> precios(D);
    int suministro_restante = 0;
    for (int i = 0; i < D; i++)
    {
        cin >> suministros[i];
        suministro_restante += suministros[i];
    }
        

    for (int i = 0; i < D; i++)
        cin >> precios[i];
    
    vector<int> sol(D, -1);

    int precio_minimo = numeric_limits<int>::max();
    VueltaAtras(F, D, 0, 0, precio_minimo, sol, facultades, suministros, precios, 0, restantes, suministro_restante);

    if (precio_minimo == numeric_limits<int>::max())
        cout << "NO";
    else
        cout << precio_minimo;
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