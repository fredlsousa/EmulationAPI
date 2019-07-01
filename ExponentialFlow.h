//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_EXPONENTIALFLOW_H
#define API_SINGLETON_EXPONENTIALFLOW_H


#include "FlowImpl.h"
#include "System.h"

class ExponentialFlow : public FlowImpl{
public:
    ExponentialFlow();
    ExponentialFlow(System*, System*);
    ExponentialFlow(const string& name, System*, System*);
    ~ExponentialFlow();
    double execute();

};


#endif //API_SINGLETON_EXPONENTIALFLOW_H
