#include<stdio.h>
#include<string.h>

int main(){
    FILE* file1 = fopen("_1/file1.txt", "r");
    FILE* file2 = fopen("_1/file2.txt", "r");
    FILE *file3 = fopen("_1/file3.txt", "w");

    if(file1 == NULL || file2 == NULL || file3 == NULL){
        printf("Error opening files.\n");
        return 1;
    }
    
    char str1[100], str2[100], str3[200];
    int i = 0, j = 0, k = 0;

    fgets(str1, sizeof(str1), file1);
    fgets(str2, sizeof(str2), file2);
    
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    
    while(str1[i] != '\0' || str2[j] != '\0'){
        if(str1[i] != '\0'){
            str3[k++] = str1[i++];
        }
        if(str2[j] != '\0'){
            str3[k++] = str2[j++];
        }
    }
    
    // Append remaining characters from longer string
    while(str1[i] != '\0'){
        str3[k++] = str1[i++];
    }
    while(str2[j] != '\0'){
        str3[k++] = str2[j++];
    }
    
    // Null-terminate the merged string
    str3[k] = '\0';
    
    // Write str3 into file3
    fprintf(file3, "%s", str3);
    
    // Close the files
    fclose(file1);
    fclose(file2);
    fclose(file3);
    
    return 0;
}