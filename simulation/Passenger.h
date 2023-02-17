#pragma once
class Passenger
{
    private:
        int id; // 乘客编号
        int source; // 出发前楼层
        static int destination; // 目标楼层
        int times; // 乘梯次数

    public:
        Passenger(int id, int times); // 构造函数

        void press_button();
        

        friend class Building; // 声明建筑类为友元类，可以访问私有成员变量和函数
        friend class Elevator; // 声明建筑类为友元类，可以访问私有成员变量和函数
};

