#include "Stronghold.h"
#include <cstring>

Message::Message() {
    sender[0] = '\0';
    receiver[0] = '\0';
    content[0] = '\0';
    type[0] = '\0';
    isRead = false;
}

void Message::setMessage(const char* s, const char* r, const char* c, const char* t) {
    strcpy(sender, s);
    strcpy(receiver, r);
    strcpy(content, c);
    strcpy(type, t);
    isRead = false;
}

void Message::markAsRead() {
    isRead = true;
}

bool Message::isForReceiver(const char* r) const {
    return strcmp(receiver, r) == 0;
}

void Message::display() const {
    cout << "From: " << sender << endl;
    cout << "Type: " << type << endl;
    cout << "Message: " << content << endl;
    cout << "Status: " << (isRead ? "Read" : "Unread") << endl;
}

DiplomacySystem::DiplomacySystem() {
    messageCount = 0;
    allianceCount = 0;
}

void DiplomacySystem::sendMessage(const char* from, const char* to, const char* content, const char* type) {
    if (messageCount >= 100) {
        cout << "Message system full!\n";
        return;
    }
    messages[messageCount].setMessage(from, to, content, type);
    messageCount++;
    cout << "Message sent successfully!\n";
}

void DiplomacySystem::viewMessages(const char* kingdom) {
    bool found = false;
    cout << "\n=== Messages for " << kingdom << " ===\n";
    for (int i = 0; i < messageCount; i++) {
        if (messages[i].isForReceiver(kingdom)) {
            found = true;
            messages[i].display();
            messages[i].markAsRead();
            cout << "-------------------\n";
        }
    }
    if (!found) cout << "No messages.\n";
}

void DiplomacySystem::formAlliance(const char* k1, const char* k2) {
    if (allianceCount >= 50) {
        cout << "Alliance system full!\n";
        return;
    }
    strcpy(alliances[allianceCount][0], k1);
    strcpy(alliances[allianceCount][1], k2);
    allianceCount++;
    cout << "Alliance formed between " << k1 << " and " << k2 << endl;
}

void DiplomacySystem::saveToFile() const {
    ofstream out("diplomacy.txt");
    if (!out) {
        cout << "Error: Could not save diplomacy data.\n";
        return;
    }
    out << messageCount << endl;
    out << allianceCount << endl;
    // Save messages and alliances
    out.close();
    cout << "Diplomacy data saved.\n";
}
// ... existing code ...

void DiplomacySystem::loadFromFile() {
    ifstream in("diplomacy.txt");
    if (!in) {
        cout << "Error: Could not load diplomacy data.\n";
        return;
    }

    in >> messageCount;
    for (int i = 0; i < messageCount; i++) {
        in >> messages[i].sender >> messages[i].receiver;
        in >> messages[i].content >> messages[i].type;
        in >> messages[i].isRead;
    }

    in >> allianceCount;
    for (int i = 0; i < allianceCount; i++) {
        in >> alliances[i].kingdom1 >> alliances[i].kingdom2;
        in >> alliances[i].active >> alliances[i].duration;
    }

    in.close();
    cout << "Diplomacy data loaded successfully.\n";
}