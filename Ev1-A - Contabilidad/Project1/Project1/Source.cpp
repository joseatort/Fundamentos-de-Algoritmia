// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;


/*
    ACLARACIONES
    ------------
    N es el numero de viajeros

    ESPECIFICACION FORMAL
    -------------- ------
    P = {0 < N < 10^5 ^ ParaTodo i: 0 <= i < N: -1000 <= v[i] <= 1000}
    bool resolver(const vector<int> &v) dev sol;
    Q = {sol = Existe i: 0 <= i < v.size() : v[i] = acumulador(v,i)}


    Predicado auxiliar...

    acumulador(v, i) <=> (i < v.size() => acumulado = Sumatorio x: i < x < v.size(): v[x] ^ 
                          i >= v.size() => acumulado = 0)

    INVARIANTE
    ----------
    -1 <= i <= v.size() - 1 ^
    acumulador = acumulador(v, i) ^
    sol es true si Existe i: 0 <= i < v.size() : v[i] = acumulador(v,i)
        es false en caso contrario

    FUNCION COTA
    ------- ----
    C = i + 1
    C >= 0 al comenzar el bucle, por la precondicion, 0 < N < 10^5, y en este caso i = N
    C decrece con cada vuelta que da el bucle

    //Correcion: Al comenzar el bucle C siempre sera >= 0, por definicion, siempre será asi

    COSTE
    -----
    El coste del algoritmo será O(N) siendo N el numero de elementos del vector, este sería el coste
    para el caso peor en el que no sé el ultimo elemento en revisar por ejemplo v[0] fuese igual a la suma
    del resto de elementos del vector sin contar este

    //Correcion: En verdad el caso peor sería cuando no existe una suma, es decir cuando i = -1

*/

bool resolver(const vector<int> &v) 
{
    int acumulador = 0;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == acumulador)
            return true;
        else
            acumulador += v[i];
        
    }

    return false; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int N;
    cin >> N;
    if (N == 0)
        return false;
    
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    if (resolver(v))
        cout << "YES\n";
    else
        cout << "NO\n";
    
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
