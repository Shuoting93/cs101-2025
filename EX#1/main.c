#include <stdio.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    int ra[3];
    char rb[3]; 
    float rc[3];


    fp = fopen("a.bin", "wb+");
    if (fp == NULL) {
        perror("error");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        fwrite(&a[i], sizeof(int), 1, fp);
    }
    for (int i = 0; i < 3; i++) {
        fwrite(&b[i], sizeof(char), 1, fp);
    }
    for (int i = 0; i < 3; i++) {
        fwrite(&c[i], sizeof(float), 1, fp);
    }

    
    fseek(fp, 0, SEEK_SET);

    
    for (int i = 0; i < 3; i++) {
        fread(&ra[i], sizeof(int), 1, fp);
    }
    for (int i = 0; i < 3; i++) {
        fread(&rb[i], sizeof(char), 1, fp);
    }
    for (int i = 0; i < 3; i++) {
        fread(&rc[i], sizeof(float), 1, fp);
    }

    
    fclose(fp);

    
    for (int i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%c ", rb[i]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%.6f ", rc[i]);
    }
    printf("\n");

    return 0;
}

