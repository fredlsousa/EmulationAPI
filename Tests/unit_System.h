//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_UNIT_SYSTEM_H
#define API_SINGLETON_UNIT_SYSTEM_H

#include "../SystemImpl.h"
#include "../System.h"
#include <assert.h>
#include <cmath>

bool nameSystemTest(const string& name){
    System* s1 = new SystemImpl();
    s1->setName(name);
    if (s1->getName() == name){
        return true;
    }
    else{
        return false;
    }
}

bool resourceTest(double& val){
    System* s1 = new SystemImpl();
    s1->setResource(val);
    if(s1->getResource() == val){
        return true;
    }
    else{
        return false;
    }
}

bool testCopy(System* sys){
    System* s1 = new SystemImpl();
    s1 = sys;
    if(s1 == sys){
        return true;
    }
    else{
        return false;
    }
}

bool testOperators(SystemImpl sys1){
    SystemImpl sys2("sys2", 20);
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
    SystemImpl sys1(100);
    SystemImpl sys2(20);
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

    System* sys3 = new SystemImpl(100);
    System* sys4 = new SystemImpl(20);
    sys3 = sys4;
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

    System* s1 = new SystemImpl("s1", 100);
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

    cout << "TEST SYSTEM RESULTS: " << endl;
    cout << "TOTAL TESTS: " << success + fails << endl;
    cout << "SUCCESS: " << success << endl;
    cout << "FAILS: " << fails << endl;
}


#endif //API_SINGLETON_UNIT_SYSTEM_H
