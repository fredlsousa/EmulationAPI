//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_SYSTEM_H
#define API_SINGLETON_SYSTEM_H

#include <iostream>

using namespace std;

class System {
public:

    friend double operator+ (const System &s1, const System &s2);
    friend double operator+ (const System &s, int r);
    friend double operator+ (const System &s, double r);
    friend double operator* (const System &s1, const System &s2);
    friend double operator* (const System &s, int r);
    friend double operator* (const System &s, double r);
    friend double operator- (const System &s1, const System& s2);
    friend double operator- (const System &s, int r);
    friend double operator- (const System &s, double r);
    friend double operator/ (const System &s1, const System &s2);
    friend double operator/ (const System &s, int r);
    friend double operator/ (const System &s, double r);
    virtual const double getResource() const = 0;
    virtual void setResource(double) = 0;
    virtual const string &getName() const = 0;
    virtual void setName(const string &name) = 0;
    virtual bool operator==(const System &rhs) const = 0;
    virtual bool operator!=(const System &rhs) const = 0;
    virtual bool operator<(const System &rhs) const = 0;
    virtual bool operator>(const System &rhs) const = 0;
    virtual bool operator<=(const System &rhs) const = 0;
    virtual bool operator>=(const System &rhs) const = 0;

};


#endif //API_SINGLETON_SYSTEM_H
