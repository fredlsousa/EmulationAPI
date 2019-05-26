//
// Created by Frederico on 08/05/19.
//

#ifndef EMULATIONAPI_MODEL_H
#define EMULATIONAPI_MODEL_H


#include <iostream>
#include <vector>
#include "Flow.h"

using namespace std;


class Model{
protected:
    int timeIni;
    int timeFin;
    int increment;
    string name;
    vector <Flow *> Flows;

public:
    typedef typename vector<Flow*>::iterator iterator;
    Model();
    Model(int, int, int);
    Model(const string&, int, int , int);
    Model(Model &other);
    Model& operator=(Model &other);
    ~Model();
    const int getTimeIni() const;
    void setTimeIni(int);
    const int getTimeFin() const;
    void setTimeFin(int);
    void add(Flow*);
    void erase(Flow* toDelete);

    iterator begin(){
        return Flows.begin();
    }

    iterator end(){
        return Flows.end();
    }

    Flow* operator[](int i){
        return Flows[i];
    }
    void report();
    void execute();
    int getIncrement() const;
    void setIncrement(int increment);

    const string &getName() const;

    void setName(const string &name);
    void getFlowNames();
    bool operator==(const Model &rhs) const;
    bool operator!=(const Model &rhs) const;

};

#endif //EMULATIONAPI_MODEL_H
