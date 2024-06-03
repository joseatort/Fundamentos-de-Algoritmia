    // Nombre del alumno .....
    // Usuario del Juez ......


    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <vector>

    using namespace std;

    typedef struct
    {
        bool extrano;
        int sum_pares;
        int sum_impares;
        int prod_pares;
        int prod_impares;
    }Datos;

    Datos resolver(int ini, int fin, const vector<int>& v)
    {
        if(ini > fin)
            return{ true, 0, 0, 0, 0 };
        else if (ini == fin)
        {
            if (v[ini] % 2 == 0)
                return{ true, v[ini], 0, v[ini], 1 };
            else
                return{ true, 0, v[ini], 1, v[ini] };
        }    
        else
        {
            int M = (ini + fin) / 2;
            Datos iz = resolver(ini, M, v);
            Datos der = resolver(M + 1, fin, v);


            if ((iz.sum_pares + iz.prod_impares <= der.prod_pares + der.sum_impares) && (iz.extrano || der.extrano))
            {

                return { true, iz.sum_pares + der.sum_pares, iz.sum_impares + der.sum_impares,
                        iz.prod_pares* der.prod_pares, iz.prod_impares* der.prod_impares };

            }
            else
                return { false, iz.sum_pares + der.sum_pares, iz.sum_impares + der.sum_impares,
                        iz.prod_pares* der.prod_pares, iz.prod_impares* der.prod_impares };

        }
     
    }

    // Resuelve un caso de prueba, leyendo de la entrada la
    // configuración, y escribiendo la respuesta
    void resuelveCaso() {
        // leer los datos de la entrada
        int N;
        cin >> N;

        vector<int> v(N);

        for (int i = 0; i < N; i++)
            cin >> v[i];
    
        cout << (resolver(0, N - 1, v).extrano ? "SI" : "NO") << "\n";
    
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