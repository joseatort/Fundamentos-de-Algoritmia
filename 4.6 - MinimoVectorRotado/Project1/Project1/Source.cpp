#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int> &v, int ini, int fin) 
{
    if (ini >= fin - 1)
        return min(v[ini], v[fin]);
    else
    {
        int M = (ini + fin) / 2;

        //Comprobamos que el vector esta ordenado
        if (v[ini] > v[M])
        {
            //Comprobamos si la posicion siguiente a la mitad es menor 
            if(v[M + 1] < v[M])
                return resolver(v, M + 1, fin);
            //Sabemos que el minimo esta comprendido en la primera mitad
            else
                return resolver(v, ini, M);
        }
        //No esta ordenado por lo que el minimo tiene que estar en la primera parte
        else
            return resolver(v, ini, M);  

    }
 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (! std::cin)
        return false;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    cout << resolver(v, 0, N - 1) << "\n";
    
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