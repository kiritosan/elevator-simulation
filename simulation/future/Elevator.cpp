#include "Elevator.h"
#include <iostream>
#include "Building.h"
using namespace std;

// ʵ�ֵ�����Ĺ��캯��
Elevator::Elevator(int id, int max_capacity) {
    this->id = id; // ���õ��ݱ��
    this->max_capacity = max_capacity; // ��������ؿ���
    this->current_floor = rand() % Building::floors + 1; // ������õ�ǰ¥��
    this->direction = 0; // ��ʼ���з���Ϊֹͣ
}

// ʵ�ֵ�������ƶ�����
void Elevator::move() {
    if (direction == 1) { // ������з���Ϊ����
        current_floor++; // ��ǰ¥���һ
        cout << "����" << id << "������" << current_floor << "�㡣" << endl;
    }
    else if (direction == -1) { // ������з���Ϊ����
        current_floor--; // ��ǰ¥���һ
        cout << "����" << id << "�½���" << current_floor << "�㡣" << endl;
    }
}

// ʵ�ֵ�������ƶ�����
void Elevator::move() {
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
    }
    else if (direction == -1) {
        current_floor--;
    }
}

// ʵ�ֵ�����Ĺرյ����ź���
void Elevator::close() {
    cout << "����" << id << "��" << current_floor << "����š�" << endl;
    // ���ݵ�ǰ¥��������б�������з���
    if (!request_list.empty()) {
        if (request_list.front() > current_floor) {
            direction = 1; // �������з���Ϊ����
        }
        else if (request_list.front() < current_floor) {
            direction = -1; // �������з���Ϊ����
        }
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

// ʵ�ֵ���������������
void Elevator::add_request(int floor) {
    cout << "����" << id << "�յ�������" << floor << "�������" << endl;
    // ����¥����������б�
    request_list.push_back(floor);
    // ���ݵ�ǰ¥�������¥����µ������з���
    if (floor > current_floor) {
        direction = 1; // �������з���Ϊ����
    }
    else if (floor < current_floor) {
        direction = -1; // �������з���Ϊ����
    }
}



