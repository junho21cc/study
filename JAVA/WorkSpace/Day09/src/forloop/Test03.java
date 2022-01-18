package forloop;

import java.util.Scanner;

public class Test03 {

	public static void main(String[] args) throws InterruptedException {
//		타이머 만들기
//	    사용자에게 분을 입력받아서 해당하는 시간이 흐른 뒤 메세지가 출력되도록 코드구현
		// (예상결과)
		// 분 입력 : 3
		// 3분 0초 남음
		// 2분 59초 남음
		// ...
		// 0분 2초 남음
		// 0분 1초 남음
		// 0분 0초 남음
		// 땡 !
		Scanner sc = new Scanner(System.in);
		System.out.print("분 입력 :");
		int min = sc.nextInt();
		
		for(int s = min * 60;s >= 0; s--) {
			System.out.println(s/60+" 분 "+s%60+" 초 남음");
			Thread.sleep(1000);
			//내가 원하는 시간만큼 코드를 멈추는 메소드..
			// 밀리언초 단위로 지정하여 시간을 설정한다.
			// 1000ms == 1s
		}

	}

}
