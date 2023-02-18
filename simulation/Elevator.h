#pragma once
#include "Passenger.h"
#include <vector>

using namespace std;

class Elevator
{
    private:
        int id; // 电梯编号
        int max_capacity; // 最大载客量
        int current_floor; // 当前楼层
        int direction; // 运行方向，1为上行，-1为下行，0为停止
        int speed; // 电梯运行速度 (S: 1-5)
        vector<Passenger> passengers; // 乘客列表
        vector<int> request_list; // 请求列表

    public:
        Elevator(int id, int max_capacity, int speed); // 构造函数
        void move(); // 移动函数
        void stop(); // 停止函数
        void open(); // 开门函数
        void close(); // 关门函数
        void load(Passenger passenger); // 装载乘客函数
        void unload(Passenger passenger); // 卸载乘客函数
        void add_request(int floor); // 添加请求函数
        void remove_request(int floor); // 移除请求函数

        friend class Building; // 声明建筑类为友元类，可以访问私有成员变量和函数
};