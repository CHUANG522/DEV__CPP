#include <stdio.h>
#include <stdlib.h> // 必须包含此头文件以使用 malloc 和 free

int main()
{
	int T;
	if (scanf("%d", &T) != 1) return 0;

	while (T--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		// 1. 动态分配内存
		// 注意：字符串需要额外一个字节存放结束符 '\0'
		char *a = (char *)malloc((n + 1) * sizeof(char));
		char *s = (char *)malloc((m + 1) * sizeof(char));

		if (a == NULL || s == NULL)
		{
			// 检查内存分配是否成功
			return 1;
		}

		// 2. 读取输入
		scanf("%s", a);
		scanf("%s", s);

		// 3. 模拟过程
		int ptr = 0; // 指针初始在第 1 位 (数组下标 0)

		for (int i = 0; i < m; i++)
		{
			char cmd = s[i];

			if (cmd == 'L')
			{
				if (ptr > 0)
				{
					ptr--;
				}
			}
			else if (cmd == 'R')
			{
				if (ptr < n - 1)
				{
					ptr++;
				}
			}
			else if (cmd == 'U')
			{
				// 加一操作：(当前值 + 1) % 10
				// a[ptr] - '0' 将字符转为数字
				a[ptr] = ((a[ptr] - '0' + 1) % 10) + '0';
			}
			else if (cmd == 'D')
			{
				// 减一操作：(当前值 - 1 + 10) % 10
				// +10 是为了处理负数情况 (例如 0-1 = -1，变成 9)
				a[ptr] = ((a[ptr] - '0' - 1 + 10) % 10) + '0';
			}
		}

		// 4. 输出结果
		printf("%s\n", a);

		// 5. 释放内存
		free(a);
		free(s);
	}

	return 0;
}
