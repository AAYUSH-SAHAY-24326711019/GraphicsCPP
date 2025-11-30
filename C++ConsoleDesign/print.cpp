#include "print.h"
#include <iostream>
using namespace std;

void println(){
    cout<<"\n";
    return;
}

int println(int input){
    cout<<input<<"\n";
    return 5;
}

float println(float input){
    cout<<input<<"\n";
    return 5.0f;
}

char println(char input){
    cout<<input<<"\n";
    return '\0';
}