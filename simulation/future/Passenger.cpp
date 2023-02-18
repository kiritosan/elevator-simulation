#include "Passenger.h"
#include "Passenger.h"
#include "Building.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>

using namespace std;

// 实现乘客类的构造函数
Passenger::Passenger(int id, int times) {
    this->id = id; // 设置乘客编号
    // this->source = rand() % floors + 1; // 随机设置出发楼层
    this->source = 1; // 设置初始出发楼层为1
    this->destination = rand() % Building::floors + 1; // 随机设置目标楼层
}

// 实现乘客类的按电梯按钮的函数
void Passenger::press_button() {
    cout << "乘客" << id << "在" << source << "层按了电梯按钮。" << endl;
    // 根据出发楼层和目标楼层判断按上行按钮还是下行按钮
    if (source < destination) {
        Building::waiting_list[source].push_back(*this); // 将乘客加入等待列表
        Building::up_button[source] = true; // 将上行按钮设为亮
    }
    else if (source > destination) {
        Building::waiting_list[source].push_back(*this); // 将乘客加入等待列表
        Building::down_button[source] = true; // 将下行按钮设为亮
    }
}

int main() {
    cout << "test" << endl;
    return 0;
}