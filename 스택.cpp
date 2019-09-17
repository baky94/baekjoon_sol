#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	int * arr = (int*)malloc(sizeof(int) * n);

	char buf[15];
	char tmp[4];
	int length = 0;

	for (int tc = 0; tc<n; tc++) {
		fgets(buf, 13, stdin);

		for (int i = 0; i<3; i++) {
			tmp[i] = buf[i];

		}
		//printf("%s\n",buf);


		if (!strncmp(tmp, "pus", 3)) {
			char num[9];
			int val;
			int k = 0;
			for (int i = 5;; i++) {
				if (buf[i] == NULL)
					break;
				num[k++] = buf[i];
				//printf("%c",buf[i]);
			}
			//printf("%s\n",num);
			val = atoi(num);
			//printf("%d\n",val);
			arr[length++] = val;
		}
		else if (!strncmp(tmp, "pop", 3)) {
			if (length != 0) {
				
				printf("%d\n", arr[length-1]);
				length--;
			}
			else	printf("-1\n");
		}

		else if (!strncmp(tmp, "siz", 3)) {
			printf("%d\n", length);
		}

		else if (!strncmp(tmp, "emp", 3)) {
			if (length == 0) {
				printf("1\n");
			}
			else	printf("0\n");
		}

		else if (!strncmp(tmp, "top", 3)) {
			if (length != 0) {
				//printf("%d\n", length);
				printf("%d\n", arr[length-1]);
			}
			else	printf("-1\n");
		}




	}
	free(arr);
}
