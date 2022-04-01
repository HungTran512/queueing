/******************************************************************************
 *  Name: Hung Tran
 *
 *  Operating system: Mac OS
 *  Compiler: g++
 *  Text editor / IDE: Atom
 *  Hours to complete assignment (optional): 5
 ******************************************************************************/


/******************************************************************************
 *  Describe concisely your algorithm to compute the horizontal and
 *  vertical seam.
 *****************************************************************************/
 For VerticalSeam, I made a struct that store the RGB color, the energy value
 (which is the sum of the energy of it's parents and itself) and a pointer to the
 parent. I first set the energy of the first row, then recursively from the second
 to the last row: I check all the possible parents and choose the one with the lowest
 energy counts. Then I check the smallest value at the last row which is the sum of the
 shortest paths possible to lead there and track back to the top.

 For HorizontalSeam, I create a temporary object of picture which is the transposed
 of the normal picture, create an object of seam carver for the temporary picture and
 run findVerticalSeam() on that seam carver object.

/******************************************************************************
 *  Describe what makes an image ideal for this seamCarving algorithm and what
 *   kind of image would not work well.
 *****************************************************************************/
 An image with seams that have low energy and in an approximately straight lines
 is an ideal image for SeamCarving.

 An image without high difference in energy and and the low energy areas are not
 in a straight vertical and horizontal lines.




/******************************************************************************
 *  Give a formula (using tilde notation) for the running time
 *  (in seconds) required to reduce image size by one row and a formula
 *  for the running time required to reduce image size by one column.
 *  Both should be functions of W and H. Removal should involve exactly
 *  one call to the appropriate find function and one call to the
 *  appropriate remove function. The randomPicture() function in SCUtility
 *  may be useful.
 *
 *  Justify your answer with sufficient data using large enough
 *  W and H values. To dampen system effects, you may wish to perform
 *  many trials for a given value of W and H and average the results.
 *
 *  Be sure to give the leading coefficient and the value of the exponents
 *  as a fraction with 2 decimal places .
 *****************************************************************************/

(keep W constant)

 H           Row removal time (seconds)     Column removal time (seconds)
--------------------------------------------------------------------------
100                     10.8379                       9.00156
200                     19.7597                       13.0571
300                     24.0712                       17.889
400                     26.5379                       21.8854


(keep H constant)

 W           Row removal time (seconds)     Column removal time (seconds)
--------------------------------------------------------------------------
100                   11.1395                       6.91047
200                   18.8175                       10.8806
300                   23.9795                       17.9298
400                   26.3593                       21.9757


Running time to remove one row as a function of both W and H:  ~ W x H



Running time to remove one column as a function of both W and H:  ~ W x H






/******************************************************************************
 *  Known bugs / limitations.
 *****************************************************************************/




/******************************************************************************
 *  Describe whatever help (if any) that you received.
 *  Don't include readings, lectures, and exercises, but do
 *  include any help from people (including classmates and friends) and
 *  attribute them by name.
 *****************************************************************************/
Tutoring.

/******************************************************************************
 *  Describe any serious problems you encountered.
 *****************************************************************************/




/******************************************************************************
 *  List any other comments here. Feel free to provide any feedback
 *  on how much you learned from doing the assignment, and whether
 *  you enjoyed doing it.
 *****************************************************************************/
