// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


// función que resuelve el problema
pair<long long int,bool> resolver(long long int N, int posicion, long long int potencia)
{
    if (N < 10)
    {   
        if (posicion == 0 && (N == 1 || N == 0))
            return { 1, true };
        else if (posicion == 0)
            return {N, true };
        else if (N % 10 >= 2)
            return { ((N - 1)) * potencia + 1, true };
        else
            return { potencia, false };
            
    }
    else
    {
        pair<long long int, bool> num = resolver(N / 10, posicion + 1, potencia * 9);

        if (num.second == true)
        {
            if (N % 10 >= 2)
                return { num.first + ((N % 10) - 1) * potencia, true };
            else if(N % 10 == 1)
                return { num.first + potencia - 1, false };

        }
        return num;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int N;
    cin >> N;
    if (!std::cin)
        return false;

    cout << resolver(N, 0, 1).first << "\n";
    
    // escribir sol
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("casos.txt");
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