#pragma once
#include <vector>
#include "Elevator.h"
#include "Passenger.h"
using namespace std;

class Building
{
    private:
        const static int floors = 40; // 楼层数量
        const static int elevators = 10; // 电梯数量

        vector<Elevator> elevator_list;   // 电梯列表
        vector<Passenger> passenger_list; // 乘客列表
        static vector<Passenger> waiting_list[floors]; // 各个楼层的乘客的等待列表
        static bool up_button[elevators]; // 上行按钮状态
        static bool down_button[elevators]; // 下行按钮状态

        static bool is_valid(Elevator e, Passenger p); // 判断电梯是否能够到达乘客的目标楼层
        Elevator find_elevator(Passenger p); // 找到最合适的电梯
        void generate_passengers(int n, int m, int k, int s, int t); // 随机生成n位乘客，在m分钟内到达一楼

    public:
        Building(); // 构造函数
        void simulate(); // 模拟仿真过程

        friend class Passenger; // 声明乘客类为友元类，可以访问私有成员变量和函数
        friend class Elevator; // 声明电梯类为友元类，可以访问私有成员变量和函数
};

