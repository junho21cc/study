package variable;

public class Test04 {

	public static void main(String[] args) {
		//String - 문자열
		// - 참조형
		// - 지금은 일반변수처럼 사용하자..
		// - 문자열을 구분하기 위해서 ""(쌍따옴표)안에 저장한다.
		
		String name = "홍길동";
		System.out.println(name);
		
		//문자열은 연산이 불가능하다..
		// 단, 문자열 더하기는 가능하다..
		// 문자열 더하기는 문자열 뒤에 문자열을 붙여준다..(이어붙이기)
		
		System.out.println(name + "더하기");
		//"홍길동" + "더하기" = "홍길동더하기"
		System.out.println(name + 10);
		//"홍길동" + 10 = "홍길동10"
		System.out.println(name + 10+20);
		//"홍길동" + 10 + 20 = "홍길동1020"
		System.out.println(name + (10+20));
		//"홍길동" + (10+20) -> "홍길동" + 30 -> "홍길동30"
		System.out.println(10+20+"홍길동");
	}

}
