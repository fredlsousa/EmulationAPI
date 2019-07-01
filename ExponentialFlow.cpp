//
// Created by Frederico on 07/06/19.
//

#include "ExponentialFlow.h"

ExponentialFlow::ExponentialFlow() {}
ExponentialFlow::ExponentialFlow(System* source, System* destiny): FlowImpl(source, destiny){}
ExponentialFlow::ExponentialFlow(const string &name, System* source, System* destiny): FlowImpl(name, source, destiny) {}

ExponentialFlow::~ExponentialFlow() {
    ExponentialFlow::~FlowImpl();
}

double ExponentialFlow::execute() {
    double value = 0;
    value = 0.01 * (getSourceSystem()->getResource());
    return value;
}