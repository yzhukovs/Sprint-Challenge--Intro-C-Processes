#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
     // Parse command line
    if (argc < 2)
    {
        fprintf(stderr, "please enter directory path\n");
        exit(1);
    }
    
    char *path = argv[1];
    
    // Open directory
    
    DIR *dir = opendir(path);
    
    if (dir == NULL)
    {
        fprintf(stdout, "can't open this directory\n");
        exit(1);
    }
    
    // Repeatly read and print entries
    
    struct dirent *ent = readdir(dir);
    
    
    while (ent != NULL)
    {
        char path[100];
        sprintf(path, "%s/%s", argv[1], ent->d_name);
        struct stat buf;
        //stat(path, &buf);
        long long file_size = buf.st_size ;
        int correct = stat(path, &buf);
        correct != -1 ? printf("file size is %10lld", file_size) : printf(" ");
        printf("\t%s\n", ent->d_name);
        ent = readdir(dir);
    }
    
    
    // Close directory
    closedir(dir);
    
    
    return 0;
 
}
