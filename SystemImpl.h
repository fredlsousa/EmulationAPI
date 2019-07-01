//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_SYSTEMIMPL_H
#define API_SINGLETON_SYSTEMIMPL_H

#include <iostream>
#include "System.h"

using namespace std;

class SystemImpl : public System{
private:
    double resource;
    string name;
public:
    SystemImpl();
    SystemImpl(double);
    SystemImpl(const string& , double);
    SystemImpl(const System& s);
    System& operator= (const System &other);
    ~SystemImpl();
    const double getResource() const;
    void setResource(double);
    friend ostream& operator<< (ostream& os, System& s);
    const string &getName() const;
    void setName(const string &name);
    bool operator==(const System &rhs) const;
    bool operator!=(const System &rhs) const;
    bool operator<(const System &rhs) const;
    bool operator>(const System &rhs) const;
    bool operator<=(const System &rhs) const;
    bool operator>=(const System &rhs) const;
};


#endif //API_SINGLETON_SYSTEMIMPL_H
