#include <iostream>
#include <map>
using namespace std;

//MARGARITA
//M 1 A 3 G 1 R 1 T 1 I 1

int main(int argc, char const *argv[])
{
    int numCasos;
    cin >> numCasos;

    while (numCasos > 0)
    {
        numCasos--;
        string palabra;
        std::map<char, int> letras;

        cin >> palabra;

        for (string::size_type i = 0; i < palabra.size(); ++i)
        {
            letras[palabra[i]]++;
        }
        int minimo = -1;
        char letrasMargarita[] = {'M', 'G', 'I', 'T'};

        int aux = letras['A'];
        minimo = aux / 3;

        aux = letras['R'];
        if (minimo > aux / 2)
        {
            minimo = aux / 2;
        }

        for (int i = 0; i < 4 && aux > 0; i++)
        {
            int aux = letras[letrasMargarita[i]];
            if (minimo == -1 || minimo > aux)
            {
                minimo = aux;
            }
        }
        cout << minimo << endl;
    }

    return 0;
}