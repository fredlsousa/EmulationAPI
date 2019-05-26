//
// Created by Frederico on 08/05/19.
//

#include "System.h"

System::System(){}
System::System(double resource): resource(resource){}
System::System(const string& name, double resource): name(name), resource(resource){}
System::~System(){}

System::System(const System &s) {
    this->setName(s.getName());
    this->setResource(s.getResource());
}

void System::setResource(double resource){
    this->resource = resource;
}

const double System::getResource() const {
    return resource;
}

ostream& operator<< (ostream& os, System& s){
    cout << "Resource: " << s.getResource() << endl;
    return os;
}

const string &System::getName() const {
    return name;
}

void System::setName(const string &name) {
    System::name = name;
}

System& System::operator=(const System &other){
    if(this != &other){
        this->setName(other.getName());
        this->setResource(other.getResource());
    }
    return *this;
}

System System::operator+(System &s) {
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() + s.getResource());
    return obj;
}

System System::operator+(int r) {
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() + r);
    return obj;
}

System System::operator+(double r){
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() + r);
    return obj;
}

System System::operator*(System &s){
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() * s.getResource());
    return obj;
}

System System::operator*(int r) {
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() * r);
    return obj;
}

System System::operator*(double r){
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() * r);
    return obj;
}

System System::operator-(System &s){
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() - s.getResource());
    return obj;
}

System System::operator-(int r){
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() - r);
    return obj;
}

System System::operator-(double r) {
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() - r);
    return obj;
}

System System::operator/(System& s){
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() / s.getResource());
    return obj;
}

System System::operator/(int r){
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() / r);
    return obj;
}

System System::operator/(double r) {
    System obj;
    obj.setName(this->getName());
    obj.setResource(this->getResource() / r);
    return obj;
}


bool System::operator==(const System &rhs) const {
    return resource == rhs.resource &&
           name == rhs.name;
}

bool System::operator!=(const System &rhs) const {
    return !(rhs == *this);
}

bool System::operator<(const System &rhs) const {
    if (resource < rhs.resource)
        return true;
    if (rhs.resource < resource)
        return false;
    return name < rhs.name;
}

bool System::operator>(const System &rhs) const {
    return rhs < *this;
}

bool System::operator<=(const System &rhs) const {
    return !(rhs < *this);
}

bool System::operator>=(const System &rhs) const {
    return !(*this < rhs);
}

