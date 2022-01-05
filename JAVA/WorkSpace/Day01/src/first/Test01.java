package first;//현재 파일이 속한 패키지를 적는 부분..
//패키지는 항상 가장 위에 적혀야한다..

//package - import - class
import java.lang.*;

public class Test01 {
	//main 영어 치고 ctrl+space -> main메소드 더블클릭
	public static void main(String[] args) {
		
		//System.out.println(출력 내용);
		// - JAVA에서의 표준 출력 명령
		
		//모든 프로그래밍 언어에서는 문장을 문자열이라 부른다..
		//""안에 적으면 문자열 데이터로 인식된다.
		
		//정수
		System.out.println(10);
		System.out.println(20);
		System.out.println("10");//정수x -> 문자열
		
		//실수
		System.out.println(10.123);
		System.out.println("2.34");//실수x -> 문자열
		
		//문자 : 단일문자 ' '
		System.out.println('A');
		System.out.println('가');
		System.out.println("A");//문자x -> 문자열
		
		//문자열 : ""
		System.out.println("Hello JAVA!!");
		System.out.println("A");
		
	}

}
