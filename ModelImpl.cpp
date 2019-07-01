//
// Created by Frederico on 07/06/19.
//

#include "ModelImpl.h"


ModelImpl::ModelImpl(){}
ModelImpl::ModelImpl(int timeIni, int timeFin, int increment): timeIni(timeIni), timeFin(timeFin), increment(increment){}
ModelImpl::ModelImpl(const string& name, int timeIni, int timeFin, int increment): name(name), timeIni(timeIni), timeFin(timeFin), increment(increment){}
ModelImpl::~ModelImpl(){}

ModelImpl::ModelImpl(Model &other) {
    this->setName(other.getName());
    this->setIncrement((other.getIncrement()));
    this->setTimeIni(other.getTimeIni());
    this->setTimeFin(other.getTimeFin());
    this->Flows.clear();
    this->Systems.clear();
    FlowIterator it = other.beginFlow();
    SystemIterator it2 = other.beginSystem();
    while(it != other.endFlow()){
        this->add(*(it));
        it++;
    }

    while(it2 != other.endSystem()){
        this->add(*(it2));
        it2++;
    }
}

Model& ModelImpl::operator=(Model &other){
    this->setName(other.getName());
    this->setIncrement((other.getIncrement()));
    this->setTimeIni(other.getTimeIni());
    this->setTimeFin(other.getTimeFin());
    FlowIterator it = other.beginFlow();
    SystemIterator it2 = other.beginSystem();
    while(it != other.endFlow()){
        this->add(*(it));
        it++;
    }

    while(it2 != other.endSystem()){
        this->add(*(it2));
        it2++;
    }
    return (*this);
}


//SINGLETON

ModelImpl* ModelImpl::_instance = 0;

ModelImpl* ModelImpl::instance() {
    if(_instance == 0){
        _instance = new ModelImpl();
    }
    return _instance;
}


//METHOD FACTORY

System* ModelImpl::createSystem(const string& name, double resource){
    System* s = new SystemImpl(name, resource);
    this->add(s);
    return s;
}

Model* Model::createModel(const string& name, int timeIni, int timeFin, int increment){
    return ModelImpl::createModel(name, timeIni, timeFin, increment);
}


Model* ModelImpl::createModel(const string& name, int timeIni, int timeFin, int increment) {
    ModelImpl* m1 = ModelImpl::instance();
    m1->instance()->setName(name);
    m1->instance()->setTimeIni(timeIni);
    m1->instance()->setTimeFin(timeFin);
    m1->instance()->setIncrement(increment);
    return m1;
}


void ModelImpl::setTimeIni(int time){
    this->timeIni = time;
}

const int ModelImpl::getTimeIni() const {
    return timeIni;
}

void ModelImpl::setTimeFin(int time){
    this->timeFin = time;
}

const int ModelImpl::getTimeFin() const{
    return timeFin;
}

void ModelImpl::add(Flow* f){
    this->Flows.push_back(f);
}

void ModelImpl::add(System* s){
    this->Systems.push_back(s);
}


void ModelImpl::execute(){
    vector<double> resources;
    int j = 0;
    for(int i = getTimeIni(); i < getTimeFin();i += getIncrement()){
        for(FlowIterator it = beginFlow(); it != endFlow(); it++){
            resources.push_back((*it)->execute());
        }
        int k = 0;
        for(FlowIterator it1 = beginFlow(); it1 != endFlow(); it1++){
            System* sourceSystem = ModelImpl::Flows[k]->getSourceSystem();
            sourceSystem->setResource(sourceSystem->getResource() - resources[j]);
            Flows[k]->setSourceSystem(sourceSystem);


            System* destinySystem = ModelImpl::Flows[k]->getDestinySystem();
            destinySystem->setResource(destinySystem->getResource() + resources[j]);
            Flows[k]->setDestinySystem(destinySystem);
            k++;
            j++;
        }
    }
}

void ModelImpl::report(){
    FlowIterator it;
    it = beginFlow();
    int i = 0;
    while(it != endFlow()){
        cout << "Flow " << i << endl;
        cout << "Source Resource: " << Flows[i]->getSourceSystem()->getResource() << endl;
        cout << "Destiny Resource: " << Flows[i]->getDestinySystem()->getResource() << endl;
        i++;
        it++;
    }

}

int ModelImpl::getIncrement() const {
    return increment;
}

void ModelImpl::setIncrement(int increment) {
    ModelImpl::increment = increment;
}

const string &ModelImpl::getName() const {
    return name;
}

void ModelImpl::setName(const string &name) {
    ModelImpl::name = name;
}


void ModelImpl::erase(Flow* toDelete) {
    auto it = Flows.begin();
    int i = 0;
    while(it != Flows.end()){
        if(toDelete->getName() == Flows[i]->getName()){
            Flows.erase(it);
            return;
        }
        i++;
        it++;
    }
    cout << "Flow " << toDelete->getName() << " not found on Model!" << endl;
}

void ModelImpl::erase(System* toDelete){
    auto it = beginSystem();
    int i = 0;
    while(it != endSystem()){
        if(toDelete->getName() == Systems.at(i)->getName()){
            Systems.erase(it);
            return;
        }
        i++;
        it++;
    }
}

void ModelImpl::getFlowNames() {
    auto it = beginFlow();
    int i = 0;
    while(it != endFlow()){
        cout << Flows[i]->getName() << endl;
        i++;
        it++;
    }
}
