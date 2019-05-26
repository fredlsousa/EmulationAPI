//
// Created by Frederico on 09/05/19.
//

#ifndef EMULATIONAPI_LOGISTICFLOW_H
#define EMULATIONAPI_LOGISTICFLOW_H

#include "Flow.h"
#include "System.h"

class LogisticFlow : public Flow{
public:
    LogisticFlow();
    LogisticFlow(System*, System*);
    ~LogisticFlow();
    double execute();
};


#endif //EMULATIONAPI_LOGISTICFLOW_H
