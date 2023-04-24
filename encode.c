#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: encode <codec> <message>\n");
        return 1;
    }

    void *lib_handle;
    void (*encode_func)(char*);

    // char lib_name[256];
    // snprintf(lib_name, sizeof(lib_name), "%s%s", argv[1], ".so");

    lib_handle = dlopen(argv[1], RTLD_LAZY);
    if (!lib_handle) {
        printf("Error loading library: %s\n", dlerror());
        return 1;
    }

    encode_func = dlsym(lib_handle, "encode");
    if (!encode_func) {
        printf("Error loading function: %s\n", dlerror());
        dlclose(lib_handle);
        return 1;
    }

    encode_func(argv[2]);

    dlclose(lib_handle);
    return 0;
}
