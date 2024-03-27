#include <iostream>

using namespace std;


#define MAX_TABLE	1000

char is_can_table[MAX_TABLE];

#define PARSE_NUM_1(x) ((x/100) % 10)
#define PARSE_NUM_2(x) ((x/10) % 10)
#define PARSE_NUM_3(x) ((x) % 10)

void init_table()
{
	// is_can_table 초기화, 중복된 숫자가 있으면 제거(0)
	//for (int i = 0; )
}

void calc_ball_count(int n1, int n2, int* scount, int* bcount)
{
	int n1_array[3] = { PARSE_NUM_1(n1), PARSE_NUM_2(n1), PARSE_NUM_3(n1) };
	int n2_array[3] = { PARSE_NUM_1(n2), PARSE_NUM_2(n2), PARSE_NUM_3(n2) };
	*scount = 0;
	*bcount = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//
		}
	}
}

void input_ball_count(int* scount, int* bcount)
{

}

void update_ball_count_to_table(int suguest_num, int scount, int bcount)
{
	for (int i = 0; i < MAX_TABLE; i++) {
		if (is_can_table[i]) {
			int s, b;
			calc_ball_count(i, suguest_num, &s, &b);
			if (s != scount || b != bcount) {
				is_can_table[i] = 0;
			}
		}
	}
}

int get_num_from_table()
{
	
}

int get_count_table()
{

}

int main()
{
	init_table();
	while(1) {
		int scount, bcount;
		// 테이블에서 가능성 있는 숫자를 하나 가져온다.
		int suguest_num = get_num_from_table();
		cout << suguest_num;
		// 볼카운트 입력받고,
		input_ball_count(&scount, &bcount);
		// 볼카운트를 테이블에 반영한다.
		update_ball_count_to_table(suguest_num, scount, bcount);

		int can_num_count = get_count_table();
		if (can_num_count == 0) {
			// error
		}
		else if (can_num_count == 1) {
			// found!!!
			break;
		}
	}


	return 0;
}