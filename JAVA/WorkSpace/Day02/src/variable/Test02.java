package variable;

public class Test02 {

	public static void main(String[] args) {
		//논리형 - boolean		1byte		true/false
		//참과 거짓을 관리하는 자료형
		// - true/ false
		// - 어떤 대상을 표현할때 상태값이 두가지인 경우
		
		boolean a = true;//참 ( 맞다 )
		System.out.println(a);
		
		//관계연산자 - 데이터의 관계를 연산하는 연산자
		// < > <= >= == !=
		// == : 같다
		// != : 다르다
		a = (10 > 5);
		System.out.println(a);
		
		a = (10 == 10);
		System.out.println(a);
		
		a = (10 != 10);
		System.out.println(a);
		
		//논리연산자
		// - 조건식에 대한 참과 거짓을 판별하는 연산자
		
		// && - and(논리곱) - 양쪽 모두 참일때 참을 발생
		System.out.println(10 > 5 && 10 != 10);
		
		// || - or(논리합) - 둘중 하나라도 참이면 참을 발생
		System.out.println(10 < 5 || 10 == 10);
		
		//true : 1		false : 0
		
		//조건식	논리연산자	 조건식	and		or
		//true			 true	true	true
		//false			 true	false	true
		//true			 false	false	true
		//false			 false	false	false
		
		// ! - not(부정) - 참이면 거짓 , 거짓이면 참
		System.out.println(!(10>5));
		
	}

}
