//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_FLOW_H
#define API_SINGLETON_FLOW_H

#include "System.h"

class Flow {
public:
    virtual double execute() = 0;
    virtual Flow& operator=(Flow& other) = 0;
    virtual bool operator==(const Flow &rhs) const = 0;
    virtual bool operator!=(const Flow &rhs) const = 0;
    virtual void connect(System*, System*) = 0;
    virtual void erase(System*) = 0;
    virtual void setSourceSystem(System*) = 0;
    virtual System * getSourceSystem() const = 0;
    virtual void setDestinySystem(System*) = 0;
    virtual System * getDestinySystem() const = 0;
    virtual const string &getName() const = 0;
    virtual void setName(const string &name) = 0;
    virtual bool operator<(const Flow &rhs) const = 0;
    virtual bool operator>(const Flow &rhs) const = 0;
    virtual bool operator<=(const Flow &rhs) const = 0;
    virtual bool operator>=(const Flow &rhs) const = 0;
    friend ostream& operator<<(ostream& , Flow* );
};


#endif //API_SINGLETON_FLOW_H
