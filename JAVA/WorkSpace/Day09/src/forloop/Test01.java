package forloop;

public class Test01 {

	public static void main(String[] args) {
		//반복 1~1000
		//문제1) 9의 배수중 일의 자리가 6인 첫번째 배수 출력 ==> 답 : 36
		for(int i=1;i<=1000;i++) {
			if(i % 9 == 0 && i % 10 == 6) {
				System.out.println(i);
				break;
			}
		}
		
		//문제2) 9의 배수중 십의 자리가 6인 첫번째 배수 출력 ==> 답 : 63
		for(int i=1;i<=1000;i++) {
			if(i % 9 == 0 && i / 10 == 6) {
				System.out.println(i);
				break;
			}
		}
		int num = 0;
		//문제3) 8의 배수중  150보다 작고 150 에 가장 가까운수를 출력 ==> 답 : 144
		for(int i=1;i<=1000;i++) {
			if(i % 8 == 0 && i < 150) {
				num = i;
				//System.out.println(num);
			}
		}
		System.out.println(num);
		

	}

}
