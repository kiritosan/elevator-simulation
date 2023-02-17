#include "Elevator.h"
#include <iostream>
#include "Building.h"
using namespace std;

// 实现电梯类的构造函数
Elevator::Elevator(int id, int max_capacity) {
    this->id = id; // 设置电梯编号
    this->max_capacity = max_capacity; // 设置最大载客量
    this->current_floor = rand() % Building::floors + 1; // 随机设置当前楼层
    this->direction = 0; // 初始运行方向为停止
}

// 实现电梯类的移动函数
void Elevator::move() {
    if (direction == 1) { // 如果运行方向为上行
        current_floor++; // 当前楼层加一
        cout << "电梯" << id << "上升到" << current_floor << "层。" << endl;
    }
    else if (direction == -1) { // 如果运行方向为下行
        current_floor--; // 当前楼层减一
        cout << "电梯" << id << "下降到" << current_floor << "层。" << endl;
    }
}

// 实现电梯类的移动函数
void Elevator::move() {
    // 如果请求列表为空，则停止运行
    if (request_list.empty()) {
        direction = 0;
        return;
    }
    // 如果当前楼层在请求列表中，则停止并开门
    if (find(request_list.begin(), request_list.end(), current_floor) != request_list.end()) {
        direction = 0;
        open();
        // 从请求列表中删除当前楼层
        request_list.erase(find(request_list.begin(), request_list.end(), current_floor));
        return;
    }
    // 根据运行方向移动一层
    if (direction == 1) {
        current_floor++;
    }
    else if (direction == -1) {
        current_floor--;
    }
}

// 实现电梯类的关闭电梯门函数
void Elevator::close() {
    cout << "电梯" << id << "在" << current_floor << "层关门。" << endl;
    // 根据当前楼层和请求列表更新运行方向
    if (!request_list.empty()) {
        if (request_list.front() > current_floor) {
            direction = 1; // 设置运行方向为上行
        }
        else if (request_list.front() < current_floor) {
            direction = -1; // 设置运行方向为下行
        }
    }
}

// 实现电梯类的开门函数
void Elevator::open() {
    cout << "电梯" << id << "在" << current_floor << "层开门。" << endl;
    // 遍历乘客列表，如果有乘客到达目标楼层，则卸载该乘客
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers[i].destination == current_floor) {
            unload(passengers[i]);
        }
    }
    // 遍历等待列表，如果有乘客在当前楼层等待合适的电梯，则装载该乘客
    for (int i = 0; i < Building::waiting_list[current_floor].size(); i++) {
        if (Building::is_valid(*this, Building::waiting_list[current_floor][i]) && passengers.size() < max_capacity) {
            load(Building::waiting_list[current_floor][i]);
        }
    }
}

// 实现电梯类的装载乘客函数
void Elevator::load(Passenger p) {
    cout << "电梯" << id << "在" << current_floor << "层装载了乘客" << p.id << "。" << endl;
    passengers.push_back(p); // 将乘客加入乘客列表
    // 根据乘客目标楼层更新电梯运行方向
    if (p.destination > current_floor) {
        direction = 1; // 设置运行方向为上行
    }
    else if (p.destination < current_floor) {
        direction = -1; // 设置运行方向为下行
    }
}

// 实现电梯类的卸载乘客函数
void Elevator::unload(Passenger p) {
    cout << "电梯" << id << "在" << current_floor << "层卸载了乘客" << p.id << "。" << endl;
    // 从乘客列表中删除该乘客
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers[i].id == p.id) {
            passengers.erase(passengers.begin() + i);
            break;
        }
    }
}

// 实现电梯类的添加请求函数
void Elevator::add_request(int floor) {
    cout << "电梯" << id << "收到了来自" << floor << "层的请求。" << endl;
    // 将该楼层加入请求列表
    request_list.push_back(floor);
    // 根据当前楼层和请求楼层更新电梯运行方向
    if (floor > current_floor) {
        direction = 1; // 设置运行方向为上行
    }
    else if (floor < current_floor) {
        direction = -1; // 设置运行方向为下行
    }
}



