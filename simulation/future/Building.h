#pragma once
#include <vector>

#include "Passenger.h"
using namespace std;

class Building
{
    private:
        const static int floors = 40; // ¥������
        const static int elevators = 10; // ��������

        vector<Elevator> elevator_list;   // �����б�
        vector<Passenger> passenger_list; // �˿��б�
        static vector<Passenger> waiting_list[floors]; // ����¥��ĳ˿͵ĵȴ��б�
        static bool up_button[elevators]; // ���а�ť״̬
        static bool down_button[elevators]; // ���а�ť״̬

        static bool is_valid(Elevator e, Passenger p); // �жϵ����Ƿ��ܹ�����˿͵�Ŀ��¥��
        Elevator find_elevator(Passenger p); // �ҵ�����ʵĵ���
        void generate_passengers(int n, int m, int k, int s, int t); // �������nλ�˿ͣ���m�����ڵ���һ¥

    public:
        Building(); // ���캯��
        void simulate(); // ģ��������

        friend class Passenger; // �����˿���Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
        friend class Elevator; // ����������Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
};

