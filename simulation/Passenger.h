#pragma once
class Passenger
{
private:
    int id; // �˿ͱ��
    int source; // ����ǰ¥��
    int destination; // Ŀ��¥��
    int times; // ���ݴ��� ÿλ�˿ͳ����� L �Σ�ÿ�˵� L ֵ��ͬ���ڲ����˿�ʱ������� 1~10 ��֮��ȷ����
    int ride_speed; // �˿��ϵ��ݵ��ٶ� (T: 2-10)
    int arriving_time; // �����չ���ĵ�ʱ�� (M: 0<M<10)

public:
    Passenger(int id, int arriving_time, int ride_speed); // ���캯��

    void press_button();

    friend class Building; // ����������Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
    friend class Elevator; // ����������Ϊ��Ԫ�࣬���Է���˽�г�Ա�����ͺ���
};
