#include "Stronghold.h"
Economy::Economy() {
    treasury = 1000;
    taxRate = 5;        
    inflation = 100;     
}
void Economy::taxPopulation(const Population& pop) {
    cout << "\n--- Tax Collection ---\n";

    int populationSize = pop.getTotal();
    int baseCollection = (populationSize * taxRate) / 100;
    int adjustedCollection = (baseCollection * inflation) / 100;
    treasury += adjustedCollection;
    cout << "Taxed " << populationSize << " people at " << taxRate << "% rate.\n";
    cout << "Collected: " << adjustedCollection << " gold\n";
    cout << "New Treasury: " << treasury << " gold\n";
    inflation += 5;
    if (inflation > 200) inflation = 200; 
}
void Economy::spend(int amount) {
    cout << "\n--- Spending Gold ---\n";

    if (amount <= 0) {
        cout << "Invalid amount. Must be greater than 0.\n";
        return;
    }

    if (amount > treasury) {
        cout << "Insufficient treasury. Available: " << treasury << " gold.\n";
        return;
    }

    treasury -= amount;
    cout << "Spent: " << amount << " gold. Remaining Treasury: " << treasury << " gold\n";
}
void Economy::showStats() const {
    cout << "\n====== Economy Stats ======\n";
    cout << "Treasury: " << treasury << " gold\n";
    cout << "Tax Rate: " << taxRate << "%\n";
    cout << "Inflation: " << inflation << " (x" << inflation / 100.0 << ")\n";
}
void Economy::saveToFile() const {
    ofstream out("economy.txt");
    if (!out) {
        cout << "Error: Unable to open file for saving economy.\n";
        return;
    }

    out << treasury << endl;
    out << taxRate << endl;
    out << inflation << endl;
    out.close();

    cout << "Economy saved to file.\n";
}
void Economy::loadFromFile() {
    ifstream in("economy.txt");
    if (!in) {
        cout << "Error: Unable to open file for loading economy.\n";
        return;
    }
    in >> treasury >> taxRate >> inflation;
    in.close();
    cout << "Economy loaded from file.\n";
}
int Economy::getTreasury() const {
    return treasury;
}
void Economy::receiveLoan(int amount) {
    treasury += amount;
}

