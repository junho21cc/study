package input;

import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
//		앞의 예제를 참고하시어 사용자에게 입력을 받아 다음을 계산하시오
//
//		(결과 화면)	
//		자바 시험 점수 입력하세요
//		95
//		파이썬 시험 점수 입력하세요
//		80
//		이름을 입력하세요
//		홍길동
//		============================
//		홍길동님의 성적 합계 = 175점, 평균 = 87.5
//		단, 이름을 next사용 x , nextLine사용 o
		
		Scanner sc = new Scanner(System.in);
		System.out.println("자바 시험 점수 입력하세요");
		int java = sc.nextInt();
		System.out.println("파이썬 시험 점수 입력하세요");
		int python = sc.nextInt();
		System.out.println("이름을 입력하세요");
		sc.nextLine();//buffer비우기
		String name = sc.nextLine();
		System.out.println("=============================");
		int tot = java + python;
		double avg = tot / 2.0;
		System.out.println(name+"님의 성적 합계 = "+tot+"점, 평균 = "+avg);
	}

}
