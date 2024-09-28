#include <stdio.h>
#include <string.h>

struct student {
    char Name[ 20 ] ;
    char ID[ 20 ] ;
    float Score1 ;
    float Score2 ;
    float Score3 ;
    float Score4 ;
    float Score5 ;
} typedef s ;//end struct

void Grade( float score ) {
    printf( " " ) ;
    if ( score >= 80 ) {
        printf( "A" ) ;
    } else if ( score >= 75 &&score < 80 ) {
        printf( "B+" ) ;
    } else if ( score >= 70 &&score < 75 ) {
        printf( "B" ) ;
    } else if ( score >= 65 &&score < 70 ) {
        printf( "C+" ) ;
    } else if ( score >= 60 &&score < 65 ) {
        printf( "C" ) ;
    } else if ( score >= 55 &&score < 60 ) {
        printf( "D+" );
    } else if ( score >= 50 &&score < 55 ) {
        printf( "D" ) ;
    } else {
        printf( "F" ) ;
    }//end if-else
}//end function

float Average ( s student ) {
    float result = 0 ;
    result = student.Score1 + student.Score2 + student.Score3 + student.Score4 + student.Score5 ;
    result = result / 5 ;
    printf( "Average scores : %.2f \n", result ) ;
    return result ;
}//end function

int main () {

    int num ;
    printf( "Enter the details of student : " ) ;
    scanf( "%d", &num ) ;

    int i ;
    s student[ num ] ;
    for( i = 0 ; i < num ; i ++ ) {
        printf( "Student%d : \n", i + 1 ) ;

        getchar() ;
        printf( "Name : " ) ;
        gets( student[ i ].Name ) ;

        printf( "ID : " ) ;
        scanf( "%s", student[ i ].ID ) ;

        printf( "Scores in Subject1 : " ) ;
        scanf( "%f", &student[ i ].Score1 ) ;

        printf( "Scores in Subject2 : " ) ;
        scanf( "%f", &student[ i ].Score2 ) ;

        printf( "Scores in Subject3 : " ) ;
        scanf( "%f", &student[ i ].Score3 ) ;

        printf( "Scores in Subject4 : " ) ;
        scanf( "%f", &student[ i ].Score4 ) ;

        printf( "Scores in Subject5 : " ) ;
        scanf( "%f", &student[ i ].Score5 ) ;
    }//end for loop

    printf( "\nStudent Details : %d \n", num ) ;
    for( i = 0 ; i < num ; i ++ ) {
        printf( "Student%d \n", i + 1 ) ;
        printf( "Name : %s \n", student[ i ].Name ) ;
        printf( "ID : %s \n", student[ i ].ID ) ;
        printf( "Scores : %.2f %.2f %.2f %.2f %.2f \n", student[ i ].Score1 , student[ i ].Score2 , student[ i ].Score3 , student[ i ].Score4 , student[ i ].Score5 ) ;
        
        printf( "Grades : " ) ;
        Grade( student[ i ].Score1 ) ;
        Grade( student[ i ].Score2 ) ;
        Grade( student[ i ].Score3 ) ;
        Grade( student[ i ].Score4 ) ;
        Grade( student[ i ].Score5 ) ;
        printf( "\n" ) ;

        Average( student[ i ] ) ;
        printf( "\n" ) ;
    }//end for loop
    return 0 ;
}//end function
