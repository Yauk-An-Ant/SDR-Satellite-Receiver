#include <stdio.h>
#include "BinaryFileSource.h"

#define CHUNK_SIZE 1024

//test for milestone 1
int file_test();

int main() {
    return file_test();
}

int file_test() {
    ISource* isource = (ISource*)binary_file_source_create("../data/test_recording.bin");
    if(!isource) {
        printf("Failed to open file source\n");
        return 1;
    }
 
    float _Complex buffer[CHUNK_SIZE];
    size_t total_samples_read = 0;
    size_t chunks_processed = 0;
    size_t samples_read = 0;

    while((samples_read = isource->read(isource, buffer, CHUNK_SIZE)) > 0) {
        chunks_processed++;
        total_samples_read += samples_read;

        printf("Chunk %zu: Read %zu samples, Total samples: %zu\n", chunks_processed, samples_read, total_samples_read);
    }

    printf("Successfully read %zu samples from %zu chunks in file.\n", total_samples_read, chunks_processed);
    isource->destroy(isource);
    return 0;
}