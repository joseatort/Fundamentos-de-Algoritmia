// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema

/*
int resolver(const vector<int> &v, int ini, int fin) 
{

    if (ini == fin) {
        return 1;
    }
    else
    {
        int M = (ini + fin) / 2;

        int izquierda = resolver(v, ini, M);
        int derecha = resolver(v, M + 1, fin);

        //Inicializamos longitud al minimo
        int longitud = 1;

        //Comprobamos si existe un tramo de al menos 2 iguales desde el medio
        if (v[M] == v[M + 1]) {
            int longitudMitad = 1;
            int j = M;

            //Comprobamos tam de mitad izquierda contando medio
            while (j >= ini && v[j] == v[M]) {
                j--;
                longitudMitad++;
            }

            //Comprobamos tam de mitad derecha si contar el medio
            int k = M + 1;
            while (k < fin && v[k] == v[k + 1]) {
                k++;
                longitudMitad++;
            }

            //Comprobamos si existe maximo
            longitud = max(longitud, longitudMitad);
        }

        //Devuelve la maxima longitud encontrada entre la que hemos calculado y la que ya teniamos
        return max(longitud, max(izquierda, derecha));
    }
    
}*/

typedef struct
{
    int mayor;
    int izquierdo;
    int derecho;
}sol;

sol resolver(const vector<int>& v, int ini, int fin)
{
    if (ini == fin) 
        return { 1, 1, 1 };
    else
    {
        int M = (ini + fin) / 2;

        sol iz = resolver(v, ini, M);
        sol dr= resolver(v, M + 1, fin);

        sol total;
        total.mayor = max(iz.mayor, dr.mayor);
        total.izquierdo = iz.izquierdo;
        total.derecho = dr.derecho;

        if (v[M] != v[M + 1])
            return total;
        else
        {
            int central = iz.derecho + dr.izquierdo;
            
            total.mayor = max(central, total.mayor);
            if (v[ini] == v[M])
                total.izquierdo += dr.izquierdo;
            
            if (v[M + 1] == v[fin])
                total.derecho += iz.derecho;

            return total;
        }
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
    
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    cout << resolver(v, 0, N - 1).mayor << "\n";
    
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
