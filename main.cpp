#include <iostream>
#include "Calculator.h"
#include <string>

int main() {
    int sentinal = 0;
    do {
        int values;
        std::cout << "Please input the number of expressions: " << std::endl;
        std::cin >> values;
        if (values < 1){
            std::cout << "Number of expression should be larger than 1!" << std::endl;

        }else{
            Calculator calc = Calculator(values);
            for (size_t i = 0; i < values; i++){
                bool flag = true;
                double answer = 0;
                while (flag){
                    std::string userString;
                    std::cout << "Please input your expression. Press STOP when you want to terminate the expression. \n" << std::endl;
                    std::cout << answer;
                    std::cin >> userString;
                    if (userString == "STOP"){
                        calc.storedExpression[calc.getStored()] = std::to_string(answer);
                        flag = false;
                        break;
                    }
                    answer = calc.process(userString, answer);
                    std::cout << userString << " = " << answer << "\n";

                }
                calc.setStore(calc.getStored() + 1);
            }
        }
        std::cout << "Please press 1 to continue!" << std::endl;
        std::cin >> sentinal;
    } while (sentinal == 1);

    return 0;
}
