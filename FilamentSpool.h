#ifndef SPOOL_H
#define SPOOL_H

#include <iostream>
#include <string>

class FilamentSpool {
    private:
        std::string id;
        std::string material;
        std::string color;
        double diameterMM;
        double totalGrams;
        double remainingGrams;
        double costPerKg;
    public:
        FilamentSpool();
        FilamentSpool(const std::string& id,
                      const std::string& material,
                      const std::string& color,
                      double diameterMM,
                      double totalGrams,
                      double remainingGrams,
                      double costPerKg);
        FilamentSpool(const FilamentSpool& other);
        ~FilamentSpool();

        friend std::ostream& operator<<(std::ostream& os, const FilamentSpool& spool);
        bool operator==(const FilamentSpool& other) const;

        double getDiameterMM() const;
        double getTotalGrams() const;
        double getRemainingGrams() const;
        double getCostPerKg() const;
        std::string getId() const;
        std::string getMaterial() const;
        std::string getColor() const;

        void setDiameterMM(double diameterMM);
        void setTotalGrams(double totalGrams);
        void setRemainingGrams(double remainingGrams);
        void setCostPerKg(double costPerKg);
        void setId(const std::string& id);
        void setMaterial(const std::string& material);
        void setColor(const std::string& color);
};

#endif
