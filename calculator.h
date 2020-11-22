
#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <string>

class Calculator{
public:
    Calculator(int values);
    Calculator(const Calculator &rhs);
    ~Calculator();
    const Calculator &operator=(const Calculator &rhs);
    std::string* storedExpression;
    double process(std::string userInput, double prevValue);
    void print();
    size_t getStored();
    void setStore(size_t newStored);

private:
    size_t stored;
};

#endif // CALCULATOR_H_INCLUDED
