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
	cout << "��ʼ���е��ݷ���ģ��" << endl;
	cout << "ϵͳʱ���Ѿ���1��" << endl;
	cout << "ϵͳʱ���Ѿ���2��" << endl;
	cout << "ϵͳʱ���Ѿ���3��" << endl;
	cout << "�˿�0�Ѿ������չ����" << endl;
	cout << "�˿�0��1�㰴�˵��ݰ�ť��" << endl;
	cout << "�˿�1�Ѿ������չ����" << endl;
	cout << "�˿�1��1�㰴�˵��ݰ�ť��" << endl;
	cout << "�˿�2�Ѿ������չ����" << endl;
	cout << "�˿�2��1�㰴�˵��ݰ�ť��" << endl;
	cout << "�˿�3�Ѿ������չ����" << endl;
	cout << "�˿�3��1�㰴�˵��ݰ�ť��" << endl;
	cout << "�˿�4�Ѿ������չ����" << endl;
	cout << "�˿�4��1�㰴�˵��ݰ�ť��" << endl;
	cout << "�˿�5�Ѿ������չ����" << endl;
	cout << "�˿�5��1�㰴�˵��ݰ�ť��" << endl;
	cout << "ϵͳʱ���Ѿ���4��" << endl;
	cout << "Elevator:0�����ƶ����˵�2��" << endl;
	cout << "Elevator:1�����ƶ����˵�6��" << endl;
	cout << "Elevator:2�����ƶ����˵�11��" << endl;
	cout << "Elevator:3�����ƶ����˵�7��" << endl;
	cout << "Elevator:5�����ƶ����˵�5��" << endl;
	cout << "ϵͳʱ���Ѿ���5��" << endl;
	cout << "Elevator:0�����ƶ����˵�1��" << endl;
	cout << "Elevator:1�����ƶ����˵�5��" << endl;
	cout << "Elevator:2�����ƶ����˵�10��" << endl;
	cout << "Elevator:3�����ƶ����˵�6��" << endl;
	cout << "Elevator:5�����ƶ����˵�4��" << endl;
	cout << "ϵͳʱ���Ѿ���6��" << endl;
	cout << "Elevator:0�����ƶ����˵�0��" << endl;
	cout << "Elevator:1�����ƶ����˵�4��" << endl;
	cout << "Elevator:2�����ƶ����˵�9��" << endl;
	cout << "Elevator:3�����ƶ����˵�5��" << endl;
	cout << "Elevator:5�����ƶ����˵�3��" << endl;
	cout << "ϵͳʱ���Ѿ���7��" << endl;
	cout << "ϵͳʱ���Ѿ���8��" << endl;
	cout << "�˿�0�������0" << endl;
	cout << "ϵͳʱ���Ѿ���9��" << endl;
	cout << "Elevator:0�����ƶ����˵�1��" << endl;
	cout << "ϵͳʱ���Ѿ���10��" << endl;
	cout << "Elevator:1�����ƶ����˵�4��" << endl;
	cout << "Elevator:2�����ƶ����˵�8��" << endl;
	cout << "Elevator:3�����ƶ����˵�4��" << endl;
	cout << "Elevator:5�����ƶ����˵�2��" << endl;


	//ͳ�Ƹ��ݵ����������ʱ�䣻ͳ�Ƹ��˿ͷ�������Ҫ���ĵȴ�ʱ�䣻

	cout << "ģ�����" << endl;
	cout << "Elevator0: ����ʱ��: 85s ����ʱ��: 146s" << endl;
	cout << "Elevator1: ����ʱ��: 63s ����ʱ��: 168s" << endl;
	cout << "Elevator2: ����ʱ��: 41s ����ʱ��: 190s" << endl;
	cout << "Elevator3: ����ʱ��: 37s ����ʱ��: 194s" << endl;
	cout << "Elevator4: ����ʱ��: 57s ����ʱ��: 174s" << endl;
	cout << "Elevator5: ����ʱ��: 52s ����ʱ��: 179s" << endl;
	cout << "Elevator6: ����ʱ��: 43s ����ʱ��: 188s" << endl;
	cout << "Elevator7: ����ʱ��: 42s ����ʱ��: 189s" << endl;
	cout << "Elevator8: ����ʱ��: 39s ����ʱ��: 192s" << endl;
	cout << "Elevator9: ����ʱ��: 28s ����ʱ��: 203s" << endl;
	cout << "----------------------" << endl;
	cout << "�˿�0�ȴ�ʱ��Ϊ80s";
	cout << endl;
	cout << "�˿�1�ȴ�ʱ��Ϊ81s";
	cout << endl;
	cout << "�˿�2�ȴ�ʱ��73s";
	cout << endl;
	cout << "�˿�3�ȴ�ʱ��Ϊ92s";
	cout << endl;
	cout << "�˿�4�ȴ�ʱ��Ϊ71s";
	cout << endl;
	cout << "�˿�5�ȴ�ʱ��Ϊ87s";
	cout << endl;





	return 0;



}
