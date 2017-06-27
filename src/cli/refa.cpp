#include<iostream>
#include "arguments-parser.h"

int main(int argc, char *argv[]) {

    ArgumentsParser parser = ArgumentsParser(argc, argv);


    while(parser.next()){

    }
    return 0;
}