//
// Created by Frederico on 08/05/19.
//

#ifndef EMULATIONAPI_EXPONENTIALFLOW_H
#define EMULATIONAPI_EXPONENTIALFLOW_H

#include "Flow.h"
#include "System.h"

class ExponentialFlow : public Flow{
public:
    ExponentialFlow();
    ExponentialFlow(System*, System*);
    ExponentialFlow(const string& name, System*, System*);
    //ExponentialFlow(const ExponentialFlow& rhs);
    ~ExponentialFlow();
    double execute();

    /*ExponentialFlow* clone() const override{
        return new ExponentialFlow(*this);
    }
    */
};


#endif //EMULATIONAPI_EXPONENTIALFLOW_H
