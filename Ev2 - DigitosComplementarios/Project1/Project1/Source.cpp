// Nombre del alumno Alvaro Velasco Garcia
//                   Jose Antonio Tortosa Aranda
// 
// Usuario del Juez F97
//                  F91


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema

/*
*   ACLARACION
*   ----------
*   N es igual al valor dado por entrada
* 
*   Funcion Complementario
*   ------- --------------
* 
*   Recursion del coste:                { c1            si N < 10   }
*                               T(N) =  {                           }   
*                                       { T(N/10) + c2  en otro caso}
* 
*   Coste:  Usando el Teorema de la Division, sabemos que a = 1, b = 10 y k = 0, por lo tanto aplicamos la siguiente formula
*  
*                                             si a < b^k  => O(N ^ k)
*                                             si a = b^k  => O(N^k * log N )
*                                             si a > b^k  => O(N^logb a)
*                                               
*                                             En nuestro caso, a = 1 y b^k = 1, por lo tanto, el coste asintotico del algoritmo
*                                             sera O(log N) ya que N^k = 1
* 
*   Aclaracion: Un ejemplo, dada la entrada 45637, haría lo siguiente
*
*               Mientras baja:  45637               Mientras sube:  5436 * 10 + (9 - 7) = 53462
*                               4563                                543 * 10 + (9 - 3) = 5436
*                               456                                 54 * 10 + (9 - 6) = 543
*                               45                                  5 * 10 + (9 - 5) = 54
*                               4                                   9 - 4 = 5
* 
* 
*   Funcion Complementario_Inverso
*   ------- ----------------------
*
*   Recursion del coste:                { c1            si N < 10   }
*                               T(N) =  {                           }
*                                       { T(N/10) + c2  en otro caso}
*
*   Coste:  Usando el Teorema de la Division, sabemos que a = 1, b = 10 y k = 0, por lo tanto aplicamos la siguiente formula
*
*                                             si a < b^k  => O(N ^ k)
*                                             si a = b^k  => O(N^k * log N )
*                                             si a > b^k  => O(N^logb a)
*
*                                             En nuestro caso, a = 1 y b^k = 1, por lo tanto, el coste asintotico del algoritmo
*                                             sera O(log N) ya que N^k = 1
* 
*   Aclaracion: Un ejemplo, dada la entrada 45637, haría lo siguiente
*               Usamos una entrada auxiliar, resultado que esta inicializada en 0
* 
*               Mientras baja:  resultado = resultado * 10 + (9 - 7)                Mientras sube: resultado = 26345
*                               resultado = resultado * 10 + (9 - 3)                               resultado = 26345                                    
*                               resultado = resultado * 10 + (9 - 6)                               resultado = 26345                                     
*                               resultado = resultado * 10 + (9 - 5)                               resultado = 26345                                    
*                               resultado = resultado * 10 + (9 - 4)                               resultado = 26345                                    
*               
*               Resultado una vez que termina de subir es el valor que devolvemos
*/

int complementario(int N)
{
    if (N < 10)
        return 9 - N;
    else
    {
        int anterior = complementario(N / 10);

        anterior *= 10;

        anterior += 9 - (N % 10);
        return anterior;
    }
}

int complementario_inverso(int N, int resultado)
{
    if (N < 10)
    {
        resultado *= 10;
        resultado += 9 - (N % 10);
        return resultado;
    }
    else
    {
        resultado *= 10;
        resultado += 9 - (N % 10);
        
        return complementario_inverso(N / 10, resultado);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;

    cout << complementario(N) << " ";
    cout << complementario_inverso(N, 0) << "\n";   
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