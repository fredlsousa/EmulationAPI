//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_LOGISTICFLOW_H
#define API_SINGLETON_LOGISTICFLOW_H

#include "FlowImpl.h"
#include "System.h"

class LogisticFlow : public FlowImpl{
public:
    LogisticFlow();
    LogisticFlow(System*, System*);
    LogisticFlow(const string&, System*, System*);
    ~LogisticFlow();
    double execute();
};



#endif //API_SINGLETON_LOGISTICFLOW_H
