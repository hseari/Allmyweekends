#include "postfixcalc.h"

int calculator::calc(const std::string& exp) {
    std::string num;
    for (char ch : exp) {
        if (std::isdigit(ch)) {  //если число
            num += ch;         //то собираем в строчку
        }
        else if (ch == ' ') {  //первый пробел считаем разделителем
            if (!num.empty()) {
                st.push(std::stoi(num));   //конвертируем строчку в инт и добавляем в стек
                num.clear();               //обнуляем
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {   //если знак
            if (st.empty()) {
                st.clear();
                throw "Ошибка: некорректное выражение";
            }
            int a = st.pop<int>();         //удаляем с начала элемент и записываем в переменную
            if (st.empty()) {
                st.clear();
                throw "Ошибка: некорректное выражение";
            }
            int b = st.pop<int>();
            if (ch == '+') st.push(a + b);   //добавляем в начало сумму
            else if (ch == '-') st.push(b - a);    //добавляем разность и т.д.
            else if (ch == '*') st.push(a * b);
            else if (ch == '/') {
                if (a == 0) {
                    st.clear();
                    throw "Ошибка: деление на ноль.";
                }
                st.push(b / a);
            }
        }
        else if (ch == ' ') continue;     //если лишний пробел то идем дальше
        else {
            st.clear();
            throw "Ошибка: посторонний знак.";
        }
    }

    if (st.empty() || st.get_size() > 1) {    //если стек пуст или там что-то осталось кроме ответа, то выводим ошибку
        st.clear();
        throw "Ошибка: некорректное выражение.";
    }

    int z = st.get_top<int>();
    st.clear();     //чистим стэк
    return z;
}