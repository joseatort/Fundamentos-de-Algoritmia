// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

bool es_completable(int i, const vector<int>& maximos, vector<int>& marcaje, int k)
{
    return marcaje[i] <= maximos[i];
}

bool es_final(int ciudades_factibles, int N, int k, int M)
{
    return k == M - 1 && ciudades_factibles == N;
}

bool es_mejorable(int coste_actual, int coste_minimo, int pago_minimo, int reservas)
{
    return coste_actual + pago_minimo * reservas < coste_minimo;
}

// función que resuelve el problema
void VueltaAtras(int N, int M, int k, const vector<int> & minimos, const vector<int> &maximos, 
                 const vector<int> &sueldos, const vector<int> &patrullas, int reservas, int R, 
                 int& costeminimo, int coste_actual, vector<int> &marcaje, vector<int> &sol, 
                 int pago_minimo, int ciudades_factibles) {
    
    for (int i = 0; i < N; i++)
    {
        //Pruebo a añadir la patrulla
        sol[k] = i;

        reservas -= patrullas[k];
        coste_actual += patrullas[k] * sueldos[i];

        if (marcaje[i] < minimos[i] && marcaje[i] + patrullas[k] >= minimos[i] && marcaje[i] + patrullas[k] <= maximos[i])
            ciudades_factibles++;

        marcaje[i] += patrullas[k];

        if (es_completable(i, maximos, marcaje, k))
        {

            if(es_final(ciudades_factibles, N, k, M))
                costeminimo = min(costeminimo, coste_actual + R * reservas);
            else if (k + 1 < M && es_mejorable(coste_actual, costeminimo, pago_minimo, reservas))
                VueltaAtras(N, M, k + 1, minimos, maximos, sueldos, patrullas, reservas, R, costeminimo, coste_actual, marcaje, sol, pago_minimo, ciudades_factibles);

        }
        
        sol[k] = -1; 
        coste_actual -= patrullas[k] * sueldos[i];
        reservas += patrullas[k];
        
        marcaje[i] -= patrullas[k];

        if (marcaje[i] < minimos[i] && marcaje[i] + patrullas[k] >= minimos[i] && marcaje[i] + patrullas[k] <= maximos[i])
            ciudades_factibles--;


    }

    //Pruebo a no añadir la patrulla
    if (es_final(ciudades_factibles, N, k, M))
        costeminimo = min(costeminimo, coste_actual + R * reservas);
    else if (k + 1 < M && es_mejorable(coste_actual, costeminimo, pago_minimo, reservas))
        VueltaAtras(N, M, k + 1, minimos, maximos, sueldos, patrullas, reservas, R, costeminimo, coste_actual, marcaje, sol, pago_minimo, ciudades_factibles);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int N, M, R;
    cin >> N >> M >> R;

    vector<int> minimos(N);
    vector<int> maximos(N);
    vector<int> sueldos(N);
    vector<int> patrullas(M);

    int pago_minimo = R;

    for (int i = 0; i < N; i++)
        cin >> minimos[i];

    for (int i = 0; i < N; i++)
        cin >> maximos[i];

    for (int i = 0; i < N; i++)
    { 
        cin >> sueldos[i];
        pago_minimo = min(pago_minimo, sueldos[i]);
    }
        

    int reservas = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> patrullas[i];
        reservas += patrullas[i];
    }
        
    vector<int> sol(M, -1);
    vector<int> marcaje(N, 0);
    int costeminimo = numeric_limits<int>::max();
    VueltaAtras(N, M, 0, minimos, maximos, sueldos, patrullas, reservas, R, costeminimo, 0, marcaje, sol, pago_minimo, 0);

    costeminimo == numeric_limits<int>::max() ? cout << "NO" : cout << costeminimo;
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