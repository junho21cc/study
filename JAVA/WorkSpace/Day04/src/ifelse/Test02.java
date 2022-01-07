package ifelse;

import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//숫자를 입력받기
		// 문제 1) 양수, 0, 음수 출력
		System.out.print("정수 입력 :");
		int num = sc.nextInt();
		if(num > 0) {
			System.out.println("양수");
		}
		if(num < 0) {
			System.out.println("음수");
		}
		if(num == 0) {
			System.out.println("0");
		}
		//sysout ctrl+스페이스바 -> 자동완성
		
		// 문제 2) 4의 배수 출력
		System.out.print("숫자 입력 :");
		num = sc.nextInt();
		if(num % 4 == 0) {
			System.out.println("4의 배수");
		}
		else {
			System.out.println("4의 배수가 아니다");
		}
		
		// 문제 3) 80점 이상 합격, 불합격 출력
		System.out.println("성적 입력 :");
		int score = sc.nextInt();
		if(score >= 80) {
			System.out.println("합격");
		}
		else {
			System.out.println("불합격");
		}
	}

}
