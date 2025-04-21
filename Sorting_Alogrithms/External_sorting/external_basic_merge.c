#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MEMORY_SIZE 1000 // Number of integers that fit in memory
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "sorted_output.txt"

// Function to generate an input file with random numbers if it doesn't exist
void generateInputFile(int numValues) {
    FILE *file = fopen(INPUT_FILE, "r");
    if (file) {
        fclose(file);
        printf("✅ Input file '%s' already exists.\n", INPUT_FILE);
        return;
    }

    file = fopen(INPUT_FILE, "w");
    if (!file) {
        perror("❌ Error creating input file");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < numValues; i++) {
        fprintf(file, "%d\n", rand() % 10000); // Random numbers from 0-9999
    }
    fclose(file);
    printf("✅ Created input file '%s' with %d random numbers.\n", INPUT_FILE, numValues);
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Create sorted runs (temporary sorted files)
int createSortedRuns() {
    FILE *in = fopen(INPUT_FILE, "r");
    if (!in) {
        perror("❌ Error opening input file");
        return -1;
    }

    int buffer[MEMORY_SIZE], count = 0, fileCount = 0;
    char tempFileName[20];

    while (1) {
        count = 0;
        while (count < MEMORY_SIZE && fscanf(in, "%d", &buffer[count]) == 1) {
            count++;
        }

        if (count == 0) break; // No more data to read

        qsort(buffer, count, sizeof(int), compare); // Sort in memory

        sprintf(tempFileName, "temp%d.txt", fileCount++);
        FILE *out = fopen(tempFileName, "w");
        if (!out) {
            perror("❌ Error creating temp file");
            fclose(in);
            return -1;
        }

        for (int i = 0; i < count; i++) {
            fprintf(out, "%d\n", buffer[i]);
        }
        fclose(out);
    }

    fclose(in);
    return fileCount; // Number of temporary files created
}

// Merge sorted runs using k-way merge
void mergeSortedFiles(int numFiles) {
    FILE *out = fopen(OUTPUT_FILE, "w");
    if (!out) {
        perror("❌ Error opening output file");
        return;
    }

    FILE *tempFiles[numFiles];
    int values[numFiles], activeFiles = numFiles;
    char tempFileName[20];
    int lastWritten = -1; // Track last written value to avoid duplicates

    // Open all temp files and read the first element
    for (int i = 0; i < numFiles; i++) {
        sprintf(tempFileName, "temp%d.txt", i);
        tempFiles[i] = fopen(tempFileName, "r");
        if (!tempFiles[i]) {
            perror("❌ Error opening temp file");
            activeFiles--;
            continue;
        }
        if (fscanf(tempFiles[i], "%d", &values[i]) != 1) {
            fclose(tempFiles[i]);
            tempFiles[i] = NULL;
            activeFiles--;
        }
    }

    // Multi-way merge
    while (activeFiles > 0) {
        int minIndex = -1;
        for (int i = 0; i < numFiles; i++) {
            if (tempFiles[i] && (minIndex == -1 || values[i] < values[minIndex])) {
                minIndex = i;
            }
        }

        if (minIndex == -1) break; // No active files left

        // 🚀 **Avoid Writing Consecutive Duplicates**
        if (values[minIndex] != lastWritten) {
            fprintf(out, "%d\n", values[minIndex]);
            lastWritten = values[minIndex];
        }

        // Read next number from the same file
        if (fscanf(tempFiles[minIndex], "%d", &values[minIndex]) != 1) {
            fclose(tempFiles[minIndex]);
            tempFiles[minIndex] = NULL;
            activeFiles--;
        }
    }

    fclose(out);
}

// Main function
int main() {
    int numValues = 5000; // Number of random values to generate

    // Step 1: Generate input file if not present
    generateInputFile(numValues);

    // Step 2: Create initial sorted runs
    int numFiles = createSortedRuns();
    if (numFiles <= 0) {
        printf("❌ No data to sort. Exiting.\n");
        return EXIT_FAILURE;
    }

    // Step 3: Merge sorted runs into the final sorted file
    mergeSortedFiles(numFiles);

    printf("✅ Sorting completed! Output saved in '%s'.\n", OUTPUT_FILE);
    return EXIT_SUCCESS;
}
