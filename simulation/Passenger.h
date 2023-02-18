#pragma once
class Passenger
{
private:
    int id; // 乘客编号
    int source; // 出发前楼层
    int destination; // 目标楼层
    int times; // 乘梯次数 每位乘客乘坐过 L 次（每人的 L 值不同，在产生乘客时随机地在 1~10 次之间确定）
    int ride_speed; // 乘客上电梯的速度 (T: 2-10)
    int arriving_time; // 到达会展中心的时间 (M: 0<M<10)

public:
    Passenger(int id, int arriving_time, int ride_speed); // 构造函数

    void press_button();

    friend class Building; // 声明建筑类为友元类，可以访问私有成员变量和函数
    friend class Elevator; // 声明电梯类为友元类，可以访问私有成员变量和函数
};
