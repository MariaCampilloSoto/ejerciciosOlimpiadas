#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int cases;
    cin >> cases;
    int caso = 1;
    while (cases > 0)
    {
        cases--;

        int numPlanets;
        cin >> numPlanets;

        list<int> planets;
        int numVotes = 0;
        int votesTotal = 0;

        for (int i = 0; i < numPlanets; i++)
        {
            cin >> numVotes;
            votesTotal += numVotes;
            planets.push_front(numVotes);
        }

        planets.sort();    //me ordena de menor a mayor
        planets.reverse(); //me la pone del reves

        int votosMin = (votesTotal / 2) + 1;
        int planetasQueNecesito = 0;
        int votosPlanetas = 0;

        list<int>::iterator it;
        for (it = planets.begin(); it != planets.end(); ++it)
        {
            planetasQueNecesito++;
            votosPlanetas += *it;

            if (votosPlanetas >= votosMin)
            {
                break;
            }
        }

        cout << "Case " << caso << ": " << planetasQueNecesito << " planets" << endl;
        caso++;
    }
}