/*
 * Plantilla para la Práctica 3
 * Escribid vuestro nombre y usuarios:
 *   - Alvaro Velasco Garcia F97
 *   - Jose Antonio Tortosa Aranda F91
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using matriz = vector<vector<int>>;

/*
 * ESCRIBE LA FUNCIÓN DIVIDE Y VENCERÁS.
 * LA RECURSIÓN DEL COSTE
 * EL COSTE QUE OBTENGAS
 */

/*
* 
*   EXPLICACION
*   -----------
*   Un ejemplo grafico de como hemos planteado la recursion sería el siguiente:
*
*       Entrada de ejemplo: 1 3 2 6
*       
*       Vamos dividiendo en mitades     1 3   |   2 6
*       hasta llegar a elementos       1 | 3  |  2 | 6
*       individuales
* 
*       Una vez alcanzados,           1 < 3 = true      |   2 < 6 = true
*       comparamos con su             return 1 + 3      |   return 2 + 6
*       correspondiente mitad
* 
*       Continuamos ascendiendo,      4 < 8 = true
*       mientras el booleano          return 4 + 8
*       sea igual a true
* 
*       Por lo tanto, nuestra salida
*       seria SI
* 
*       (Si en cualquiera de los casos la comparacion hubiese sido false, la recursion 
*       dejaria de seguir comparando y la salida seria NO)
* 
*   FUNCION DE RECURRENCIA
*   ------- -- -----------
*         { c0              si N = 1 }
*   T(N) ={                          }
*         { 2T(N/2) + c1    si N > 1 }
* 
*   Siendo N el numero de elementos visibles del vector, cada vector corresponde a una fila 
*   de la matriz dada
* 
*   COSTE DE LA FUNCION RECURSIVA
*   ----- -- -- ------- ---------
*   Aplicando el teorema de la division, en la que a partir de a, b y k podemos deducir el coste
*   del algoritmo recursivo:
* 
*           Si a < b^k => O(N^k)
*           Si a = b^k => O((N^k)*log N)
*           Si a > b^k => O(N^(logb a))
* 
*   En nuestro caso, a = 2, b = 2 y k = 0, por lo tanto, usamos Si a > b^k => O(N^(logb a)),
*   donde (log2 2) = 1, y el coste se nos queda en O(N).
* 
*   Por lo tanto el coste del algoritmo recursivo sera de O(N), siendo N el numero de columnas de 
*   la matriz dada.
* 
*   COSTE TOTAL
*   ----- -----
*   El coste total del algoritmo en el peor caso es O(F * N), siendo F el numero de filas y N el 
*   numero de columnas, dado que en la funcion comprueba_matriz, por cada iteracion del bucle, 
*   correspondiente a cada fila de la matriz, hace una llamada a la funcion recursiva que tiene 
*   coste O(N), como hemos dicho anteriormente.
*   
*/

pair<int, bool> degradado(const vector<int>& v, const int ini, const int fin)
{
    if (ini == fin)
        return { v[ini], true };
    else
    {
        int M = (ini + fin) / 2;

        pair<int, bool> izq = degradado(v, ini, M);
        pair<int, bool> der = degradado(v, M + 1, fin);

        if (izq.second && der.second)
        {
            if (izq.first < der.first)
                return { izq.first + der.first, true };
        }
        
        return { 0 , false };
    }
}

/*
 * Función iterativa que llama a una función recursiva que comprueba si la fila es un degradado.
 * ¡¡¡COMPLETALA!!
 */
bool comprueba_matriz(const matriz& v, const int N, const int M){
    bool lo_es = true;
    int i = 0;
    while (lo_es && i < N) {
        //LLama a la función recursiva y actualiza las variables
        lo_es = degradado(v[i], 0, M - 1).second;
        i++;
    }

    return lo_es;
}

//--- NO MODIFIQUES NADA AQUÍ -----//
//------------------------------------------------------
bool resuelveCaso() {

    //Lectura de datos
    int N,M; //filas y columnas
    cin >> N >> M;
    if (!cin)
        return false;

    matriz imagen;
    for (int i = 0; i < N; i++) {
        vector<int> fila(M); //para leer la fila
        for (int j = 0; j < M; j++)
            cin >> fila[j];
        imagen.push_back(fila);
    }

    //En imagen hay N filas y cada una de ellas es un vector de tamaño M

    bool sol = comprueba_matriz(imagen, N, M);

    if(sol)
        cout << "SI\n";
    else
        cout <<"NO\n";

    return true;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}