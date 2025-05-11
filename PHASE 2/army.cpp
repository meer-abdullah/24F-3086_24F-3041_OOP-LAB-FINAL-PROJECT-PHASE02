#include "Stronghold.h"
Army::Army() {
    soldiers = 20;
    morale = 70;       
    foodSupply = 100; 
}
void Army::recruitAndTrain(Population& pop) {
    cout << "\n--- Army Recruitment & Training ---\n";
    int recruitCount;
    cout << "Enter number of soldiers to recruit: ";
    cin >> recruitCount;
    if (recruitCount <= 0 || recruitCount > pop.getTotal()) {
        cout << "Invalid number of recruits. Aborting...\n";
        return;
    }
    int foodRequired = recruitCount * 2;
    if (foodSupply < foodRequired) {
        cout << "Not enough food to train " << recruitCount << " soldiers!\n";
        morale -= 10;
        return;
    }
    pop.decrease(recruitCount);
    soldiers += recruitCount;
    foodSupply -= foodRequired;
    morale += 5;
    if (morale > 100) morale = 100;
    if (morale < 0) morale = 0;
    cout << recruitCount << " soldiers recruited and trained.\n";
    cout << "Food used: " << foodRequired << "\n";
    cout << "Current morale: " << morale << "%\n";
}
void Army::showStats() const {
    cout << "\n====== Army Stats ======\n";
    cout << "Total Soldiers: " << soldiers << endl;
    cout << "Morale: " << morale << "%\n";
    cout << "Food Supply: " << foodSupply << " units\n";
}
void Army::saveToFile() const {
    ofstream out("army.txt");
    if (!out) {
        cerr << "Error: Could not save army data.\n";
        return;
    }
    out << soldiers << endl;
    out << morale << endl;
    out << foodSupply << endl;
    out.close();
    cout << "Army data saved successfully.\n";
}
void Army::loadFromFile() {
    ifstream in("army.txt");
    if (!in) {
        cerr << "Error: Could not load army data.\n";
        return;
    }
    in >> soldiers >> morale >> foodSupply;
    in.close();
    cout << "Army data loaded successfully.\n";
}
void Army::lowerMorale(int amount) {
    morale -= amount;
    if (morale < 0) morale = 0;
}
