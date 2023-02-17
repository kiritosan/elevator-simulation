#include "Passenger.h"
#include "Passenger.h"
#include "Building.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>

using namespace std;

// ʵ�ֳ˿���Ĺ��캯��
Passenger::Passenger(int id, int times) {
    this->id = id; // ���ó˿ͱ��
    // this->source = rand() % floors + 1; // ������ó���¥��
    this->source = 1; // ���ó�ʼ����¥��Ϊ1
    this->destination = rand() % Building::floors + 1; // �������Ŀ��¥��
}

// ʵ�ֳ˿���İ����ݰ�ť�ĺ���
void Passenger::press_button() {
    cout << "�˿�" << id << "��" << source << "�㰴�˵��ݰ�ť��" << endl;
    // ���ݳ���¥���Ŀ��¥���жϰ����а�ť�������а�ť
    if (source < destination) {
        Building::waiting_list[source].push_back(*this); // ���˿ͼ���ȴ��б�
        Building::up_button[source] = true; // �����а�ť��Ϊ��
    }
    else if (source > destination) {
        Building::waiting_list[source].push_back(*this); // ���˿ͼ���ȴ��б�
        Building::down_button[source] = true; // �����а�ť��Ϊ��
    }
}

int main() {
    cout << "test" << endl;
    return 0;
}