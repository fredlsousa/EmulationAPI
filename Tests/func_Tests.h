//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_FUNC_TESTS_H
#define API_SINGLETON_FUNC_TESTS_H

#include <iostream>
#include "../ExponentialFlow.h"
#include "../LogisticFlow.h"
#include "../System.h"
#include "../Flow.h"
#include "../Model.h"
#include "assert.h"
#include <cmath>


void exponentialTest(){
    Model* m1 = Model::createModel("m1", 0, 100, 1);
    System* pop1 = m1->createSystem("pop1", 100);
    System* pop2 = m1->createSystem("pop2", 0);
    Flow* f1 = m1->createFlow<ExponentialFlow>("f1", pop1, pop2);
    m1->execute();
    cout << "Modelo Exponencial: " << endl;
    m1->report();
    assert(fabs(pop1->getResource() - 36.6032) < 0.0001);
    assert(fabs(pop2->getResource() - 63.3968) < 0.0001);

}


void logisticTest(){
    Model* m1 = Model::createModel("m1", 0, 100, 1);
    System* p1 = m1->createSystem("p1", 100);
    System* p2 = m1->createSystem("p2", 10);
    Flow* f1 = m1->createFlow<LogisticFlow>("f1", p1, p2);
    m1->execute();
    cout << "Modelo Logistico: " << endl;
    m1->report();
    assert(fabs(p1->getResource() - 88.2167) < 0.0001);
    assert(fabs(p2->getResource() - 21.7834) < 0.0001);
}


void finalTest(){
    Model* m1 = Model::createModel("m1", 0, 100, 1);
    System* Q1 = m1->createSystem("Q1", 100);
    System* Q2 = m1->createSystem("Q2", 0);
    System* Q3 = m1->createSystem("Q3", 100);
    System* Q4 = m1->createSystem("Q4", 0);
    System* Q5 = m1->createSystem("Q5", 0);
    Flow* f = m1->createFlow<ExponentialFlow>("f", Q1, Q2);
    Flow* g = m1->createFlow<ExponentialFlow>("g", Q1, Q3);
    Flow* t = m1->createFlow<ExponentialFlow>("t", Q2, Q3);
    Flow* r = m1->createFlow<ExponentialFlow>("r", Q2, Q5);
    Flow* u = m1->createFlow<ExponentialFlow>("u", Q3, Q4);
    Flow* v = m1->createFlow<ExponentialFlow>("v", Q4, Q1);
    m1->execute();
    cout << "Modelo Final: " << endl;
    m1->report();
    assert(fabs(Q1->getResource() - 31.8513) < 0.0001);
    assert(fabs(Q2->getResource() - 18.4003) < 0.0001);
    assert(fabs(Q3->getResource() - 77.1143) < 0.0001);
    assert(fabs(Q4->getResource() - 56.1728) < 0.0001);
    assert(fabs(Q5->getResource() - 16.4612) < 0.0001);
}


#endif //API_SINGLETON_FUNC_TESTS_H
