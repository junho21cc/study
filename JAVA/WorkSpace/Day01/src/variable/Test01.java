package variable;

public class Test01 {

	public static void main(String[] args) {
		//선언과 동시에 초기화
		int a = 20;
		System.out.println(a);//변수의 호출
		
		a = 10;//초기화 x, 값 변경
		System.out.println(a);
		// - 변수의 선언은 단 한번만 가능하다 ( 같은 변수명 )
		//int a = 10; x    a = 10; o
		
		//int 1a; - 변수명은 숫자로 시작 x
		//int a1; - o
		int 한글;//변수명은 한글 가능
		int A = 30;//대소문자 구별
		System.out.println(A);
		System.out.println(a);
		
		//int 한 글; - 변수명 공백 불가능
		int 한_글;// - 언더바 가능
	}

}
