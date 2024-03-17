#include <iostream>
// #include 는 전처리기라고 한다. 기능 : 헤더파일을 여기에 포함시키는 기능
// visual studio는 컴파일러, cpp는 고수준 언어(사람이 쉽게 이해할 수 있는 수준의 언어)
// 컴파일 : 번역작업(고수준 언어 → 저수준 언어(컴퓨터가 이해할 수 있는 언어))
// 컴파일 → 빌드 (Ctrl + Shift + B)

using namespace std;

// CPP의 시작점은 main 함수이다. main함수는 반드시 있어야 한다.
int main()
{
    // cpp 표준 기능의 대부분은 std라는 namespace 안에 존재한다. 
    cout << "Hello World!" << endl;

    /*
    변수 : 변하는 수, 값이 바뀔 수 있다.
    용량의 최소단위 : bit
    1byte = 8bit

    문자를 표현하는 방법 : ASCII 코드 표를 참고한다
    종류    ]     용량      |   데이터    |    표현범위    |   unsigned
    char    ]     1byte     |   문자      |    -128 ~ 127  |   0-255
    bool    ]     1byte     |   참/거짓   |   true / false |   true/false
    short   ]     2byte     |   정수      | -32768 ~ 32767 |   0-65535
    int     ]     4byte     |   정수      | 약 -22억 ~ 21억|   0-약 43억
    float   ]     4byte     |   실수      |    
    double  ]     8byte     |   실수      |    
    */

    int abc = 10;

    cout << abc << endl;

    bool bTest = true;

    cout << bTest << endl;

    char cTest = 'h';

    cout << cTest << endl;

    float fNum = 3.14f;
    // float 변수에는 뒤에 f를 붙여줘야된다 안붙이면 double 변수가 되어서 메모리가 쓸데없이 크게 할당될 수 있다
    // 
    // 컴퓨터는 4byte를 할당하고 abc라는 변수를 만든다

    /*
    사칙 연산자 : +, -, *, /, %
    연산 순서 → 괄호부터
    관계 연산자 : 값대 값은 연산하여 참/거짓으로 결과를 반환한다.
    >, >=, <. <=, ==, !=
    */

    cout << "10 < 20 = " << (10 < 20) << endl;
    cout << "10 <= 20 = " << (10 <= 20) << endl;
    cout << "10 > 20 = " << (10 > 20) << endl;
    cout << "10 >= 20 = " << (10 >= 20) << endl;
    cout << "10 == 20 = " << (10 == 20) << endl;
    cout << "10 != 20 = " << (10 != 20) << endl;

    /*
    논리 연산자 : 참/거짓 대 참/거짓을 연산하여 참/거짓으로 결과를 반환한다
    AND(&&), OR(||), NOT(!)

    우선순위 : 관계연산 → 논리연산
    */

    cout << "숫자를 입력하세요 : ";
    cin >> abc;

    cout << (10 <= abc && abc <= 20) << endl;

    return 0;
}