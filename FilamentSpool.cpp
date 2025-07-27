#include "FilamentSpool.h"


FilamentSpool::FilamentSpool() 
    : id(""), material(""), color(""), diameterMM(1.75), 
      totalGrams(0.0), remainingGrams(0.0), costPerKg(0.0) {}
FilamentSpool::FilamentSpool(const std::string& id, const std::string& material, const std::string& color,
                             double diameterMM, double totalGrams, double remainingGrams, double costPerKg)
    : id(id), material(material), color(color), diameterMM(diameterMM),
      totalGrams(totalGrams), remainingGrams(remainingGrams), costPerKg(costPerKg) {}
FilamentSpool::FilamentSpool(const FilamentSpool& other)
    : id(other.id), material(other.material), color(other.color), diameterMM(other.diameterMM),
      totalGrams(other.totalGrams), remainingGrams(other.remainingGrams), costPerKg(other.costPerKg) {}
FilamentSpool::~FilamentSpool() {}

std::ostream& operator<<(std::ostream& os, const FilamentSpool& spool) {
    os << "FilamentSpool [ID: " << spool.id 
       << ", Material: " << spool.material 
       << ", Color: " << spool.color 
       << ", Diameter: " << spool.diameterMM 
       << "mm, Total: " << spool.totalGrams 
       << "g, Remaining: " << spool.remainingGrams 
       << "g, Cost per Kg: $" << spool.costPerKg << "]";
    return os;
}
bool FilamentSpool::operator==(const FilamentSpool& other) const {
    return id == other.id && material == other.material && color == other.color &&
           diameterMM == other.diameterMM && totalGrams == other.totalGrams &&
           remainingGrams == other.remainingGrams && costPerKg == other.costPerKg;
}
double FilamentSpool::getDiameterMM() const {
    return diameterMM;
}
double FilamentSpool::getTotalGrams() const {
    return totalGrams;
}
double FilamentSpool::getRemainingGrams() const {
    return remainingGrams;
}
double FilamentSpool::getCostPerKg() const {
    return costPerKg;
}
std::string FilamentSpool::getId() const {
    return id;
}
std::string FilamentSpool::getMaterial() const {
    return material;
}
std::string FilamentSpool::getColor() const {
    return color;
}
void FilamentSpool::setDiameterMM(double diameterMM) {
    this->diameterMM = diameterMM;
}
void FilamentSpool::setTotalGrams(double totalGrams) {
    this->totalGrams = totalGrams;
}
void FilamentSpool::setRemainingGrams(double remainingGrams) {
    this->remainingGrams = remainingGrams;
}
void FilamentSpool::setCostPerKg(double costPerKg) {
    this->costPerKg = costPerKg;
}
void FilamentSpool::setId(const std::string& id) {
    this->id = id;
}
void FilamentSpool::setMaterial(const std::string& material) {
    this->material = material;
}
void FilamentSpool::setColor(const std::string& color) {
    this->color = color;
}
