#pragma once
class Passenger
{
    private:
        int id; // �˿ͱ��
        int source; // ����ǰ¥��
        static int destination; // Ŀ��¥��
        int times; // ���ݴ���

    public:
        Passenger(int id, int times); // ���캯��

        void press_button();
        

        friend class Building; // ����������Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
        friend class Elevator; // ����������Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
};

