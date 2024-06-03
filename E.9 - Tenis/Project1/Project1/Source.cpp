// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct datos
{
    int partidosjugados;
    int ronda;
    bool jugador;
};

datos resolver(int ini, int fin, const vector<bool>& v, int R)
{
    if (ini == fin)
    {
        if (v[ini])
            return { 0 , 0, true };
        else
            return { 0 , 0, false };
    }
    else
    {
        int m = (ini + fin) / 2;
        datos izq = resolver(ini, m, v, R);
        datos der = resolver(m + 1, fin, v, R);

        int partidos_jugados = izq.partidosjugados + der.partidosjugados;

        if (izq.ronda < R)
        {
            if (!izq.jugador && !der.jugador)
                return { partidos_jugados, izq.ronda + 1, false };
            else if (!izq.jugador || !der.jugador)
                return { partidos_jugados, izq.ronda + 1, true };
            else
                return { partidos_jugados + 1, izq.ronda + 1, true };
        }
        else 
            return { partidos_jugados, izq.ronda, true };

        


    }


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, R;
    cin >> N >> R;
    if (!std::cin)
        return false;

    vector<bool> v(N);
    string aux;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        if (aux == "NP")
            v[i] = false;
        else
            v[i] = true;

    }


    cout << resolver(0, N - 1, v, R).partidosjugados << "\n";
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