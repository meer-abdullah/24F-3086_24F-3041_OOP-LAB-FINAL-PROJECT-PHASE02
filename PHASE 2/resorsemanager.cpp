#include "Stronghold.h"
ResourceManager::ResourceManager() {
    food = 500;
    wood = 300;
    stone = 200;
    iron = 100;
}
void ResourceManager::manage() {
    cout << "\n--- Resource Management ---\n";
    cout << "Choose operation:\n";
    cout << "1. Gather Resources\n";
    cout << "2. Consume Resources\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        gatherResources();
    }
    else if (choice == 2) {
        consumeResources();
    }
    else {
        cout << "Invalid option.\n";
    }
}
void ResourceManager::gatherResources() {
    int f, w, s, i;
    cout << "\nEnter amount of each resource to gather:\n";
    cout << "Food: "; cin >> f;
    cout << "Wood: "; cin >> w;
    cout << "Stone: "; cin >> s;
    cout << "Iron: "; cin >> i;
    if (f < 0 || w < 0 || s < 0 || i < 0) {
        cout << "Invalid input. Cannot gather negative resources.\n";
        return;
    }
    food += f;
    wood += w;
    stone += s;
    iron += i;
    cout << "Resources gathered successfully.\n";
}
void ResourceManager::consumeResources() {
    int f, w, s, i;
    cout << "\nEnter amount of each resource to consume:\n";
    cout << "Food: "; cin >> f;
    cout << "Wood: "; cin >> w;
    cout << "Stone: "; cin >> s;
    cout << "Iron: "; cin >> i;
    if (f < 0 || w < 0 || s < 0 || i < 0) {
        cout << "Invalid input. Cannot consume negative resources.\n";
        return;
    }
    if (food < f || wood < w || stone < s || iron < i) {
        cout << "Insufficient resources. Consumption failed.\n";
        return;
    }
    food -= f;
    wood -= w;
    stone -= s;
    iron -= i;
    cout << "Resources consumed successfully.\n";
}
void ResourceManager::showStats() const {
    cout << "\n====== Resource Stock ======\n";
    cout << "Food: " << food << "\n";
    cout << "Wood: " << wood << "\n";
    cout << "Stone: " << stone << "\n";
    cout << "Iron: " << iron << "\n";
}
void ResourceManager::saveToFile() const {
    ofstream out("resources.txt");
    if (!out) {
        cout << "Error: Could not save resources.\n";
        return;
    }
    out << food << endl;
    out << wood << endl;
    out << stone << endl;
    out << iron << endl;
    out.close();
    cout << "Resources saved to file.\n";
}
void ResourceManager::loadFromFile() {
    ifstream in("resources.txt");
    if (!in) {
        cout << "Error: Could not load resources.\n";
        return;
    }
    in >> food >> wood >> stone >> iron;
    in.close();
    cout << "Resources loaded from file.\n";
}
void ResourceManager::consumeFixed(string resourceType, int amount) {
    if (resourceType == "food" && food >= amount) food -= amount;
    else if (resourceType == "wood" && wood >= amount) wood -= amount;
    else if (resourceType == "stone" && stone >= amount) stone -= amount;
    else if (resourceType == "iron" && iron >= amount) iron -= amount;
    else cout << "Not enough " << resourceType << " to consume.\n";
}
