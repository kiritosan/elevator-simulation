#include "Elevator.h"
#include <iostream>
#include "Building.h"

using namespace std;

// ʵ�ֵ�����Ĺ��캯��
Elevator::Elevator(int id, int max_capacity, int speed)
{
	this->id = id;
	this->max_capacity = max_capacity;
    this->speed = speed;
	current_floor = rand() % 40 + 1; // ������õ�ǰ¥��
	direction = 0;

	cout << "Elevator��" << id << "������" << endl;
	cout << "���ݳ�ʼ¥��Ϊ��" << current_floor << endl;
    cout << "��������״̬Ϊ��" << direction << endl;
    cout << "��������ؿ���Ϊ��" << max_capacity << endl;
    cout << "���������ٶ�Ϊ��" << speed << endl;
}

// ʵ�ֵ��ݵ��ƶ�����
void Elevator::move()
{
    // ��������б�Ϊ�գ���ֹͣ����
    if (request_list.empty()) {
        direction = 0;
        return;
    }
    // �����ǰ¥���������б��У���ֹͣ������
    if (find(request_list.begin(), request_list.end(), current_floor) != request_list.end()) {
        direction = 0;
        open();
        // �������б���ɾ����ǰ¥��
        request_list.erase(find(request_list.begin(), request_list.end(), current_floor));
        return;
    }
    // �������з����ƶ�һ��
    if (direction == 1) {
        current_floor++;
        cout << "Elevator:" << id << "�����ƶ����˵�" << current_floor << "��" << endl;
    }
    else if (direction == -1) {
        current_floor--;
        cout << "Elevator:" << id << "�����ƶ����˵�" << current_floor << "��" << endl;
    }
}

// ʵ�ֵ�����Ŀ��ź���
void Elevator::open() {
    cout << "����" << id << "��" << current_floor << "�㿪�š�" << endl;
    // �����˿��б�����г˿͵���Ŀ��¥�㣬��ж�ظó˿�
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers[i].destination == current_floor) {
            unload(passengers[i]);
        }
    }
    // �����ȴ��б�����г˿��ڵ�ǰ¥��ȴ����ʵĵ��ݣ���װ�ظó˿�
    for (int i = 0; i < Building::waiting_list[current_floor].size(); i++) {
        if (Building::is_valid(*this, Building::waiting_list[current_floor][i]) && passengers.size() < max_capacity) {
            load(Building::waiting_list[current_floor][i]);
        }
    }
}

// ʵ�ֵ������װ�س˿ͺ���
void Elevator::load(Passenger p) {
    cout << "����" << id << "��" << current_floor << "��װ���˳˿�" << p.id << "��" << endl;
    passengers.push_back(p); // ���˿ͼ���˿��б�
    // ���ݳ˿�Ŀ��¥����µ������з���
    if (p.destination > current_floor) {
        direction = 1; // �������з���Ϊ����
    }
    else if (p.destination < current_floor) {
        direction = -1; // �������з���Ϊ����
    }
}

// ʵ�ֵ������ж�س˿ͺ���
void Elevator::unload(Passenger p) {
    cout << "����" << id << "��" << current_floor << "��ж���˳˿�" << p.id << "��" << endl;
    // �ӳ˿��б���ɾ���ó˿�
    for (int i = 0; i < passengers.size(); i++) {
        if (passengers[i].id == p.id) {
            passengers.erase(passengers.begin() + i);
            break;
        }
    }
}
