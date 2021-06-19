#include <stdio.h>

#define PAN_SIZE 8

struct stone_num {//돌의 갯수 

	int o;

	int x;

}st;

struct position_dol {//돌의 위치 

	int ga;

	int se;

}po;

void pan();//판초기화

void pan_print();//판출력

void dol_check();//둘수 있는 곳인지 확인

void dol_input();//돌 입력

void com_dol_input();//컴퓨터 돌입력

void dol_change(); //돌뒤집기

void turn_change();//턴체인지

void mark();//?지우기

void dol_num();//돌갯수

void mu();//한수무르기 저장

void save();//게임 저장

void insave();//저장 불러오기

int end(); //끝인지 확인

char turn = 'o';

char pans[PAN_SIZE + 1][PAN_SIZE + 2];

int end_count = 0;//두명다 둘곳이 없을때 체크용

int main() {

	int start;

	while (1) {

		printf("처음 시작은 1번\n이어하기 2번\n입력:");

		scanf("%d", &start);

		if (start == 1) {

			pan();

			break;

		}

		else if (start == 2) {//2일때 불러오기 

			insave();

			break;

		}

		else {

			printf("다시 입력해주세요");

		}

	}



	do {

		dol_check();

		pan_print();

		if (turn == 'o')//o일때 플레이어 

		{

			dol_input();

		}

		else if (turn == 'x') {//x일때 컴퓨터 

			com_dol_input();

		}

		mu();

		dol_change();

		turn_change();

		mark();

	} while (end());

}

void pan() {//판초기화 

	int i, j;

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			pans[i][j] = '.';

		}

	}

	pans[4][4] = 'o';

	pans[4][5] = 'x';

	pans[5][4] = 'x';

	pans[5][5] = 'o';

}

void pan_print() {//판을 출력 

	int i, j;

	printf("    1   2   3   4   5   6   7   8\n");

	for (i = 1; i <= PAN_SIZE; i++)

	{

		printf("%d", i);

		for (j = 1; j <= PAN_SIZE; j++)

		{

			printf("   %c", pans[i][j]);

		}

		printf("\n");

	}

}

void dol_check() {//둘수 있는지 확인 

	int i, j, x;

	x = 1;

	char noturn;

	if (turn == 'o')noturn = 'x';

	else noturn = 'o';

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			while (pans[i][j] == turn && pans[i + x][j] == noturn) {//남

				x++;

				if (pans[i + x][j] == '.') {//둘수 있다면 

					pans[i + x][j] = '?';//그자리에 ?을 넣는다 

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i + x][j + x] == noturn) {//남동

				x++;

				if (pans[i + x][j + x] == '.') {

					pans[i + x][j + x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i][j + x] == noturn) {//동

				x++;

				if (pans[i][j + x] == '.') {

					pans[i][j + x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i - x][j + x] == noturn) {//동북

				x++;

				if (pans[i - x][j + x] == '.') {

					pans[i - x][j + x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i - x][j] == noturn) {//북

				x++;

				if (pans[i - x][j] == '.') {

					pans[i - x][j] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i - x][j - x] == noturn) {//북서

				x++;

				if (pans[i - x][j - x] == '.') {

					pans[i - x][j - x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i][j - x] == noturn) {//서

				x++;

				if (pans[i][j - x] == '.') {

					pans[i][j - x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i + x][j - x] == noturn) {//서남

				x++;

				if (pans[i + x][j - x] == '.') {

					pans[i + x][j - x] = '?';

				}

			}

		}

	}

}

void dol_input() {//플레이어 입력 

	while (1) {

		int i, j, count = 0;

		for (i = 1; i <= PAN_SIZE; i++)//둘곳이 없는지 확인

		{

			for (j = 1; j <= PAN_SIZE; j++)

			{

				if (pans[i][j] == '?') {

					count++;//둘곳의 갯수 

				}

			}

		}

		if (end_count == 2) {//두명다 둘곳이 없다면 리턴 

			return;

		}

		if (count == 0) {//둘곳이 없으면 end_count를 하나 더하고 리턴 

			end_count++;

			return;

		}

		printf("%c의 차례\n", turn);

		printf("가로or세로에100입력시 무르기\n500입력시 저장 \n가로 입력:");//가로 세로 각각 입력 

		scanf("%d", &po.ga);

		printf("세로 입력:");

		scanf("%d", &po.se);

		if (po.ga >= 1 && po.ga <= PAN_SIZE && po.se >= 1 && po.se <= PAN_SIZE && pans[po.se][po.ga] == '?') {//둘수 있는 곳인지 확인후 turn을 넣는다 

			pans[po.se][po.ga] = turn;

			break;

		}

		else if (po.ga == 100 || po.se == 100) {//한수무를떄 사용 

			char c[100] = "E:\Othello";

			strncat(c, &turn);

			strncat(c, ".txt");

			FILE* call;

			call = fopen(c, "r");

			fscanf(call, "%c", &turn);//turn 불러오기 

			for (i = 1; i <= PAN_SIZE; i++)

			{

				for (j = 1; j <= PAN_SIZE; j++)

				{

					fscanf(call, "%d", &pans[i][j]); //판의 상태 불러오기 

				}

			}

			fclose(call);

			pan_print();//판출력 

		}

		else if (po.ga == 500 || po.se == 500) {//저장할때 사용 

			save();

		}

		else {

			printf("다시 입력하세요.\n");

		}

	}

	end_count = 0;//제대로 돌수 있으면 초기화 

}

void com_dol_input() {//컴퓨터 입력 

	int x = 1, cnt = 0, ck = 0;//x는 자리 더할때,cnt 넘길수 있는 돌의 갯수, ck는 맞는지 확인

	int ck_cnt = 0;//ck에 의해 틀리면 cnt를 ck_cnt만큼 빼기

	int i, j, count = 0, big = 0;//big은 컴퓨터가 돌을 둘때 가장 많은 돌을 먹을수 있는 곳 

	for (i = 1; i <= PAN_SIZE; i++)//둘곳이 없는지 확인

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			if (pans[i][j] == '?') {

				count++;//count가 0이 아니면 둘곳이 있다는 뜻

			}

		}

	}

	if (end_count == 2) {//두명다 둘곳이 없으면 리턴 

		return;

	}

	if (count == 0) {//자신이 둘곳이 없으면 end_count에 1을 더하고 리턴 

		end_count++;

		return;

	}

	for (i = 1; i <= PAN_SIZE; i++)//둘곳이 없는지 확인

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			if (pans[i][j] == '?') {

				while (pans[i + x][j] == 'o') {//남

					if (pans[i + x][j] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i + x][j] != 'x') {//마지막에 자기자신이 아니라면 ck=1

					ck = 1;

				}

				if (ck == 1) {//ck가 1이라면(마지막에 자신의 돌이 없다면) cnt에 ck_cnt만큼 뺀다  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i + x][j + x] == 'o') {//남동

					if (pans[i + x][j + x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i + x][j + x] != 'x') {//마지막에 자기자신이 아니라면 ck=1

					ck = 1;

				}

				if (ck == 1) {//ck가 1이라면(마지막에 자신의 돌이 없다면) cnt에 ck_cnt만큼 뺀다  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i][j + x] == 'o') {//동

					if (pans[i][j + x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i][j + x] != 'x') {//마지막에 자기자신이 아니라면 ck=1

					ck = 1;

				}

				if (ck == 1) {//ck가 1이라면(마지막에 자신의 돌이 없다면) cnt에 ck_cnt만큼 뺀다  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i - x][j + x] == 'o') {//동북

					if (pans[i - x][j + x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i - x][j + x] != 'x') {//마지막에 자기자신이 아니라면 ck=1

					ck = 1;

				}

				if (ck == 1) {//ck가 1이라면(마지막에 자신의 돌이 없다면) cnt에 ck_cnt만큼 뺀다  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i - x][j] == 'o') {//북

					if (pans[i - x][j] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i - x][j] != 'x') {//마지막에 자기자신이 아니라면 ck=1

					ck = 1;

				}

				if (ck == 1) {//ck가 1이라면(마지막에 자신의 돌이 없다면) cnt에 ck_cnt만큼 뺀다  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i - x][j - x] == 'o') {//북서

					if (pans[i - x][j - x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i - x][j - x] != 'x') {//마지막에 자기자신이 아니라면 ck=1

					ck = 1;

				}

				if (ck == 1) {//ck가 1이라면(마지막에 자신의 돌이 없다면) cnt에 ck_cnt만큼 뺀다  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i][j - x] == 'o') {//서

					if (pans[i][j - x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i][j - x] != 'x') {//마지막에 자기자신이 아니라면 ck=1

					ck = 1;

				}

				if (ck == 1) {//ck가 1이라면(마지막에 자신의 돌이 없다면) cnt에 ck_cnt만큼 뺀다  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i + x][j - x] == 'o') {//서남

					if (pans[i + x][j - x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i + x][j - x] != 'x') {//마지막에 자기자신이 아니라면 ck=1

					ck = 1;

				}

				if (ck == 1) {//ck가 1이라면(마지막에 자신의 돌이 없다면) cnt에 ck_cnt만큼 뺀다  

					cnt = cnt - ck_cnt;

				}

				if (big < cnt) {//가장 큰놈으로 바꾼다 

					big = cnt;

					po.ga = j;

					po.se = i;

				}

				cnt = 1;

			}

		}

	}



	pans[po.se][po.ga] = turn;//돌을 넣는다 

	end_count = 0;//제대로 된다면 초기화 

}

void dol_change() {//돌을 뒤집는곳 

	char noturn;

	int x = 1;

	int count = 1;

	int ck = 0;

	if (turn == 'o')noturn = 'x';

	else noturn = 'o';

	while (pans[po.se + x][po.ga] == noturn) {//남

		if (pans[po.se + x][po.ga] == noturn) {

			count++;//남의 돌이 있는 만큼 count를 1씩 더한다 

		}

		x++;

		if (pans[po.se + x][po.ga] == turn)

			ck = 1;//마지막에 자기돌이 있다면 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count만큼 남의돌을 자기돌로 바꾼다 

			pans[po.se + x][po.ga] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se + x][po.ga + x] == noturn) {//남동

		if (pans[po.se + x][po.ga + x] == noturn) {

			count++;//남의 돌이 있는 만큼 count를 1씩 더한다 

		}

		x++;

		if (pans[po.se + x][po.ga + x] == turn)

			ck = 1;//마지막에 자기돌이 있다면 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count만큼 남의돌을 자기돌로 바꾼다 

			pans[po.se + x][po.ga + x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se][po.ga + x] == noturn) {//동

		if (pans[po.se][po.ga + x] == noturn) {

			count++;//남의 돌이 있는 만큼 count를 1씩 더한다 

		}

		x++;

		if (pans[po.se][po.ga + x] == turn)

			ck = 1;//마지막에 자기돌이 있다면 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count만큼 남의돌을 자기돌로 바꾼다 

			pans[po.se][po.ga + x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se - x][po.ga + x] == noturn) {//동북

		if (pans[po.se - x][po.ga + x] == noturn) {

			count++;//남의 돌이 있는 만큼 count를 1씩 더한다 

		}

		x++;

		if (pans[po.se - x][po.ga + x] == turn)

			ck = 1;//마지막에 자기돌이 있다면 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count만큼 남의돌을 자기돌로 바꾼다 

			pans[po.se - x][po.ga + x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se - x][po.ga] == noturn) {//북

		if (pans[po.se - x][po.ga] == noturn) {

			count++;//남의 돌이 있는 만큼 count를 1씩 더한다 

		}

		x++;

		if (pans[po.se - x][po.ga] == turn)

			ck = 1;//마지막에 자기돌이 있다면 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count만큼 남의돌을 자기돌로 바꾼다 

			pans[po.se - x][po.ga] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se - x][po.ga - x] == noturn) {//북서

		if (pans[po.se - x][po.ga - x] == noturn) {

			count++;//남의 돌이 있는 만큼 count를 1씩 더한다 

		}

		x++;

		if (pans[po.se - x][po.ga - x] == turn)

			ck = 1;//마지막에 자기돌이 있다면 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count만큼 남의돌을 자기돌로 바꾼다 

			pans[po.se - x][po.ga - x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se][po.ga - x] == noturn) {//서

		if (pans[po.se][po.ga - x] == noturn) {

			count++;//남의 돌이 있는 만큼 count를 1씩 더한다 

		}

		x++;

		if (pans[po.se][po.ga - x] == turn)

			ck = 1;//마지막에 자기돌이 있다면 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count만큼 남의돌을 자기돌로 바꾼다 

			pans[po.se][po.ga - x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se + x][po.ga - x] == noturn) {//서남

		if (pans[po.se + x][po.ga - x] == noturn) {

			count++;//남의 돌이 있는 만큼 count를 1씩 더한다 

		}

		x++;

		if (pans[po.se + x][po.ga - x] == turn)

			ck = 1;//마지막에 자기돌이 있다면 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count만큼 남의돌을 자기돌로 바꾼다 

			pans[po.se + x][po.ga - x] = turn;

		}

	}

}

void turn_change() {//턴을 바꾼다 

	if (turn == 'o')turn = 'x';

	else turn = 'o';

}

void mark() {//?을 다시 .으로 바꾼다 

	int i, j;

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			if (pans[i][j] == '?') {

				pans[i][j] = '.';

			}

		}

	}

}

void dol_num() {//각돌의 갯수를 알아본다 

	int i, j;

	st.o = 0;

	st.x = 0;

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			if (pans[i][j] == 'o') {

				st.o++;

			}

			else if (pans[i][j] == 'x') {

				st.x++;

			}

		}

	}

}

void mu() {//무르기 저장용 

	int i, j;

	char m[100] = "E:\Othello";

	strncat(m, &turn);

	strncat(m, ".txt");

	FILE* min;

	min = fopen(m, "w");

	fprintf(min, "%c ", turn);//턴저장 

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			fprintf(min, "%d ", pans[i][j]);//판의 상태저장 

		}

	}

	fclose(min);

}

void save() {//저장 

	int i, j;

	char c[100] = "E:\Othello";

	FILE* sv;

	sv = fopen(c, "w");

	fprintf(sv, "%c ", turn);//턴저장 

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			fprintf(sv, "%d ", pans[i][j]);//판의 상태저장 

		}

	}

	fclose(sv);

}

void insave() {//불러오기 

	int i, j;

	char c[100] = "E:\Othello";

	FILE* insv;

	insv = fopen(c, "r");

	fscanf(insv, "%c", &turn);//턴불러오기 

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			fscanf(insv, "%d", &pans[i][j]);//판의 상태 불러오기 

		}

	}

	fclose(insv);

}

int end() {//끝내는 조건 

	dol_num();

	if ((st.o + st.x) == PAN_SIZE * PAN_SIZE || end_count == 2) {//돌의갯수가 놓을수있는 자리가 같을때나 둘다 둘곳이 없을때 

		printf("o의 갯수:%d", st.o);

		printf("x의 갯수:%d", st.x);

		if (st.o > st.x) {

			printf("o의 승리!\n");

		}

		else if (st.o == st.x) {

			printf("무승부!\n");

		}

		else {

			printf("x의 승리!\n");

		}

		pan_print();

		return 0;

	}

	return 1;

}
