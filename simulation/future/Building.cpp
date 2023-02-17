#include "Building.h"
#include <iostream>

// 实现建筑类的判断电梯是否能够到达乘客目标楼层的函数
bool Building::is_valid(Elevator e, Passenger p) {
    // 根据电梯编号和乘客目标楼层判断是否符合运行规则
    switch (e.id) {
    case 0:
    case 1:
        return true; // E0、E1：可到达每层。
    case 2:
    case 3:
        return p.destination == 1 || (p.destination >= 25 && p.destination <= 40); // E2、E3：可到达 1、25~40 层。
    case 4:
    case 5:
        return p.destination >= 1 && p.destination <= 25; // E4、E5：可到达 1~25 层。
    case 6:
    case 7:
        return p.destination == 1 || p.destination % 2 == 0; // E6、E7：可到达偶数层和一层。
    default:
        return false; // 其他情况返回false。
    }
}













int main()
{
    std::cout << "Hello World!\n";
}