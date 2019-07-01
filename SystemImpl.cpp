//
// Created by Frederico on 07/06/19.
//

#include "SystemImpl.h"

#include "SystemImpl.h"

SystemImpl::SystemImpl(){}
SystemImpl::SystemImpl(double resource): resource(resource){}
SystemImpl::SystemImpl(const string& name, double resource): name(name), resource(resource){}
SystemImpl::~SystemImpl(){}

SystemImpl::SystemImpl(const System &s) {
    this->setName(s.getName());
    this->setResource(s.getResource());
}

void SystemImpl::setResource(double resource){
    this->resource = resource;
}

const double SystemImpl::getResource() const {
    return resource;
}

ostream& operator<< (ostream& os, System& s){
    cout << "Resource: " << s.getResource() << endl;
    return os;
}

const string &SystemImpl::getName() const {
    return name;
}

void SystemImpl::setName(const string &name) {
    SystemImpl::name = name;
}

System& SystemImpl::operator=(const System &other){
    if(this != &other){
        this->setName(other.getName());
        this->setResource(other.getResource());
    }
    return *this;
}

double operator+ (const System &s1, const System &s2){
    return s1.getResource() + s2.getResource();
}

double operator+ (const System &s, int r){
    return s.getResource() + r;
}

double operator+ (const System &s, double r){
    return s.getResource() + r;
}

double operator* (const System &s1, const System &s2){
    return s1.getResource() * s2.getResource();
}

double operator* (const System &s, int r){
    return s.getResource() * r;
}

double operator* (const System &s, double r){
    return s.getResource() * r;
}

double operator- (const System &s1, const System& s2){
    return s1.getResource() - s2.getResource();
}

double operator- (const System &s, int r){
    return s.getResource() - r;
}

double operator- (const System &s, double r){
    return s.getResource() - r;
}

double operator/ (const System &s1, const System &s2){
    return s1.getResource() / s2.getResource();
}

double operator/ (const System &s, int r){
    return s.getResource() / r;
}

double operator/ (const System &s, double r){
    return s.getResource() / r;
}


bool SystemImpl::operator==(const System &rhs) const {
    return resource == rhs.getResource() &&
           name == rhs.getName();
}

bool SystemImpl::operator!=(const System &rhs) const {
    return !(rhs == *this);
}

bool SystemImpl::operator<(const System &rhs) const {
    if (resource < rhs.getResource())
        return true;
    if (rhs.getResource() < resource)
        return false;
    return name < rhs.getName();
}

bool SystemImpl::operator>(const System &rhs) const {
    return rhs < *this;
}

bool SystemImpl::operator<=(const System &rhs) const {
    return !(rhs < *this);
}

bool SystemImpl::operator>=(const System &rhs) const {
    return !(*this < rhs);
}

