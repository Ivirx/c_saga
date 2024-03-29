#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSentence(char **sentence, int sent, int para);
void printParagraph(char ***paragraph, int para);
void printDoc(char ****doc);

int main() {
    // char text[] = "She sells seashells by the seashore.The shells she sells are surely seashells.\nSo if she sells shells on the seashore, I'm sure she sells seashore shells.\nPeter Piper picked a peck of pickled peppers.How many pickled peppers did Peter Piper pick.\nQuick brown fox jumps over the lazy dog.";
    char text[] = "This is not working.\nI do not know why.But I will figure this out.";
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

        if (ch == '.') {
            printf("%d : %d : %d\n", kthParagraph + 1, mthSentence + 1, nthWord + 1);
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

        doc[kthParagraph][mthSentence][nthWord] = (char *)realloc(doc[kthParagraph][mthSentence][nthWord], (othChar + 1) * sizeof(char));
        if (doc[kthParagraph][mthSentence][nthWord] == NULL)
            printf("---- Error : doc[kthParagraph][mthSentence][nthWord]\n");
        doc[kthParagraph][mthSentence][nthWord][othChar] = ch;
        // printf("%c => %d : %d : %d : %d\n", doc[kthParagraph][mthSentence][nthWord][othChar], kthParagraph, mthSentence, nthWord, othChar);
        othChar++;
    }

    // printf("%d : %d : %d : %d\n", kthParagraph + 1, mthSentence + 1, nthWord + 1, othChar);

    printDoc(doc);

    free(doc);

    return 0;
}

void printSentence(char **sentence, int sentences, int paragraphs) {
    int words;
    printf("%d : %d : ", paragraphs + 1, sentences + 1);
    scanf("%d", &words);

    for (int i = 0; i < words; i++) {
        printf("%s", sentence[i]);
        if (i != words - 1)
            printf(" ");
    }
}

void printParagraph(char ***paragraph, int paragraphs) {
    int sentences;
    printf("%d : ", paragraphs + 1);
    scanf("%d", &sentences);

    for (int i = 0; i < sentences; i++) {
        printSentence(*(paragraph + i), i, paragraphs);
        printf(".\n");
    }
}

void printDoc(char ****doc) {
    int paragraphs;
    printf("Number of paragraphs : ");
    scanf("%d", &paragraphs);

    for (int i = 0; i < paragraphs; i++) {
        printParagraph(*(doc + i), i);
    }
}

/* int main() {
    char text[] = "She sells seashells by the seashore.The shells she sells are surely seashells.\nSo if she sells shells on the seashore, I'm sure she sells seashore shells.\nPeter Piper picked a peck of pickled peppers.How many pickled peppers did Peter Piper pick.\nQuick brown fox jumps over the lazy dog.";
    int len = strlen(text);

    int kthParagraph = 0, mthSentence = 0, nthWord = 0, othChar = 0;

    // Allocate memory for initial paragraph
    char ****doc = (char ****)malloc(sizeof(char ***));
    doc[0] = (char ***)malloc(sizeof(char **));
    doc[0][0] = (char **)malloc(sizeof(char *));
    doc[0][0][0] = (char *)malloc(sizeof(char));

    for (int i = 0; i < len; i++) {
        char ch = text[i];

        if (ch == '\n' || ch == '.') {
            if (ch == '\n') {
                kthParagraph++;
                mthSentence = 0;
            } else {
                mthSentence++;
                nthWord = 0;
            }

            // Allocate memory for new sentence/word
            doc = (char ****)realloc(doc, (kthParagraph + 1) * sizeof(char ***));
            doc[kthParagraph] = (char ***)malloc((mthSentence + 1) * sizeof(char **));
            doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));
            doc[kthParagraph][mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));
            othChar = 0;
        } else if (ch == ' ') {
            nthWord++;
            doc[kthParagraph][mthSentence] = (char **)realloc(doc[kthParagraph][mthSentence], (nthWord + 1) * sizeof(char *));
            doc[kthParagraph][mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));
            othChar = 0;
        } else {
            // Expand character buffer
            doc[kthParagraph][mthSentence][nthWord] = (char *)realloc(doc[kthParagraph][mthSentence][nthWord], (othChar + 2) * sizeof(char));
            doc[kthParagraph][mthSentence][nthWord][othChar] = ch;
            doc[kthParagraph][mthSentence][nthWord][othChar + 1] = '\0';
            othChar++;
        }
    }

    printf("%d : %d : %d : %d\n", kthParagraph, mthSentence, nthWord, othChar);

    // Free allocated memory
    // for (int p = 0; p <= kthParagraph; p++) {
    //     for (int s = 0; s <= mthSentence; s++) {
    //         for (int w = 0; w <= nthWord; w++) {
    //             free(doc[p][s][w]);
    //         }
    //         free(doc[p][s]);
    //     }
    //     free(doc[p]);
    // }
    // free(doc);

    return 0;
} */

/* int main() {
    // char str[] = "She sells seashells by the seashore.The shells she sells are surely seashells.\nSo if she sells shells on the seashore, I'm sure she sells seashore shells.\nPeter Piper picked a peck of pickled peppers.How many pickled peppers did Peter Piper pick.\nQuick brown fox jumps over the lazy dog.";
    char str[] = "this is not working.\ni do not know why.but i will figure it out.";
    int len = strlen(str);

    // kthParagraph, mthSentence, nthWord, othChar
    int othChar = 0, nthWord = 0, mthSentence = 0, kthParagraph = 0;
    char *word = (char *)malloc((len + 1) * sizeof(char));
    char ****doc = (char ****)malloc((kthParagraph + 1) * sizeof(char ***));
    doc[kthParagraph] = (char ***)malloc((mthSentence + 1) * sizeof(char **));
    doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));

    for (int i = 0; i < len; i++) {
        if (str[i] == '\n') {
            word[0] = '\0';
            othChar = 0;
            nthWord = 0;
            mthSentence = 0;
            kthParagraph++;

            doc = (char ****)realloc(doc, (kthParagraph + 1) * sizeof(char ***));
            if (doc == NULL) printf("doc Error\n");

            doc[kthParagraph] = (char ***)malloc((mthSentence + 1) * sizeof(char **));
            if (doc[kthParagraph] == NULL) printf("doc[kthParagraph] Error\n");

            doc[kthParagraph][mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));
            if (doc[kthParagraph][mthSentence] == NULL) printf("doc[kthParagraph][mthSentence] Error\n");

            continue;
        }

        if (str[i] == ' ' || str[i] == '.') {
            word[othChar] = '\0';

            doc[kthParagraph][mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));
            if (doc[kthParagraph][mthSentence][nthWord] == NULL) printf("doc[kthParagraph][mthSentence][nthWord] Error\n");

            strcpy(doc[kthParagraph][mthSentence][nthWord], word);
            nthWord++;

            word[0] = '\0';
            othChar = 0;

        } else {
            word[othChar] = str[i];
            othChar++;
        }

        if (str[i] == '.') {
            printf("Paragraph : %d, Sentence : %d, Words: %d\n", kthParagraph + 1, mthSentence + 1, nthWord);

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

    free(doc);
    free(word);

    return 0;
} */

// paragraph tokenizier
/* int main() {
    char str[] = "She sells seashells by the seashore.The shells she sells are surely seashells.So if she sells shells on the seashore, I'm sure she sells seashore shells.";
    int len = strlen(str);

    // kthParagraph, mthSentence, nthWord, othChar
    int othChar = 0, nthWord = 0, mthSentence = 0;
    char *word = (char *)malloc((len + 1) * sizeof(char));
    char ***kthParagraph = (char ***)malloc((mthSentence + 1) * sizeof(char **));
    kthParagraph[mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '.') {
            word[othChar] = '\0';

            printf("%s ; mthSentence : %d ; nthWord : %d ;\n", word, mthSentence, nthWord);

            kthParagraph = (char ***)realloc(kthParagraph, (mthSentence + 1) * sizeof(char **));
            if (kthParagraph == NULL) printf("kthParagraph Error\n");
            kthParagraph[mthSentence] = (char **)realloc(kthParagraph[mthSentence], (nthWord + 1) * sizeof(char *));
            if (kthParagraph[mthSentence] == NULL) printf("kthParagraph[mthSentence] Error\n");
            kthParagraph[mthSentence][nthWord] = (char *)malloc((othChar + 1) * sizeof(char));
            if (kthParagraph[mthSentence][nthWord] == NULL) printf("kthParagraph[mthSentence][nthWord] Error\n");

            strcpy(kthParagraph[mthSentence][nthWord], word);
            nthWord++;

            word[0] = '\0';
            othChar = 0;

        } else {
            word[othChar] = str[i];
            othChar++;
        }

        if (str[i] == '.') {
            word[0] = '\0';
            othChar = 0;
            nthWord = 0;
            mthSentence++;

            kthParagraph = (char ***)realloc(kthParagraph, (mthSentence + 1) * sizeof(char **));
            kthParagraph[mthSentence] = (char **)malloc((nthWord + 1) * sizeof(char *));
        }
    }

    free(kthParagraph);
    free(word);

    return 0;
} */

/* int main() {
    // char str[] = "Quick brown fox jumps over the lazy dog.This is the second sentence.\nNew sentence.second new sentence.";
    char str[] = "Learning C is fun.Learning pointers is more fun.It is good to have pointers.";
    int len = strlen(str);

    int charCount = 0, wordCount = 1, sentCount = 1, paraCount = 1;
    char ch;
    char *charArr = (char *)malloc((len + 1) * sizeof(char));
    char ****doc = NULL;

    for (int i = 0; i < len; i++) {
        ch = str[i];
        if (ch == '\n') {
            wordCount = 0;
            sentCount = 0;
            paraCount++;
            continue;
        }

        if (ch == ' ' || ch == '.') {
            charArr[charCount] = '\0';

            printf("%s : ", charArr);
            printf("%d : %d : %d : %d\n", paraCount, sentCount, wordCount, charCount);

            // document[paragraph][sentence][word]
            doc = (char ****)realloc(doc, (paraCount) * sizeof(char ***));
            if (doc == NULL) printf("Error 1");

            doc[paraCount] = (char ***)realloc(doc[paraCount], (sentCount) * sizeof(char **));
            if (doc == NULL) printf("Error 2");

            doc[paraCount][sentCount] = (char **)realloc(doc[paraCount][sentCount], (wordCount) * sizeof(char *));
            if (doc == NULL) printf("Error 3");

            doc[paraCount][sentCount][wordCount] = (char *)malloc((charCount + 1) * sizeof(char));
            if (doc == NULL) printf("Error 4");

            // Copy the word
            strcpy(doc[paraCount][sentCount][wordCount], charArr);

            if (ch == ' ') {
                wordCount++;
            } else if (ch == '.' && i != len - 1) {
                wordCount = 0;
                sentCount++;
            }

            // Clear word for next iteration
            strcpy(charArr, "");
            charCount = 0;
        } else {
            charArr[charCount] = ch;
            charCount++;
        }
    }

    printf("\n%d : %d : %d\n", paraCount + 1, sentCount + 1, wordCount + 1);
    printf("Tokenized words : \n");
    for (int i = 0; i < wordCount + 1; i++) {
        printf("%s\n", doc[paraCount][sentCount][i]);
    }

    free(charArr);
    free(doc);

    return 0;
} */

/* int main() {
    char str[] = "Quick brown fox jumps over the lazy dog";
    int len = strlen(str);

    int charCount = 0, wordCount = 0;
    char *charArr = (char *)malloc((len + 1) * sizeof(char));  // single word
    char **wordArr = NULL;                                     // multiple words or a sentence

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            charArr[charCount] = '\0';

            wordArr = (char **)realloc(wordArr, (wordCount + 1) * sizeof(char *));
            if (wordArr == NULL) printf("Error 1");
            wordArr[wordCount] = (char *)malloc((charCount + 1) * sizeof(char));
            if (wordArr[wordCount] == NULL) printf("Error 2");

            // Copy the word into the wordArr array
            strcpy(wordArr[wordCount], charArr);
            wordCount++;

            // Clear word for next iteration
            strcpy(charArr, "");
            charCount = 0;
        } else {
            charArr[charCount] = str[i];
            charCount++;
        }
    }

    // Print the tokenized words
    printf("Tokenized words:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", wordArr[i]);
        free(wordArr[i]);  // Free memory allocated for each word
    }
    free(wordArr);  // Free memory allocated for wordArr array
    free(charArr);  // Free memory allocated for word

    return 0;
} */