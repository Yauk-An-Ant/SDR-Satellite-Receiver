#include <stdio.h>
#include "BinaryFileSource.h"

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

    float _Complex buffer[1056];
    size_t read_count = isource->read(isource, buffer, 1056);
    printf("Successfully read %zu samples from file.\n", read_count);
    isource->destroy(isource);
    return 0;
}