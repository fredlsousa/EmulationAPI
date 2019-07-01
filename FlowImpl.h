//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_FLOWIMPL_H
#define API_SINGLETON_FLOWIMPL_H

#include "System.h"
#include "Flow.h"
#include <iostream>


using namespace std;

class FlowImpl : public Flow{
protected:
    string name;
    System* source;
    System* destiny;
public:
    FlowImpl();
    FlowImpl(System*, System*);
    FlowImpl(const string& name, System*, System*);
    FlowImpl(Flow &other);
    virtual ~FlowImpl();
    virtual double execute() = 0;
    virtual Flow& operator=(Flow& other);
    virtual bool operator==(const Flow &rhs) const;
    virtual bool operator!=(const Flow &rhs) const;
    virtual void connect(System*, System*);
    virtual void erase(System*);
    virtual void setSourceSystem(System*);
    virtual System * getSourceSystem() const;
    virtual void setDestinySystem(System*);
    virtual System * getDestinySystem() const;
    friend ostream& operator<<(ostream& , Flow* );
    virtual const string &getName() const;
    virtual void setName(const string &name);
    virtual bool operator<(const Flow &rhs) const;
    virtual bool operator>(const Flow &rhs) const;
    virtual bool operator<=(const Flow &rhs) const;
    virtual bool operator>=(const Flow &rhs) const;

};


#endif //API_SINGLETON_FLOWIMPL_H
