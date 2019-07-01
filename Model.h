//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_MODEL_H
#define API_SINGLETON_MODEL_H

#include "Flow.h"
#include "FlowImpl.h"
#include "System.h"
#include <vector>

typedef typename vector<Flow*>::iterator FlowIterator;
typedef typename vector<System*>::iterator SystemIterator;


class Model {
public:
    virtual const int getTimeIni() const = 0;
    virtual void setTimeIni(int) = 0;
    virtual const int getTimeFin() const = 0;
    virtual void setTimeFin(int) = 0;
    virtual FlowIterator beginFlow() = 0;
    virtual FlowIterator endFlow()  = 0;
    virtual SystemIterator beginSystem() = 0;
    virtual SystemIterator endSystem() = 0;
    virtual void report() = 0;
    virtual void execute() = 0;
    virtual int getIncrement() const = 0;
    virtual void setIncrement(int increment) = 0;
    virtual const string &getName() const = 0;
    virtual void setName(const string &name) = 0;
    virtual void getFlowNames() = 0;

    template<class T>
    Flow* createFlow(const string& name, System* source, System* destiny){
        FlowImpl* f = new T(name, source, destiny);
        add(f);
        return f;
    }

    virtual System* createSystem(const string&, double) = 0;
    static Model* createModel(const string&, int, int , int);
protected:
    virtual void add(Flow*) = 0;
    virtual void erase(Flow* toDelete) = 0;
    virtual void add(System*) = 0;
    virtual void erase(System*) = 0;
};


#endif //API_SINGLETON_MODEL_H
