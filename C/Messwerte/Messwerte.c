	// include input/output, EXIT_SUCCESS constant and booleans
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

	// fixed min and max values for coordinates and temperature
const int POSMAX = 1023;
const int POSMIN = -1024;
const int TEMPMAX = 85;
const int TEMPMIN = -40;

	// Gets the number of lines (tree-digit integer) and returns it.
int readNumberOfLines() {
	int lines; {
		printf("Hi, how many lines do you want the table to have?\n");
		scanf("%2d", &lines);
	}
	return lines;
}
	/* Input loop for measurement data
	 *which checks if the gives value is within the min and max values.*/
void readTemperaturAtPosition(int count, double* data_set) {
	bool values_invalid = true;
	do {
		/* consecutive numeration of measured values
		 * get measured values and position
		 * checking for possible errors. */
		printf("x position for temperature #%02i:", count + 1);
		scanf("%10lf", &data_set[0]);
		printf("y position for temperature #%02i:", count + 1);
		scanf("%10lf", &data_set[1]);
		printf("temperature #%02i:", count + 1);
		scanf("%10lf", &data_set[2]);
			// check if coordinates are within min and max values
		if (data_set[0] < POSMIN || data_set[0] > POSMAX ||
			data_set[1] < POSMIN || data_set[1] > POSMAX) {
			printf("The position needs to be between %d and %d.\n", POSMIN, POSMAX);
		}
			// check if temperates is within the min and max values
		else if (data_set[2] < TEMPMIN || data_set[2] > TEMPMAX) {
			printf("The temperate needs to be between %d and %d.\n", TEMPMIN, TEMPMAX);
		}
			// set boolean to false when all values are valid
		else {
			values_invalid = false;
		}
	} while (values_invalid);
}

	// print table header
void printTableHeader() {
	printf("\n");
	printf("x position | y position | temperature[C]\n");
	printf("+++++++++++|++++++++++++|+++++++++++++++");
}

	// print table row
void printTableLine(double * data_set) {
	printf("\n  %+8.0f", data_set[0]);
	printf(" |  %+9.0f", data_set[1]);
	printf(" | %+06.3f", data_set[2]);
	// %[+ = algebraic sign ] [0 = left-hand zeros] [width = length of the string] [. = precision of decimal places] [f = float]
}

	// start program
int main() {
    int i;
    int j;
		// set number of table rows
	int numberOfLines = readNumberOfLines();
		// nested array[table_row][x_position, y_position, temperature]
	double data[numberOfLines][3];
		// for loop to get each rows values
	for (i = 0; i < numberOfLines; i++) {
		readTemperaturAtPosition(i, data[i]);
	}
		// first print table header then loop and print each row
	printTableHeader();
	for (j = 0; j < numberOfLines; j++) {
		printTableLine(data[j]);
	}
	return EXIT_SUCCESS;
}
