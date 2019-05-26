//
// Created by Frederico on 08/05/19.
//

#include "ExponentialFlow.h"

ExponentialFlow::ExponentialFlow() {}
ExponentialFlow::ExponentialFlow(System* source, System* destiny): Flow(source, destiny){}
ExponentialFlow::ExponentialFlow(const string &name, System* source, System* destiny): Flow(name, source, destiny) {}

ExponentialFlow::~ExponentialFlow() {
    ExponentialFlow::~Flow();
}

double ExponentialFlow::execute() {
    double value = 0;
    value = 0.01 * (getSourceSystem()->getResource());
    return value;
}
