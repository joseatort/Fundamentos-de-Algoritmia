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
    N es el numero de elementos del vector
    A es el año en el que comienza el intervalo
    B es el año en el que termina el intervalo
        
    ESPECIFICACION FORMAL
    -------------- ------
    P = {1700 <= A < B <= 10^5 ^ v.size() B - A ^ ParaTodo i: 0 <= i < N: -2^31 +1 <= v[i] <= 2^31 -1 }
    vector <int> resolver(const vector<int> &v, int A, int B) dev s
    Q = {ParaTodo i: 0 <= i < v.size(): (esRecord(v,i) <=> estáEn(a + 1, s) ) ^ ordenado(s)}

    esRecord(vector <int> v, int i) <=> i > 0 ^ ParaTodo n: 0 <= n < i: v[n] < v[i]
    estáEn(int x, vector <int> v) <=> Existe i: 0 <= i < v.size(): v[i] == x 
    ordenado(vector <int> v) <=> ParaTodo i: 0 <= i < v.size() - 1: v[i] < v[i + 1]

    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/

// función que resuelve el problema
vector <int> resolver(const vector<int> &anos, int AnoInicial) 
{
    
    vector <int> resultado;
    int anomax = anos[0];


    for (int i = 1; i < anos.size(); i++)
    {
        if (anos[i] > anomax)
        {
            anomax = anos[i];
            resultado.push_back(AnoInicial + i);
        }
    }


    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int AnoInicial, AnoFinal;
    cin >> AnoInicial >> AnoFinal;

    int N = AnoFinal - AnoInicial;
    vector<int> anos, resultado;

    int aux;
    for (int i = 0; i <= N; i++)
    {
        cin >> aux;
        anos.push_back(aux);
    }
       
    resultado = resolver(anos, AnoInicial);

    for (int y = 0; y < resultado.size(); y++)
        cout << resultado[y] << " ";

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