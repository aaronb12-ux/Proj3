#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void delete_numarray(int** *numarray, int numpoints); 
typedef struct vertexpoints_struct
//initializing a struct for the 2d points
{
    int x1;
    int y1;
    int x2;
    int y2;
    float distance;
    int numofpoints;
} vertexpoints;

vertexpoints coordinates; 
//variable for the struct

void calc_perimeter(int **numarray,int numofpoints )
{

double perimeter = 0;
int currcol = 0; //the current column is set to zero because we are not looping through columns, only rows
//initialiing the perimeter
    for (int i = 0; i < numofpoints; ++i){
     //looping through the rows
      if(i == numofpoints - 1){
        coordinates.x1 = numarray[i][currcol];              
        coordinates.y1 = numarray[i][currcol + 1];
        coordinates.x2 = numarray[0][currcol];
        coordinates.y2 = numarray[0][currcol + 1];
    //this branch is only passed when we reach the last point in the array, because it needs to be multiplied by the first point
    }
       
    else{
       coordinates.x1 = numarray[i][currcol];
       coordinates.y1 = numarray[i][currcol + 1];
       coordinates.x2 = numarray[i + 1][currcol];
       coordinates.y2 = numarray[i + 1][currcol + 1];
    //otherwise multiply the current point with the next one
      }
    coordinates.distance = sqrt(pow(coordinates.x2 - coordinates.x1, 2) + pow(coordinates.y2 - coordinates.y1,2));
    //using distance formula to calculate the distance between 2 poins
    perimeter = perimeter + coordinates.distance;
    //ading that value to the perimeter
    }


printf("The perimeter is %.2lf", perimeter);
//printing the perimeter
delete_numarray(&numarray, numofpoints);
//deleting the array
}     

    


int read_bin_number_to_array(char *file_name)
{
    FILE *file = fopen(file_name, "rb");
    //opening the file in binary read mode
    coordinates.numofpoints = 0;
    //creating a variable that stored the number of points
    
    fread(&coordinates.numofpoints, sizeof(int), 1, file);
    //reading the FIRST line in the file because the first line is the number of points
     

    int** numarray = (int **)malloc(coordinates.numofpoints * sizeof(int *)); //allocating an array that stores the number of points as rows
     
    for(int numpoints = 0; numpoints < coordinates.numofpoints; ++numpoints){ //allocting more space for a 2d array, each column is 2 spaces long because all points in a 2d system has length 2

        numarray[numpoints] = (int *)malloc(2 * sizeof(int));               
    }
    
    while (!feof(file))
    {//while not at the end of the file
       
     for (int currRow = 0; currRow < coordinates.numofpoints; ++currRow)
    {       
        for (int currCol = 0; currCol < 2; ++currCol)
        {
            fread(&numarray[currRow][currCol], sizeof(int), 1, file);  //whatever integer the user inters it will be stored into the current index
            //reading each line in the file, and storing that value in the array at the current row and column
        }
    }
}

calc_perimeter(numarray, coordinates.numofpoints);
//now calling the function that calculates the perimeter
//its passed the array with the values and number of points
return 0;
}

    


int main(int argc, char **argv)
{

    read_bin_number_to_array(argv[1]);
    //calling the function to read the binary numbers into an array. Its passed the first command line argument which is the input file.
    return 0;
}



void delete_numarray(int** *numarray, int numpoints) 
{//this function deletes the array and sets it to NULL. 
    for (int i = 0; i < numpoints; ++i){               
   //looping through all the rows in the array
   //going through each row, and deleting the array made at that row  
    free((*numarray)[i]);                                         

 }
free(*numarray);
*numarray = NULL;
}









