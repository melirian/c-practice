#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a structure for key-value pairs
struct KeyValuePair {
    char key[50];
    int value;
};

// Define a structure for the map
struct Map {
    struct KeyValuePair data[MAX_SIZE];
    int size;
};

// Function to initialize the map
void initializeMap(struct Map* map) {
    map->size = 0;
}

// Function to insert a key-value pair into the map
void insert(struct Map* map, const char* key, int value) {
    if (map->size < MAX_SIZE) {
        strcpy(map->data[map->size].key, key);
        map->data[map->size].value = value;
        map->size++;
    } else {
        printf("Map is full, cannot insert.\n");
    }
}

// Function to get the value associated with a key in the map
int get(struct Map* map, const char* key) {
    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->data[i].key, key) == 0) {
            return map->data[i].value;
        }
    }
    return -1; // Key not found
}

int main() {
    struct Map map;
    initializeMap(&map);

    insert(&map, "apple", 5);
    insert(&map, "banana", 3);
    insert(&map, "cherry", 7);

    printf("Value of apple: %d\n", get(&map, "apple"));
    printf("Value of banana: %d\n", get(&map, "banana"));
    printf("Value of grape: %d\n", get(&map, "grape"));

    return 0;
}
