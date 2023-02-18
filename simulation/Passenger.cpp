#include "Passenger.h"
#include <iostream>
#include "Building.h"

using namespace std;

Passenger::Passenger(int id, int arriving_time, int ride_speed)
{
	this->id = id;
    this->ride_speed = ride_speed;
    this->arriving_time = arriving_time;
    times = rand() % 10 + 1; // 随机生成每个乘客乘坐次数(L: 1-10)
	source = 1; // 原楼层设为1
    destination = rand() % 40 + 1; // 目标楼层在1-40范围内随机取值
	cout << "乘客 " << id << "已生成" << endl;
    cout << "目标楼层为 " << destination << endl;
    cout << "到达时间为 " << arriving_time << endl;
}

void Passenger::press_button()
{
    cout << "乘客" << id << "在" << source << "层按了电梯按钮。" << endl;
    // 根据出发楼层和目标楼层判断按上行按钮还是下行按钮
    if (source < destination) {
        Building::waiting_list[source - 1].push_back(*this); // 将乘客加入等待列表
        // Building::up_button[source] = true; // 将上行按钮设为亮
    }
    else if (source > destination) {
        Building::waiting_list[source - 1].push_back(*this); // 将乘客加入等待列表
        // Building::down_button[source] = true; // 将下行按钮设为亮
    }
}
