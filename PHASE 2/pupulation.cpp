#include "Stronghold.h"
Population::Population()
{
    total = 100;
    peasants = 60;
    merchants = 25;
    nobles = 15;
    happiness = 70.0;
    foodStock = 300.0;
}
void Population::simulate()
{
    cout << "\n--- Simulating Population Changes ---\n";

    int foodConsumptionPerPerson = 2;
    int requiredFood = total * foodConsumptionPerPerson;

    cout << "Total population: " << total << endl;
    cout << "Food required: " << requiredFood << endl;
    cout << "Food available: " << foodStock << endl;

    if (foodStock >= requiredFood)
    {
        cout << "Everyone is well-fed. Population is growing.\n";
        foodStock -= requiredFood;
        total += 10;
        happiness += 5;
    }
    else
    {
        int shortage = requiredFood - foodStock;
        cout << "Food shortage of " << shortage << " units! People are starving.\n";
        int deaths = shortage / foodConsumptionPerPerson;
        total -= deaths;
        happiness -= 10;
        foodStock = 0;
    }
    if (happiness > 100)
        happiness = 100;
    if (happiness < 0)
        happiness = 0;
    if (total < 0)
        total = 0;
    peasants = total * 0.6;
    merchants = total * 0.25;
    nobles = total * 0.15;
    if (happiness < 30)
    {
        cout << "Revolt risk! Citizens are angry.\n";
        int revoltLoss = rand() % 10;
        total -= revoltLoss;
        cout << revoltLoss << " people lost in revolt.\n";
    }
}
void Population:: showStats() const
{
    cout << "\n====== Population Stats ======\n";
    cout << "Total Population: " << total << endl;
    cout << " Peasants: " << peasants << endl;
    cout << " Merchants: " << merchants << endl;
    cout << " Nobles: " << nobles << endl;
    cout << " Happiness: " << happiness << "%\n";
}
void Population::saveToFile() const
{
    ofstream out("population.txt");
    if (!out)
    {
        cerr << "Error: Unable to save population data.\n";
        return;
    }
    out << total << endl;
    out << peasants << endl;
    out << merchants << endl;
    out << nobles << endl;
    out << happiness << endl;
    out.close();
    cout << "Population data saved successfully.\n";
}
void Population::loadFromFile()
{
    ifstream in("population.txt");
    if (!in)
    {
        cerr << "Error: Unable to load population data.\n";
        return;
    }

    in >> total >> peasants >> merchants >> nobles >> happiness;
    in.close();
    cout << "Population data loaded successfully.\n";
}
int Population::getTotal() const
{
    return total;
}
void Population::decrease(int amount)
{
    total -= amount;
    if (total < 0)
    {
        total = 0;
    }
    peasants = total * 0.6;
    merchants = total * 0.25;
    nobles = total * 0.15;
}
