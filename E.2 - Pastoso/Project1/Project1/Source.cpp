// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<bool,int> resolver(const vector<int> &v) 
{
    bool encontrado = false;
    int indice = -1;
    int acumulador = 0;
    for (int i = v.size() - 1; i >= 0  && !encontrado; i--)
    {
        if (v[i] == acumulador)
        {
            encontrado = true;
            indice = i;
        }

        acumulador += v[i];
        
    }
    
    return { encontrado, indice };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int N;
    cin >> N;
    
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    pair<bool, int> sol = resolver(v);

    if (sol.first)
        cout << "Si " << sol.second;
    else
        cout << "No";
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