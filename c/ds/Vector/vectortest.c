#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

#define YES_OR_NO(value) (value != 0 ? "Yes" : "No")

/**
 * PrintChar
 * ---------
 * Mapping function used to print one character element in a vector.
 * The file pointer is passed as the client data, so that it can be
 * used to print to any FILE *.
 */

static void PrintChar(void *elem, void *fp)
{
  fprintf((FILE *)fp, "%c", *(char *)elem);
  fflush((FILE *)fp);
}

/**
 * CompareChar
 * -----------
 * Comparator function used to compare two character elements within a vector.
 * Used for both sorting and searching in the array of characters.  Has the same
 * return value semantics as the strcmp library function (negative if A<B, zero if A==B,
 * positive if A>B).
 */

static int CompareChar(const void *elemA, const void *elemB)
{
  return (*(char *)elemA - *(char *)elemB);
}

/**
 * Function: TestAppend
 * --------------------
 * Appends letters of alphabet in order, then appends a few digit chars.
 * Uses VectorMap to print the vector contents before and after.
 */

static void TestAppend(vector *alphabet)
{
  char ch;
  int i;

  for (ch = 'A'; ch <= 'Z'; ch++)   //  Start with letters of alphabet
    VectorAppend(alphabet, &ch);
  fprintf(stdout, "First, here is the alphabet: ");
  VectorMap(alphabet, PrintChar, stdout);

  for (i = 0; i < 10; i++) {	    // Append digit characters
    ch = '0' + i;                   // convert int to ASCII digit character
    VectorAppend(alphabet, &ch);
  }
  fprintf(stdout, "\nAfter append digits: ");
  VectorMap(alphabet, PrintChar, stdout);
}


/**
 * Function: TestSearch
 * --------------------
 * Tests the searching capability of the vector by looking for specific
 * character.  Calls VectorSearch twice, once to see if it finds the character
 * using a binary search (given the array is sorted) and once to see if it
 * finds the character using a linear search.  Reports results to stdout.
 */

static void TestSearch(vector *v, char ch)
{
  int foundSorted, foundNot;

  foundSorted = VectorSearch(v, &ch, CompareChar, 0, true); // Test sorted
  foundNot = VectorSearch(v, &ch, CompareChar, 0, false);   // Not sorted
  fprintf(stdout,"\nFound '%c' in sorted array? %s. How about unsorted? %s.",
	  ch, YES_OR_NO((foundSorted != -1)),
	  YES_OR_NO((foundNot != -1)));
}

/**
 * Function: TestSortSearch
 * ------------------------
 * Sorts the vector into alphabetic order and then tests searching
 * capabilities, both the linear and binary search versions.
 */

static void TestSortSearch(vector *alphabet)
{
  VectorSort(alphabet, CompareChar);	 // Sort into order again
  fprintf(stdout, "\nAfter sorting: ");
  VectorMap(alphabet, PrintChar, stdout);
  TestSearch(alphabet, 'J');	// Test searching capabilities
  TestSearch(alphabet, '$');
}

/**
 * Function: TestAt
 * ----------------
 * Uses VectorNth to access every other letter and
 * lowercase it. Prints results using VectorMap.
 */

static void TestAt(vector *alphabet)
{
  int i;

  for (i = 0; i < VectorLength(alphabet); i += 2) { // Lowercase every other
    char *elem = (char *) VectorNth(alphabet, i);
    *elem = tolower(*elem);
  }

  fprintf(stdout, "\nAfter lowercase every other letter: ");
  VectorMap(alphabet, PrintChar, stdout);
}

/**
 * Function: TestInsertDelete
 * --------------------------
 * Inserts dashes at regular intervals, then uses delete to remove
 * them.  Makes sure that insert at allows you to insert at end of
 * array and checks no problem with deleting very last element.  It's
 * always a good idea to directly test the borderline cases to make
 * sure you have handled even the unusual scenarios.
 */

static void TestInsertDelete(vector *alphabet)
{
  char ch = '-';
  int i;

  for (i = 3; i < VectorLength(alphabet); i += 4) // Insert dash every 4th char
    VectorInsert(alphabet, &ch, i);
  fprintf(stdout, "\nAfter insert dashes: ");
  VectorMap(alphabet, PrintChar, stdout);

  for (i = 3; i < VectorLength(alphabet); i += 3) // Delete every 4th char
    VectorDelete(alphabet, i);
  fprintf(stdout, "\nAfter deleting dashes: ");
  VectorMap(alphabet, PrintChar, stdout);

  ch = '!';
  VectorInsert(alphabet, &ch, VectorLength(alphabet));
  VectorDelete(alphabet, VectorLength(alphabet) - 1);
  fprintf(stdout, "\nAfter adding and deleting to very end: ");
  VectorMap(alphabet, PrintChar, stdout);
}

/**
 * Function: TestReplace
 * ---------------------
 * Uses repeated searches to find all occurrences of a particular
 * character and then uses replace it to overwrite value.
 */

static void TestReplace(vector *alphabet)
{
  int found = 0;
  char toFind = 's', toReplace = '*';

  while (found < VectorLength(alphabet)) {
    found = VectorSearch(alphabet, &toFind, CompareChar, found, false);
    if (found == -1) break;
    VectorReplace(alphabet, &toReplace, found);
  }

  fprintf(stdout, "\nAfter changing all %c to %c: ", toFind, toReplace);
  VectorMap(alphabet, PrintChar, stdout);
}

/**
 * Function: SimpleTest
 * --------------------
 * Exercises the vector when it stores characters.
 * Because characaters are small and don't have any
 * complicated memory requirements, this test is a
 * good starting point to see whether or not your vector
 * even has a prayer of passing more rigorous tests.
 *
 * See the documentation for each of the helper functions
 * to gain a sense as to how SimpleTest works.  The intent
 * it certainly to try out all of the vector operations so
 * that everything gets exercised.
 */

static void SimpleTest()
{
  fprintf(stdout, " ------------------------- Starting the basic test...\n");
  vector alphabet;
  VectorNew(&alphabet, sizeof(char), NULL, 4);
  TestAppend(&alphabet);
  TestSortSearch(&alphabet);
  TestAt(&alphabet);
  TestInsertDelete(&alphabet);
  TestReplace(&alphabet);
  VectorDispose(&alphabet);
}

/**
 * Function: InsertPermutationOfNumebrs
 * ------------------------------------
 * Uses a little bit of number theory to populate the
 * presumably empty numbers vector with some permutation
 * of the integers between 0 and d - 1, inclusive.
 * By design, each number introduced to the vector should
 * be introduces once and exactly once.  This happens
 * provided n < d and that both n and d are prime numbers.
 */

static void InsertPermutationOfNumbers(vector *numbers, long n, long d)
{
  long k;
  long residue;
  fprintf(stdout, "Generating all of the numbers between 0 and %ld (using some number theory). ", d - 1);
  fflush(stdout); // force echo to the screen...

  for (k = 0; k < d; k++) {
    residue = (long) (((long long)k * (long long) n) % d);
    VectorAppend(numbers, &residue);
  }

  assert(VectorLength(numbers) == d);
  fprintf(stdout, "[All done]\n");
  fflush(stdout);
}

/**
 * Function: LongCompare
 * ---------------------
 * Called when searching or sorting a vector known to
 * be storing long integer data types.
 */

static int LongCompare(const void *vp1, const void *vp2)
{
  return (*(const long *)vp1) - (*(const long *)vp2);
}

/**
 * Function: SortPermutation
 * -------------------------
 * Sorts the (very, very large) vectorToSort, and confirms
 * that the sort worked.  This is slightly more strenous
 * that the TestSort routine above simply because the vector
 * is much, much bigger.
 */

static void SortPermutation(vector *vectorToSort)
{
  long residue, embeddedLong;
  vector *sortedVector;
  fprintf(stdout, "Sorting all of those numbers. ");
  fflush(stdout);
  VectorSort(vectorToSort, LongCompare);
  fprintf(stdout, "[Done]\n");
  fflush(stdout);
  fprintf(stdout, "Confirming everything was properly sorted. ");
  fflush(stdout);
  sortedVector = vectorToSort; // need better name now that it's sorted...
  for (residue = 0; residue < VectorLength(sortedVector); residue++) {
    embeddedLong = *(const long *) VectorNth(sortedVector, residue);
    assert(embeddedLong == residue);
  }
  fprintf(stdout, "[Yep, it's sorted]\n");
  fflush(stdout);
}

/**
 * Function: DeleteEverythingVerySlowly
 * ------------------------------------
 * Empties out the vector in such a way that VectorDelete
 * is exercised to the hilt.  By repeatedly deleting from
 * within the vector, we ensure that the shifting over of
 * bytes is working properly.
 */

static void DeleteEverythingVerySlowly(vector *numbers)
{
  long largestOriginalNumber;
  fprintf(stdout, "Erasing everything in the vector by repeatedly deleting the 100th-to-last remaining element (be patient).\n");
  fflush(stdout);
  largestOriginalNumber = *(long *)VectorNth(numbers, VectorLength(numbers) - 1);
  while (VectorLength(numbers) >= 100) {
    VectorDelete(numbers, VectorLength(numbers) - 100);
    assert(largestOriginalNumber == *(long *)VectorNth(numbers, VectorLength(numbers) -1));
  }
  fprintf(stdout, "\t[Okay, almost done... deleting the last 100 elements... ");
  fflush(stdout);
  while (VectorLength(numbers) > 0) VectorDelete(numbers, 0);
  fprintf(stdout, "and we're all done... whew!]\n");
  fflush(stdout);
}

/**
 * Function: ChallengingTest
 * -------------------------
 * Uses a little bit of number theory to generate a very large vector
 * of four-byte values.  Some permutation of the numbers [0, 3021367)
 * is generated, and in the process the vector grows in such a way that
 * several realloc calls are likely made.  This will catch any errors
 * with the reallocation, particulatly those where the implementation
 * fails to catch realloc's return value.  The test then goes on the
 * sort the array, confirm that the sort succeeded, and then finally
 * delete all of the elements one by one.
 */

static const long kLargePrime = 1398269;
static const long kEvenLargerPrime = 3021377;
static void ChallengingTest()
{
  vector lotsOfNumbers;
  fprintf(stdout, "\n\n------------------------- Starting the more advanced tests...\n");
  VectorNew(&lotsOfNumbers, sizeof(long), NULL, 4);
  InsertPermutationOfNumbers(&lotsOfNumbers, kLargePrime, kEvenLargerPrime);
  SortPermutation(&lotsOfNumbers);
  DeleteEverythingVerySlowly(&lotsOfNumbers);
  VectorDispose(&lotsOfNumbers);
}

/**
 * Function: FreeString
 * --------------------
 * Understands how to free a C-string.  This
 * function should be used by all vectors that
 * store char *'s (but only when those char *s
 * point to dynamically allocated memory, as
 * they do with strings.)
 */

static void FreeString(void *elemAddr)
{
  char *s = *(char **) elemAddr;
  free(s);
}

/**
 * Function: PrintString
 * ---------------------
 * Understands how to print a C-string stored
 * inside a vector.  The target FILE * should
 * be passed in via the auxData parameter.
 */

static void PrintString(void *elemAddr, void *auxData)
{
  char *word = *(char **)elemAddr;
  FILE *fp = (FILE *) auxData;
  fprintf(fp, "\t%s\n", word);
}

/**
 * Function: MemoryTest
 * --------------------
 * MemoryTest exercises the vector functionality by
 * populating one with pointers to dynamically allocated
 * memory.  The insertion process marks the transfer of
 * of responsibility from the client to the vector, so
 * we now need to specify a non-NULL VectorFreeFunction so
 * the a vector can apply it to the elements it inherits
 * from the client.  Make sure you understand why the
 * casts within the two functions above (FreeString, PrintString)
 * are char ** casts and not char *.  If you truly understand,
 * they you've learned what is probably the most difficult-to-
 * learn concept taught in CS107.
 */

static void MemoryTest()
{
  int i;
  const char * const kQuestionWords[] = {"who", "what", "where", "how", "why"};
  const int kNumQuestionWords = sizeof(kQuestionWords) / sizeof(kQuestionWords[0]);
  vector questionWords;
  char *questionWord;

  fprintf(stdout, "\n\n------------------------- Starting the memory tests...\n");
  fprintf(stdout, "Creating a vector designed to store dynamically allocated C-strings.\n");
  VectorNew(&questionWords, sizeof(char *), FreeString, kNumQuestionWords);
  fprintf(stdout, "Populating the char * vector with the question words.\n");
  for (i = 0; i < kNumQuestionWords; i++) {
    questionWord = malloc(strlen(kQuestionWords[i]) + 1);
    strcpy(questionWord, kQuestionWords[i]);
    VectorInsert(&questionWords, &questionWord, 0);  // why the ampersand? isn't questionWord already a pointer?
  }

  fprintf(stdout, "Mapping over the char * vector (ask yourself: why are char **'s passed to PrintString?!!)\n");
  VectorMap(&questionWords, PrintString, stdout);
  fprintf(stdout, "Finally, destroying the char * vector.\n");
  VectorDispose(&questionWords);
}

/**
 * Function: main
 * --------------
 * The enrty point into the test application.  The
 * first test is easy, the second one is medium, and
 8 the final test is hard.
 */

int cmpFn(const void *elemOne, const void *elemTwo){
  return *(int *)elemOne - *(int *)elemTwo;
}

int main(int ignored, char **alsoIgnored)
{
  /*
  vector myVect;
  VectorNew(&myVect, sizeof(int), NULL, 0);
  int n = 20;
  int m = 6;
  int k = 8;
  int l = 9;
  int h = 10;
  int j = 111;
  VectorAppend(&myVect, &n);
  VectorAppend(&myVect, &m);
  VectorAppend(&myVect, &k);
  VectorAppend(&myVect, &l);
  VectorAppend(&myVect, &h);
  VectorSort(&myVect, cmpFn);
  //VectorReplace(&myVect, &j, 4);
  for (int i = 0; i < VectorLength(&myVect); i++){
    printf("At index ");
    printf("%d\n", i);
    printf("%d\n", *(int *)VectorNth(&  myVect, i));
  }
  printf("%d\n", VectorSearch(&myVect, &h, cmpFn, 0, 1));
  */

  SimpleTest();
  ChallengingTest();
  MemoryTest();
  
  return 0;
}
