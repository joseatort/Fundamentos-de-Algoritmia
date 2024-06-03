/*
 * Plantilla para la práctica 4
 * Escribid vuestro nombre y usuarios:
 *   - Alvaro Velasco Garcia F97
 *   - Jose Antonio Tortosa Aranda F91
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/* Para los colores usamos 3 valores enteros:
 *    0 -> azul
 *    1 -> rojo
 *    2 -> verde
 * Esta función devuelve un string según el valor del entero
 */
string color(const int i){
    switch(i){
        case 0:
            return "azul";
        case 1:
            return "rojo";
        case 2:
            return "verde";
    }
}

/*
*   ESPACIO DE SOLUCIONES
*   ------- -- ----------
 *  El espacio de soluciones es de O(3^H), siendo H la altura de la torre, el 3 corresponde a los
 *  tres colores que tenemos, azul, rojo y verde.
 * 
 *  MARCADORES
 *  ----------
 *  Colores = corresponde a un vector de enteros en el que guardamos el numero de piezas que usamos 
 *            de cada color ( 0 ==> azul, 1 ==> rojo,  2 ==> verde)
 * 
 *  sol = corresponde a un vector de enteros en el que guardamos el color de las piezas colocada
 *        por cada altura
 * 
 *  hay_solucion = booleano declarado inicialmente a False y que cambia a True una vez que se 
 *                 encuentre la primera solucion
 * 
 *  EXPLICACION
 *  -----------
 *  Asignamos una pieza a cada altura de la torre, por lo que cada nodo del arbol tiene 3 hijos
 *  correspondientes a los 3 posibles colores que se pueden llegar a tomar.
 * 
 *  De este modo, vamos recorriendo en profundidad el espacio de soluciones, descartando las que 
 *  no cumplan las restricciones dadas mediante la funcion es_valida(), una vez que este llega a 
 *  la altura del arbol == H - 1, siendo H la altura de la torre, llamamos a imprimir_solucion()
 *  la cual escribe por pantalla la solucion actual y convertirmos hay_solucion a True, en caso de 
 *  que acabe la ejecucion y este tenga valor False, escribiriamos por pantalla "SIN SOLUCION"
 * 
 */

bool es_valida(const int A, const int R, const int V, const vector<int> &Colores, const int i, const int k, const int H, const vector<int> &sol)
{
    if ((Colores[i] > A && i == 0) || (Colores[i] > R && i == 1) || (Colores[i] > V && i == 2))
        return false;
    else if (sol[0] != 1)
        return false;
    else if (k > 1 && (sol[k - 1] == sol[k] && sol[k] == 2))
        return false;
    else if (Colores[2] > Colores[0])
        return false;
    else if (k == H - 1 && Colores[1] <= Colores[0] + Colores[2])
        return false;
    else
        return true;
}

bool es_final(const int k, const int H)
{
    return k == H - 1;
}

bool es_completable()
{
    //Funcion de poda aqui
    return true;
}

void imprimir_solucion(const vector<int>& sol)
{
    for (int i = 0; i < sol.size(); i++)
        cout << color(sol[i]) << " ";

    cout << "\n";
}

void VueltaAtras(const int H, const int A, const int R, const int V, vector<int> &Colores, const int k, vector<int> &sol,
                bool & hay_solucion)
{

    for (int i = 0; i < 3; i++)
    {
        sol[k] = i;
        Colores[i]++;

        if (es_valida(A, R, V, Colores, i, k, H, sol))
        {

            if (es_final(k, H))
            {
                hay_solucion = true;
                imprimir_solucion(sol);
            }  
            else if (es_completable())
                VueltaAtras(H, A, R, V, Colores, k + 1, sol, hay_solucion);

        }

        Colores[i]--;
        sol[k] = -1;
    }
}



bool resuelveCaso() {
    int H, A, R, V; //Altura, Azul, Rojo y Verde
    cin >> H >> A >> R >> V;
    if (H == 0 && A == 0 && R == 0 && V == 0)
        return false;

    //Crea los datos para la solución, marcadores, etc
    vector<int> Colores(3, 0);
    vector<int> sol(H, -1);
    //Llama a la función vuelta atrás
    bool hay_solucion = false;
    VueltaAtras(H, A, R, V, Colores, 0, sol, hay_solucion);

    //Escribe el resultado: 
   
    if (!hay_solucion)
        cout << "SIN SOLUCION\n";

    cout << "\n";
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