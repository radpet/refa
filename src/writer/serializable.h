//
// Created by radoslav on 08.06.17.
//

#ifndef REFA_SERIALIZABLE_H
#define REFA_SERIALIZABLE_H


class Serializable {
    virtual bool serialize() = 0;

    virtual ~Serializable();
};


#endif //REFA_SERIALIZABLE_H
