#include "Building.h"
#include <iostream>

// ʵ�ֽ�������жϵ����Ƿ��ܹ�����˿�Ŀ��¥��ĺ���
bool Building::is_valid(Elevator e, Passenger p) {
    // ���ݵ��ݱ�źͳ˿�Ŀ��¥���ж��Ƿ�������й���
    switch (e.id) {
    case 0:
    case 1:
        return true; // E0��E1���ɵ���ÿ�㡣
    case 2:
    case 3:
        return p.destination == 1 || (p.destination >= 25 && p.destination <= 40); // E2��E3���ɵ��� 1��25~40 �㡣
    case 4:
    case 5:
        return p.destination >= 1 && p.destination <= 25; // E4��E5���ɵ��� 1~25 �㡣
    case 6:
    case 7:
        return p.destination == 1 || p.destination % 2 == 0; // E6��E7���ɵ���ż�����һ�㡣
    default:
        return false; // �����������false��
    }
}













int main()
{
    std::cout << "Hello World!\n";
}