// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// función que resuelve el problema

/*
void resolver(int N, int &acumulativo) 
{
    if (N < 10)
    {
        acumulativo *= 10;
        acumulativo += N % 10;
    }
    else
    {
        acumulativo *= 10;
        acumulativo += N % 10;
        resolver(N / 10, acumulativo);
    }
    
}*/


int resolver(int N)
{

    if (N < 10)
    {
        return N;
    }
    else
    {
        int aux = resolver(N/10);

        int suma = N % 10;
        suma *= pow(10, to_string(N).size() - 1);

        suma += aux;
        return suma;
    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;

    
    cout << resolver(N) << "\n";
    
    // escribir sol
    
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
