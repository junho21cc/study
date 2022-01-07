package variable;

public class Test03 {

	public static void main(String[] args) {
		
		//문자
		// - ''(외따옴표)안에 적어야 문자형 데이터로 인식된다.
		
		//char 	2byte	0~65535
		
		//컴퓨터는 정수만 처리할 수 있다.
		//컴퓨터에서 문자를 처리하기 위해서 고유한 약속을 정해 놓았다.
		//문자마다 고유한 정수값을 정해놓고 문자 사용시 정수값으로 읽는다.
		
		//1.아스키코드 - 1byte
		// - 가장 처음 만들어진 문자 체계
		// - 총 128가지의 문자들을 처리하였다.
		// - 키보드 위에있는 문자들..
		// - C계열의 언어는 기본 문자 체계가 아스키코드이다..
		
		//2.유니코드 - 2byte
		// - 아스키코드 + 이세상의 모든 문자 = 약 6만개
		// - 자바는 기본 문자형식을 유니코드를 사용
		// - 오늘날 가장 널리 쓰이는 문자체계 (UTF-8)
		
		char ch = 'A';
		System.out.println(ch);
		System.out.println((int)ch);
		
		ch = '나';
		System.out.println(ch);
		System.out.println((int)ch);
		
		ch = '\n';
		System.out.println((int)ch);

	}

}
