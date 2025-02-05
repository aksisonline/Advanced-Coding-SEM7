#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int key;
    int val;
    struct node *next;
    struct node *prev;
};

typedef struct
{
    int cap;
    int count;
} LRUCache;

struct node *head;
struct node *tail;

struct node *rem[10001];
LRUCache *lRUCacheCreate(int capacity)
{

    LRUCache *cache = malloc(sizeof(LRUCache));
    cache->cap = capacity;
    cache->count = 0;
    head = malloc(sizeof(struct node));
    tail = malloc(sizeof(struct node));

    head->next = tail;
    tail->prev = head;

    for (int i = 0; i < 10001; i++)
        rem[i] = NULL;

    return cache;
}

void del(struct node *curr)
{

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
}

void add(struct node *curr)
{

    curr->next = head->next;
    curr->prev = head;

    head->next->prev = curr;
    head->next = curr;
}

int lRUCacheGet(LRUCache *obj, int key)
{
    if (obj->count == 0)
        return -1;

    if (rem[key] == NULL)
        return -1;

    int val;
    struct node *curr = rem[key];
    val = curr->val;
    del(curr);
    add(curr);
    return val;
}

void lRUCachePut(LRUCache *obj, int key, int value)
{

    printf("key=%d\n", key);
    if (rem[key] != NULL)
    {

        struct node *curr = rem[key];
        curr->val = value;
        del(curr);
        add(curr);
    }

    else
    {

        if (obj->count == obj->cap)
        {
            obj->count--;
            rem[tail->prev->key] = NULL;
            del(tail->prev);
        }

        obj->count++;
        struct node *curr = malloc(sizeof(struct node));
        curr->val = value;
        curr->key = key;
        printf("curr=%p\n", (void *)curr);
        printf("add key=%d val =%d \n", key, value);
        rem[key] = curr;
        add(curr);
    }
}

void lRUCacheFree(LRUCache *obj)
{

    for (int i = 0; i <= 10000; i++)
        if (rem[i])
            free(rem[i]);

    free(head);
    free(tail);
    free(obj);
}

int main() {
    char* operations[] = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    int values[][2] = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};
    int results[10];
    int index = 0;
    LRUCache* cache = NULL;

    for (int i = 0; i < 10; i++) {
        if (strcmp(operations[i], "LRUCache") == 0) {
            cache = lRUCacheCreate(values[i][0]);
            results[index++] = -1; // Corresponds to "null"
        } else if (strcmp(operations[i], "put") == 0) {
            lRUCachePut(cache, values[i][0], values[i][1]);
            results[index++] = -1; // Corresponds to "null"
        } else if (strcmp(operations[i], "get") == 0) {
            results[index++] = lRUCacheGet(cache, values[i][0]);
        }
    }

    printf("[");
    for (int i = 0; i < index; i++) {
        if (i != 0) {
            printf(", ");
        }
        if (results[i] == -1) {
            printf("null");
        } else {
            printf("%d", results[i]);
        }
    }
    printf("]\n");

    lRUCacheFree(cache);
    return 0;
}