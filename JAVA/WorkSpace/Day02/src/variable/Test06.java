package variable;

public class Test06 {

	public static void main(String[] args) {
		//예) 현금이 1000원이 있다. 200원짜리 과자 구입 후 잔돈출력
		int price = 1000;
		int 과자 = 200;
		int 잔돈 = price - 과자;
		System.out.println("잔돈 = "+잔돈+"원");
		
		// 문제1) 월급이 100원이다. 연봉은? (조건 : 세금 10% 제외)
		int 월급 = 100;
		double 연봉 = 월급 * 12 * 0.9;
		System.out.println("연봉 = "+연봉+"원");
		int 연봉1 = (int)연봉;//cast
		System.out.println("연봉 = "+연봉1+"원");

		// 문제2) 시험점수를 30, 50, 4점 을 받았다. 평균은?
		int score1 = 30;
		int score2 = 50;
		int score3 = 4;
		int tot = score1 + score2 + score3;//총점
		double avg = tot / 3.0;//정수 / 실수 -> 실수
		System.out.println("평균 = "+avg+"점");

		// 문제3) 가로가 3이고 세로가 6인 삼각형 넓이 출력
		int garo = 3;
		int sero = 6;
		double area = garo * sero / 2.0;
		System.out.println("삼각형의 넓이 = "+area);

		// 문제4) 100초를 1분 40초로 출력
		int su = 100;
		int m = su / 60;
		int s = su % 60;
		System.out.println(m+"분 "+s+"초");

		// 문제5) 800원에서 500원짜리 개수 , 100원짜리 개수
		// 정답5) 500원(1개), 100원(3개)
		price = 800;//값교체
		int 오백원 = price / 500;//몫
		int 백원 = price % 500 / 100;
		//800 % 500 -> 300 / 100 -> 3
		System.out.println("500원 ="+오백원+"개");
		System.out.println("100원 = "+백원+"개");

	}

}
