//
// Created by Frederico on 08/05/19.
//

#ifndef EMULATIONAPI_FLOW_H
#define EMULATIONAPI_FLOW_H


#include "System.h"
#include <iostream>


using namespace std;

class Flow{
protected:
    string name;
    System* source;
    System* destiny;
public:
    Flow();
    Flow(System*, System*);
    Flow(const string& name, System*, System*);
    Flow(Flow &other);
    //static Flow* create();
    virtual ~Flow();
    virtual double execute() = 0;
    Flow& operator=(Flow& other);
    //virtual Flow* clone() const = 0;
    bool operator==(const Flow &rhs) const;
    bool operator!=(const Flow &rhs) const;
    void connect(System*, System*);
    void erase(System*);
    void setSourceSystem(System*);
    System * getSourceSystem() const;
    void setDestinySystem(System*);
    System * getDestinySystem() const;
    friend ostream& operator<<(ostream& , Flow* );
    const string &getName() const;
    void setName(const string &name);
    bool operator<(const Flow &rhs) const;
    bool operator>(const Flow &rhs) const;
    bool operator<=(const Flow &rhs) const;
    bool operator>=(const Flow &rhs) const;

};


#endif //EMULATIONAPI_FLOW_H
