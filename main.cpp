#include <iostream>
#include "postfixcalc.h"
#include "converter_s.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::string exp;
    calculator c;
    �onverter conv;
    std::cout << "��� ������ �� ��������� ����������� ������ exit\n";

    while (exp != "exit") {
        std::cout << "���� ��������� ���������: ";
        std::getline(std::cin, exp);
        try {
            std::string postfixexp = conv.convert(exp);
            std::cout << "�����: " << c.calc(postfixexp) << std::endl;
        }
        catch (const char* error) {
            std::cout << error << std::endl;
        }
    }

    return 0;
}