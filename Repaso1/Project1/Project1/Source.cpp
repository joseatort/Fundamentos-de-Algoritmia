// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


/*
* 
*   ACLARACION
*   ----------
*   N es el numero de elementos del vector
* 
*   ESPECIFICACION
*   --------------
*   P = {1 <= N ^ Existe i: 0 <= i < N: v[i] > 0}
*   datos resolver(const vector<int> &v) dev {int maximo, int inicio_max, int longitud}
*   Q = {maximo = max i,j : 0 <= i < j < N: suma_intervalos(i,j,v) ^ 
*        inicio_max = i ^                                            
*        longitud = minima_logitud(v, i, j, maximo)}
* 
*   Predicados auxiliares...
*   
*   suma_intervalos(i,j,v) <=> (Sumatorio w: i <= w <= j: v[w])
*   minima_logitud(v, i, j, maximo) <=> (min i,j: 0 <= i <= j < N: suma_intervalos(i,j,v) == maximo: j - i + 1)
* 
*   INVARIANTE
*   ----------
*   0 <= i <= N ^
*   maximo = minima_logitud(v, i, j, maximo) ^
*   acumulador_actual = suma_intervalos(i,j,v) ^
*   inicio_maximo = i ^
*   inicio = i
*   
*   FUNCION COTA
*   ----------
*   N - i
*   C >= 0 al comenzar el bucle
*   C decrece por cada iteraccion que realiza el bucle
*  
*   COSTE
*   -----
*   El coste del algoritmo en el caso peor es de O(N), siendo N el numero de elementos
*   del vector, ya que recorremos todos los elementos buscando el intervalo con valor maximo
*   
* 
* 
* 
*/




typedef struct datos
{
    int acumulado;
    int inicio;
    int longitud;
};

datos resolver(const vector<int> &v)
{
    int maximo = 0;
    int inicio_max = 0, longitud = 0;

    int acumulador_actual = 0;
    int inicio = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (acumulador_actual + v[i] <= 0)
        {
            acumulador_actual = 0;
            inicio = i + 1;
        }
        else
            acumulador_actual += v[i];

        if (acumulador_actual > maximo)
        {
            maximo = acumulador_actual;
            inicio_max = inicio;
            longitud = i - inicio + 1;
        }

    }
    
    return { maximo, inicio_max, longitud};
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

    datos aux = resolver(v);
    
    cout << aux.acumulado << " " << aux.inicio << " " << aux.longitud << "\n";
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