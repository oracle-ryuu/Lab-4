/*
  CPSC 223C
  Spring 2015
  CSU Fullerton

  Lab 4: variable arguments

  Authors: Jared vanotterdyk (oracleryuu@csu.fullerton.edu)
*/ 

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

/* num is the number of variable arguments, all of type int. Compute
   and return the median of the variable arguments. Recall that in the
   case of an even number of arguments, you need to take the mean of
   the two arguments closest to the middle, which is why the return
   type is double. */
float median(int num, ...);

/* num is the number of variable arguments, all of type int. Compute
   and return the mode of the variable arguments. Recall that the mode
   is the most frequently-ocurring value. If there are multiple values
   tied for the same number of occurences, return the lesser of the
   tied values.
 */
int mode(int num, ...);
//--------------------------------------------

float median(int num, ...) {

  float numpop;
  numpop=0;
  float average;
  average=0;
 
  va_list myList;
  va_start (myList, num);
  if ((num%2)==0){ 
    numpop = (num/2)-1;
    int i; 
    for (i=0; i<numpop; i++){
      va_arg (myList,int);
}

    average = va_arg (myList, int);
    average = average + va_arg (myList, int);
    average = average/2;
    printf("i am here(even)");   
}

  else {
    numpop = num/2;
    int i;
    for (i=0; i<numpop; i++){
       va_arg (myList, int);
     
}

    average = va_arg (myList, int);
    printf("i am here(odd)");
   
 }



  va_end (myList);  

  /* This function definition is obviously incorrect and needs to be
     replaced. */
  return average;
}

int mode(int num, ...)
{

  va_list myList;
  va_start (myList, num);
   
  int iscounting;
  int countone;
  int highestcount;
  int counttwo;
  int c,d,swap;


  int intarray [num];


  int i;
  for (i=0 ; i<num; i++){
    intarray[i]=va_arg (myList,int);

}

  for (i=0 ; i<num; i++){
    printf ("%d", intarray[i]);
}
  printf("/n");
for (c = 0 ; c < ( num - 1 ); c++)
  {
    for (d = 0 ; d < num - c - 1; d++)
    {
      if (intarray[d] > intarray[d+1]) /* For decreasing order use < */
      {
        swap          = intarray[d];
        intarray[d]   = intarray[d+1];
        intarray[d+1] = swap;
      }
    }
  }
 highestcount = 0;
 counttwo =0;


 iscounting = intarray[0];
 countone=1;
 for (i=1; i<num; i++)
   {
   if (intarray[i]==iscounting)
     {
     countone++;
     }
   else 
     {
       if( countone == counttwo)
	 {
	   if (highestcount > iscounting ){highestcount = iscounting;} 
	 }

       if(countone > counttwo)
	 {
	   highestcount = iscounting;
	   counttwo = countone;
	 }

       iscounting =intarray[i];
       countone=1;

     }


   }



  va_end (myList);


 /* This function definition is obviously incorrect and needs to be
     replaced. */
  return highestcount;
}

int main() {

  /* MEDIAN */

  printf("the median is %f", median(3, 1,2,3));  /* one argument */
  // assert(median(1, 1) == 1);
  printf("the median is %f",  median (4, 1,2,3,4));
  /* special case: even number of arguments */
  //assert(median(2, 1, 2) == 1.5);
  printf("the modn is %d", mode(6, 1,1,2,2,2,3));
  /* straightforward three-argument cases */
  // assert(median(3, 1, 2, 3) == 2);
  //assert(median(3, 3, 2, 1) == 2);
  // assert(median(3, 3, 3, 3) == 3);

  /* straightforward four-argument cases */
  // assert(median(6, 9, -10, -1, 8, 3, 5) == 4);
  // assert(median(7, 5, 6, 4, 1, 2, 3, 7) == 4);

  /* TODO: you should add at least two more test cases for your
     median() function here. */

  /* MODE */

  /* straightforward cases */
  // assert(mode(1, 1) == 1);
  //assert(mode(3, 2, 1, 1) == 1);
  //assert(mode(7, 1, 1, 1, 2, 2, 2, 2) == 2);

  /* special case: tie */
  //assert(mode(6, 3, 3, 3, 2, 2, 2) == 2);
  //assert(mode(6, 2, 3, 2, 3, 2, 3) == 2);

  /* TODO: you should add at least two more test cases for your mode()
     function here. */

  return 0;
}

