package ifelse;

import java.util.Scanner;

public class Test03 {
	

	public static void main(String[] args) {
		//System.currentTimeMillis();
		//1970년 1월 1일 0시 0분 0초부터 지금까지의 시간을 밀리언 초 단위로 반환하는 함수
		// 1000밀리언초 == 1초
		long a = System.currentTimeMillis();//밀리언 초
		long b = a / 1000;//초
		long c = b / 60;//분
		long d = c /60;//시간
		long e = d /24;//일
		long f = e / 365;//년
		long g = 1970 + f;//올해년도
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
		System.out.println(d);
		System.out.println(e);
		System.out.println(f);
		System.out.println(g);
		
		int sysyear = 1970 + (int)(System.currentTimeMillis()/1000/60/60/24/365);
		System.out.println(sysyear);
//		사용자에게 출생년도 4자리를 입력받으시고 나이를 계산해서 화면에 출력
		//	2000년생 → 23살
		//	2001년생 → 22살
		//	n     년생 → ?살
		//
		//	나이가 20살 이상이면 성인입니다! 출력
		//	나이가 20살 미만이면 미성년자입니다! 출력
		Scanner sc = new Scanner(System.in);
		System.out.print("출생년도 입력 :");
		int myYear = sc.nextInt();
		int year = sysyear - myYear + 1;//사람 나이는 1살부터
		if(year >= 20) {
			System.out.println("성인입니다");
		}
		else {
			System.out.println("미성년자입니다");
		}
		sc.close();
	}

}
