#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Ncasos
// P C
// prod...
// consumi

// ordenar por key de mayor a menor
bool comparatorMayorMenor(int x, int y)
{
    return x > y;
}

// ordenar por key de menor a mayor
bool comparatorMenorMayor(int x, int y)
{
    return x < y;
}

long int getCabreados(long int valor, vector<long int> consumidores, vector<long int> productores)
{
    long int cabreados = 0;

    for (auto &consumidor : consumidores)
    {
        //cout << "Valor del consumidor: " << consumidor << " Valor: " << valor << endl;
        if (consumidor < valor)
        {
            //  cout << "incremento el numero de cabreados" << endl;
            cabreados++;
        }
    }

    for (auto &productor : productores)
    {
        //cout << "Valor del productor: " << productor << " Valor: " << valor << endl;
        if (productor > valor)
        {
            //  cout << "incremento el numero de cabreados" << endl;
            cabreados++;
        }
    }

    return cabreados;
}

int main(int argc, char const *argv[])
{
    int numCasos;
    cin >> numCasos;

    while (numCasos > 0)
    {
        numCasos--;
        long int productores, consumidores;

        cin >> productores >> consumidores;

        vector<long int> precionsProductores;
        vector<long int> precionsConsuidores;

        //Leer productores
        for (long int i = 0; i < productores; i++)
        {
            int aux;
            cin >> aux;
            precionsProductores.push_back(aux);
        }

        sort(precionsProductores.begin(), precionsProductores.end(), comparatorMenorMayor);

        //Leer consumidores
        for (long int i = 0; i < consumidores; i++)
        {
            long aux;
            cin >> aux;
            precionsConsuidores.push_back(aux);
        }

        sort(precionsConsuidores.begin(), precionsConsuidores.end(), comparatorMenorMayor);

        long int precioActual = 0;
        long int cabreoSolucion;

        if (productores == 0 || consumidores == 0)
        {
            cabreoSolucion = 0;
            precioActual = 0;
        }
       /*  else if (consumidores == 0)
        {
            cabreoSolucion = productores;
            precioActual = 0;
        } */
        else
        {
            cabreoSolucion = consumidores + productores;
            //Primera evaluacion
            for (long int precioAevaluar : precionsProductores)
            {
                long int nCabreos = getCabreados(precioAevaluar, precionsConsuidores, precionsProductores);

                if (nCabreos < cabreoSolucion)
                {
                    precioActual = precioAevaluar;
                    cabreoSolucion = nCabreos;
                }
            }
            //Segunda evaluacion
            for (long int precioAevaluar : precionsConsuidores)
            {
                long int nCabreos = getCabreados(precioAevaluar, precionsConsuidores, precionsProductores);

                if (nCabreos < cabreoSolucion)
                {
                    precioActual = precioAevaluar;
                    cabreoSolucion = nCabreos;
                }
            }
        }

        //cout << " " << endl;
        cout << precioActual << " " << cabreoSolucion << endl;
    }

    return 0;
}