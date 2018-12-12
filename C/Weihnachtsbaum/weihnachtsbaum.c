	// include input/output, EXIT_SUCCESS constant and booleans
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

	// get height of the tree
int readTreeHeight() {
	printf("Ho Ho Ho. Ho-w high do you want the tree to be?\n");
	int lines;
	scanf("%2d", &lines);
	return lines;
}

	// print out each line of the tree to the console
void printLine(int maxWidth, int line) {
    int i;
    int j;
    int k;
		// calculate tree width and dot portion
	int treeWidth = line + (line - 1);
	int dotPortion = (maxWidth - treeWidth) / 2;
		// print left side dots
	for (i = 0; i < dotPortion; i++) {
		printf("."); }
		// print tree
	for (j = 0; j < treeWidth; j++) {
		printf("*"); }
		// print right side dots
	for (k = 0; k < dotPortion; k++) {
		printf("."); }

	printf("\n");
}

	// start program
int main() {
    int i;
		// calculate width from height
	int height = readTreeHeight();
	int maxWidth = height * 2 - 1;

		// print each row of the tree
	for (i = 1; i <= height; i++) {
		printLine(maxWidth, i);
	}

	return EXIT_SUCCESS;
}
