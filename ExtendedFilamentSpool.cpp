#include "ExtendedFilamentSpool.h"

ExtendedFilamentSpool::ExtendedFilamentSpool()
    : FilamentSpool(), vendor(""), purchaseDate(""), isOpen(false) {}

ExtendedFilamentSpool::ExtendedFilamentSpool(const std::string& id,
                                             const std::string& material,
                                             const std::string& color,
                                             double diameterMM,
                                             double totalGrams,
                                             double remainingGrams,
                                             double costPerKg,
                                             const std::string& vendor,
                                             const std::string& purchaseDate,
                                             bool isOpen)
    : FilamentSpool(id, material, color, diameterMM, totalGrams, remainingGrams, costPerKg),
      vendor(vendor), purchaseDate(purchaseDate), isOpen(isOpen) {}

std::string ExtendedFilamentSpool::getVendor() const {
    return vendor;
}

std::string ExtendedFilamentSpool::getPurchaseDate() const {
    return purchaseDate;
}

bool ExtendedFilamentSpool::getIsOpen() const {
    return isOpen;
}

void ExtendedFilamentSpool::setVendor(const std::string& vendor) {
    this->vendor = vendor;
}

void ExtendedFilamentSpool::setPurchaseDate(const std::string& purchaseDate) {
    this->purchaseDate = purchaseDate;
}

void ExtendedFilamentSpool::setIsOpen(bool isOpen) {
    this->isOpen = isOpen;
}

void ExtendedFilamentSpool::print(std::ostream& os) const{
    FilamentSpool::print(os);
    os << ", Vendor: " << vendor
       << ", Purchase Date: " << purchaseDate
       << ", Is Open: " << (isOpen ? "Yes" : "No") << "]";
}

