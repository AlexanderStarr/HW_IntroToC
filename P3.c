#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 100

void trim(char *string) {
    size_t len = strlen(string) - 1;
    if(string[len] == '\n') string[len] = '\0';
}

int main() {
    // First open the files.
    FILE *wiki = fopen("wiki.txt", "r");
    FILE *authors = fopen("authors.txt", "r");
    FILE *output = fopen("wikiauthor.txt", "w");

    // Initialize the needed variables.
    char read_line[LINE_LEN], search_line[LINE_LEN];
    char *item_ptr, *search_ptr;

    // Read all the lines in wiki.txt.
    while(fgets(read_line, sizeof(read_line), wiki) != NULL) {
        trim(read_line);
        // For each read_line, copy elements 1 and 2.
        // strtok returns a ptr to elements, and advances when called with NULL.
        item_ptr = strtok(read_line, ",");
        for (int i=0; i<2; i++) {
            fprintf(output, "%s,", item_ptr);
            item_ptr = strtok(NULL, ",");
        }
        // Now we need to find the line in authors.txt that starts
        // with the string item_ptr and copy it into output.
        while(fgets(search_line, sizeof(search_line), authors) != NULL) {
            trim(search_line);
            search_ptr = strtok(search_line, ",");
            //printf("Searching for %s, found %s", item_ptr, search_ptr);
            if(strcmp(item_ptr, search_ptr) == 0) {
                printf("Match found/n");
                search_ptr = strtok(NULL, ",");
                fprintf(output, "%s,", search_ptr);
                search_ptr = strtok(NULL, ",");
                fprintf(output, "%s\n", search_ptr);
                break;
            }
        }
        authors = fopen("authors.txt", "r");
    }
    return 0;
}