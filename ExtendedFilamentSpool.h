#ifndef EXTENDED_FILAMENT_SPOOL_H
#define EXTENDED_FILAMENT_SPOOL_H

#include "FilamentSpool.h"

class ExtendedFilamentSpool : public FilamentSpool {
private:
    std::string vendor;
    std::string purchaseDate; // e.g., "2025-08-01"
    bool isOpen;

public:
    ExtendedFilamentSpool();
    ExtendedFilamentSpool(const std::string& id,
                          const std::string& material,
                          const std::string& color,
                          double diameterMM,
                          double totalGrams,
                          double remainingGrams,
                          double costPerKg,
                          const std::string& vendor,
                          const std::string& purchaseDate,
                          bool isOpen);

    // Getters
    std::string getVendor() const;
    std::string getPurchaseDate() const;
    bool getIsOpen() const;

    // Setters
    void setVendor(const std::string& vendor);
    void setPurchaseDate(const std::string& purchaseDate);
    void setIsOpen(bool isOpen);

    void print(std::ostream& os) const override;

};

#endif
