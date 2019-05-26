//
// Created by Frederico on 22/05/19.
//

#ifndef EMULATIONAPI_TESTS_H
#define EMULATIONAPI_TESTS_H


#include <iostream>
#include "../System.h"
#include "../ExponentialFlow.h"
#include "../Model.h"
#include "../LogisticFlow.h"
#include "assert.h"
#include <cmath>


void exponentialTest(){
    System pop1;
    System pop2;
    pop1.setResource(100);
    pop2.setResource(0);
    ExponentialFlow f1(&pop1, &pop2);
    Model modelo1(0, 100, 1);
    modelo1.add(&f1);
    modelo1.execute();
    cout << "Modelo Exponencial: " << endl;
    modelo1.report();
    assert(fabs(pop1.getResource() - 36.6032) < 0.0001);
    assert(fabs(pop2.getResource() - 63.3968) < 0.0001);
}


void logisticTest(){
    System p1(100);
    System p2(10);
    LogisticFlow f1(&p1, &p2);
    Model modelo1(0, 100, 1);
    modelo1.add(&f1);
    modelo1.execute();
    cout << "Modelo Logistico: " << endl;
    modelo1.report();
    assert(fabs(p1.getResource() - 88.2167) < 0.0001);
    assert(fabs(p2.getResource() - 21.7834) < 0.0001);
}


void finalTest(){
    System Q1(100);
    System Q2(0);
    System Q3(100);
    System Q4(0);
    System Q5(0);
    ExponentialFlow f(&Q1, &Q2);
    ExponentialFlow g(&Q1, &Q3);
    ExponentialFlow t(&Q2, &Q3);
    ExponentialFlow r(&Q2, &Q5);
    ExponentialFlow u(&Q3, &Q4);
    ExponentialFlow v(&Q4, &Q1);
    Model modelo1(0, 100, 1);
    modelo1.add(&f);
    modelo1.add(&g);
    modelo1.add(&r);
    modelo1.add(&t);
    modelo1.add(&u);
    modelo1.add(&v);
    modelo1.execute();
    cout << "Modelo Final: " << endl;
    modelo1.report();
    assert(fabs(Q1.getResource() - 31.8513) < 0.0001);
    assert(fabs(Q2.getResource() - 18.4003) < 0.0001);
    assert(fabs(Q3.getResource() - 77.1143) < 0.0001);
    assert(fabs(Q4.getResource() - 56.1728) < 0.0001);
    assert(fabs(Q5.getResource() - 16.4612) < 0.0001);
}





#endif //EMULATIONAPI_TESTS_H
