#ifndef CLONABLE_H
#define CLONABLE_H

template<typename T>
class Cloneable {

    virtual T *clone() const = 0;

};


#endif