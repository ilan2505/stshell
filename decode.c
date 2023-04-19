#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: decode <codec> <message>\n");
        return 1;
    }

    void *lib_handle;
    void (*decode_func)(char*);

    // char lib_name[256];
    lib_handle = dlopen(argv[1], RTLD_LAZY);
    // lib_handle = dlopen(lib_name, RTLD_NOW);
    if (!lib_handle) {
        printf("Error loading library: %s\n", dlerror());
        return 1;
    }

    decode_func = dlsym(lib_handle, "decode");
    if (!decode_func) {
        printf("Error loading function: %s\n", dlerror());
        dlclose(lib_handle);
        return 1;
    }

    decode_func(argv[2]);

    dlclose(lib_handle);
    return 0;
}
