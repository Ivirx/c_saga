#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    int cmp = strcmp(a, b);

    if (cmp < 0) {
        return 0;
    } else {
        return 1;
    }
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return !(lexicographic_sort(a, b));
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distinctA = strlen(a);
    int distinctB = strlen(b);

    for (int i = 0; i < strlen(a); i++) {
        for (int j = i + 1; j < strlen(a); j++) {
            if (a[i] == a[j]) {
                distinctA--;
                break;
            }
        }
    }

    for (int i = 0; i < strlen(b); i++) {
        for (int j = i + 1; j < strlen(b); j++) {
            if (b[i] == b[j]) {
                distinctB--;
                break;
            }
        }
    }

    if (distinctA == distinctB) {
        return lexicographic_sort(a, b);
    } else if (distinctA < distinctB) {
        return 0;
    } else {
        return 1;
    }
}

int sort_by_length(const char* a, const char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    if (lenA == lenB) {
        return lexicographic_sort(a, b);
    } else if (lenA < lenB) {
        return 0;
    } else {
        return 1;
    }
}

void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    char temp[2500];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1])) {
                strcpy(temp, arr[j]);
                *(arr + j) = realloc(*(arr + j), strlen(*(arr + j + 1)) + 1);
                strcpy(arr[j], arr[j + 1]);
                *(arr + j + 1) = realloc(*(arr + j + 1), strlen(temp) + 1);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    printf("\n");

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}

/*

12
jmdughngvfqgxczcfoqrb
pildeemcsvoxpugebbmtjjwiobyeta
kkynreztwwhtnebuhcganpwydawjvywfluucyvvwrere
sypweqkwoibqgllhhqsekwehrbyxufgndxjkpviedju
uiteyni
joscptzmyfzdfkpugxylhvxdfshdfrqoglqxgqjexkjcvzxd
xqfuqjzisfomxcsivrqlbwkngnkhmndjg
gwwfeoksaixuss
jfpfpcncnuq
yai
gehnjvydyicsauglbvtragvpbm
bocmuitjrqhxorzjuwpfxnyqnfmcgavhoxvkgotzedyvuy

 */
// Expected Output
/*

bocmuitjrqhxorzjuwpfxnyqnfmcgavhoxvkgotzedyvuy
gehnjvydyicsauglbvtragvpbm
gwwfeoksaixuss
jfpfpcncnuq
jmdughngvfqgxczcfoqrb
joscptzmyfzdfkpugxylhvxdfshdfrqoglqxgqjexkjcvzxd
kkynreztwwhtnebuhcganpwydawjvywfluucyvvwrere
pildeemcsvoxpugebbmtjjwiobyeta
sypweqkwoibqgllhhqsekwehrbyxufgndxjkpviedju
uiteyni
xqfuqjzisfomxcsivrqlbwkngnkhmndjg
yai

yai
xqfuqjzisfomxcsivrqlbwkngnkhmndjg
uiteyni
sypweqkwoibqgllhhqsekwehrbyxufgndxjkpviedju
pildeemcsvoxpugebbmtjjwiobyeta
kkynreztwwhtnebuhcganpwydawjvywfluucyvvwrere
joscptzmyfzdfkpugxylhvxdfshdfrqoglqxgqjexkjcvzxd
jmdughngvfqgxczcfoqrb
jfpfpcncnuq
gwwfeoksaixuss
gehnjvydyicsauglbvtragvpbm
bocmuitjrqhxorzjuwpfxnyqnfmcgavhoxvkgotzedyvuy

yai
uiteyni
jfpfpcncnuq
gwwfeoksaixuss
jmdughngvfqgxczcfoqrb
gehnjvydyicsauglbvtragvpbm
pildeemcsvoxpugebbmtjjwiobyeta
xqfuqjzisfomxcsivrqlbwkngnkhmndjg
sypweqkwoibqgllhhqsekwehrbyxufgndxjkpviedju
kkynreztwwhtnebuhcganpwydawjvywfluucyvvwrere
bocmuitjrqhxorzjuwpfxnyqnfmcgavhoxvkgotzedyvuy
joscptzmyfzdfkpugxylhvxdfshdfrqoglqxgqjexkjcvzxd

yai
uiteyni
jfpfpcncnuq
gwwfeoksaixuss
jmdughngvfqgxczcfoqrb
gehnjvydyicsauglbvtragvpbm
pildeemcsvoxpugebbmtjjwiobyeta
kkynreztwwhtnebuhcganpwydawjvywfluucyvvwrere
joscptzmyfzdfkpugxylhvxdfshdfrqoglqxgqjexkjcvzxd
sypweqkwoibqgllhhqsekwehrbyxufgndxjkpviedju
xqfuqjzisfomxcsivrqlbwkngnkhmndjg
bocmuitjrqhxorzjuwpfxnyqnfmcgavhoxvkgotzedyvuy

 */