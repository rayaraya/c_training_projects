#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define default_size 8

typedef int T;

int main(int argc, char const *argv[]) // iterator test
{
	srand(time(NULL));
	T data = rand();

	struct htable* t = htable_create(default_size);

	size_t i;
	char a, b, c, d;
	char str[5];

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[4] = 0;

	for (i = 0; i < 13; i++)
	{
		str[3] = i + 'd';
		htable_set(&t, str, strlen(str)+1, &data);
	}

	htable_dump_n(t);
	char* key = htable_iter_key(t, "abcj");

	char p[30];

	T dat; 
	printf("get next for: ");
	while(scanf("%s", p)> 0)
	{
		if(!strcmp("print", p))
			htable_dump_n(t);
		else
		{
			if(htable_get(t, p, strlen(p) + 1, &dat) > 0)
				printf("NOT FOUND ELEMENT\n");
			else
			{
				key = htable_iter_key(t, p);

				if(key == NULL)
					printf("END TABLE\n");
				else
					printf("next = %s\n", key);
			}
		}
		printf("get next for: ");
	}

	htable_free(t);
	return 0;
}