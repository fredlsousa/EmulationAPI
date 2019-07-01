//
// Created by Frederico on 07/06/19.
//

#include "LogisticFlow.h"


LogisticFlow::LogisticFlow() {}

LogisticFlow::LogisticFlow(System* source, System* destiny): FlowImpl(source, destiny) {}

LogisticFlow::LogisticFlow(const string& name, System* source, System* destiny): FlowImpl(name, source, destiny){}

LogisticFlow::~LogisticFlow() {
    LogisticFlow::~FlowImpl();
}

double LogisticFlow::execute() {
    return (0.01 * (getDestinySystem()->getResource())) * (1 - (getDestinySystem()->getResource()) / 70);
}
