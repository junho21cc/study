package whileloop;

public class Test04 {

	public static void main(String[] args) {
		//전역변수 - Java는 전역변수가 존재하지 않는다.
		
		//지역변수
		// - 어느 한 지역에서 우선적으로 사용되는 변수
		// - 그 지역이 실행할때 공간이 생성되고 그 지역이 끝날때 공간이 소멸된다.
		
		//		if(true) {
		//		int a = 10;
		//		System.out.println(a);
		//	}
		//	System.out.println(a);
		
		//1 ~ 10까지의 임의의 수를 구해서 합을구한다.
		//합이 100이 넘을때까지의 반복횟수를 구하세요.
		int sum = 0;
		int cnt = 0;
		
		while(true) {
			int su = (int)(Math.random() * 10)+1;
			
			sum += su;
			cnt++;
			if(sum > 100) {
				break;
			}
		}
		System.out.println(sum);
		System.out.println(cnt);
		sum = 0;
		cnt = 0;
		while(sum <= 100) {
			int su = (int)(Math.random() * 10)+1;
			sum += su;
			cnt ++;
		}
		System.out.println(sum);
		System.out.println(cnt);
		
	}

}
