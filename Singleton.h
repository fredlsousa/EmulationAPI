//
// Created by Frederico on 07/06/19.
//

#ifndef API_SINGLETON_SINGLETON_H
#define API_SINGLETON_SINGLETON_H

template<class T>

class Singleton{
public:
    static T& instance(){
        static T instance_;
        if(!instance_){
            instance_ = new T();
        }
        return instance_;
    }
    virtual ~Singleton(){}
protected:
    Singleton(){}
private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&) {return *this;}
};


#endif //API_SINGLETON_SINGLETON_H
