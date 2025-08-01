#include "SpoolList.h"
#include <iostream>
#include <iomanip>

void SpoolList::addSpool(FilamentSpool* spool) {
    spools.push_back(spool);
}
bool SpoolList::removeSpool(const std::string& id) {
    int idx = -1;

    for (int i =0; i < spools.size(); ++i) {
        if (spools[i]->getId() == id) {
            idx = i;
            break;
        }
    }
    if (idx >=0) {
        spools.erase(spools.begin() + idx);
        return true;
    }
    return false;
}
std::ostream& operator<<(std::ostream& os, const SpoolList& spoolList) {
    os << "SpoolList contains " << spoolList.spools.size() << " spools:\n";
    for (int i = 0; i < spoolList.spools.size(); ++i) {
        os << *spoolList.spools[i];
        if (i < spoolList.spools.size() - 1) {
            os << "\n"; // Add a newline between surfboards
        }
    }
    return os;
}
SpoolList& SpoolList::operator-=(FilamentSpool* spool) {
    removeSpool(spool->getId());
    return *this;
}
SpoolList& SpoolList::operator+=(FilamentSpool* spool) {
    addSpool(spool);
    return *this;
}
void SpoolList::updateSpool(FilamentSpool* updatedSpool) {
    for (auto& spool : spools) {
        if (spool->getId() == updatedSpool->getId()) {
            spool = updatedSpool; // Uses the copy assignment operator
            return;
        }
    }
    std::cout << "~~~ Spool ID not found: " << updatedSpool->getId() << " ~~~\n";
}
bool SpoolList::operator==(const SpoolList& other) const {
    if (spools.size() != other.spools.size()) {
        return false;
    }
    for (size_t i = 0; i < spools.size(); ++i) {
        if (!(spools[i] == other.spools[i])) {
            return false;
        }
    }
    return true;
}