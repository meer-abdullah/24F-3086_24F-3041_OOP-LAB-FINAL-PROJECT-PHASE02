#include "Stronghold.h"

Leader::Leader(string n) {
    name = n;
}

string Leader::getName() const {
    return name;
}

void Leader::imposePolicy(Economy& economy, Army& army) {
    cout << name << " has not imposed any specific policy.\n";
}

King::King() : Leader("King") {}

void King::imposePolicy(Economy& economy, Army& army) {
    cout << "The King enacts a peace policy.\n";
    economy.spend(100);
    army.lowerMorale(5);
}

Tyrant::Tyrant() : Leader("Tyrant") {}

void Tyrant::imposePolicy(Economy& economy, Army& army) {
    cout << "The Tyrant enforces harsh military rules.\n";
    economy.spend(50);
    army.lowerMorale(-10);
}
