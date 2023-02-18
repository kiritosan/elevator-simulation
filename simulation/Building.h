#pragma once
#include <vector>
#include "Elevator.h"
#include "Passenger.h"

class Building
{
    private:
        int floors; // ¥������
        int elevators; // ��������
        int timers; // ϵͳ��ʱ��

        vector<Elevator> elevator_list;   // �����б�
        vector<Passenger> passenger_list; // �˿��б�
        static bool *up_button; // ���а�ť״̬
        static bool *down_button; // ���а�ť״̬
        static vector<Passenger> waiting_list[40]; // ����¥��ĳ˿͵ĵȴ��б�

        static bool is_valid(Elevator e, Passenger p); // �жϵ����Ƿ��ܹ�����˿͵�Ŀ��¥��
        void find_elevator(Passenger p); // �ҵ�����ʵĵ���
        void generate_passengers(int N, int M, int T); // �������nλ�˿ͣ���m�����ڵ���һ¥

    public:

        Building(int floors, int elevators); // ���캯��
        static void simulate(); // ģ��������
        int get_timers(); // �õ���ǰϵͳ������ʱ��

        friend class Passenger; // �����˿���Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
        friend class Elevator; // ����������Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
};