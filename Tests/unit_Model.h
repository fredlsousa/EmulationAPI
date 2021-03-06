//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_UNIT_MODEL_H
#define API_SINGLETON_UNIT_MODEL_H

#include "../ModelImpl.h"
#include "../ExponentialFlow.h"
#include "../Model.h"
#include <cmath>
#include <assert.h>

bool unitModelName(const string& name){
    Model* model1 = new ModelImpl();
    model1->setName(name);
    if(model1->getName() == name){
        return true;
    }
    else{
        return false;
    }
}

bool unitInitTimeTest(int& ini){
    Model* model1 = new ModelImpl();
    model1->setTimeIni(ini);
    if(model1->getTimeIni() == ini){
        return true;
    }
    else{
        return false;
    }
}

bool unitFinalTimeTest(int& fin){
    Model* model1 = new ModelImpl();
    model1->setTimeFin(fin);
    if(model1->getTimeFin() == fin){
        return true;
    }
    else{
        return false;
    }
}

bool unitIncrementTest(int& inc){
    Model* model1 = new ModelImpl();
    model1->setIncrement(inc);
    if(model1->getIncrement() == inc){
        return true;
    }
    else{
        return false;
    }
}

bool unitAddTest(){
    auto sys1 = new SystemImpl(100);
    auto sys2 = new SystemImpl(0);
    auto sys3 = new SystemImpl(100);
    auto sys4 = new SystemImpl(0);
    auto sys5 = new SystemImpl(0);
    auto f1 = new ExponentialFlow("f1", sys1, sys2);
    auto f2 = new ExponentialFlow("f2", sys1, sys3);
    auto f3 = new ExponentialFlow("f3", sys2, sys3);
    auto f4 = new ExponentialFlow("f4", sys2, sys5);
    auto f5 = new ExponentialFlow("f5", sys3, sys4);
    auto f6 = new ExponentialFlow("f6", sys4, sys1);
    auto model1 = new ModelImpl(0, 100, 1);
    model1->add(f1);
    model1->add(f2);
    model1->add(f3);
    model1->add(f4);
    model1->add(f5);
    model1->add(f6);
    auto it = model1->beginFlow();
    int countFlow = 0;
    while(it != model1->endFlow()){
        countFlow++;
        it++;
    }
    assert(countFlow == 6);
    if(countFlow == 6){
        delete model1;
        delete sys1;
        delete sys2;
        delete sys3;
        delete sys4;
        delete sys5;
        delete f1;
        delete f2;
        delete f3;
        delete f4;
        delete f5;
        delete f6;
        return true;
    }
    else{
        delete model1;
        delete sys1;
        delete sys2;
        delete sys3;
        delete sys4;
        delete sys5;
        delete f1;
        delete f2;
        delete f3;
        delete f4;
        delete f5;
        delete f6;
        return false;
    }
}

bool unitEraseTest(){
    auto sys1 = new SystemImpl(100);
    auto sys2 = new SystemImpl(0);
    auto sys3 = new SystemImpl(100);
    auto sys4 = new SystemImpl(0);
    auto sys5 = new SystemImpl(0);
    auto f1 = new ExponentialFlow("f1", sys1, sys2);
    auto f2 = new ExponentialFlow("f2", sys1, sys3);
    auto f3 = new ExponentialFlow("f3", sys2, sys3);
    auto f4 = new ExponentialFlow("f4", sys2, sys5);
    auto f5 = new ExponentialFlow("f5", sys3, sys4);
    auto f6 = new ExponentialFlow("f6", sys4, sys1);
    auto model1 = new ModelImpl(0, 100, 1);
    model1->add(f1);
    model1->add(f2);
    model1->add(f3);
    model1->add(f4);
    model1->add(f5);
    model1->add(f6);
    model1->erase(f6);
    model1->erase(f1);
    auto it = model1->beginFlow();
    int countFlow = 0;
    while(it != model1->endFlow()){
        countFlow++;
        it++;
    }
    if (countFlow == 4){
        delete model1;
        delete sys1;
        delete sys2;
        delete sys3;
        delete sys4;
        delete sys5;
        delete f1;
        delete f2;
        delete f3;
        delete f4;
        delete f5;
        delete f6;
        return true;
    }
    else{
        delete model1;
        delete sys1;
        delete sys2;
        delete sys3;
        delete sys4;
        delete sys5;
        delete f1;
        delete f2;
        delete f3;
        delete f4;
        delete f5;
        delete f6;
        return false;
    }

}


bool unitOperatorEqualTest(Model* model1){
    Model* m1 = new ModelImpl("name", 0, 100, 1);
    m1 = model1;
    if(m1 == model1){
        return true;
    }
    else{
        return false;
    }

}


bool unitCopyConstructor(Model* model1){
    Model* m1 = new ModelImpl(*model1);
    if(m1 == model1){
        return true;
    }
    else{
        return false;
    }
}



void unitaryModelTest(){

    int success = 0;
    int fails = 0;

    auto sys1 = new SystemImpl(100);
    auto sys2 = new SystemImpl(0);
    auto sys3 = new SystemImpl(100);
    auto sys4 = new SystemImpl(0);
    auto sys5 = new SystemImpl(0);
    auto f1 = new ExponentialFlow("f1", sys1, sys2);
    auto f2 = new ExponentialFlow("f2", sys1, sys3);
    auto f3 = new ExponentialFlow("f3", sys2, sys3);
    auto f4 = new ExponentialFlow("f4", sys2, sys5);
    auto f5 = new ExponentialFlow("f5", sys3, sys4);
    auto f6 = new ExponentialFlow("f6", sys4, sys1);
    auto model1 = new ModelImpl(0, 100, 1);
    model1->add(f1);
    model1->add(f2);
    model1->add(f3);
    model1->add(f4);
    model1->add(f5);
    model1->add(f6);
    auto it = model1->beginFlow();
    int countFlow = 0;
    while(it != model1->endFlow()){
        countFlow++;
        it++;
    }
    assert(countFlow == 6);
    model1->execute();
    model1->report();
    assert(fabs(sys1->getResource() - 31.8513) < 0.0001);
    assert(fabs(sys2->getResource() - 18.4003) < 0.0001);
    assert(fabs(sys3->getResource() - 77.1143) < 0.0001);
    assert(fabs(sys4->getResource() - 56.1728) < 0.0001);
    assert(fabs(sys5->getResource() - 16.4612) < 0.0001);
    model1->erase(f6);
    model1->erase(f1);
    it = model1->beginFlow();
    countFlow = 0;
    while(it != model1->endFlow()){
        countFlow++;
        it++;
    }
    assert(countFlow == 4);
    model1->getFlowNames();
    model1->execute();
    model1->report();
    delete model1;


    if(unitModelName("modelName")){
        cout << "Model name passed!" << endl;
        success++;
    }
    else{
        cout << "Model name not passed!" << endl;
        fails++;
    }


    int v1 = 0;
    if(unitInitTimeTest(v1)){
        cout << "Model init time passed!" << endl;
        success++;
    }
    else{
        cout << "Model init time not passed!" << endl;
        fails++;
    }

    int v2 = 100;
    if(unitFinalTimeTest(v2)){
        cout << "Model final time passed!" << endl;
        success++;
    }
    else{
        cout << "Model final time not passed!" << endl;
        fails++;
    }

    int inc = 1;
    if(unitIncrementTest(inc)){
        cout << "Model increment passed!" << endl;
        success++;
    }
    else{
        cout << "Model increment not passed!" << endl;
        fails++;
    }

    if(unitAddTest()){
        cout << "Model add passed!" << endl;
        success++;
    }
    else{
        cout << "Model add not passed!" << endl;
        fails++;
    }

    if(unitEraseTest()){
        cout << "Model erase passed!" << endl;
        success++;
    }
    else{
        cout << "Model erase not passed!" << endl;
        fails++;
    }

    if(unitOperatorEqualTest(model1)){
        cout << "Model equal passed!" << endl;
        success++;
    }
    else{
        cout << "Model equal not passed!" << endl;
        fails++;
    }

    if(unitCopyConstructor(model1)){
        cout << "Model copy construct passed!" << endl;
        success++;
    }
    else{
        cout << "Model copy constructor not passed!" << endl;
        fails++;
    }


    cout << "TEST MODEL RESULTS: " << endl;
    cout << "TOTAL TESTS: " << success + fails << endl;
    cout << "SUCCESS: " << success << endl;
    cout << "FAILS: " << fails << endl;

}

#endif //API_SINGLETON_UNIT_MODEL_H
