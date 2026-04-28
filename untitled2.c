#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);
	// 注意：这里不需要 getchar()，因为 N 后面的换行符会被下一次 scanf 吃掉

	for (int t = 1; t <= N; t++)
	{
		int n1, n2;
		// 读取 n1, n2
		if (scanf("%d %d", &n1, &n2) != 2)   // 检查返回值很重要
		{
			fprintf(stderr, "Error reading n1, n2 for case %d.\n", t);
			return 1;
		}
		getchar(); // <--- 关键修复：吃掉 5 6 后面的换行符

		if (n1 <= 0 || n2 <= 0)
		{
			fprintf(stderr, "n1 and n2 must be positive for case %d.\n", t);
			return 1;
		}

		char *string = (char*)malloc(sizeof(char) * (n1 + 1));
		char *a = (char*)malloc(sizeof(char) * (n2 + 1));

		if (!string || !a)
		{
			perror("malloc failed");
			free(string);
			free(a);
			return 1;
		}

		// 读取 string
		if (scanf("%s", string) != 1)   // 检查返回值
		{
			fprintf(stderr, "Error reading string for case %d.\n", t);
			free(string);
			free(a);
			return 1;
		}
		// 验证长度（可选）
		if (strlen(string) != n1)
		{
			fprintf(stderr, "Warning: String length mismatch for case %d.\n", t);
			// 可选择退出或继续
		}

		// 读取 a
		if (scanf("%s", a) != 1)   // 检查返回值
		{
			fprintf(stderr, "Error reading command string for case %d.\n", t);
			free(string);
			free(a);
			return 1;
		}

		// 主逻辑：模拟光标移动
		char *p = string;
		char *cmd = a; // 用 cmd 遍历 a，不修改 a 本身，方便最后释放 a
		while (*cmd)
		{
			if (*cmd == 'L')
			{
				if (p > string) p--;
			}
			else if (*cmd == 'R')
			{
				if (p < &string[n1 - 1]) p++; // 修正边界，防止 p 越界到 \0 之后
			}
			else if (*cmd == 'U')
			{
				if (*p == '9') *p = '0';
				else (*p)++;
			}
			else if (*cmd == 'D')
			{
				if (*p == '0') *p = '9';
				else (*p)--;
			}
			cmd++;
		}

		printf("%s\n", string);

// 释放内存
		free(string);
		free(a);
	}

	return 0;
}
