//
// Created by radoslav on 08.06.17.
//

#ifndef REFA_SERIALIZABLE_H
#define REFA_SERIALIZABLE_H

#include <iostream>

class Serializable {
public:
    virtual void serialize(std::ostream &out) const = 0;
};


#endif //REFA_SERIALIZABLE_H
