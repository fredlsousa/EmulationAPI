//
// Created by Frederico on 08/05/19.
//

#include "Flow.h"

Flow::Flow(){}
Flow::Flow(System* source, System* destiny): source(source), destiny(destiny){}
Flow::Flow(const string& name, System* source, System* destiny): name(name), source(source), destiny(destiny){}
Flow::Flow(Flow &other){
    this->setName(other.getName());
    this->setSourceSystem(other.getSourceSystem());
    this->setDestinySystem(other.getDestinySystem());
}
Flow::~Flow(){}

Flow& Flow::operator=(Flow& other){
    this->setName(other.getName());
    this->setSourceSystem(other.getSourceSystem());
    this->setDestinySystem(other.getDestinySystem());
    return *this;
}

void Flow::setSourceSystem(System* s1){
    this->source = s1;
}

System * Flow::getSourceSystem() const {
    return source;
}

void Flow::setDestinySystem(System* d1){
    this->destiny = d1;
}

System * Flow::getDestinySystem() const {
    return destiny;
}

double Flow::execute() {}

void Flow::connect(System* sysSource, System* sysDestiny){
    this->setSourceSystem(sysSource);
    this->setDestinySystem(sysDestiny);
}


void Flow::erase(System* toDelete){
    if (toDelete == getSourceSystem()) {
        setSourceSystem(nullptr);
        return;
    }
    else if (toDelete == getDestinySystem()) {
        setDestinySystem(nullptr);
        return;
    }
    cout << "System does not belong to flow" << endl;
}

ostream& operator<<(ostream& os, Flow* f){
    cout << "Source System: " << f->getSourceSystem()->getResource();
    cout << "Destiny System: " << f->getDestinySystem()->getResource();
    return os;
}

const string &Flow::getName() const {
    return name;
}

void Flow::setName(const string &name) {
    Flow::name = name;
}

bool Flow::operator==(const Flow &rhs) const {
    return name == rhs.name &&
           source == rhs.source &&
           destiny == rhs.destiny;
}

bool Flow::operator!=(const Flow &rhs) const {
    return !(rhs == *this);
}

bool Flow::operator<(const Flow &rhs) const {
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    if (source < rhs.source)
        return true;
    if (rhs.source < source)
        return false;
    return destiny < rhs.destiny;
}

bool Flow::operator>(const Flow &rhs) const {
    return rhs < *this;
}

bool Flow::operator<=(const Flow &rhs) const {
    return !(rhs < *this);
}

bool Flow::operator>=(const Flow &rhs) const {
    return !(*this < rhs);
}




