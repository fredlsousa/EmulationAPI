//
// Created by Frederico on 08/05/19.
//

#ifndef EMULATIONAPI_SYSTEM_H
#define EMULATIONAPI_SYSTEM_H

#include <iostream>


using namespace std;

class System{
private:
    double resource;
    string name;
public:
    System();
    System(double);
    System(const string& , double);
    System(const System& s);
    System& operator= (const System &other);
    ~System();
    const double getResource() const;
    void setResource(double);
    friend ostream& operator<< (ostream& os, System& s);
    System operator+ (System &s);
    System operator+ (int r);
    System operator+ (double r);
    System operator* (System &s);
    System operator* (int r);
    System operator* (double r);
    System operator- (System &s);
    System operator- (int r);
    System operator- (double r);
    System operator/ (System &s);
    System operator/ (int r);
    System operator/ (double r);
    const string &getName() const;
    void setName(const string &name);
    bool operator==(const System &rhs) const;
    bool operator!=(const System &rhs) const;
    bool operator<(const System &rhs) const;
    bool operator>(const System &rhs) const;
    bool operator<=(const System &rhs) const;
    bool operator>=(const System &rhs) const;
};





#endif //EMULATIONAPI_SYSTEM_H
