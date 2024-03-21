#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* _word;
    int word_count;  // denotes number of words in a sentence
};

struct paragraph {
    struct sentence* _sentence;
    int sentence_count;  // denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* _paragraph;
    int paragraph_count;  // denotes number of paragraphs in a document
};

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc._paragraph[n - 1]._sentence[m - 1]._word[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc._paragraph[m - 1]._sentence[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc._paragraph[k - 1];
}

struct document get_document(char* text) {
    int len = strlen(text), othChar = 0, nthWord = 0, mthSentence = 0, kthParagraph = 0;
    char ch, _word[MAX_CHARACTERS];

    struct document doc;
    doc.paragraph_count = 0;
    doc._paragraph = (struct paragraph*)malloc((kthParagraph + 1) * sizeof(struct paragraph));
    if (doc._paragraph == NULL)
        printf("---- Error : doc._paragraph\n");
    doc._paragraph[0].sentence_count = 0;
    doc._paragraph[0]._sentence = (struct sentence*)malloc((mthSentence + 1) * sizeof(struct sentence));
    if (doc._paragraph[0]._sentence == NULL)
        printf("---- Error : doc._paragraph[0]._sentence\n");
    doc._paragraph[0]._sentence[0].word_count = 0;
    doc._paragraph[0]._sentence[0]._word = (struct word*)malloc((nthWord + 1) * sizeof(struct word));
    if (doc._paragraph[0]._sentence[0]._word == NULL)
        printf("---- Error : doc._paragraph[0]._sentence[0]._word\n");
    doc._paragraph[0]._sentence[0]._word[0].data = (char*)malloc(sizeof(char));
    if (doc._paragraph[0]._sentence[0]._word[0].data == NULL)
        printf("---- Error : doc._paragraph[0]._sentence[0]._word[0].data\n");

    for (int i = 0; i < len; i++) {
        ch = text[i];

        printf("ch: %c\n", ch);

        if (ch == '\n') {
            doc._paragraph[kthParagraph].sentence_count = mthSentence;

            kthParagraph++;
            mthSentence = 0;
            nthWord = 0;
            othChar = 0;

            doc._paragraph = (struct paragraph*)realloc(doc._paragraph, kthParagraph * sizeof(struct paragraph));
            if (doc._paragraph == NULL)
                printf("---- Error : doc._paragraph '\\n'\n");
            doc._paragraph[kthParagraph].sentence_count = 0;
            doc._paragraph[kthParagraph]._sentence = (struct sentence*)malloc((mthSentence + 1) * sizeof(struct sentence));
            if (doc._paragraph[kthParagraph]._sentence == NULL)
                printf("---- Error : doc._paragraph[kthParagraph]._sentence '\\n'\n");
            doc._paragraph[kthParagraph]._sentence[mthSentence].word_count = 0;
            doc._paragraph[kthParagraph]._sentence[mthSentence]._word = (struct word*)malloc((nthWord + 1) * sizeof(struct word));
            if (doc._paragraph[kthParagraph]._sentence[mthSentence]._word == NULL)
                printf("---- Error : doc._paragraph[kthParagraph]._sentence[mthSentence]._word '\\n'\n");
            doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data = (char*)malloc(sizeof(char));
        } else if (ch == ' ' || ch == '.') {
            _word[othChar] = '\0';
            doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data = (char*)realloc(doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data, (strlen(_word) + 1) * sizeof(char));
            if (doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data == NULL)
                printf("---- Error : doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data ' &.' \n");
            strcpy(doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data, _word);

            _word[0] = '\0';
            othChar = 0;

            if (ch == ' ') {
                nthWord++;
                doc._paragraph[kthParagraph]._sentence[mthSentence]._word = (struct word*)realloc(doc._paragraph[kthParagraph]._sentence[mthSentence]._word, nthWord * sizeof(struct word));
                if (doc._paragraph[kthParagraph]._sentence[mthSentence]._word == NULL)
                    printf("---- Error : doc._paragraph[kthParagraph]._sentence[mthSentence]._word ' ' \n");
                doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data = (char*)malloc(sizeof(char));
                if (doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data == NULL)
                    printf("---- Error : doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data ' ' \n");
            }

            if (ch == '.') {
                doc._paragraph[kthParagraph]._sentence[mthSentence].word_count = nthWord;

                // if (i == len - 1) continue;

                mthSentence++;
                nthWord = 0;

                doc._paragraph[kthParagraph]._sentence = (struct sentence*)realloc(doc._paragraph[kthParagraph]._sentence, mthSentence * sizeof(struct sentence));
                if (doc._paragraph[kthParagraph]._sentence == NULL)
                    printf("---- Error : doc._paragraph[kthParagraph]._sentence '.'\n");
                doc._paragraph[kthParagraph]._sentence[mthSentence].word_count = 0;
                doc._paragraph[kthParagraph]._sentence[mthSentence]._word = (struct word*)malloc((nthWord + 1) * sizeof(struct word));
                if (doc._paragraph[kthParagraph]._sentence[mthSentence]._word == NULL)
                    printf("---- Error : doc._paragraph[kthParagraph]._sentence[mthSentence]._word '.'\n");
                doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data = (char*)malloc(sizeof(char));
                if (doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data == NULL)
                    printf("---- Error : doc._paragraph[kthParagraph]._sentence[mthSentence]._word[nthWord].data '.'\n");
            }
        } else {
            _word[othChar] = ch;
            othChar++;
        }
    }
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for (int i = 0; i < sen.word_count; i++) {
        print_word(sen._word[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for (int i = 0; i < para.sentence_count; i++) {
        print_sentence(para._sentence[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for (int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc._paragraph[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {
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

    char* returnDoc = (char*)malloc((strlen(doc) + 1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() {
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3) {
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else {
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
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
2 1 1
3 1 1 1
*/