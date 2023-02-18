#include "Building.h"
#include <iostream>
#include "Test.h"

using namespace std;

Building::Building(int floors, int elevators)
{
	// up_button = new bool[elevators];
	// down_button = new bool[elevators];

	this->floors = floors;
	this->elevators = elevators;
	// int Building::timers = 0; // ϵͳ��ʱ����ʼ��
	cout << "Building ������" << endl;
	cout << "¥����Ϊ " << floors << endl;
	cout << "��������Ϊ " << elevators << endl;
}

// ʵ�ֽ�������жϵ����Ƿ��ܹ�����˿�Ŀ��¥��ĺ���
bool Building::is_valid(Elevator e, Passenger p) {
    // ���ݵ��ݱ�źͳ˿�Ŀ��¥���ж��Ƿ�������й���
    switch (e.id) {
    case 0:
    case 1:
        return true; // E0��E1���ɵ���ÿ�㡣
    case 2:
    case 3:
        return p.destination == 1 || (p.destination >= 25 && p.destination <= 40); // E2��E3���ɵ��� 1��25~40 �㡣
    case 4:
    case 5:
        return p.destination >= 1 && p.destination <= 25; // E4��E5���ɵ��� 1~25 �㡣
    case 6:
    case 7:
        return p.destination == 1 || p.destination % 2 == 0; // E6��E7���ɵ���ż�����һ�㡣
    default:
        return false; // �����������false��
    }
}

// �� N λ�˿ͣ�0 < N < 1000���� M ���ӣ�0 < M < 10��������شﵽ�ù��ʻ�չ���ĵ� 1 �㣬��ʼ���ݻ��
void Building::generate_passengers(int N, int M, int T) // N���˿����� M: �˿͵����չ����ʱ�� T���˿ʹ�¥�����µ�����Ҫ��ʱ��
{
	for (int i = 0; i < N; i++)
	{
		Passenger p(i, M, T);
		passenger_list.push_back(p);
	}
}

void Building::find_elevator(Passenger p) {
	for (auto& p: passenger_list)
	{
		for (auto& e : elevator_list) {
			if (is_valid(e, p)) {
				p.press_button();

				int dir;
				if (p.destination - p.source > 0) {
					dir = 1;
				}
				else if (p.destination - p.source < 0) {
					dir = -1;
				}
				else {
					dir = 0;
				}
				if (e.request_list.size() <= e.max_capacity) {
					e.request_list.push_back(dir);
				}
			}
		}
	}
}

// �õ���ǰϵͳ������ʱ��
int Building::get_timers() {
	return timers;
}

// ����ϵͳ��ģ��
void Building::simulate() {

	// ������Ҫ�Ķ���>>>>>>>>>>>>
	cout << "��ʼ���ɻ�չ����>>>>>>>>>>>>" << endl;
	Building b(40, 10); //���ɹ��ʻ�չ����
	cout << "���ɻ�չ���Ľ���<<<<<<<<<<<<" << endl;

	// ���ɵ���
	int K, S, N, M, T;
	cout << "��������ݵ�����ؿ���(10-18)��";
	cout << endl;
	cin >> K;
	cout << "��������ݵ������ٶ�(1-5)��";
	cout << endl;
	cin >> S;

	cout << "��ʼ���ɵ���>>>>>>>>>>>>" << endl;
	vector<Elevator> elevator_list;
	for (int i = 0; i < 10; i++) // ����ʮ�����ݣ�������һ���б���
	{
		Elevator e(i, K, S); // ����һ�����ݶ��󣬴���id����
		elevator_list.push_back(e); // �ѵ��ݼ��뵽������
	}
	cout << "���ɵ��ݽ���<<<<<<<<<<<<" << endl;

	cout << "������˿͵�������0 < N < 1000����";
	cout << endl;
	cin >> N;
	cout << "������˿͵����չ���ĵ�ʱ�䣨0 < M < 10����";
	cout << endl;
	cin >> M;
	cout << "������ÿ������ʱ��Ϊ ��2 << T << 10����";
	cout << endl;
	cin >> T;

	cout << "��ʼ���ɳ˿�>>>>>>>>>>>>" << endl;
	b.generate_passengers(N, M, T); // ���ɳ˿͵� passenger_list
	cout << "���ɳ˿ͽ���<<<<<<<<<<<<" << endl;
	// ���ɶ���������<<<<<<<<<<<<

	// ��ʼģ��
	cout << "��ʼ���е��ݷ���ģ��" << endl;

	// ����ϵͳʱ�����
	int last_time = clock();
	int timers = b.get_timers();

	while (true) {
		int current_time = clock();
		if (current_time - last_time >= 1000) {
			cout << "ϵͳʱ���Ѿ���" << ++timers << "��" << endl;
			last_time = current_time;

			for (auto& passenger : b.passenger_list)
			{
				if (passenger.arriving_time == timers) {
					cout << "�˿�" << passenger.id << "�Ѿ������չ����" << endl;
					b.find_elevator(passenger);
					passenger.press_button();
				}
				
			}

			// ÿ��S�룬ִ��һ��elevator��move
			if ((timers - 1) % S == 0) {
				for (auto& elevator : elevator_list)
				{
					elevator.move();
				}
			}
		}

	}
}