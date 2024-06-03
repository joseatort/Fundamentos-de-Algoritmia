// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int, int> resolver(int ini, int fin, const vector<int> & v) 
{
    if (ini == fin)
        return { v[ini], 1 };
    else if (ini > fin)
        return { -1, 0 };
    else
    {
        int m = (ini + fin) / 2;
        pair<int,int> izq = resolver(ini, m, v);
        pair<int, int> der = resolver(m + 1, fin, v);


        if (izq.first == der.first)
            return { izq.first, izq.second + der.second };
        else
        {
            int contador1 = 0;
            for (int i = m + 1; i <= fin && izq.first != -1; i++)
                if (v[i] == izq.first)
                    contador1++;

            int contador2 = 0;
            for (int i = ini; i < m + 1 && der.first != -1; i++)
                if (v[i] == der.first)
                    contador2++;

            if (izq.second + contador1 > der.second + contador2)
                return { izq.first, izq.second + contador1 };
            else if (izq.second + contador1 < izq.second + contador2)
                return { der.first, der.second + contador2 };
            else
                return { -1, 0 };
        }

        
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    vector <int> v;
    int aux;
    do
    {
        cin >> aux;
        if (aux != 0)
            v.push_back(aux);
        
    } while (aux != 0);

    pair<int, int> sol = resolver(0, v.size() - 1, v);

    if (sol.first != -1 && sol.second > v.size() / 2)
        cout << sol.first;
    else
        cout << "NO";

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