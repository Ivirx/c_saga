#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[] =
        "She sells seashells by the seashore.The shells she sells are "
        "surely seashells.So if she sells shells on the seashore, I'm "
        "sure she sells seashore shells.";
    int len = strlen(str);

    // kthParagraph, mthSentence, nthWord, othChar
    int othChar = 0, nthWord = 0, mthSentence = 0;
    char *word = (char *)malloc((len + 1) * sizeof(char));
    char ***kthParagraph = NULL;

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '.') {
            word[othChar] = '\0';

            printf("%s\n", word);

            kthParagraph =
                (char ***)realloc(kthParagraph, (mthSentence + 1) * sizeof(char **));
            if (kthParagraph == NULL)
                printf("kthParagraph Error");
            kthParagraph[mthSentence] = (char **)realloc(
                kthParagraph[mthSentence], (nthWord + 1) * sizeof(char *));
            if (kthParagraph[mthSentence] == NULL)
                printf("kthParagraph[mthSentence] Error");
            kthParagraph[mthSentence][nthWord] =
                (char *)malloc((othChar + 1) * sizeof(char));
            if (kthParagraph[mthSentence][nthWord] == NULL)
                printf("kthParagraph[mthSentence][nthWord] Error");

            strcpy(kthParagraph[mthSentence][nthWord], word);
            nthWord++;

            strcpy(word, "");
            othChar = 0;

        } else {
            word[othChar] = str[i];
            othChar++;
        }

        if (str[i] == '.') {
            strcpy(word, "");
            othChar = 0;
            nthWord = 0;
            mthSentence++;
        }
    }

    free(kthParagraph);
    free(word);

    return 0;
}

/* int main() {
  // char str[] = "Quick brown fox jumps over the lazy dog.This is the second "
  //              "sentence.\nNew sentence.second new sentence.";
  char str[] = "Learning C is fun.\nLearning pointers is more fun.It is good "
               "to have pointers.";
  int len = strlen(str);

  int charCount = 0, wordCount = 0, sentCount = 0, paraCount = 0;
  char ch;
  char *charArr = (char *)malloc((len + 1) * sizeof(char)); // single word
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

      // document[paragraph][sentence][word]
      doc = (char ****)realloc(doc, (paraCount + 1) * sizeof(char ***));
      doc[paraCount] =
          (char ***)realloc(doc[paraCount], (sentCount + 1) * sizeof(char **));
      doc[paraCount][sentCount] = (char **)realloc(
          doc[paraCount][sentCount], (wordCount + 1) * sizeof(char *));
      doc[paraCount][sentCount][wordCount] =
          (char *)malloc((charCount + 1) * sizeof(char));
     // doc[paraCount][sentCount][wordCount] = (char
       // *)realloc(doc[paraCount][sentCount][wordCount], (charCount + 1) *
       // sizeof(char));

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
  char *charArr = (char *)malloc((len + 1) * sizeof(char)); // single word
  char **wordArr = NULL;                                    // multiple words or
a sentence

  for (int i = 0; i <= len; i++) {
    if (str[i] == ' ' || str[i] == '\0') {
      charArr[charCount] = '\0';

      wordArr = (char **)realloc(wordArr, (wordCount + 1) * sizeof(char *));
      wordArr[wordCount] = (char *)malloc((charCount + 1) * sizeof(char));

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
    // printf("%s : ", wordArr[i]);
    // printf("%ld\n", strlen(wordArr[i]));
    free(wordArr[i]); // Free memory allocated for each word
  }
  free(wordArr); // Free memory allocated for wordArr array
  free(charArr); // Free memory allocated for word

  return 0;
} */