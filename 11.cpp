/*
    จงเขียนฟังก์ชันในการตรวจสอบตัวเลขที่ผู้ใช้ป้อนเข้ามา ว่าเป็นตัวเลขที่เป็นอาร์มสตรองหรือไม่ หากใช่ให้แสดงคำว่า Pass หากไม่ใช่แสดงคำว่า Not Pass
    
    หมายเหตุ: ตัวเลขอาร์มสตรอง คือ ตัวเลขที่ผลรวมของเลขยกกำลังของจำนวนหลัก เช่น
    153 เป็นตัวเลขอาร์มสตรอง เพราะ 153 มีทั้งหมด 3 หลัก จึงมีค่าเท่ากับ = 1^3 +  5^3 +  3^3 (โดยที่เครื่องหมาย ^ หมายถึงเลขยกกำลัง)
    370 = 3^3 + 7^3 + 0^3

    Test Case:
        Enter Number:
            153
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            370
    Output:
        Pass.
    
    Test Case:
        Enter Number:
            372
    Output:
        Not Pass.
*/
#include <stdio.h>
#include <string.h>

int power( int base , int e ) {
    int result = 1 ;
    for ( int i = 0 ; i < e ; i++ ) {
        result *= base ; 
    }
    return result;
}//end function

void Armstrong( char Number[] ) {
    int c = strlen( Number ) ;
    int i ;
    int ans = 0 ;

    for( i = 0 ; i < c ; i ++ ) {
        int num = Number[ i ] - '0' ;
        ans += power( num , c ) ;
    }//end for
    printf( "%d \n", ans ) ;

    int Usernumber = 0 ;
    for ( i = 0 ; i < c ; i++ ) {
        Usernumber = Usernumber * 10 + ( Number[ i ] - '0' ) ;
    }//end for

    if( Usernumber != ans ) {
        printf( "Not Pass" ) ;
    } else {
        printf( "Pass" ) ;
    }//end if-else
}//end function

int main() {

    char Number[ 100 ] ;
    printf( "-------------------------------------\n" ) ;
    printf( "Enter your number : " ) ;
    scanf( "%s" , Number ) ;
    printf( "Your number is : %s", Number ) ;
    printf( "\n-------------------------------------\n" ) ;

    Armstrong( Number ) ;
    printf( "\n-------------------------------------\n" ) ;
    
    return 0 ;
}//end function
