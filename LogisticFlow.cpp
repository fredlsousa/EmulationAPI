//
// Created by Frederico on 09/05/19.
//

#include "LogisticFlow.h"


LogisticFlow::LogisticFlow() {}

LogisticFlow::LogisticFlow(System* source, System* destiny): Flow(source, destiny) {}

LogisticFlow::~LogisticFlow() {
    LogisticFlow::~Flow();
}

double LogisticFlow::execute() {
    return (0.01 * (getDestinySystem()->getResource())) * (1 - (getDestinySystem()->getResource()) / 70);
}