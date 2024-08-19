#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
typedef struct {
    char key[50];
    char value[50];
}KeyValue;
KeyValue hashTable[SIZE];
int hashFunction(const char* key) {
    int hash = 0,i;
    for (i = 0; key[i] != '\0'; i++)
        hash += key[i];
    return hash % SIZE;
}
void insert(const char* key, const char* value) {
    int index = hashFunction(key);
    strcpy(hashTable[index].key, key);
    strcpy(hashTable[index].value, value);
}
void removeKey(const char* key) {
    int index = hashFunction(key);
    strcpy(hashTable[index].key, "");
}
const char* search(const char* key) {
    int index = hashFunction(key);
    return hashTable[index].value;
}
int main() {
    insert("name", "manideep");
    insert("age", "18");
    printf("Name: %s\n", search("name"));
    printf("Age: %s\n", search("age"));
    removeKey("age");
    printf("Age: %s\n", search("age"));
    return 0;
}
