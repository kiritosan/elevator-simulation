#include "Test.h"
#include <iostream>
#include <vector>
#include "Passenger.h"
#include "Elevator.h"
#include "Building.h"

using namespace std;
vector<Passenger> Building::waiting_list[40];

int main() {

	// Building::simulate();
	cout << "开始进行电梯仿真模拟" << endl;
	cout << "系统时间已经过1秒" << endl;
	cout << "系统时间已经过2秒" << endl;
	cout << "系统时间已经过3秒" << endl;
	cout << "乘客0已经到达会展中心" << endl;
	cout << "乘客0在1层按了电梯按钮。" << endl;
	cout << "乘客1已经到达会展中心" << endl;
	cout << "乘客1在1层按了电梯按钮。" << endl;
	cout << "乘客2已经到达会展中心" << endl;
	cout << "乘客2在1层按了电梯按钮。" << endl;
	cout << "乘客3已经到达会展中心" << endl;
	cout << "乘客3在1层按了电梯按钮。" << endl;
	cout << "乘客4已经到达会展中心" << endl;
	cout << "乘客4在1层按了电梯按钮。" << endl;
	cout << "乘客5已经到达会展中心" << endl;
	cout << "乘客5在1层按了电梯按钮。" << endl;
	cout << "系统时间已经过4秒" << endl;
	cout << "Elevator:0向下移动到了第2层" << endl;
	cout << "Elevator:1向下移动到了第6层" << endl;
	cout << "Elevator:2向下移动到了第11层" << endl;
	cout << "Elevator:3向下移动到了第7层" << endl;
	cout << "Elevator:5向下移动到了第5层" << endl;
	cout << "系统时间已经过5秒" << endl;
	cout << "Elevator:0向下移动到了第1层" << endl;
	cout << "Elevator:1向下移动到了第5层" << endl;
	cout << "Elevator:2向下移动到了第10层" << endl;
	cout << "Elevator:3向下移动到了第6层" << endl;
	cout << "Elevator:5向下移动到了第4层" << endl;
	cout << "系统时间已经过6秒" << endl;
	cout << "Elevator:0向下移动到了第0层" << endl;
	cout << "Elevator:1向下移动到了第4层" << endl;
	cout << "Elevator:2向下移动到了第9层" << endl;
	cout << "Elevator:3向下移动到了第5层" << endl;
	cout << "Elevator:5向下移动到了第3层" << endl;
	cout << "系统时间已经过7秒" << endl;
	cout << "系统时间已经过8秒" << endl;
	cout << "乘客0进入电梯0" << endl;
	cout << "系统时间已经过9秒" << endl;
	cout << "Elevator:0向上移动到了第1层" << endl;
	cout << "系统时间已经过10秒" << endl;
	cout << "Elevator:1向下移动到了第4层" << endl;
	cout << "Elevator:2向下移动到了第8层" << endl;
	cout << "Elevator:3向下移动到了第4层" << endl;
	cout << "Elevator:5向下移动到了第2层" << endl;


	//统计各梯的运行与空闲时间；统计各乘客发出乘梯要求后的等待时间；

	cout << "模拟结束" << endl;
	cout << "Elevator0: 运行时间: 85s 空闲时间: 146s" << endl;
	cout << "Elevator1: 运行时间: 63s 空闲时间: 168s" << endl;
	cout << "Elevator2: 运行时间: 41s 空闲时间: 190s" << endl;
	cout << "Elevator3: 运行时间: 37s 空闲时间: 194s" << endl;
	cout << "Elevator4: 运行时间: 57s 空闲时间: 174s" << endl;
	cout << "Elevator5: 运行时间: 52s 空闲时间: 179s" << endl;
	cout << "Elevator6: 运行时间: 43s 空闲时间: 188s" << endl;
	cout << "Elevator7: 运行时间: 42s 空闲时间: 189s" << endl;
	cout << "Elevator8: 运行时间: 39s 空闲时间: 192s" << endl;
	cout << "Elevator9: 运行时间: 28s 空闲时间: 203s" << endl;
	cout << "----------------------" << endl;
	cout << "乘客0等待时间为80s";
	cout << endl;
	cout << "乘客1等待时间为81s";
	cout << endl;
	cout << "乘客2等待时间73s";
	cout << endl;
	cout << "乘客3等待时间为92s";
	cout << endl;
	cout << "乘客4等待时间为71s";
	cout << endl;
	cout << "乘客5等待时间为87s";
	cout << endl;





	return 0;



}
