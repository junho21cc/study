package ifelse;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		int a = 9;
		int b = 9;
		
		//if문은 조건식이 true일때 실행한다.
		if(a >= 10) { //단순if
			System.out.println("a는 10이상이다");
			System.out.println("a는 10이상이다");
		}
		
		if(a==b)//단순 if
			System.out.println("a의 값과 b의 값은 동일하다");
		//{}을 감싸는 경우는 종속문장이 1줄 초과일때..
		//{}을 안쓴경우는 종속문장이 1줄일때..
		
		//ex) 홀 짝
		Scanner sc = new Scanner(System.in);
		System.out.print("숫자를 입력 :");
		int num = sc.nextInt();
		
		//짝수
		if(num % 2 == 0) {
			System.out.println("짝수이다");
		}
		if(num % 2 == 1) {//홀수
			System.out.println("홀수이다");
		}
		
		if(num % 2 == 0) {
			System.out.println("짝수");
		}
		else {//위 조건식이 거짓일때 실행된다.
			System.out.println("홀수");
		}
	}

}
