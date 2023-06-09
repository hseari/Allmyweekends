#include "postfixcalc.h"

int calculator::calc(const std::string& exp) {
    std::string num;
    for (char ch : exp) {
        if (std::isdigit(ch)) {  //���� �����
            num += ch;         //�� �������� � �������
        }
        else if (ch == ' ') {  //������ ������ ������� ������������
            if (!num.empty()) {
                st.push(std::stoi(num));   //������������ ������� � ��� � ��������� � ����
                num.clear();               //��������
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {   //���� ����
            if (st.empty()) {
                st.clear();
                throw "������: ������������ ���������";
            }
            int a = st.pop<int>();         //������� � ������ ������� � ���������� � ����������
            if (st.empty()) {
                st.clear();
                throw "������: ������������ ���������";
            }
            int b = st.pop<int>();
            if (ch == '+') st.push(a + b);   //��������� � ������ �����
            else if (ch == '-') st.push(b - a);    //��������� �������� � �.�.
            else if (ch == '*') st.push(a * b);
            else if (ch == '/') {
                if (a == 0) {
                    st.clear();
                    throw "������: ������� �� ����.";
                }
                st.push(b / a);
            }
        }
        else if (ch == ' ') continue;     //���� ������ ������ �� ���� ������
        else {
            st.clear();
            throw "������: ����������� ����.";
        }
    }

    if (st.empty() || st.get_size() > 1) {    //���� ���� ���� ��� ��� ���-�� �������� ����� ������, �� ������� ������
        st.clear();
        throw "������: ������������ ���������.";
    }

    int z = st.get_top<int>();
    st.clear();     //������ ����
    return z;
}