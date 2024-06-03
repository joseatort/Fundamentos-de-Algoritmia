// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema

bool es_completable(int k, int Tam_palabra, vector<bool>& marcas, int i)
{
    return k < Tam_palabra - 1 && !marcas[i];
}

bool es_final(int k, int Tam_palabra, vector<bool>& marcas, int i)
{
    return k == Tam_palabra - 1 && !marcas[i];
}

void VueltaAtras(int Numerodeletras, int Tam_palabra , int k, vector<string> &palabras, string palabra_actual, vector<bool> &marcas)
{
    for (int i = 0; i < Numerodeletras; i++)
    {
        palabra_actual.push_back(97 + i);

        if (es_final(k, Tam_palabra, marcas, i))
            palabras.push_back(palabra_actual);
        else if (es_completable(k, Tam_palabra, marcas, i))
        {
            marcas[i] = true;
            VueltaAtras(Numerodeletras, Tam_palabra, k + 1, palabras, palabra_actual, marcas);
            marcas[i] = false;
        }

        palabra_actual.pop_back();
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int M, N;
    cin >> M >> N;
    if (! std::cin)
        return false;
    
    vector<string> sol;
    vector<bool> marcas(M, false);
    VueltaAtras(M, N, 0, sol, "", marcas);
    
    // escribir sol
    
    for (int i = 0; i < sol.size(); i++)
        cout << sol[i] << "\n";
    cout << "\n";
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