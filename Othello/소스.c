#include <stdio.h>

#define PAN_SIZE 8

struct stone_num {//���� ���� 

	int o;

	int x;

}st;

struct position_dol {//���� ��ġ 

	int ga;

	int se;

}po;

void pan();//���ʱ�ȭ

void pan_print();//�����

void dol_check();//�Ѽ� �ִ� ������ Ȯ��

void dol_input();//�� �Է�

void com_dol_input();//��ǻ�� ���Է�

void dol_change(); //��������

void turn_change();//��ü����

void mark();//?�����

void dol_num();//������

void mu();//�Ѽ������� ����

void save();//���� ����

void insave();//���� �ҷ�����

int end(); //������ Ȯ��

char turn = 'o';

char pans[PAN_SIZE + 1][PAN_SIZE + 2];

int end_count = 0;//�θ�� �Ѱ��� ������ üũ��

int main() {

	int start;

	while (1) {

		printf("ó�� ������ 1��\n�̾��ϱ� 2��\n�Է�:");

		scanf("%d", &start);

		if (start == 1) {

			pan();

			break;

		}

		else if (start == 2) {//2�϶� �ҷ����� 

			insave();

			break;

		}

		else {

			printf("�ٽ� �Է����ּ���");

		}

	}



	do {

		dol_check();

		pan_print();

		if (turn == 'o')//o�϶� �÷��̾� 

		{

			dol_input();

		}

		else if (turn == 'x') {//x�϶� ��ǻ�� 

			com_dol_input();

		}

		mu();

		dol_change();

		turn_change();

		mark();

	} while (end());

}

void pan() {//���ʱ�ȭ 

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

void pan_print() {//���� ��� 

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

void dol_check() {//�Ѽ� �ִ��� Ȯ�� 

	int i, j, x;

	x = 1;

	char noturn;

	if (turn == 'o')noturn = 'x';

	else noturn = 'o';

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			while (pans[i][j] == turn && pans[i + x][j] == noturn) {//��

				x++;

				if (pans[i + x][j] == '.') {//�Ѽ� �ִٸ� 

					pans[i + x][j] = '?';//���ڸ��� ?�� �ִ´� 

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i + x][j + x] == noturn) {//����

				x++;

				if (pans[i + x][j + x] == '.') {

					pans[i + x][j + x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i][j + x] == noturn) {//��

				x++;

				if (pans[i][j + x] == '.') {

					pans[i][j + x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i - x][j + x] == noturn) {//����

				x++;

				if (pans[i - x][j + x] == '.') {

					pans[i - x][j + x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i - x][j] == noturn) {//��

				x++;

				if (pans[i - x][j] == '.') {

					pans[i - x][j] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i - x][j - x] == noturn) {//�ϼ�

				x++;

				if (pans[i - x][j - x] == '.') {

					pans[i - x][j - x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i][j - x] == noturn) {//��

				x++;

				if (pans[i][j - x] == '.') {

					pans[i][j - x] = '?';

				}

			}

			x = 1;

			while (pans[i][j] == turn && pans[i + x][j - x] == noturn) {//����

				x++;

				if (pans[i + x][j - x] == '.') {

					pans[i + x][j - x] = '?';

				}

			}

		}

	}

}

void dol_input() {//�÷��̾� �Է� 

	while (1) {

		int i, j, count = 0;

		for (i = 1; i <= PAN_SIZE; i++)//�Ѱ��� ������ Ȯ��

		{

			for (j = 1; j <= PAN_SIZE; j++)

			{

				if (pans[i][j] == '?') {

					count++;//�Ѱ��� ���� 

				}

			}

		}

		if (end_count == 2) {//�θ�� �Ѱ��� ���ٸ� ���� 

			return;

		}

		if (count == 0) {//�Ѱ��� ������ end_count�� �ϳ� ���ϰ� ���� 

			end_count++;

			return;

		}

		printf("%c�� ����\n", turn);

		printf("����or���ο�100�Է½� ������\n500�Է½� ���� \n���� �Է�:");//���� ���� ���� �Է� 

		scanf("%d", &po.ga);

		printf("���� �Է�:");

		scanf("%d", &po.se);

		if (po.ga >= 1 && po.ga <= PAN_SIZE && po.se >= 1 && po.se <= PAN_SIZE && pans[po.se][po.ga] == '?') {//�Ѽ� �ִ� ������ Ȯ���� turn�� �ִ´� 

			pans[po.se][po.ga] = turn;

			break;

		}

		else if (po.ga == 100 || po.se == 100) {//�Ѽ������� ��� 

			char c[100] = "E:\Othello";

			strncat(c, &turn);

			strncat(c, ".txt");

			FILE* call;

			call = fopen(c, "r");

			fscanf(call, "%c", &turn);//turn �ҷ����� 

			for (i = 1; i <= PAN_SIZE; i++)

			{

				for (j = 1; j <= PAN_SIZE; j++)

				{

					fscanf(call, "%d", &pans[i][j]); //���� ���� �ҷ����� 

				}

			}

			fclose(call);

			pan_print();//����� 

		}

		else if (po.ga == 500 || po.se == 500) {//�����Ҷ� ��� 

			save();

		}

		else {

			printf("�ٽ� �Է��ϼ���.\n");

		}

	}

	end_count = 0;//����� ���� ������ �ʱ�ȭ 

}

void com_dol_input() {//��ǻ�� �Է� 

	int x = 1, cnt = 0, ck = 0;//x�� �ڸ� ���Ҷ�,cnt �ѱ�� �ִ� ���� ����, ck�� �´��� Ȯ��

	int ck_cnt = 0;//ck�� ���� Ʋ���� cnt�� ck_cnt��ŭ ����

	int i, j, count = 0, big = 0;//big�� ��ǻ�Ͱ� ���� �Ѷ� ���� ���� ���� ������ �ִ� �� 

	for (i = 1; i <= PAN_SIZE; i++)//�Ѱ��� ������ Ȯ��

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			if (pans[i][j] == '?') {

				count++;//count�� 0�� �ƴϸ� �Ѱ��� �ִٴ� ��

			}

		}

	}

	if (end_count == 2) {//�θ�� �Ѱ��� ������ ���� 

		return;

	}

	if (count == 0) {//�ڽ��� �Ѱ��� ������ end_count�� 1�� ���ϰ� ���� 

		end_count++;

		return;

	}

	for (i = 1; i <= PAN_SIZE; i++)//�Ѱ��� ������ Ȯ��

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			if (pans[i][j] == '?') {

				while (pans[i + x][j] == 'o') {//��

					if (pans[i + x][j] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i + x][j] != 'x') {//�������� �ڱ��ڽ��� �ƴ϶�� ck=1

					ck = 1;

				}

				if (ck == 1) {//ck�� 1�̶��(�������� �ڽ��� ���� ���ٸ�) cnt�� ck_cnt��ŭ ����  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i + x][j + x] == 'o') {//����

					if (pans[i + x][j + x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i + x][j + x] != 'x') {//�������� �ڱ��ڽ��� �ƴ϶�� ck=1

					ck = 1;

				}

				if (ck == 1) {//ck�� 1�̶��(�������� �ڽ��� ���� ���ٸ�) cnt�� ck_cnt��ŭ ����  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i][j + x] == 'o') {//��

					if (pans[i][j + x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i][j + x] != 'x') {//�������� �ڱ��ڽ��� �ƴ϶�� ck=1

					ck = 1;

				}

				if (ck == 1) {//ck�� 1�̶��(�������� �ڽ��� ���� ���ٸ�) cnt�� ck_cnt��ŭ ����  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i - x][j + x] == 'o') {//����

					if (pans[i - x][j + x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i - x][j + x] != 'x') {//�������� �ڱ��ڽ��� �ƴ϶�� ck=1

					ck = 1;

				}

				if (ck == 1) {//ck�� 1�̶��(�������� �ڽ��� ���� ���ٸ�) cnt�� ck_cnt��ŭ ����  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i - x][j] == 'o') {//��

					if (pans[i - x][j] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i - x][j] != 'x') {//�������� �ڱ��ڽ��� �ƴ϶�� ck=1

					ck = 1;

				}

				if (ck == 1) {//ck�� 1�̶��(�������� �ڽ��� ���� ���ٸ�) cnt�� ck_cnt��ŭ ����  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i - x][j - x] == 'o') {//�ϼ�

					if (pans[i - x][j - x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i - x][j - x] != 'x') {//�������� �ڱ��ڽ��� �ƴ϶�� ck=1

					ck = 1;

				}

				if (ck == 1) {//ck�� 1�̶��(�������� �ڽ��� ���� ���ٸ�) cnt�� ck_cnt��ŭ ����  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i][j - x] == 'o') {//��

					if (pans[i][j - x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i][j - x] != 'x') {//�������� �ڱ��ڽ��� �ƴ϶�� ck=1

					ck = 1;

				}

				if (ck == 1) {//ck�� 1�̶��(�������� �ڽ��� ���� ���ٸ�) cnt�� ck_cnt��ŭ ����  

					cnt = cnt - ck_cnt;

				}

				//----------------------------------------------------------

				x = 1;

				ck = 0;

				ck_cnt = 0;

				while (pans[i + x][j - x] == 'o') {//����

					if (pans[i + x][j - x] == 'o') {

						cnt++;

						ck_cnt++;

					}

					x++;

				}

				if (pans[i + x][j - x] != 'x') {//�������� �ڱ��ڽ��� �ƴ϶�� ck=1

					ck = 1;

				}

				if (ck == 1) {//ck�� 1�̶��(�������� �ڽ��� ���� ���ٸ�) cnt�� ck_cnt��ŭ ����  

					cnt = cnt - ck_cnt;

				}

				if (big < cnt) {//���� ū������ �ٲ۴� 

					big = cnt;

					po.ga = j;

					po.se = i;

				}

				cnt = 1;

			}

		}

	}



	pans[po.se][po.ga] = turn;//���� �ִ´� 

	end_count = 0;//����� �ȴٸ� �ʱ�ȭ 

}

void dol_change() {//���� �����°� 

	char noturn;

	int x = 1;

	int count = 1;

	int ck = 0;

	if (turn == 'o')noturn = 'x';

	else noturn = 'o';

	while (pans[po.se + x][po.ga] == noturn) {//��

		if (pans[po.se + x][po.ga] == noturn) {

			count++;//���� ���� �ִ� ��ŭ count�� 1�� ���Ѵ� 

		}

		x++;

		if (pans[po.se + x][po.ga] == turn)

			ck = 1;//�������� �ڱ⵹�� �ִٸ� 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count��ŭ ���ǵ��� �ڱ⵹�� �ٲ۴� 

			pans[po.se + x][po.ga] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se + x][po.ga + x] == noturn) {//����

		if (pans[po.se + x][po.ga + x] == noturn) {

			count++;//���� ���� �ִ� ��ŭ count�� 1�� ���Ѵ� 

		}

		x++;

		if (pans[po.se + x][po.ga + x] == turn)

			ck = 1;//�������� �ڱ⵹�� �ִٸ� 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count��ŭ ���ǵ��� �ڱ⵹�� �ٲ۴� 

			pans[po.se + x][po.ga + x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se][po.ga + x] == noturn) {//��

		if (pans[po.se][po.ga + x] == noturn) {

			count++;//���� ���� �ִ� ��ŭ count�� 1�� ���Ѵ� 

		}

		x++;

		if (pans[po.se][po.ga + x] == turn)

			ck = 1;//�������� �ڱ⵹�� �ִٸ� 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count��ŭ ���ǵ��� �ڱ⵹�� �ٲ۴� 

			pans[po.se][po.ga + x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se - x][po.ga + x] == noturn) {//����

		if (pans[po.se - x][po.ga + x] == noturn) {

			count++;//���� ���� �ִ� ��ŭ count�� 1�� ���Ѵ� 

		}

		x++;

		if (pans[po.se - x][po.ga + x] == turn)

			ck = 1;//�������� �ڱ⵹�� �ִٸ� 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count��ŭ ���ǵ��� �ڱ⵹�� �ٲ۴� 

			pans[po.se - x][po.ga + x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se - x][po.ga] == noturn) {//��

		if (pans[po.se - x][po.ga] == noturn) {

			count++;//���� ���� �ִ� ��ŭ count�� 1�� ���Ѵ� 

		}

		x++;

		if (pans[po.se - x][po.ga] == turn)

			ck = 1;//�������� �ڱ⵹�� �ִٸ� 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count��ŭ ���ǵ��� �ڱ⵹�� �ٲ۴� 

			pans[po.se - x][po.ga] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se - x][po.ga - x] == noturn) {//�ϼ�

		if (pans[po.se - x][po.ga - x] == noturn) {

			count++;//���� ���� �ִ� ��ŭ count�� 1�� ���Ѵ� 

		}

		x++;

		if (pans[po.se - x][po.ga - x] == turn)

			ck = 1;//�������� �ڱ⵹�� �ִٸ� 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count��ŭ ���ǵ��� �ڱ⵹�� �ٲ۴� 

			pans[po.se - x][po.ga - x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se][po.ga - x] == noturn) {//��

		if (pans[po.se][po.ga - x] == noturn) {

			count++;//���� ���� �ִ� ��ŭ count�� 1�� ���Ѵ� 

		}

		x++;

		if (pans[po.se][po.ga - x] == turn)

			ck = 1;//�������� �ڱ⵹�� �ִٸ� 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count��ŭ ���ǵ��� �ڱ⵹�� �ٲ۴� 

			pans[po.se][po.ga - x] = turn;

		}

	}

	//----------------------------------------------------------

	x = 1;

	count = 1;

	ck = 0;

	while (pans[po.se + x][po.ga - x] == noturn) {//����

		if (pans[po.se + x][po.ga - x] == noturn) {

			count++;//���� ���� �ִ� ��ŭ count�� 1�� ���Ѵ� 

		}

		x++;

		if (pans[po.se + x][po.ga - x] == turn)

			ck = 1;//�������� �ڱ⵹�� �ִٸ� 

	}

	if (ck == 1) {

		for (x = 1; x <= count; x++) {//count��ŭ ���ǵ��� �ڱ⵹�� �ٲ۴� 

			pans[po.se + x][po.ga - x] = turn;

		}

	}

}

void turn_change() {//���� �ٲ۴� 

	if (turn == 'o')turn = 'x';

	else turn = 'o';

}

void mark() {//?�� �ٽ� .���� �ٲ۴� 

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

void dol_num() {//������ ������ �˾ƺ��� 

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

void mu() {//������ ����� 

	int i, j;

	char m[100] = "E:\Othello";

	strncat(m, &turn);

	strncat(m, ".txt");

	FILE* min;

	min = fopen(m, "w");

	fprintf(min, "%c ", turn);//������ 

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			fprintf(min, "%d ", pans[i][j]);//���� �������� 

		}

	}

	fclose(min);

}

void save() {//���� 

	int i, j;

	char c[100] = "E:\Othello";

	FILE* sv;

	sv = fopen(c, "w");

	fprintf(sv, "%c ", turn);//������ 

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			fprintf(sv, "%d ", pans[i][j]);//���� �������� 

		}

	}

	fclose(sv);

}

void insave() {//�ҷ����� 

	int i, j;

	char c[100] = "E:\Othello";

	FILE* insv;

	insv = fopen(c, "r");

	fscanf(insv, "%c", &turn);//�Ϻҷ����� 

	for (i = 1; i <= PAN_SIZE; i++)

	{

		for (j = 1; j <= PAN_SIZE; j++)

		{

			fscanf(insv, "%d", &pans[i][j]);//���� ���� �ҷ����� 

		}

	}

	fclose(insv);

}

int end() {//������ ���� 

	dol_num();

	if ((st.o + st.x) == PAN_SIZE * PAN_SIZE || end_count == 2) {//���ǰ����� �������ִ� �ڸ��� �������� �Ѵ� �Ѱ��� ������ 

		printf("o�� ����:%d", st.o);

		printf("x�� ����:%d", st.x);

		if (st.o > st.x) {

			printf("o�� �¸�!\n");

		}

		else if (st.o == st.x) {

			printf("���º�!\n");

		}

		else {

			printf("x�� �¸�!\n");

		}

		pan_print();

		return 0;

	}

	return 1;

}
