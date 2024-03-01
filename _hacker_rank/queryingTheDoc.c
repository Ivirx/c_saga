#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m) {
    return document[m - 1][k - 1];
}

char ***kth_paragraph(char ****document, int k) { return document[k - 1]; }

char ****get_document(char *text) {
    int len = strlen(text);

    int charCount = 0, wordCount = 0, sentCount = 0, paraCount = 0;
    char ch;
    char *word = (char *)malloc((len + 1) * sizeof(char));
    char ****doc = (char ****)malloc((paraCount + 1) * sizeof(char ***));

    for (int i = 0; i < len; i++) {
        ch = text[i];
        if (ch == '\n') {
            wordCount = 0;
            sentCount = 0;
            paraCount++;
            continue;
        }

        if (ch == ' ' || ch == '.') {
            word[charCount] = '\0';

            // document[paragraph][sentence][word]
            doc = (char ****)realloc(doc, (paraCount + 1) * sizeof(char ***));
            if (doc == NULL) printf("Error 1");

            doc[paraCount] = (char ***)realloc(doc[paraCount], (sentCount + 1) * sizeof(char **));
            if (doc[paraCount] == NULL) printf("Error 2");

            doc[paraCount][sentCount] = (char **)realloc(doc[paraCount][sentCount], (wordCount + 1) * sizeof(char *));
            if (doc[paraCount][sentCount] == NULL) printf("Error 3");

            doc[paraCount][sentCount][wordCount] = (char *)malloc((charCount + 1) * sizeof(char));
            if (doc[paraCount][sentCount][wordCount] == NULL) printf("Error 4");

            // Copy the word
            strcpy(doc[paraCount][sentCount][wordCount], word);

            if (ch == ' ') {
                wordCount++;
            } else if (ch == '.') {
                wordCount = 0;
                sentCount++;
            }

            // Clear word for next iteration
            strcpy(word, "");
            charCount = 0;

        } else {
            word[charCount] = ch;
            charCount++;
        }
    }

    free(word);

    return doc;
}

char *get_input_text() {
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char *returnDoc = (char *)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char *word) {
    printf("\n------------------------Printing Word\n");

    printf("%s", word);
}

void print_sentence(char **sentence) {
    printf("\n------------------------Printing Sentence\n");

    int word_count;
    scanf("%d", &word_count);
    for (int i = 0; i < word_count; i++) {
        printf("%s", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char ***paragraph) {
    printf("\n------------------------Printing Para\n");

    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() {
    char *text = get_input_text();
    char ****document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        printf("Enter Type : \n");
        scanf("%d", &type);
        printf("Type is : %d\n", type);

        if (type == 3) {
            printf("Query 3\n");
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char *word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
            printf("Query 3 Ends\n");
        }

        else if (type == 2) {
            printf("Query 2\n");
            int k, m;
            scanf("%d %d", &k, &m);
            char **sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
            printf("Query 2 Ends\n");

        }

        else {
            printf("Query 1\n");
            int k;
            scanf("%d", &k);
            char ***paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
            printf("Query 1 Ends\n");
        }
        printf("\n");
    }
}

/*
2
Learning C is fun.
Learning pointers is more fun.It is good to have pointers.
3
1 2
2
5
6
2 1 1
4
3 1 1 1
*/