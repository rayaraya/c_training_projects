#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define default_size 8

typedef int T;

int main(int argc, char const *argv[]) // set and del test
{
	srand(time(NULL));
	T data = rand();

	struct htable* t = htable_create(default_size);

	FILE* f = fopen("kek.so", "rb");
	size_t i, j;
	char a, b, c, d;
	char str[5];

	for(i = 0; i < 5000; i++)
	{
		data = rand();
		fscanf(f, "%c%c%c%c", &a, &b, &c, &d);
		str[0] = a;
		str[1] = b;
		str[2] = c;
		str[3] = d;
		str[4] = 0;
		htable_set(&t, str, strlen(str)+1, &data);
		htable_dump_p(t);
		usleep(20000);
	}

	fclose(f);
	f = fopen("kek.so", "rb");
	for(i = 0; i < 5000; i++) {
		fscanf(f, "%c%c%c%c", &a, &b, &c, &d);
		str[0] = a;
		str[1] = b;
		str[2] = c;
		str[3] = d;
		str[4] = 0;
		htable_del(t, str, strlen(str)+1, &data);
		htable_dump_p(t);
		usleep(20000);
	}

	htable_free(t);
	return 0;
}