package output;

public class Test01 {

	public static void main(String[] args) {
		//IO - Input / Output -입출력
		//stream방식의 언어
		
		//System.out - 표준 출력 객체
		// - 자바에서 출력을 하기위해 미리 만들어진 통로
		
		//.println() - 내용 출력 후 엔터
		//.print() - 내용만 출력
		//.printf() - x - C방식
		
		System.out.print(".print()");
		System.out.println("- 내용만 출력 ");
		
		//제어문자
		// - 특수한 기능을 하는 문자들..
		// - 주로 콘솔창을 제어하는 문자이다..
		// - 실행하고자 하는 위치에 적어주면된다.
		// - \뒤에 기능에 맞는 문자들을 적으면 된다. (원화)
		// - 약 30가지
		
		// \n ( New Line, Line Feed )
		// - 커서를 다음줄로 이동시키는 제어문자
		System.out.println("가\n나");
		System.out.print("Hello\n");
		System.out.println("JAVA");
		
		// \t ( Tab )
		// - 커서를 탭 크기만큼 이동시키는 제어문자
		// - 주로 줄 맞출때 사용한다..
		System.out.println("이름\t : 홍길동");
		System.out.println("전화번호\t : 010-1234-5678");
		
		//\r , \b , \a..
		
		//문자열에서 특수한 기능을 하는 문자들을 출력할때 지장이 생긴다..
		// \ 뒤에 적으면 문자로 인식된다.
		
		//"HI"
		System.out.println("\"HI\"");
		
		//D:\안소연JAVA_0104\WorkSpace\Day03
		System.out.println("D:\\안소연JAVA_0104\\WorkSpace\\Day03");

	}

}
