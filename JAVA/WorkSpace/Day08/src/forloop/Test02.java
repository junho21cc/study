package forloop;

public class Test02 {

	public static void main(String[] args) {
//		아래의 구간을 for문을 이용하여 화면에 출력
//		
//		[1] 2자리 정수
		for(int i=10;i<100;i++) {
			System.out.println(i);
		}
		
//		[2] 1부터 100사이의 홀수
		for(int i=1;i<=100;i++) {
			if(i % 2 == 1) {
				System.out.println(i);
			}
		}
		
//		[3] 대문자 알파벳
		for(int i=65;i<=90;i++) {
			System.out.println((char)i);
		}
		for(char ch='A';ch<='Z';ch++) {
			System.out.println(ch);
		}
//		[4] 1000보다 작은 3의 배수
		for(int i=1;i<1000;i++) {
			if(i % 3 == 0) {
				System.out.println(i);
			}
		}
		
//		[5] 1000보다 작은 2의 제곱수	(1, 2, 4, 8, 16, 32, ..., 256, 512)
		for(int i=1;i<1000;i*=2) {//i = i*2
			System.out.println(i);
		}

	}

}
