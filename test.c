#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10000

typedef struct kv {
    char *key;
    char *value;
    struct kv *next;
} KeyValuePair;

typedef struct {
    KeyValuePair **buckets;
    int size;
} HashTable;

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

HashTable *create_table(int size) {
    HashTable *table = malloc(sizeof(HashTable));
    table->buckets = calloc(size, sizeof(KeyValuePair *));
    table->size = size;
    return table;
}

void destroy_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        KeyValuePair *pair = table->buckets[i];
        while (pair != NULL) {
            KeyValuePair *next = pair->next;
            free(pair->key);
            free(pair->value);
            free(pair);
            pair = next;
        }
    }
    free(table->buckets);
    free(table);
}

void insert(HashTable *table, const char *key, const char *value) {
    unsigned long index = hash(key) % table->size;
    KeyValuePair *pair = table->buckets[index];

    while (pair != NULL) {
        if (strcmp(pair->key, key) == 0) {
            free(pair->value);
            pair->value = strdup(value);
            return;
        }
        pair = pair->next;
    }

    pair = malloc(sizeof(KeyValuePair));
    pair->key = strdup(key);
    pair->value = strdup(value);
    pair->next = table->buckets[index];
    table->buckets[index] = pair;
}

char *lookup(HashTable *table, const char *key) {
    unsigned long index = hash(key) % table->size;
    KeyValuePair *pair = table->buckets[index];

    while (pair != NULL) {
        if (strcmp(pair->key, key) == 0) {
            return pair->value;
        }
        pair = pair->next;
    }

    return NULL;
}

void read_file(HashTable *table, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char *line = NULL;
    size_t line_size = 0;
    ssize_t line_length;

    while ((line_length = getline(&line, &line_size, file)) != -1) {
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[line_length - 1] = '\0';
        }

        char *key = strtok(line, "$");
        char *value = strtok(NULL, "$");

        if (key != NULL && value != NULL) {
            insert(table, key, value);
        }
    }

    free(line);
    fclose(file);
}

int main(int argc, char **argv) {
    HashTable *table = create_table(TABLE_SIZE);

    if (argc > 1) {
        read_file(table, argv[1]);
    }

    char *line = NULL;
    size_t line_size = 0;
    ssize_t line_length;

    while ((line_length = getline(&line, &line_size, stdin)) != -1) {
        if (line_length > 0 && line[line_length - 1] == '\n') {
            line[line_length - 1] = '\0';
        }

        char *value = lookup(table, line);
        if (value != NULL) {
            printf("%s\n", value);
        } else {
            printf("%s: Not found.\n", line);
        }
    }

    free(line);
    destroy_table(table);

    return 0;
}