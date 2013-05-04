#include "convert.h"
/** \brief Entry point of hhr2tsv
 * Convert hhr file from HHBlits output to tsv (tab separated values) file
 * Usage: hhr2tsv <hhr_file> <tsv_file>
 */
int main(int argc, const char** argv)
{
	FILE *fhhr, *ftsv;

	if (argc < 3) {
		printf("Convert hhr file to tsv format\nUsage: hhr2tsv <hhr> <tsv>\n");
		return 0;
	}

	fhhr = fopen(argv[1], "r");
	if (fhhr == NULL) {
		perror("Unable to open hhr file!");
		return -1;
	}

	ftsv = fopen(argv[2], "w");
	if (ftsv == NULL) {
		perror("Unable to create tsv file!");
		fclose(fhhr);
		return -1;
	}

	hhr2tsv(fhhr, ftsv);

	fclose(fhhr);
	fflush(ftsv);
	fclose(ftsv);

	printf("Done!\n");

	return 0;
}

