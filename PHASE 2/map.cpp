#include "Stronghold.h"
#include <cstring>

Territory::Territory() {
    name[0] = '\0';
    owner[0] = '\0';
    resources = 100;
    for (int i = 0; i < 10; i++) {
        connections[i] = false;
    }
}

void Territory::setName(const char* n) {
    strcpy(name, n);
}

void Territory::setOwner(const char* o) {
    strcpy(owner, o);
}

MapSystem::MapSystem() {
    territoryCount = 4;  // Default map size
    initializeMap();
}

void MapSystem::initializeMap() {
    const char* names[] = { "North", "South", "East", "West" };
    for (int i = 0; i < territoryCount; i++) {
        territories[i].setName(names[i]);
        territories[i].setResources(100);
        // Set connections
        for (int j = 0; j < territoryCount; j++) {
            if (i != j) territories[i].connect(j);
        }
    }
}

void MapSystem::showMap() const {
    cout << "\n====== Kingdom Map ======\n";
    for (int i = 0; i < territoryCount; i++) {
        cout << territories[i].getName() << ":\n";
        cout << "Owner: " << (territories[i].getOwner()[0] ? territories[i].getOwner() : "Unclaimed") << endl;
        cout << "Connected to: ";
        for (int j = 0; j < territoryCount; j++) {
            if (territories[i].isConnected(j)) {
                cout << territories[j].getName() << " ";
            }
        }
        cout << "\n-------------------\n";
    }
}

void MapSystem::saveToFile() const {
    ofstream out("map.txt");
    if (!out) {
        cout << "Error: Could not save map data.\n";
        return;
    }
    out << territoryCount << endl;
    // Save territory data
    out.close();
    cout << "Map data saved.\n";
}
// ... existing code ...

void MapSystem::loadFromFile() {
    ifstream in("map.txt");
    if (!in) {
        cout << "Error: Could not load map data.\n";
        return;
    }

    in >> territoryCount;
    for (int i = 0; i < territoryCount; i++) {
        in >> territories[i].name >> territories[i].owner;
        in >> territories[i].resources;
        for (int j = 0; j < 10; j++) {
            in >> territories[i].adjacent[j];
        }
    }

    in.close();
    cout << "Map data loaded successfully.\n";
}