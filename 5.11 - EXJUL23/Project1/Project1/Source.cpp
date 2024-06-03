// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

typedef struct
{
    vector<int> heroes;
    int nivel;
    float ataque;
    int N_heroes;
}Cristal;

bool es_completable(int cristales_actuales, int min_cristales, int k, int H)
{
    return cristales_actuales < min_cristales && k < H - 1;
}

bool es_final(float ataquetotal, int PV, int k, int H)
{
    return ataquetotal >= PV && k == H - 1;
}

bool es_valido(int i, const vector<Cristal>& cristales, int M)
{
    if (cristales[i].N_heroes > 4 || cristales[i].nivel > M)
        return false;

    bool iguales = true;
    int contador = 0;
    for (int j = 0; j < cristales[i].N_heroes - 1 && iguales; j++)
        if (cristales[i].heroes[j] == cristales[i].heroes[cristales[i].N_heroes - 1])
        {
            contador++;
            if(contador == 2)
                return false;
        }
            

    return true;
}

// función que resuelve el problema
void VueltaAtras(int H, int C, int M, int PV, const vector<int> &clase, const vector<int> &nivel,
                 const vector<int> &pataque, int &min_cristales, int cristales_actuales, float ataque_total, vector<Cristal> &cristales, 
                 int k, vector<int> &sol)
{            

    //Usamos cristales ya existentes
    for (int i = 0; i < cristales_actuales; i++)
    {
        sol[k] = i;
        
        //Deshacemos ataque_total
        float porcentaje1 = 0 , porcentaje2 = 0;
        if (cristales[i].N_heroes > 0)
        {
            porcentaje2 = 25 * cristales[i].N_heroes;
            porcentaje2 /= 100;
            ataque_total -= cristales[i].ataque + cristales[i].ataque * porcentaje2;
        }

        cristales[i].heroes[cristales[i].N_heroes] = clase[k];
        cristales[i].N_heroes++;
        cristales[i].ataque += pataque[k];
        cristales[i].nivel += nivel[k];

        //Rehacemos la suma
        porcentaje1 = 25 * cristales[i].N_heroes;
        porcentaje1 /= 100;
        ataque_total += cristales[i].ataque + cristales[i].ataque * porcentaje1;

        if (es_valido(i, cristales, M))
        {
            if (es_final(ataque_total, PV, k, H))
                min_cristales = min(min_cristales, cristales_actuales);
            else if (es_completable(cristales_actuales, min_cristales, k, H))
                VueltaAtras(H, C, M, PV, clase, nivel, pataque, min_cristales, cristales_actuales, ataque_total, cristales, k + 1, sol);

        }
        //Es orientativo para ver lo que esta pasando, no tiene ninguna funcion
        sol[k] = -1;

        ataque_total -= cristales[i].ataque + cristales[i].ataque * porcentaje1;

        cristales[i].nivel -= nivel[k];
        cristales[i].ataque -= pataque[k];
        cristales[i].N_heroes--;
        cristales[i].heroes[cristales[i].N_heroes] = -1;
        
        if (cristales[i].N_heroes > 0)
            ataque_total += cristales[i].ataque + cristales[i].ataque * porcentaje2;
    }
    

    //Añadimos un cristal
    if (cristales_actuales < C && k < H)
    {
        cristales_actuales++;
        int i = cristales_actuales - 1;
        sol[k] = i;

        //Deshacemos ataque_total
        float porcentaje1 = 0, porcentaje2 = 0;
        if (cristales[i].N_heroes > 0)
        {
            porcentaje2 = 25 * cristales[i].N_heroes;
            porcentaje2 /= 100;
            ataque_total -= cristales[i].ataque + cristales[i].ataque * porcentaje2;
        }

        cristales[i].heroes[cristales[i].N_heroes] = clase[k];
        cristales[i].N_heroes++;
        cristales[i].ataque += pataque[k];
        cristales[i].nivel += nivel[k];

        //Rehacemos la suma
        porcentaje1 = 25 * cristales[i].N_heroes;
        porcentaje1 /= 100;
        ataque_total += cristales[i].ataque + cristales[i].ataque * porcentaje1;

        if (es_final(ataque_total, PV, k, H))
            min_cristales = min(min_cristales, cristales_actuales);
        else if (es_completable(cristales_actuales, min_cristales, k, H))
            VueltaAtras(H, C, M, PV, clase, nivel, pataque, min_cristales, cristales_actuales, ataque_total, cristales, k + 1, sol);

        sol[k] = -1;

        ataque_total -= cristales[i].ataque + cristales[i].ataque * porcentaje1;

        cristales[i].nivel -= nivel[k];
        cristales[i].ataque -= pataque[k];
        cristales[i].N_heroes--;
        cristales[i].heroes[cristales[i].N_heroes] = -1;

        if (cristales[i].N_heroes > 0)
            ataque_total += cristales[i].ataque + cristales[i].ataque * porcentaje2;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int H, C, M, PV;
    cin >> H >> C >> M >> PV;

    vector<int> clase(H);
    for (int i = 0; i < H; i++)
        cin >> clase[i];

    vector<int> nivel(H);
    for (int i = 0; i < H; i++)
        cin >> nivel[i];

    vector<int> pataque(H);
    for (int i = 0; i < H; i++)
        cin >> pataque[i];
    
    vector<int> sol(H, -1);
    int min_cristales = numeric_limits<int>::max();

    vector<Cristal> cristales(C, { vector<int> (4, -1), 0, 0, 0});

    VueltaAtras(H, C, M, PV, clase, nivel, pataque, min_cristales, 0, 0, cristales, 0, sol);

    if (min_cristales == numeric_limits<int>::max() && PV != 0)
        cout << "DERROTA";
    else if (PV == 0)
        cout << 0;
    else
        cout << min_cristales;

    cout << "\n";
    // escribir sol
 
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