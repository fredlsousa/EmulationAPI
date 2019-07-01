//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_MODELIMPL_H
#define API_SINGLETON_MODELIMPL_H

#include <iostream>
#include "Model.h"
#include "SystemImpl.h"


using namespace std;


class ModelImpl : public Model{
private:
    static ModelImpl* _instance;
protected:
    int timeIni;
    int timeFin;
    int increment;
    string name;
    vector <Flow *> Flows;
    vector <System *> Systems;

public:
    ModelImpl();
    ModelImpl(int, int, int);
    ModelImpl(const string&, int, int , int);
    ModelImpl(Model &other);
    Model& operator=(Model &other);
    static ModelImpl* instance();
    virtual System* createSystem(const string&, double);
    static Model* createModel(const string&, int, int , int);
    ~ModelImpl();
    virtual const int getTimeIni() const;
    virtual void setTimeIni(int);
    virtual const int getTimeFin() const;
    virtual void setTimeFin(int);
    virtual void add(Flow*);
    virtual void erase(Flow* toDelete);
    virtual void add(System*);
    virtual void erase(System*);
    virtual FlowIterator beginFlow(){
        return Flows.begin();
    }

    virtual FlowIterator endFlow(){
        return Flows.end();
    }

    virtual SystemIterator beginSystem(){
        return Systems.begin();
    }

    virtual SystemIterator endSystem(){
        return Systems.end();
    }

    virtual void report();
    virtual void execute();
    virtual int getIncrement() const;
    virtual void setIncrement(int increment);
    virtual const string &getName() const;
    virtual void setName(const string &name);
    virtual void getFlowNames();

};

#endif //API_SINGLETON_MODELIMPL_H
