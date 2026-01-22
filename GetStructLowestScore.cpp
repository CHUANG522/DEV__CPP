#include <stdio.h>
// 题目：已知学生的记录由学号和学习成绩构成，N 名学生的数据已存入 a
// 结构体数组中。 请编写函数 fun，该函数的功能是：
// 找出成绩最低的学生记录，通过形参返回主函数（规定只有一个最低分）
struct student_formation {
  int ID;
  int score; // 结构体定义时不初始化
};
void fun(student_formation a[], int N, int *min);

int main(void) {
  int N = 3;
  // 前面以及说明结构体的成员类型，这里直接赋值即可
  struct student_formation a[] = {{1, 80}, {2, 90}, {3, 89}};
  int min = a[0].score;
  fun(a, N, &min);
  printf("%d", min);
  return 0;
}
// 参数要结构体数组，*min是对main中min变量的直接修改
void fun(student_formation a[], int N, int *min) {
  for (int i = 0; i < N; i++) {

    if (*min >= a[i].score) {
      *min = a[i].score; // 找min
    }
  }
}
