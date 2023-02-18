#pragma once
#include "Passenger.h"
#include <vector>

using namespace std;

class Elevator
{
    private:
        int id; // ���ݱ��
        int max_capacity; // ����ؿ���
        int current_floor; // ��ǰ¥��
        int direction; // ���з���1Ϊ���У�-1Ϊ���У�0Ϊֹͣ
        int speed; // ���������ٶ� (S: 1-5)
        vector<Passenger> passengers; // �˿��б�
        vector<int> request_list; // �����б�

    public:
        Elevator(int id, int max_capacity, int speed); // ���캯��
        void move(); // �ƶ�����
        void stop(); // ֹͣ����
        void open(); // ���ź���
        void close(); // ���ź���
        void load(Passenger passenger); // װ�س˿ͺ���
        void unload(Passenger passenger); // ж�س˿ͺ���
        void add_request(int floor); // ���������
        void remove_request(int floor); // �Ƴ�������

        friend class Building; // ����������Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
};