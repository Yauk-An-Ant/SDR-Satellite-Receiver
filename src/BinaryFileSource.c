#include "BinaryFileSource.h"
#include <stdlib.h>
#include <string.h>

static size_t binary_file_read(ISource* self, float _Complex *buffer, size_t num_samples);
static void binary_file_destroy(ISource* self);

BinaryFileSource* binary_file_source_create (const char* filepath) {
    FILE* f = fopen(filepath, "rb");
    if(!f) return NULL;
    
    BinaryFileSource* src = (BinaryFileSource*)malloc(sizeof(BinaryFileSource));
    if(!src) {
        fclose(f);
        return NULL;
    }

    //set function pointers
    src->base.read = binary_file_read;
    src->base.destroy = binary_file_destroy;
    src->file = f;
    return src;
}

static size_t binary_file_read(ISource* self, float _Complex *buffer, size_t num_samples) {
    if(!self) return 0;
    BinaryFileSource* file_src = (BinaryFileSource*)self;
    if(!file_src->file) return 0;

    size_t items_read = fread(buffer, sizeof(float _Complex), num_samples, file_src->file);
    return items_read;
}

//free mem
static void binary_file_destroy(ISource* self) {
    if(!self) return;
    BinaryFileSource* file_src = (BinaryFileSource*)self;
    if(file_src->file) fclose(file_src->file);
    free(file_src);
}