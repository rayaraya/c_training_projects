#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define default_size 8
#define CONST_FOR_TABLE 50

typedef int T;

enum errors
{
	SUCCESS,
	ERROR_ALLOCATE_MEM,
	ERROR_NOT_FOUND
};

struct htbl_unit
{
	uint32_t hash;
	char* key;
	size_t len;
	struct htbl_unit* next_unit;
	T data;
};

struct htable
{
	uint32_t mask;
	size_t htbl_size;
	size_t htbl_items;
	struct htbl_unit** htble_units;
	size_t max_list_len;
};

uint32_t htable_hash(const char *key, const size_t len);

struct htable* htable_create(size_t size);

size_t htable_free(struct htable* tbl);

size_t htable_del(struct htable* tbl, const char* key, const size_t len, T* data);

size_t htable_get(struct htable* tbl, const char* key, const size_t len, T* data);

size_t htable_set(struct htable** tbl_ptr, const char* key, const size_t len, T* data);

size_t htable_resize(struct htable** tbl_ptr);

void htable_dump_p(struct htable* tbl);

void htable_dump_n(struct htable* tbl);

char* htable_iter_key(struct htable *tbl, const char* key);

struct htbl_unit* htable_iter(struct htable* tbl, struct htbl_unit* unit);

uint32_t htable_hash(const char *key, const size_t len) /*Jenkins hash function, https://en.wikipedia.org/wiki/Jenkins_hash_function*/
{
	uint32_t hash, i;

	for(hash = i = 0; i < len; ++i) 
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}

	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash;
}

struct htable* htable_create(size_t size)
{
	struct htable* tbl = (struct htable*) calloc (1, sizeof(struct htable));
	if(tbl == NULL)
	{
		perror("error during allocate memory for htable");
		return NULL;
	}
	tbl->mask = size;
	tbl->htbl_size = size;
	tbl->htbl_items = 0;
	tbl->max_list_len = 0;
	tbl->htble_units = (struct htbl_unit**)calloc(tbl->htbl_size, sizeof(struct htbl_unit*)); 

	size_t i;
	for(i = 0; i < size; i++)
	{
		tbl->htble_units[i] = NULL;
	}
	if(tbl->htble_units == NULL)
	{	
		perror("error during allocate memory for htable array");
		return NULL;
	}
	return tbl;
}

size_t htable_set(struct htable** tbl_ptr, const char* key, const size_t len, T* data)
{
	struct htable* tbl = *tbl_ptr;
	tbl->htbl_items++;
	size_t temp_len = 0;

	uint32_t hash = htable_hash(key, len);

	struct htbl_unit* temp = tbl->htble_units[hash % tbl->mask];

	if(temp == NULL)
	{
		temp = tbl->htble_units[hash % tbl->mask] =
		(struct htbl_unit*)calloc(1, sizeof(struct htbl_unit));
		temp_len = 1;
	}
	else
	{
		temp_len = 1;
		while(temp->next_unit != NULL)
		{
			temp_len++;
			if(!strcmp(temp->key, key))
			{
				memcpy(&(temp->data),data, sizeof(T));
				return SUCCESS;
			}
			temp = temp->next_unit;
		}
		if(!strcmp(temp->key, key))
		{
			memcpy(&(temp->data),data, sizeof(T));
			return SUCCESS;
		}
		else
		{
			temp_len++;
			temp = temp->next_unit = (struct htbl_unit*)calloc(1, sizeof(struct htbl_unit));
		}
	}

	if(temp == NULL)
			return ERROR_ALLOCATE_MEM;
	temp->hash = hash;

	temp->key = (char*)calloc(1, sizeof(char)*strlen(key) + 1);

	if (temp->key == NULL)
		return ERROR_ALLOCATE_MEM;

	memcpy(temp->key, key, sizeof(char)*strlen(key) + 1);
	temp->len = len;
	temp->next_unit = NULL;
	memcpy(&temp->data, data, sizeof(T));

	if(tbl->max_list_len < temp_len)
		tbl->max_list_len = temp_len;

	if (tbl->max_list_len >= CONST_FOR_TABLE)
		htable_resize(tbl_ptr);

	return SUCCESS;
}

size_t htable_get(struct htable* tbl, const char* key, const size_t len, T* data)
{
	uint32_t hash = htable_hash(key, len);
	struct htbl_unit* temp = tbl->htble_units[hash % tbl->mask];

	if(temp == NULL)
		return ERROR_NOT_FOUND;
	else
	{
		while(temp != NULL)
		{
			if (strcmp(temp->key,key) == 0)
			{
				memcpy(data, &temp->data, sizeof(T));
				return SUCCESS;
			}
			temp = temp->next_unit;
		}
		return ERROR_NOT_FOUND;
	}
}

size_t htable_del(struct htable* tbl, const char* key, const size_t len, T* data)
{
	uint32_t hash = htable_hash(key, len);
	struct htbl_unit* temp = tbl->htble_units[hash % tbl->mask];
	struct htbl_unit* prev_temp = temp;

	if(temp == NULL)
		return ERROR_NOT_FOUND;
	else
	{
		while(temp != NULL)
		{

			if (strcmp(temp->key,key) == 0)
			{
				memcpy(data, &temp->data, sizeof(T));
				if(prev_temp == temp)
				{
					tbl->htble_units[hash % tbl->mask] = temp->next_unit;
					free(temp->key);
					free(temp);
				}
				else
				{
					prev_temp->next_unit = temp->next_unit;
					free(temp->key);
					free(temp);
				}
				tbl->htbl_items--;
				return SUCCESS;
			}
			prev_temp = temp;
			temp = temp->next_unit;
		}
		return ERROR_NOT_FOUND;
	}
}

size_t htable_free(struct htable* tbl)
{
	size_t i;
	struct htbl_unit* temp;
	struct htbl_unit* p_temp;
	for (i = 0; i < tbl->htbl_size; i++)
	{
		temp = tbl->htble_units[i];
		while(temp != NULL)
		{
			p_temp = temp;
			temp = temp->next_unit;
			free(p_temp->key);
			free(p_temp);
		}
	}
	free(tbl->htble_units);
	free(tbl);
	return SUCCESS;
}

size_t htable_resize(struct htable** tbl_ptr)
{
	struct htable* tbl = *tbl_ptr;

	struct htable* temp = htable_create(tbl->htbl_size * 2);

	size_t i;
	struct htbl_unit* temp_unit;

	for (i = 0; i < tbl->htbl_size; i++)
	{
		temp_unit = tbl->htble_units[i];
		while(temp_unit != NULL)
		{
			htable_set(&temp, temp_unit->key, strlen(temp_unit->key) + 1, &(temp_unit->data));
			temp_unit = temp_unit->next_unit;
		}
	}
	htable_free(tbl);

	*tbl_ptr = temp;

	return SUCCESS;
}

void htable_dump_p(struct htable* tbl)
{
	size_t i;
	struct htbl_unit* temp;
	printf("\n");
	for (i = 0; i < tbl->htbl_size; i++)
	{
		printf("cell %lu: ", i);
		temp = tbl->htble_units[i];
		while(temp != NULL)
		{
			printf(".");
			temp = temp->next_unit;
		}
		printf("\n");
	}
}

void htable_dump_n(struct htable* tbl)
{
	size_t i;
	struct htbl_unit* temp;
	printf("\n");
	for (i = 0; i < tbl->htbl_size; i++)
	{
		printf("cell %lu: ", i);
		temp = tbl->htble_units[i];
		while(temp != NULL)
		{
			printf("%s ",temp->key);
			temp = temp->next_unit;
		}
		printf("\n");
	}
}

struct htbl_unit* htable_iter(struct htable* tbl, struct htbl_unit* unit)
{
	if(unit == NULL)
		return NULL;

	char * key = unit->key;
	uint32_t hash = htable_hash(key, strlen(key) + 1);

	if(unit->next_unit != NULL)
		return unit->next_unit;
	else
	{
		size_t i;
		for(i = hash % tbl->mask + 1; i < tbl->htbl_size; i++)
		{
			if(tbl->htble_units[i] != NULL)
				return tbl->htble_units[i];
		}
	}

	return NULL;
}

char* htable_iter_key(struct htable *tbl, const char* key)
{
	uint32_t hash = htable_hash(key, strlen(key) + 1);
	struct htbl_unit* temp = tbl->htble_units[hash % tbl->mask];

	if(temp == NULL)
		return NULL;

	if(temp->next_unit != NULL)
	{
		while(temp->next_unit != NULL)
		{
			if (strcmp(temp->key,key) == 0)
			{
						return temp->next_unit->key;
			}
			temp = temp->next_unit;
		}
	}

	size_t i;
	for(i = hash % tbl->mask + 1; i < tbl->htbl_size; i++)
	{
		if(tbl->htble_units[i] != NULL)
			return tbl->htble_units[i]->key;
	}

	return NULL;
}
