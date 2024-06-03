// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>  
#include <fstream>
#include <vector>
using namespace std;

/*
    ACLARACIONES
    ------------
    N es el numero de elementos del primer vector
    M es el numero de elementos del segundo vector

    ESPECIFICACION FORMAL
    -------------- ------
    P = {0 <= N < 100000 ^ 0 <= M < 100000 ^ ParaTodo i: 0 <= i < N : v[i] >= 0 ^ ParaTodo j: 0 <= i < M : v[j] >= 0}
    vector<int> resolver(const vector<int> &primero, const vector<int> &segundo)  dev resultado
    Q = { ordenado(resultado) ^ ¿?  }


    ordenado(resultado) = ParaTodo i: 0 <= i < resultado.size() : v[i] < v[i + 1]

    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/

vector<int> resolver(const vector<int> &primero, const vector<int> &segundo) 
{
    
    vector<int> resultado;

    if (primero.size() == 0)
        return segundo;
    else if (segundo.size() == 0)
        return primero;
    else
    {
        int i = 0, y = 0;
        while (resultado.size() < (primero.size() + segundo.size()))
        {

            if (i < primero.size() && y < segundo.size())
            {
                if (primero[i] <= segundo[y])
                {
                    resultado.push_back(primero[i]);
                    i++;
                }
                else
                {
                    resultado.push_back(segundo[y]);
                    y++;
                }
            }
            else if(i >= primero.size())
            {
                resultado.push_back(segundo[y]);
                y++;
            }
            else if (y >= segundo.size())
            {
                resultado.push_back(primero[i]);
                i++;
            }

        }
    }
 
    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int N, M;
    cin >> N >> M;
    
    vector<int> primero, segundo;

    int aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        primero.push_back(aux);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> aux;
        segundo.push_back(aux);
    }

    vector<int> resultado;
    resultado = resolver(primero, segundo);    

    for (int i = 0; i < resultado.size(); i++)
        cout << resultado[i] << " ";
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