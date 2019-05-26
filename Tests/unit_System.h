//
// Created by Frederico on 25/05/19.
//

#ifndef EMULATIONAPI_UNIT_SYSTEM_H
#define EMULATIONAPI_UNIT_SYSTEM_H

#include "../System.h"
#include <assert.h>
#include <cmath>

bool nameSystemTest(const string& name){
    System* s1 = new System();
    s1->setName(name);
    if (s1->getName() == name){
        return true;
    }
    else{
        return false;
    }
}

bool resourceTest(double& val){
    System* s1 = new System();
    s1->setResource(val);
    if(s1->getResource() == val){
        return true;
    }
    else{
        return false;
    }
}

bool testCopy(System* sys){
    System* s1 = new System();
    s1 = sys;
    if(s1 == sys){
        delete s1;
        return true;
    }
    else{
        return false;
    }
}

bool testOperators(System sys1){
    System sys2("sys2", 20);
    sys1 = sys1 * 10;
    assert((sys1.getResource() - 1000) < 0.0001);
    sys2 = sys2*sys1;
    assert((sys2.getResource() - 20000) < 0.0001);
    sys2 = sys2*0.5;
    assert((sys2.getResource() - 10000) < 0.0001);
    sys1 = sys1 / sys2;
    assert(fabs(sys1.getResource() - 0.1) < 0.0001);
    sys2 = sys2 + sys1;
    cout << sys2.getResource() << endl;
    assert(fabs(sys2.getResource() - 10000.1) < 0.0001);
    return true;
}

void unitarySystemTest(){
    int success = 0;
    int fails = 0;
    System sys1(100);
    System sys2(20);
    sys1 = sys1*10;
    assert((sys1.getResource() - 1000) < 0.0001);
    sys2 = sys2*sys1;
    assert((sys2.getResource() - 20000) < 0.0001);
    sys2 = sys2*0.5;
    assert((sys2.getResource() - 10000) < 0.0001);
    sys1 = sys1 / sys2;
    assert(fabs(sys1.getResource() - 0.1) < 0.0001);
    sys2 = sys2 + sys1;
    cout << sys2.getResource() << endl;
    assert(fabs(sys2.getResource() - 10000.1) < 0.0001);

    System* sys3 = new System(100);
    System* sys4 = new System(20);
    sys3 = sys4;
    delete sys4;
    double val = sys3->getResource();
    assert(fabs(val - 20) < 0.0001);

    if(nameSystemTest("s1")){
        cout << "Name passed!" << endl;
        success++;
    }
    else{
        cout << "Name not passed!" << endl;
        fails++;
    }

    double v = 100;
    if(resourceTest(v)){
        cout << "Resource passed!" << endl;
        success++;
    }
    else{
        cout << "Resource not passed!" << endl;
        fails++;
    }

    System* s1 = new System("s1", 100);
    if(testCopy(s1)){
        cout << "System copy passed!" << endl;
        success++;
    }
    else{
        cout << "Copy not passed!" << endl;
        fails++;
    }

    if(testOperators(*s1)){
        cout << "Operators passed!" << endl;
        success++;
    }
    else{
        cout << "Operators not passed!" << endl;
        fails++;
    }

    cout << "TEST RESULTS: " << endl;
    cout << "TOTAL TESTS: " << success + fails << endl;
    cout << "SUCCES: " << success << endl;
    cout << "FAILS: " << fails << endl;
}


#endif //EMULATIONAPI_UNIT_SYSTEM_H
