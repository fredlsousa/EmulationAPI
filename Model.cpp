//
// Created by Frederico on 08/05/19.
//


#include "Model.h"

Model::Model(){}
Model::Model(int timeIni, int timeFin, int increment): timeIni(timeIni), timeFin(timeFin), increment(increment){}
Model::Model(const string& name, int timeIni, int timeFin, int increment): name(name), timeIni(timeIni), timeFin(timeFin), increment(increment){}
Model::~Model(){}
Model::Model(Model &other) {
    this->setName(other.getName());
    this->setIncrement((other.getIncrement()));
    this->setTimeIni(other.getTimeIni());
    this->setTimeFin(other.getTimeFin());
    int i = 0;
    for(auto *elem: other.Flows){
        Flow* f = elem;
        this->Flows[i] = f;
        i++;
    }
}

Model& Model::operator=(Model &other){
    this->setName(other.getName());
    this->setIncrement((other.getIncrement()));
    this->setTimeIni(other.getTimeIni());
    this->setTimeFin(other.getTimeFin());
    int i = 0;
    for(auto *elem: other.Flows){
        Flow* f = elem;
        this->Flows[i] = f;
        i++;
    }
}

void Model::setTimeIni(int time){
    this->timeIni = time;
}

const int Model::getTimeIni() const {
    return timeIni;
}

void Model::setTimeFin(int time){
    this->timeFin = time;
}

const int Model::getTimeFin() const{
    return timeFin;
}

void Model::add(Flow* f){
    this->Flows.push_back(f);
}


void Model::execute(){
    vector<double> resources;
    int j = 0;
    //double valueResource = 0;
    for(int i = getTimeIni(); i < getTimeFin();i += getIncrement()){
        for(iterator it = begin(); it != end(); it++){
            //valueResource = Model::Flows[j]->execute();
            //resources.push_back(valueResource);
            resources.push_back((*it)->execute());
            //cout << "Value v: " << v << endl;
        }
        int k = 0;
        for(iterator it1 = begin(); it1 != Flows.end(); it1++){
            //valueResource = Model::Flows[k]->execute();
            System* sourceSystem = Model::Flows[k]->getSourceSystem();
            sourceSystem->setResource(sourceSystem->getResource() - resources[j]);
            //sourceSystem->setResource(sourceSystem->getResource() - valueResource);
            Flows[k]->setSourceSystem(sourceSystem);
            //cout << "Flow Source: " << Flows[k] << endl;


            System* destinySystem = Model::Flows[k]->getDestinySystem();
            destinySystem->setResource(destinySystem->getResource() + resources[j]);
            //destinySystem->setResource(destinySystem->getResource() + valueResource);
            Flows[k]->setDestinySystem(destinySystem);

            //cout << "Flow Destiny: " << Flows[k] << endl;
            k++;
            j++;
        }
    }
}

void Model::report(){
    iterator it;
    it = Flows.begin();
    int i = 0;
    while(it != Flows.end()){
        cout << "Flow " << i << endl;
        cout << "Source Resource: " << Flows[i]->getSourceSystem()->getResource() << endl;
        cout << "Destiny Resource: " << Flows[i]->getDestinySystem()->getResource() << endl;
        i++;
        it++;
    }

}

int Model::getIncrement() const {
    return increment;
}

void Model::setIncrement(int increment) {
    Model::increment = increment;
}

const string &Model::getName() const {
    return name;
}

void Model::setName(const string &name) {
    Model::name = name;
}


void Model::erase(Flow* toDelete) {     //when there's no name on the flow it'll delete the first
                                        //position because names are equal to ""
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

void Model::getFlowNames() {
    auto it = begin();
    int i = 0;
    while(it != end()){
        cout << Flows[i]->getName() << endl;
        i++;
        it++;
    }
}

bool Model::operator==(const Model &rhs) const {
    return timeIni == rhs.timeIni &&
           timeFin == rhs.timeFin &&
           increment == rhs.increment &&
           name == rhs.name &&
           Flows == rhs.Flows;
}

bool Model::operator!=(const Model &rhs) const {
    return !(rhs == *this);
}
