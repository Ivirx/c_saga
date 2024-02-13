#include <stdio.h>
#include <string.h>

void sort_by_number_of_distinct_characters(const char* a) {
    int distinctA = strlen(a);

    for (int i = 0; i < strlen(a); i++) {
        for (int j = i + 1; j < strlen(a); j++) {
            if (a[i] == a[j]) {
                distinctA--;
                break;
            }
        }
    }

    printf("%d\t%d\n", strlen(a), distinctA);
}

int main() {
    sort_by_number_of_distinct_characters("appleisgoodforhealthy");  // apleisgodfrhty
    sort_by_number_of_distinct_characters("aaaaab");
    sort_by_number_of_distinct_characters("sortbynumberofdistinctcharacters");  // sortbynumefdicha

    // sort_by_number_of_distinct_characters("yai");                                               // 3
    // sort_by_number_of_distinct_characters("uiteyni");                                           // 6
    // sort_by_number_of_distinct_characters("jfpfpcncnuq");                                       // 7
    // sort_by_number_of_distinct_characters("gwwfeoksaixuss");                                    // 11
    // sort_by_number_of_distinct_characters("jmdughngvfqgxczcfoqrb");                             // 16
    // sort_by_number_of_distinct_characters("gehnjvydyicsauglbvtragvpbm");                        // 19
    // sort_by_number_of_distinct_characters("pildeemcsvoxpugebbmtjjwiobyeta");                    // 19
    // sort_by_number_of_distinct_characters("kkynreztwwhtnebuhcganpwydawjvywfluucyvvwrere");      // 20
    // sort_by_number_of_distinct_characters("joscptzmyfzdfkpugxylhvxdfshdfrqoglqxgqjexkjcvzxd");  // 21
    // sort_by_number_of_distinct_characters("sypweqkwoibqgllhhqsekwehrbyxufgndxjkpviedju");       // 21
    // sort_by_number_of_distinct_characters("xqfuqjzisfomxcsivrqlbwkngnkhmndjg");                 // 21
    // sort_by_number_of_distinct_characters("bocmuitjrqhxorzjuwpfxnyqnfmcgavhoxvkgotzedyvuy");    // 24

    return 0;
}