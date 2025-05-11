#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Army;
class Population;
class Economy;
class Bank;
class ResourceManager;
class EventManager;
class Leader;
class DiplomacySystem;
class MapSystem;
class MessageSystem;
class Person {
protected:
    string name;
    int age;
public:
    Person();
    Person(string n, int a);
    virtual void display() const;
};
class SocialClass {
protected:
    string title;
    int population;
public:
    SocialClass();
    SocialClass(string t, int pop);
    virtual void showStatus() const;
};

class Population {
private:
    int total;
    int peasants, merchants, nobles, foodStock;
    float happiness;
public:
    Population();
    void simulate();
    void showStats() const;
    void saveToFile() const;
    void loadFromFile();
    int getTotal() const;
    void decrease(int amount);
};

class Army {
private:
    int soldiers;
    int morale;
    int foodSupply;
public:
    Army();
    void recruitAndTrain(Population& pop);
    void showStats() const;
    void saveToFile() const;
    void loadFromFile();
    void lowerMorale(int amount);
};

class Economy {
private:
    int treasury;
    float taxRate;
    float inflation;
public:
    Economy();
    void taxPopulation(const Population& pop);
    void spend(int amount);
    void showStats() const;
    void saveToFile() const;
    void loadFromFile();
    int getTreasury() const;
    void receiveLoan(int amount);
};

class Bank {
private:
    int loansIssued;
    int fraudDetected;
public:
    Bank();
    void auditTreasury(Economy& economy);
    void issueLoan(Economy& economy, int amount);
    void repayLoan(Economy& economy, int amount);
    void showStats() const;
    void saveToFile() const;
    void loadFromFile();
};

class ResourceManager {
private:
    int food;
    int wood;
    int stone;
    int iron;
public:
    ResourceManager();
    void manage();
    void gatherResources();
    void consumeResources();
    void showStats() const;
    void saveToFile() const;
    void loadFromFile();
    void consumeFixed(string resourceType, int amount);
};

class EventManager {
public:
    EventManager();
    void trigger(Population& pop, Army& army, Economy& eco, ResourceManager& res);
    void famine(ResourceManager& res, Population& pop);
    void disease(Population& pop);
    void war(Army& army, Economy& eco);
    void betrayal(Economy& eco);
    void earthquake(ResourceManager& res);
};

class Leader {
protected:
    string name;
public:
    Leader(string n);
    virtual void imposePolicy(Economy& economy, Army& army);
    string getName() const;
    virtual ~Leader() {}
};

class King : public Leader {
public:
    King();
    void imposePolicy(Economy& economy, Army& army) override;
};

class Tyrant : public Leader {
public:
    Tyrant();
    void imposePolicy(Economy& economy, Army& army) override;
};
class Message {
private:
    char sender[50];
    char receiver[50];
    char content[200];
    char type[20];
    bool isRead;

public:
    Message();
    void setMessage(const char* s, const char* r, const char* c, const char* t);
    void markAsRead();
    bool isForReceiver(const char* r) const;
    void display() const;
};

class DiplomacySystem {
private:
    Message messages[100];
    int messageCount;
    char alliances[50][2][50];  // stores pairs of allied kingdoms
    int allianceCount;

public:
    DiplomacySystem();
    void sendMessage(const char* from, const char* to, const char* content, const char* type);
    void viewMessages(const char* kingdom);
    void formAlliance(const char* k1, const char* k2);
    void breakAlliance(const char* k1, const char* k2);
    bool areAllies(const char* k1, const char* k2);
    void saveToFile() const;
    void loadFromFile();
};

class Territory {
private:
    char name[50];
    char owner[50];
    int resources;
    bool connections[10]; 

public:
    Territory();
    void setName(const char* n);
    void setOwner(const char* o);
    void setResources(int r);
    void connect(int index);
    bool isConnected(int index) const;
    const char* getName() const;
    const char* getOwner() const;
};

class MapSystem {
private:
    Territory territories[10];
    int territoryCount;

public:
    MapSystem();
    void initializeMap();
    void claimTerritory(const char* kingdom, const char* territory);
    bool canMove(const char* from, const char* to) const;
    void showMap() const;
    void saveToFile() const;
    void loadFromFile();
};