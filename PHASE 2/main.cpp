#include <iostream>
#include "Stronghold.h"
using namespace std;
int main() {
    Population populationSystem;
    Army armySystem;
    Economy economySystem;
    ResourceManager resourceSystem;
    Leader* currentLeader = new King();  // Leader object
    EventManager eventSystem;
    Bank bankSystem;

    int choice;
    bool running = true;
    cout << "Welcome to StrongHold Game" << endl;

    while (running) {
        cout << "\n================ STRONGHOLD MENU ================\n";
        cout << "1. View Kingdom Overview\n";
        cout << "2. Simulate Population Changes\n";
        cout << "3. Recruit and Train Army\n";
        cout << "4. Manage Economy (Taxation, Treasury)\n";
        cout << "5. Handle Resource Operations\n";
        cout << "6. Trigger Random Event\n";
        cout << "7. Save Game to File\n";
        cout << "8. Load Game from File\n";
        cout << "9. Leader Imposes Policy\n";
        cout << "10. Send Message\n";
        cout << "11. View Messages\n";
        cout << "12. Form Alliance\n";
        cout << "13. Break Alliance\n";
        cout << "14. View Map\n";
        cout << "15. Claim Territory\n";
        cout << "16. Switch Kingdom\n";
        cout << "17. Save Game\n";
        cout << "18. Load Game\n";
        cout << "19. Exit\n";
        cout << "=================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > 10) {
            cout << "Invalid input! Please enter a number between 1 and 10.\n";
            continue;
        }

        switch (choice) {
        case 1:
            populationSystem.showStats();
            armySystem.showStats();
            economySystem.showStats();
            resourceSystem.showStats();
            bankSystem.showStats();
            break;
        case 2:
            populationSystem.simulate();
            break;
        case 3:
            armySystem.recruitAndTrain(populationSystem);
            break;
        case 4:
            economySystem.taxPopulation(populationSystem);
            bankSystem.auditTreasury(economySystem);
            break;
        case 5:
            resourceSystem.manage();
            break;
        case 6:
            eventSystem.trigger(populationSystem, armySystem, economySystem, resourceSystem);
            break;
        case 7:
            populationSystem.saveToFile();
            armySystem.saveToFile();
            economySystem.saveToFile();
            resourceSystem.saveToFile();
            bankSystem.saveToFile();
            break;
        case 8:
            populationSystem.loadFromFile();
            armySystem.loadFromFile();
            economySystem.loadFromFile();
            resourceSystem.loadFromFile();
            bankSystem.loadFromFile();
            break;
        case 9:
            currentLeader->imposePolicy(economySystem, armySystem);
            break;
        case 10: {
            char receiver[50], content[200], type[20];
            cout << "Send message to kingdom: ";
            cin >> receiver;
            cout << "Message type (alliance/trade/threat): ";
            cin >> type;
            cout << "Message content: ";
            cin.ignore();
            cin.getline(content, 200);
            diplomacySystem.sendMessage(currentKingdom, receiver, content, type);
            break;
        }
        case 11:
            diplomacySystem.viewMessages(currentKingdom);
            break;
        case 12: {
            char otherKingdom[50];
            cout << "Form alliance with kingdom: ";
            cin >> otherKingdom;
            diplomacySystem.formAlliance(currentKingdom, otherKingdom);
            break;
        }
        case 13: {
            char otherKingdom[50];
            cout << "Break alliance with kingdom: ";
            cin >> otherKingdom;
            diplomacySystem.breakAlliance(currentKingdom, otherKingdom);
            break;
        }
        case 14:
            mapSystem.showMap();
            break;
        case 15: {
            char territory[50];
            cout << "Enter territory name to claim: ";
            cin >> territory;
            mapSystem.claimTerritory(currentKingdom, territory);
            break;
        }
        case 16: {
            cout << "Enter kingdom name: ";
            cin >> currentKingdom;
            cout << "Switched to controlling " << currentKingdom << endl;
            break;
        }
        case 17:
            // ... existing save functionality ...
            diplomacySystem.saveToFile();
            mapSystem.saveToFile();
            break;
        case 18:
            // ... existing load functionality ...
            diplomacySystem.loadFromFile();
            mapSystem.loadFromFile();
            break;
        case 19:
            running = false;
            break;
    }

    delete currentLeader;
    cout << "\nGame exited successfully. Long live the kingdom!\n";
    return 0;
}
