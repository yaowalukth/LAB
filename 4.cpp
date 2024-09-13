#include <stdio.h>

int main() {
    char ID[ 10 ] ;
    int WorkingHour, Salary ;
    printf( "\n\nInput the Employees ID(Max. 10 chars): " ) ;//รหัสงาน(งานอะไร)
    scanf( "%s", ID ) ;
    printf( "Input the working hrs: " ) ;//ชั่วโมงการทำงานกี่ชั่วโมง
    scanf( "%d", &WorkingHour ) ;
    printf( "Salary amount/hr: " ) ;//จำนวนเงินต่อชั่วโมง
    scanf( "%d", &Salary ) ;

    printf( "\n---------------\n" ) ;
    printf( "Employees ID = %s\n", ID ) ;
    printf( "Salary = %d THB", WorkingHour * Salary * 22 ) ;

    printf( "\n\n" ) ;
    return 0 ;
}//end function
