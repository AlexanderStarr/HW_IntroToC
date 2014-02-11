#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 100

// Trims the newline character from a string.
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

    // Read, trim, and copy all the lines in wiki.txt.
    while(fgets(read_line, sizeof(read_line), wiki) != NULL) {
        trim(read_line);
        // For each read_line, copy elements 1 and 2.
        // strtok returns a ptr to elements delimited by ","
        // and advances to the next one when called with NULL.
        item_ptr = strtok(read_line, ",");
        for (int i=0; i<2; i++) {
            fprintf(output, "%s,", item_ptr);
            item_ptr = strtok(NULL, ",");
        }
        // item_ptr now points to the author ID.
        // Find the line in authors.txt with that ID and copy it into output.
        while(fgets(search_line, sizeof(search_line), authors) != NULL) {
            trim(search_line);
            search_ptr = strtok(search_line, ",");
            // If search_ptr == item_ptr, the author IDs match and we copy.
            if(strcmp(item_ptr, search_ptr) == 0) {
                search_ptr = strtok(NULL, ",");
                fprintf(output, "%s,", search_ptr);
                search_ptr = strtok(NULL, ",");
                fprintf(output, "%s", search_ptr);
                break;
            }
        }
        // Starts a new line even if the auther ID was not found.
        fprintf(output, "\n");
        // Start the authors file back at the beginning for the next search.
        authors = fopen("authors.txt", "r");
    }
    // Close all the files.
    int fclose(FILE *wiki);
    int fclose(FILE *authors);
    int fclose(FILE *output);
    fclose(wiki);
    fclose(authors);
    fclose(output);
    return 0;
}
