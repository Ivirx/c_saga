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

char ***kth_paragraph(char ****document, int k) {
    return document[k - 1];
}

char ****get_document(char *text) {
    int len = strlen(text);

    // kthParagraph, mthSentence, nthWord, othChar
    int othChar = 0, nthWord = 0, mthSentence = 0, kthParagraph = 0;
    char ch, ****doc = (char ****)malloc((kthParagraph + 1) * sizeof(char ***));
    doc[kthParagraph] = (char ***)malloc((mthSentence + 1) * sizeof(char **));
    doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));
    doc[kthParagraph][mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        ch = text[i];

        if (ch == '\n') {
            kthParagraph++;
            doc = (char ****)realloc(doc, (kthParagraph + 1) * sizeof(char ***));
            if (doc[kthParagraph] == NULL)
                printf("---- Error : doc[kthParagraph] '\\n'\n");

            mthSentence = 0;
            doc[kthParagraph] = (char ***)malloc((mthSentence + 1) * sizeof(char **));
            if (doc[kthParagraph] == NULL)
                printf("---- Error : doc[kthParagraph] '\\n'\n");

            nthWord = 0;
            doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));
            if (doc[kthParagraph][mthSentence] == NULL)
                printf("---- Error : doc[kthParagraph][mthSentence] '\\n'\n");

            othChar = 0;
            doc[kthParagraph][mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));
            if (doc[kthParagraph][mthSentence][nthWord] == NULL)
                printf("---- Error : doc[kthParagraph][mthSentence][nthWord] '\\n'\n");

            continue;
        }

        if (ch == '.' || ch == ' ') {
            doc[kthParagraph][mthSentence][nthWord] = (char *)realloc(doc[kthParagraph][mthSentence][nthWord], (othChar + 1) * sizeof(char));
            if (doc[kthParagraph][mthSentence][nthWord] == NULL)
                printf("---- Error : doc[kthParagraph][mthSentence][nthWord]\n");
            doc[kthParagraph][mthSentence][nthWord][othChar] = '\0';

            // if (ch == '.') {
            if (ch == '.' && i != len - 1) {
                mthSentence++;
                doc[kthParagraph] = (char ***)realloc(doc[kthParagraph], (mthSentence + 1) * sizeof(char **));
                if (doc[kthParagraph] == NULL)
                    printf("---- Error : doc[kthParagraph] '.'\n");

                nthWord = 0;
                doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));
                if (doc[kthParagraph][mthSentence] == NULL)
                    printf("---- Error : doc[kthParagraph][mthSentence] '.'\n");

                othChar = 0;
                doc[kthParagraph][mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));
                if (doc[kthParagraph][mthSentence][nthWord] == NULL)
                    printf("---- Error : doc[kthParagraph][mthSentence][nthWord] '.'\n");
            }

            // if (ch == ' ') {
            if (ch == ' ' && i != len - 1) {
                nthWord++;
                doc[kthParagraph][mthSentence] = (char **)realloc(doc[kthParagraph][mthSentence], (nthWord + 1) * sizeof(char *));
                if (doc[kthParagraph][mthSentence] == NULL)
                    printf("---- Error : doc[kthParagraph][mthSentence] ' '\n");

                othChar = 0;
                doc[kthParagraph][mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));
                if (doc[kthParagraph][mthSentence][nthWord] == NULL)
                    printf("---- Error : doc[kthParagraph][mthSentence][nthWord] ' '\n");
            }

            continue;
        }

        // printf("%c : %d : %d : %d : %d : %d : %d\n", ch, i, len, kthParagraph, mthSentence, nthWord, othChar);

        doc[kthParagraph][mthSentence][nthWord] = (char *)realloc(doc[kthParagraph][mthSentence][nthWord], (othChar + 1) * sizeof(char));
        if (doc[kthParagraph][mthSentence][nthWord] == NULL)
            printf("---- Error : doc[kthParagraph][mthSentence][nthWord]\n");
        doc[kthParagraph][mthSentence][nthWord][othChar] = ch;
        // printf("%c => %d : %d : %d : %d\n", doc[kthParagraph][mthSentence][nthWord][othChar], kthParagraph, mthSentence, nthWord, othChar);
        othChar++;
    }

    printf("%d : %d : %d : %d\n", kthParagraph + 1, mthSentence + 1, nthWord + 1, othChar);

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
    printf("-------------------------- printing word\n");

    printf("%s", word);

    printf("\n");
}

void print_sentence(char **sentence) {
    printf("-------------------------- printing sentence : No. of Words in it : ");

    int word_count;
    scanf("%d", &word_count);
    for (int i = 0; i < word_count; i++) {
        printf("%s ", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
    printf("\n");
}

void print_paragraph(char ***paragraph) {
    printf("-------------------------- printing paragraph : No. of Sentences in it : ");

    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
    printf("\n");
}

int main() {
    char *text = get_input_text();
    char ****document = get_document(text);

    int q;
    printf("Enter number of Queries : ");
    scanf("%d", &q);

    printf("Number of Queries : %d\n", q);

    while (q--) {
        int type;
        printf("Enter query type : ");
        scanf("%d", &type);
        printf("Query type is : %d\n", type);

        if (type == 3) {
            printf("* Entering query 3 *\n");
            printf("k m n : ");
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char *word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
            printf("\n* Exiting query 3 *\n");
        }

        else if (type == 2) {
            printf("* Entering query 2 *\n");
            printf("k m : ");
            int k, m;
            scanf("%d %d", &k, &m);
            char **sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
            printf("\n* Exiting query 2 *\n");

        }

        else {
            printf("* Entering query 1 *\n");
            printf("k : ");
            int k;
            scanf("%d", &k);
            char ***paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
            printf("\n* Exiting query 1 *\n");
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
//
2
this is not working.
i do not know why.but i will figure.
1
1 1
1
4
//
4
She sells seashells by the seashore.The shells she sells are surely seashells.
So if she sells shells on the seashore, I'm sure she sells seashore shells.
Peter Piper picked a peck of pickled peppers.How many pickled peppers did Peter Piper pick.
Quick brown fox jumps over the lazy dog.This should work fine.I hope it works.
4
1 3
2
8
8
2 4 2
4
1 2 1 8
1 4 1 1
*/