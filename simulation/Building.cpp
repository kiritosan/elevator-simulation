#include "Building.h"
#include <iostream>
#include "Test.h"

using namespace std;

Building::Building(int floors, int elevators)
{
	// up_button = new bool[elevators];
	// down_button = new bool[elevators];

	this->floors = floors;
	this->elevators = elevators;
	// int Building::timers = 0; // 系统计时器初始化
	cout << "Building 已生成" << endl;
	cout << "楼层数为 " << floors << endl;
	cout << "电梯数量为 " << elevators << endl;
}

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

// 有 N 位乘客（0 < N < 1000）在 M 分钟（0 < M < 10）内随机地达到该国际会展中心的 1 层，开始乘梯活动。
void Building::generate_passengers(int N, int M, int T) // N：乘客数量 M: 乘客到达会展中心时间 T：乘客从楼层上下电梯需要的时间
{
	for (int i = 0; i < N; i++)
	{
		Passenger p(i, M, T);
		passenger_list.push_back(p);
	}
}

void Building::find_elevator(Passenger p) {
	for (auto& p: passenger_list)
	{
		for (auto& e : elevator_list) {
			if (is_valid(e, p)) {
				p.press_button();

				int dir;
				if (p.destination - p.source > 0) {
					dir = 1;
				}
				else if (p.destination - p.source < 0) {
					dir = -1;
				}
				else {
					dir = 0;
				}
				if (e.request_list.size() <= e.max_capacity) {
					e.request_list.push_back(dir);
				}
			}
		}
	}
}

// 得到当前系统经过的时间
int Building::get_timers() {
	return timers;
}

// 进行系统的模拟
void Building::simulate() {

	// 生成需要的对象>>>>>>>>>>>>
	cout << "开始生成会展中心>>>>>>>>>>>>" << endl;
	Building b(40, 10); //生成国际会展中心
	cout << "生成会展中心结束<<<<<<<<<<<<" << endl;

	// 生成电梯
	int K, S, N, M, T;
	cout << "请输入电梯的最大载客量(10-18)：";
	cout << endl;
	cin >> K;
	cout << "请输入电梯的运行速度(1-5)：";
	cout << endl;
	cin >> S;

	cout << "开始生成电梯>>>>>>>>>>>>" << endl;
	vector<Elevator> elevator_list;
	for (int i = 0; i < 10; i++) // 生成十个电梯，并存入一个列表里
	{
		Elevator e(i, K, S); // 创建一个电梯对象，传入id参数
		elevator_list.push_back(e); // 把电梯加入到向量中
	}
	cout << "生成电梯结束<<<<<<<<<<<<" << endl;

	cout << "请输入乘客的数量（0 < N < 1000）：";
	cout << endl;
	cin >> N;
	cout << "请输入乘客到达会展中心的时间（0 < M < 10）：";
	cout << endl;
	cin >> M;
	cout << "请输入每人上下时间为 （2 << T << 10）：";
	cout << endl;
	cin >> T;

	cout << "开始生成乘客>>>>>>>>>>>>" << endl;
	b.generate_passengers(N, M, T); // 生成乘客到 passenger_list
	cout << "生成乘客结束<<<<<<<<<<<<" << endl;
	// 生成对象工作结束<<<<<<<<<<<<

	// 开始模拟
	cout << "开始进行电梯仿真模拟" << endl;

	// 进行系统时间计数
	int last_time = clock();
	int timers = b.get_timers();

	while (true) {
		int current_time = clock();
		if (current_time - last_time >= 1000) {
			cout << "系统时间已经过" << ++timers << "秒" << endl;
			last_time = current_time;

			for (auto& passenger : b.passenger_list)
			{
				if (passenger.arriving_time == timers) {
					cout << "乘客" << passenger.id << "已经到达会展中心" << endl;
					b.find_elevator(passenger);
					passenger.press_button();
				}
				
			}

			// 每过S秒，执行一次elevator的move
			if ((timers - 1) % S == 0) {
				for (auto& elevator : elevator_list)
				{
					elevator.move();
				}
			}
		}

	}
}