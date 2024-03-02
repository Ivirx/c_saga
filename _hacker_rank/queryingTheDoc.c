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
    // printf("%s", text);
    int len = strlen(text);

    // kthParagraph, mthSentence, nthWord, othChar
    int othChar = 0, nthWord = 0, mthSentence = 0, kthParagraph = 0;
    char ch,
        *word = (char *)malloc((len + 1) * sizeof(char));
    char ****doc = (char ****)malloc((kthParagraph + 1) * sizeof(char ***));
    doc[kthParagraph] = (char ***)malloc((mthSentence + 1) * sizeof(char **));
    doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));

    for (int i = 0; i < len; i++) {
        ch = text[i];

        if (ch == '\n') {
            word[0] = '\0';
            othChar = 0;
            nthWord = 0;
            mthSentence = 0;
            kthParagraph++;

            doc = (char ****)realloc(doc, (kthParagraph + 1) * sizeof(char ***));
            if (doc == NULL) printf("docn Error\n");

            doc[kthParagraph] = (char ***)malloc((mthSentence + 1) * sizeof(char **));
            if (doc[kthParagraph] == NULL) printf("doc[kthParagraph]n Error\n");

            doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));
            if (doc[kthParagraph][mthSentence] == NULL) printf("doc[kthParagraph][mthSentence]n Error\n");

            continue;
        }

        if (ch == ' ' || ch == '.') {
            word[othChar] = '\0';

            doc[kthParagraph][mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));
            if (doc[kthParagraph][mthSentence][nthWord] == NULL) printf("doc[kthParagraph][mthSentence][nthWord] Error\n");

            strcpy(doc[kthParagraph][mthSentence][nthWord], word);
            printf("%s : ", word);
            nthWord++;

            word[0] = '\0';
            othChar = 0;

        } else {
            printf("%c ", ch);
            word[othChar] = ch;
            othChar++;
        }

        if (ch == '.') {
            printf("=> Paragraph : %d, Sentence : %d, Words: %d\n", kthParagraph + 1, mthSentence + 1, nthWord);

            word[0] = '\0';
            othChar = 0;
            nthWord = 0;
            mthSentence++;

            doc[kthParagraph] = (char ***)realloc(doc[kthParagraph], (mthSentence + 1) * sizeof(char **));
            if (doc[kthParagraph] == NULL) printf("doc[kthParagraph]. Error\n");

            doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));
            if (doc[kthParagraph][mthSentence] == NULL) printf("doc[kthParagraph][mthSentence]. Error\n");
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
    // printf("-------------------------- printing word\n");

    printf("%s", word);
}

void print_sentence(char **sentence) {
    // printf("-------------------------- printing sentence\n");

    int word_count;
    scanf("%d", &word_count);
    for (int i = 0; i < word_count; i++) {
        printf("%s ", sentence[i]);
        if (i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char ***paragraph) {
    // printf("-------------------------- printing paragraph\n");

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
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char *word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
            printf("\n* Exiting query 3 *\n");
        }

        else if (type == 2) {
            printf("* Entering query 2 *\n");
            int k, m;
            scanf("%d %d", &k, &m);
            char **sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
            printf("\n* Exiting query 2 *\n");

        }

        else {
            printf("* Entering query 1 *\n");
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
*/