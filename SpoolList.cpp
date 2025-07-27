#include "SpoolList.h"
#include <iostream>
#include <iomanip>

void SpoolList::addSpool(FilamentSpool& spool) {
    spools.push_back(spool);
}
bool SpoolList::removeSpool(const std::string& id) {
    int idx = -1;

    for (int i =0; i < spools.size(); ++i) {
        if (spools[i].getId() == id) {
            idx = i;
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
        os << spoolList.spools[i];
        if (i < spoolList.spools.size() - 1) {
            os << "\n"; // Add a newline between surfboards
        }
    }
    return os;
}
SpoolList& SpoolList::operator-=(const FilamentSpool& spool) {
    removeSpool(spool.getId());
    return *this;
}
SpoolList& SpoolList::operator+=(const FilamentSpool& spool) {
    addSpool(const_cast<FilamentSpool&>(spool));
    return *this;
}