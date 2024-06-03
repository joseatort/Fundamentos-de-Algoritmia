// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// función que resuelve el problema
bool comprobar(long long int N, int tam) 
{
    if (N < pow(10, tam - 1))
        return true;
    else
        return comprobar(N / 10, tam) && (N % (to_string(N).size()) == 0);
}

void escribePolidivisibles(long long int raiz, int maxDigitos)
{
    long long int iniciales = to_string(raiz).size();
    long long int valor = raiz;
    bool aux;
   
    vector<int> ultimos_digitos(maxDigitos - to_string(raiz).size(), -1);

    cout << raiz << "\n";

    for (int i = 0; i <= 10 && to_string(raiz).size() < maxDigitos; i++)
    {
        if (iniciales == to_string(raiz).size() && i == 10)
            break;


        if (i == 10)
        {
            raiz /= 10; 
            ultimos_digitos[ultimos_digitos.size() - (maxDigitos - to_string(raiz).size()) + 1] = -1;
            i = ultimos_digitos[ultimos_digitos.size() - (maxDigitos - to_string(raiz).size())];
        }
        else if (comprobar(raiz * 10 + i, to_string(raiz).size()))
        {
            cout << raiz * 10 + i << "\n";

            ultimos_digitos[ultimos_digitos.size() - (maxDigitos - to_string(raiz).size())] = i;
            if (to_string(raiz * 10).size() < maxDigitos)
            {
                raiz = raiz * 10 + i;
                i = ultimos_digitos[ultimos_digitos.size() - (maxDigitos - to_string(raiz).size())];

            }
                
        }

            
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int N;
    int D;
    cin >> N >> D;
    if (! std::cin)
        return false;
    
    escribePolidivisibles(N, D);

    cout << "---\n";

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