# CS 173: Intermediate Computer Science


### Homework 6:Sorting

Complete this project with a randomly assigned partner. See the Notebowl assignment page for
partners.

In this problem, you will compare the running times of four sorting algorithms: selection sort,
insertion sort, merge sort, and quicksort. We discussed selection sort, merge sort, and quicksort
in class and you can also read about them in your textbook. Insertion sort, the algorithm most
people use to sort a hand of cards, is described on page 466-7 of your textbook.

Write functions for each of the four sorts. Each function should take a vector of integers as a
reference parameter.

Use thegettimeofday()function from sys/time.h to time each of the four sorts on a sequence
of randomly generated lists with increasing lengths between 1000 and 100,000, in increments of
1000. The following snippet of code illustrates how to usegettimeofday(). You can learn more
by typing man gettimeofday in the terminal.

```
#include <sys/time.h>

int main()
{
timeval timeBefore, timeAfter; // timeval type defined in sys/time.h
long diffSeconds, diffUSeconds; // elapsed seconds and microseconds
gettimeofday(&timeBefore, NULL); // get the time before
selectionSort(list);
gettimeofday(&timeAfter, NULL); // get the time after
diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec; // elapsed seconds
diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
double time = diffSeconds + diffUSeconds / 1000000.0; // total elapsed time
return 0;
}
```
Plot your results using the tool of your choice. Your plot should have input size on the x-axis, time
on the y-axis, and four “curves” for the four algorithms then save the plot as a PDF. Submit your
code (all in one file) and the PDF plot by the deadline.

Important note: In your tests, make sure that you never use a list that has been previously
sorted! This will significantly skew your results.

# For more information, read Hw6-Sorting.pdf



