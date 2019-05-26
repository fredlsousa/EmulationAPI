//
// Created by Frederico on 26/05/19.
//

#ifndef EMULATIONAPI_UNIT_FLOW_H
#define EMULATIONAPI_UNIT_FLOW_H

#include "../ExponentialFlow.h"
#include <cmath>
#include <assert.h>

bool unitNameTest(const string& name){
    ExponentialFlow* f1 = new ExponentialFlow();
    f1->setName(name);
    if(f1->getName() == name){
        delete f1;
        return true;
    }
    else{
        return false;
    }
}

bool unitSystemSourceTest(System* s1){
    System* s2 = new System("s2", 30);
    ExponentialFlow* f1 = new ExponentialFlow("f1", s1, s2);
    if(f1->getSourceSystem() == s1){
        delete s2;
        delete f1;
        return true;
    }
    else{
        return false;
    }

}

bool unitSystemDestinyTest(System* s2){
    System* s1 = new System("s1", 100);
    ExponentialFlow* f1 = new ExponentialFlow("f1", s1, s2);
    if(f1->getDestinySystem() == s2){
        delete s1;
        delete f1;
        return true;
    }
    else{
        return false;
    }
}

bool unitConnectTest(System* sysConnect){
    System* s1 = new System("s1", 100);
    System* s2 = new System("s2", 50);
    ExponentialFlow* f1 = new ExponentialFlow("f1", s1, s2);
    f1->connect(sysConnect, s1);
    if(f1->getSourceSystem() == sysConnect){
        delete s1;
        delete s2;
        delete f1;
        return true;
    }
    else{
        return false;
    }
}

bool unitEraseTest(System* toErase){
    System* s1 = new System("s1", 100);
    ExponentialFlow* f1 = new ExponentialFlow("f1", toErase, s1);
    f1->erase(toErase);
    if(f1->getSourceSystem() == nullptr){
        delete s1;
        delete f1;
        return true;
    }
    else{
        return false;
    }
}

bool unitEqualOperatorTest(ExponentialFlow* rhs){
    System* s1 = new System("s1", 100);
    System* s2 = new System("s2", 50);
    ExponentialFlow* f1 = new ExponentialFlow("f1", s1, s2);
    f1 = rhs;
    if(f1 == rhs){              //in this case, it works because rhs is not deleted
        delete s1;              //what really happens is that f1 points to rhs, but it is not hard copied
        delete s2;              //it needs to hard copy rhs in f1, not just point to rhs's adress
        delete f1;
        return true;
    }
    else{
        return false;
    }
}

bool unitCopyConstructorTest(ExponentialFlow* rhs){
    ExponentialFlow* f1 = new ExponentialFlow(*rhs);
    if(f1 == rhs){
        delete f1;
        return true;
    }
    else{
        return false;
    }
}

void unitaryFlowTest(){

    int success = 0;
    int fails = 0;

    System sys3(100);
    System sys4(5);
    ExponentialFlow lf1(&sys3, nullptr);
    double val = lf1.execute();
    assert(fabs(val - 1) < 0.0001);
    lf1.connect(&sys3, &sys4);
    val = lf1.execute();
    assert(fabs(val - 1) < 0.0001);
    lf1.erase(&sys3);
    System* sys5 = new System(200);
    System* sys6 = new System(20);
    ExponentialFlow* f1 = new ExponentialFlow("f1", sys5, sys6);
    ExponentialFlow* f2 = new ExponentialFlow(*f1);
    //ExponentialFlow* f2 = new ExponentialFlow("f2", sys6, sys5);
    val = f1->execute();
    val = f2->execute();
    //assert(fabs(val - 2) < 0.0001);
    //f2 = f1;
    delete f1;
    cout << f2->getName() << endl;
    val = f2->execute();
    //assert(fabs(val - 2) < 0.0001);
    delete f2;


    if(unitNameTest("Flow1")){
        cout << "Flow name passed!" << endl;
        success++;
    }
    else{
        cout << "Flow name not passed!" << endl;
        fails++;
    }


    if(unitSystemSourceTest(sys5)){
        cout << "Flow source system passed!" << endl;
        success++;
    }
    else{
        cout << "Flow source system not passed!" << endl;
        fails++;
    }

    if(unitSystemDestinyTest(sys6)){
        cout << "Flow destiny system passed!" << endl;
        success++;
    }
    else{
        cout << "Flow destiny system not passed!" << endl;
        fails++;
    }


    if(unitConnectTest(sys5)){
        cout << "Flow connect passed!" << endl;
        success++;
    }
    else{
        cout << "Flow connect not passed!" << endl;
        fails++;
    }

    if(unitEraseTest(sys6)){
        cout << "Flow erase passed!" << endl;
        success++;
    }
    else{
        cout << "Flow erase not passed!" << endl;
        fails++;
    }

    ExponentialFlow* fq = new ExponentialFlow("fq", sys5, sys6);

    if(unitEqualOperatorTest(fq)){
        cout << "Flow equal passed!" << endl;
        success++;
    }

    else{
        cout << "Flow equal not passed!" << endl;
        fails++;
    }

    if(unitCopyConstructorTest(fq)){
        cout << "Flow copy constructor passed!" << endl;
        success++;
    }
    else{
        cout << "Flow copy constructor not passed!" << endl;
        fails++;
    }

    cout << "TEST RESULTS: " << endl;
    cout << "TOTAL TESTS: " << success + fails << endl;
    cout << "SUCCES: " << success << endl;
    cout << "FAILS: " << fails << endl;
}



#endif //EMULATIONAPI_UNIT_FLOW_H
