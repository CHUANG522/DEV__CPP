#include <stdio.h>
#include <stdlib.h>

int main (void) {

	/*	char string[11] = "HUI";
		char grap = 'H';
		scanf(" %c",string);

		printf("%d\t %d \n", sizeof(string), sizeof(grap));
	for (int i =0; i<sizeof(string);i++){
		printf("%c",string[i]);
		}*/


	char *string = NULL;  // 指针置空
	int  string_len = 20; // 初步规定字符串长度
	int counter = 1;      //单词计数器
	string = (char *)malloc(sizeof(char) * string_len ); //动态内存分配，勿忘类型转换
	if (string == NULL) {	//申请成功判断
		perror(" The error is : "); 
		return 1 ;          //return 1 若申请失败，提前终止整个程序
	}
//	for (int i = 0; i < string_len; i++) {
	//scanf("%s", string);
//	}
	fgets(string, string_len, stdin);// fgets输入函数可识别空格，\0
	for (int i = 0; i < string_len; i++) {
		printf("%c", *(string + i )); // 遍历输出字符串
		if ( *(string + i) == ' ') { //单词数判定
			counter ++;
		}
		if (*(string + i) == '\0') { //终止循环，减少时间
			break;
		}
	}
	printf(" \n");
	printf(" The words has %d ", counter);

	free(string);
	string = NULL; //释放内存，指针置空

	return 0;
}
