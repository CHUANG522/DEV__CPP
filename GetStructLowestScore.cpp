#include <stdio.h>

struct student_formation {
	int ID;
	int score;
};
void	fun(student_formation a[], int N, int *min);

int main (void) {
	int N = 3;
	struct student_formation a[] = {
		{1, 80},
		{2, 90},
		{3, 89}
	};
	int min = a[0].score	;
	fun (a, N, &min);
	printf("%d", min);
	return 0;

}

void fun(student_formation a[], int N, int *min) {
	for (int i = 0; i < N; i++) {

		if ( *min >= a[i ].score) {
			*min = a[i ].score;

		}
	}

}
