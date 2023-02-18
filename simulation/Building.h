#pragma once
#include <vector>
#include "Elevator.h"
#include "Passenger.h"

class Building
{
    private:
        int floors; // 楼层数量
        int elevators; // 电梯数量
        int timers; // 系统计时器

        vector<Elevator> elevator_list;   // 电梯列表
        vector<Passenger> passenger_list; // 乘客列表
        static bool *up_button; // 上行按钮状态
        static bool *down_button; // 下行按钮状态
        static vector<Passenger> waiting_list[40]; // 各个楼层的乘客的等待列表

        static bool is_valid(Elevator e, Passenger p); // 判断电梯是否能够到达乘客的目标楼层
        void find_elevator(Passenger p); // 找到最合适的电梯
        void generate_passengers(int N, int M, int T); // 随机生成n位乘客，在m分钟内到达一楼

    public:

        Building(int floors, int elevators); // 构造函数
        static void simulate(); // 模拟仿真过程
        int get_timers(); // 得到当前系统经过的时间

        friend class Passenger; // 声明乘客类为友元类，可以访问私有成员变量和函数
        friend class Elevator; // 声明电梯类为友元类，可以访问私有成员变量和函数
};