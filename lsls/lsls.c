#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/errno.h>


/**
 * Main
 */
int main(int argc, char **argv)
{
    char *path = argv[1];
    
    
    if (argc < 2) {
        path = ".";
    }
    
    DIR *dir = opendir(path);
    
    if (dir == NULL)
    {
        fprintf(stderr, "error: '%s': can't open this directory: %s\n", path, strerror(errno));
        exit(1);
    }
    
    struct dirent *ent = readdir(dir);
    
    
    while (ent != NULL)
    {
        char file_path[100];
        sprintf(file_path, "%s/%s", path, ent->d_name);
        struct stat buf;
        if (stat(file_path, &buf) == -1) {
            fprintf(stderr, "error: '%s': %s\n", file_path, strerror(errno));
            exit(1);
        } else {
            if (S_ISDIR(buf.st_mode)) {
                printf("<DIR>  %s\n", ent->d_name);
            } else {
                long long file_size = buf.st_size ;
                printf("%lld", file_size);
                printf("\t%s\n", ent->d_name);
            }
            ent = readdir(dir);
        }
    }
    
    // Close directory
    closedir(dir);
    
    
    return 0;
    
}
