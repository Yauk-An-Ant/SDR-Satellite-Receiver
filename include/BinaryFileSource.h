#ifndef BINARY_SOURCE_FILE_H
#define BINARY_SOURCE_FILE_H

#include<complex.h>
#include<stddef.h>
#include<stdio.h>

typedef struct ISource ISource;

struct ISource {
    size_t (*read)(ISource* self, float _Complex buffer, size_t num_samples);
    void (*destroy)(ISource* self);
};

typedef struct {
    ISource base;
    FILE* file;
} BinaryFileSource;

BinaryFileSource* binary_file_source_create(const char* filepath);

#endif