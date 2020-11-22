#include <iostream>
#include "calculator.h"
#include "stddef.h"
#include <cmath>

Calculator::Calculator(int values): storedExpression(new std::string[values]), stored(0){

}

Calculator::Calculator(const Calculator &rhs){
    if (storedExpression != nullptr){
        storedExpression = new std::string[rhs.stored];
    }
}

Calculator::~Calculator(){
    delete[] storedExpression;
    storedExpression = nullptr;
    stored = 0;
}
const Calculator &Calculator::operator=(const Calculator &rhs){
    if (this != &rhs){
        Calculator temp = rhs;
        std::swap(storedExpression, temp.storedExpression);
        std::swap(stored, temp.stored);
    }
    return *this;
}

double Calculator::process(std::string userInput, double prevValue){
    std::string cleansedStr;
    for (size_t i = 0; i < userInput.size(); i++){
        if (userInput[i] == '=' || userInput[i] == ' ' || userInput[i] == '(' || userInput[i] == ')'){

        }else{
            cleansedStr += userInput[i];
        }
    }
    double value = std::stoi(cleansedStr.substr(1, cleansedStr.length() - 1));
    if (cleansedStr[0] == '^'){
        return pow(prevValue, value);
    }else if (cleansedStr[0] == '*' || cleansedStr[0] == '/'){
        if (cleansedStr[0] == '*'){
            return prevValue * value;
        }else{
            if (value == 0){
                std::exit(0);
            }else{
                return prevValue/value;
            }
        }
    }else if (cleansedStr[0] == '+' || cleansedStr[0] == '-'){
        if (cleansedStr[0] == '+'){
            return prevValue + value;
        }else{
            return prevValue - value;
        }
    }else{
        std::cout << "Must start with an operator!" << std::endl;
        return -100000;

    }
    return -100000;

}

void Calculator::setStore(size_t newStored){
    stored = newStored;
}

size_t Calculator::getStored(){
    return Calculator::stored;
}

void Calculator::print(){
    std::cout << "You have " << Calculator::stored << " expressions. " << std::endl;

}



