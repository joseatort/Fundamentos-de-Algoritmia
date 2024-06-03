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
    S es el beneficio minimo esperado

    ESPECIFICACION FORMAL
    -------------- ------
    P = {0 <= N <= 10^8 ^ 0 <= S}
    fun Result max_profit_sequence(vector<int>& v, int S) dev {max_profit , start, end}
    Q = {maximo >= s ? maximo, i, j : "NO COMPENSA"}

    maximo_posible(v) = ( max i, j: 0 <= i < j <= N: suma_intervalos(v, i, j))
    suma_intervalos(v, i, j) = (suma = Sumatorio w: i <= w < j <= N : v[w])

    COSTE
    -----
    El coste del algoritmo será O(n) siendo n el numero de elementos del vector
*/

struct Result {
    int max_profit;
    int start;
    int end;
};

Result max_profit_sequence(vector<int>& v, int s) {
    int max_profit = 0;
    int current_profit = 0;

    int current_start = 0;
    int start = 0;
    int end = -1;

    for (int i = 0; i < v.size(); i++) {
        current_profit += v[i];

        if (current_profit < 0) {
            current_profit = 0;
            current_start = i + 1;
        }

        if (current_profit >= s && current_profit > max_profit) {
            start = current_start;
            max_profit = current_profit;
            end = i;
        }
    }


    return { max_profit, start, end };
}

int resuelveCaso() {
    int N, S;

    while (cin >> N >> S) {
        vector<int> numbers(N);
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }

        Result result = max_profit_sequence(numbers, S);
        if (result.max_profit == 0) {
            cout << "NO COMPENSA" << endl;
        }
        else {
            cout << result.max_profit << " " << result.start << " " << result.end << endl;
        }
    }

    return 0;
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