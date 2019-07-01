//
// Created by Frederico on 07/06/19.
//

#include "FlowImpl.h"


FlowImpl::FlowImpl(){}
FlowImpl::FlowImpl(System* source, System* destiny): source(source), destiny(destiny){}
FlowImpl::FlowImpl(const string& name, System* source, System* destiny): name(name), source(source), destiny(destiny){}

FlowImpl::FlowImpl(Flow &other){
    if(&other == this){
        return;
    }
    this->setName(other.getName());
    this->setSourceSystem(other.getSourceSystem());
    this->setDestinySystem(other.getDestinySystem());
}

FlowImpl::~FlowImpl(){}

Flow& FlowImpl::operator=(Flow& other){
    if(&other == this){
        return (*this);
    }
    this->setName(other.getName());
    this->setSourceSystem(other.getSourceSystem());
    this->setDestinySystem(other.getDestinySystem());
    return (*this);
}

void FlowImpl::setSourceSystem(System* s1){
    this->source = s1;
}

System* FlowImpl::getSourceSystem() const {
    return source;
}

void FlowImpl::setDestinySystem(System* d1){
    this->destiny = d1;
}

System* FlowImpl::getDestinySystem() const {
    return destiny;
}

double FlowImpl::execute() {}

void FlowImpl::connect(System* sysSource, System* sysDestiny){
    this->setSourceSystem(sysSource);
    this->setDestinySystem(sysDestiny);
}


void FlowImpl::erase(System* toDelete){
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

const string &FlowImpl::getName() const {
    return name;
}

void FlowImpl::setName(const string &name) {
    FlowImpl::name = name;
}

bool FlowImpl::operator==(const Flow &rhs) const {
    return name == rhs.getName() &&
           source == rhs.getSourceSystem() &&
           destiny == rhs.getDestinySystem();
}

bool FlowImpl::operator!=(const Flow &rhs) const {
    return !(rhs == *this);
}

bool FlowImpl::operator<(const Flow &rhs) const {
    if (name < rhs.getName())
        return true;
    if (rhs.getName() < name)
        return false;
    if (source < rhs.getSourceSystem())
        return true;
    if (rhs.getSourceSystem() < source)
        return false;
    return destiny < rhs.getDestinySystem();
}

bool FlowImpl::operator>(const Flow &rhs) const {
    return rhs < *this;
}

bool FlowImpl::operator<=(const Flow &rhs) const {
    return !(rhs < *this);
}

bool FlowImpl::operator>=(const Flow &rhs) const {
    return !(*this < rhs);
}




