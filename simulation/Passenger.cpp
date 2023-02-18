#include "Passenger.h"
#include <iostream>
#include "Building.h"

using namespace std;

Passenger::Passenger(int id, int arriving_time, int ride_speed)
{
	this->id = id;
    this->ride_speed = ride_speed;
    this->arriving_time = arriving_time;
    times = rand() % 10 + 1; // �������ÿ���˿ͳ�������(L: 1-10)
	source = 1; // ԭ¥����Ϊ1
    destination = rand() % 40 + 1; // Ŀ��¥����1-40��Χ�����ȡֵ
	cout << "�˿� " << id << "������" << endl;
    cout << "Ŀ��¥��Ϊ " << destination << endl;
    cout << "����ʱ��Ϊ " << arriving_time << endl;
}

void Passenger::press_button()
{
    cout << "�˿�" << id << "��" << source << "�㰴�˵��ݰ�ť��" << endl;
    // ���ݳ���¥���Ŀ��¥���жϰ����а�ť�������а�ť
    if (source < destination) {
        Building::waiting_list[source - 1].push_back(*this); // ���˿ͼ���ȴ��б�
        // Building::up_button[source] = true; // �����а�ť��Ϊ��
    }
    else if (source > destination) {
        Building::waiting_list[source - 1].push_back(*this); // ���˿ͼ���ȴ��б�
        // Building::down_button[source] = true; // �����а�ť��Ϊ��
    }
}
