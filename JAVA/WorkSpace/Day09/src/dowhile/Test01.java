package dowhile;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		//do ~ while
		// - 무조건 한번은 실행을 해야하며 잘못된 데이터를 걸러낼때 사용한다.
		// - 형식상 종속문장이 먼저 실행을 하고 조건식을 비교하는 형식이다.
		// - 반복문안에서 만들어진 결과를 조건식에서 비교하기에 좋다.
		// - while이랑 구별하기 위해서 제일 끝에 ;을 적어준다.
		
		//형식
		//do{
		//		종속문장;
		//}while(조건식);
		Scanner sc = new Scanner(System.in);
		//10 ~ 20사이의 숫자를 입력받으면 반복 종료
		int su;
		do {
			System.out.print("10 ~ 20 사이 정수 입력 :");
			su = sc.nextInt();
		}while(su < 10 || su > 20);
		System.out.println(su);
	}

}
