#ifndef SPOOLLIST_H
#define SPOOLLIST_H

#include "FilamentSpool.h"
#include <vector>
#include <iostream>



class SpoolList{
    private:
        std::vector<FilamentSpool*> spools;
    public:
        void addSpool(FilamentSpool* spool);
        bool removeSpool(const std::string& id);
        void updateSpool(FilamentSpool* spool);
        friend std::ostream& operator<<(std::ostream& os, const SpoolList& spoolList);
        bool operator==(const SpoolList& other) const;
        SpoolList& operator-=(FilamentSpool* spool);
        SpoolList& operator+=(FilamentSpool* spool);
        
};

#endif