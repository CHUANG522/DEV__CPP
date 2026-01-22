#include <stdio.h>
#include <stdlib.h>

int main(void) {

  /*	char string[11] = "HUI";
          char grap = 'H';
          scanf(" %c",string);

          printf("%d\t %d \n", sizeof(string), sizeof(grap));
  for (int i =0; i<sizeof(string);i++){
          printf("%c",string[i]);
          }*/

  char *string = NULL;                                // ָ���ÿ�
  int string_len = 20;                                // �����涨�ַ�������
  int counter = 1;                                    // ���ʼ�����
  string = (char *)malloc(sizeof(char) * string_len); // ��̬�ڴ���䣬��������ת��
  if (string == NULL) {                               // ����ɹ��ж�
    perror(" The error is : ");
    return 1; // return 1 ������ʧ�ܣ���ǰ��ֹ��������
  }
  //	for (int i = 0; i < string_len; i++) {
  // scanf("%s", string);
  //	}
  fgets(string, string_len, stdin); // fgets���뺯����ʶ��ո�\0
  for (int i = 0; i < string_len; i++) {
    printf("%c", *(string + i)); // ��������ַ���
    if (*(string + i) == ' ') {  // �������ж�
      counter++;
    }
    if (*(string + i) == '\0') { // ��ֹѭ��������ʱ��
      break;
    }
  }
  printf(" \n");
  printf(" The words has %d ", counter);

  free(string);
  string = NULL; // �ͷ��ڴ棬ָ���ÿ�

  return 0;
}
