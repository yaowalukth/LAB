/*
    จงเขียนโปรแกรมทายตัวเลขซึ่งทำงานดังนี้
    - ตอนเริ่มเกมผู้เล่นจะมีคะแนนเต็ม 100
    - โปรแกรมจะสุ่มตัวเลขที่มีค่าตั้งแต่ 1 ถึง 100
    - ให้ผู้เล่นทายว่าตัวเลขที่โปรแกรมสุ่มมามีค่าเป็นเท่าใด
        - หากทายผิด โปรแกรมจะลบคะแนนของผู้เล่นไป 10 หน่วย พร้อมแจ้งคะแนนปัจจุบันให้ผู้เล่นทราบด้วย
        - หากทายผิด โปรแกรมจะต้องบอกใบ้ว่าคำตอบที่ถูกมีค่า "มากกว่า" หรือ "น้อยกว่า" ตัวเลขที่ผู้ใช้ทาย
        - หากทายผิด ให้โปรแกรมรอรับตัวเลขถัดไปได้เลย
        - หากทายถูก ให้โปรแกรมแสดงความยินดีกับผู้ใช้ พร้อมแจ้งคะแนนปัจจุบันให้กับผู้เช่น
        - เมื่อเล่นเสร็จโปรแกรมรอรับคำสั่งจากผู้ใช้ หากผู้ใช้กรอกเลข 1 จะเข้าสู่โหมดการเล่นเกมใหม่อีกครั้ง หากกด -1 ให้หยุดการทำงานของโปรแกรม

    หมายเหตุ : การสุ่มตัวเลขจะใช้คำสั่ง rand() ที่อยู่ใน stdlib.h หากต้องการสุ่มตัวเลข 0 ถึง 100 ต้องใช้คำสั่งดังนี้
        rand() % 100 + 1
    หมายเหตุ : หากต้องการสุ่มตัวเลขที่เปลี่ยนแปลงตามเวลา ต้องใช้คำสั่ง srand( time( NULL ) ) ในตอนต้นของโปรแกรมด้วย

    Test case & Output:
        Do you want to play game (1=play,-1=exit) :
            1
        (Score=100)
        Guess the winning number (1-100) :
            20
        Sorry, the winning number is HIGHER than 20. (Score=90)
        Guess the winning number (21-100) :
            50
        Sorry, the winning number is LOWER than 50. (Score=80)
        Guess the winning number (21-49) :
            42
        That is correct! The winning number is 42.
        Score this game: 80

        Do you want to play game (1=play,-1=exit) :
            1
        (Score=100)
        Guess the winning number (1-100) : 
            75
        Sorry, the winning number is LOWER than 75. (Score=90)
        Guess the winning number (1-74) : 
            20
        Sorry, the winning number is LOWER than 20. (Score=80)
        Guess the winning number (1-19) : 
            2
        Sorry, the winning number is HIGHER than 2. (Score=70)
        Guess the winning number (3-19) : 
            15
        That is correct! The winning number is 15.
        Score this game: 70

        Do you want to play game (1=play,-1=exit) :
            -1
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int play ;
    int playAgain ;

    printf( "Do you want to play game? ( 1 = play , -1 = exit ) \n" ) ;
    scanf( "%d", &play ) ;

    if( play == 1 ) {
        printf( "Let's play \n" ) ;

        do {
            int number ;
            int guess ;
            int score = 100 ;
            int min = 1 ;
            int max = 100 ;

            number = rand() % 100 + 1 ;
            srand( time( NULL ) ) ;

            printf( "Your score is : %d \n", score ) ;
            while( score > 0  ) {
                printf( "Guess  the wining number ( %d - %d ) : \n", min , max ) ;
                scanf( "%d", &guess ) ;
                
                if( guess < 1 || guess > 100 ) {
                    printf( "Please enter number between 1 -100 \n" ) ;
                    continue ;
                }//end if

                if( guess == number ) {
                    printf( "That is correct! The winning number is %d \n", guess ) ;
                    printf( "Your score is %d \n", score ) ;
                    break ;
                } else {
                    score -= 10 ;
                    if( score <= 0 ) {
                        printf( "Your point are all gone \n" ) ;
                        printf( "The correct number is : %d \n", number ) ;
                        break ;
                    }//end if
                    if( guess < number ) {
                        if( guess > min ) {
                            min = guess + 1 ;
                        }//end if
                        printf( "Sorry, the winning number is higher than %d \n", guess ) ;
                    } else {
                        if( guess < max ) {
                            max = guess -1 ;
                        }//end if
                        printf( "Sorry, the winning number is lower than %d \n", guess ) ;
                    }//end else-if
                    printf( "Your score now is %d \n", score ) ;
                }//end else-if
            }// while
            printf( "Do you want to playagain? ( 1 = playAgain , -1 = exit ) \n" ) ;
            scanf( "%d", &playAgain ) ;
            if( playAgain != 1 ) {
                printf( "Thank you for playing \n" ) ;
            } else {
                printf( "Let's play" ) ;
            }//end else-if
        }while( playAgain == 1 ) ;//do-while
    } else {
        printf( "Thank you \n" ) ;
    }//end if
    return 0 ;
}//end function
