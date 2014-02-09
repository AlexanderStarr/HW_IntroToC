#include <stdio.h>
#include <stdlib.h>

int main() {
    // First open the files.
    FILE *wiki = fopen("wiki.txt", "r");
    FILE *output = fopen("wikiauthor.txt", "w");

    // Initialize the needed variables.
    int pageID, authorID;
    char title[100], author[100];
    while(fgets(wiki, "%d,%s,%d", &pageID, title, &authorID)) {
        // For each line in wiki.txt, we want to copy the pageID and title
        fprintf(output, "%d,%s \n", pageID, title);
    }
    return 0;
}