#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
    int char_count;
};

struct sentence {
    struct word* _word;
    int word_count;  // denotes number of words in a sentence
};

struct paragraph {
    struct sentence* _sentence;
    int sentence_count;  // denotes number of sentences in a paragraph
};

/* struct document {
    struct paragraph* _paragraph;
    int paragraph_count;  // denotes number of paragraphs in a document
}; */

struct paragraph get_paragraph(char* text) {
    int len = strlen(text), othChar = 0, nthWord = 0, mthSentence = 0, kthParagraph = 0;
    char ch, _word[MAX_CHARACTERS];

    struct paragraph para;
    para.sentence_count = 0;
    para._sentence = malloc((mthSentence + 1) * sizeof(struct sentence));
    if (para._sentence == NULL) {
        printf("---- Error : para._sentence\n");
        return para;
    }
    para._sentence[mthSentence].word_count = 0;
    para._sentence[mthSentence]._word = malloc((nthWord + 1) * sizeof(struct word));
    if (para._sentence[mthSentence]._word == NULL) {
        printf("---- Error : para._sentence[mthSentence]._word\n");
        return para;
    }
    para._sentence[mthSentence]._word[nthWord].char_count = 0;
    para._sentence[mthSentence]._word[nthWord].data = malloc((othChar + 1) * sizeof(char));
    if (para._sentence[mthSentence]._word[nthWord].data == NULL) {
        printf("---- Error : para._sentence[mthSentence]._word[nthWord].data\n");
        return para;
    }

    for (int i = 0; i < len; i++) {
        ch = text[i];
        printf("ch: %c\n", ch);

        if (ch == ' ' || ch == '.') {
            para._sentence[mthSentence]._word[nthWord].data = realloc(para._sentence[mthSentence]._word[nthWord].data, (othChar + 1) * sizeof(char));
            if (para._sentence[mthSentence]._word[nthWord].data == NULL) {
                printf("---- Error : para._sentence[mthSentence]._word[nthWord].data : ' '||'.'\n");
                return para;
            }
            para._sentence[mthSentence]._word[nthWord].data[othChar] = '\0';
            para._sentence[mthSentence]._word[nthWord].char_count = othChar;

            nthWord++;

            if (ch == ' ') {
                othChar = 0;

                para._sentence[mthSentence]._word = realloc(para._sentence[mthSentence]._word, nthWord * sizeof(struct word));
                if (para._sentence[mthSentence]._word == NULL) {
                    printf("---- Error : para._sentence[mthSentence]._word : ' '\n");
                    return para;
                }
                para._sentence[mthSentence]._word[nthWord].char_count = 0;
                para._sentence[mthSentence]._word[nthWord].data = malloc((othChar + 1) * sizeof(char));
                if (para._sentence[mthSentence]._word[nthWord].data == NULL) {
                    printf("---- Error : para._sentence[mthSentence]._word[nthWord].data : ' '\n");
                    return para;
                }
            }

            if (ch == '.') {
                para._sentence[mthSentence].word_count = nthWord;

                mthSentence++;
                nthWord = 0;
                othChar = 0;

                return para;
            }

            continue;
        }

        othChar++;
        para._sentence[mthSentence]._word[nthWord].data = realloc(para._sentence[mthSentence]._word[nthWord].data, othChar * sizeof(char));
        if (para._sentence[mthSentence]._word[nthWord].data == NULL) {
            printf("---- Error : para._sentence[mthSentence]._word[nthWord].data : 'loop'\n");
            return para;
        }
        para._sentence[mthSentence]._word[nthWord].data[othChar] = ch;
    }

    return para;
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

/* void print_document(struct document doc) {
    for (int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc._paragraph[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
} */

int main() {
    // char* text = "peter piper picked a peck of pickled peppers.how many pickled peppers did peter piper pick.";
    char* text = "she sells seashells by the seashore.the shells she sells are surely seashells.";
    struct paragraph para = get_paragraph(text);

    printf("\n------------------------\n");

    // printf("%d\n", para._sentence[0].word_count);

    printf("\nThe end of his life was misery.\n");
    return 0;
}
