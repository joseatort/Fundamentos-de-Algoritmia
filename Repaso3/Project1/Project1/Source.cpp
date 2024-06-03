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
*   C es el numero de columnas de la matriz dada
*   F es el numero de filas de la matriz dada
* 
*   F. RECURSIVA
*   ------------
*          {c0           si N == 1      }
*   T(N) = {                            }
*          {2T(N/2) + c1 en otro caso   }
* 
*   COSTE
*   -----
*   
* 
* 
* 
*/


using matriz = vector<vector<int>>;
// función que resuelve el problema
pair<int, bool> resolver(int ini, int fin, const vector<int> & v) 
{
    if (ini == fin)
        return {v[ini], true};
    else
    {
        int M = (ini + fin) / 2;

        pair<int, bool> iz = resolver(ini, M, v);
        pair<int, bool> der = resolver(M + 1, fin, v);

        if (iz.second && der.second)
        {
            if (iz.first <= der.first)
                return { iz.first + der.first, true };
            else
                return { 0,false };
        }
        else
        {
            return { 0, false };
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int F, C;
    cin >> F >> C;
    if (! std::cin)
        return false;
    
    matriz degradado(F, vector<int>(C));
    for (int i = 0; i < F; i++)
        for (int j = 0; j < C; j++)
            cin >> degradado[i][j];

    bool okey = true;
    for (int i = 0;( i < F && okey); i++)
        okey = resolver(0, C - 1, degradado[i]).second;
    
    if (okey)
        cout << "SI";
    else
        cout << "NO";
    cout << "\n";
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