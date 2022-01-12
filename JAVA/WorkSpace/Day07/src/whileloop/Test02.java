package whileloop;

public class Test02 {

	public static void main(String[] args) {
		
		//문제1) 1 ~ 10까지 출력
		int i = 1;
		while(true) {
			System.out.println("i = "+i);
			if(i==10) {
				break;
			}
			i++;
		}
		i = 1;
		while(i<=10) {
			System.out.println("i = "+i);
			i++;
		}
		
		//문제2) 1 ~ 10까지 반복해 5~9 출력
		// 정답2) 5, 6, 7, 8, 9
		i = 1;
		while(true) {
			if(i>=5 && i<=9) {
				System.out.print(i+" ");
			}
			if(i==10) {
				break;//break;를 한 이후에 코드가 들어갈수가없다.
			}
			i++;
		}
		System.out.println();
		i = 1;
		while(i<=10) {
			if(i >= 5 && i<=9) {
				System.out.print(i+" ");
			}
			i++;
		}
		System.out.println();
		//문제3) 10~1까지 반복해 6~3 거꾸로 출력
		// 정답3) 6, 5, 4, 3
		i = 10;
		while(true) {
			if(i >= 3 && i<= 6) {
				System.out.print(i+" ");
			}
			if(i == 1) {
				break;
			}
			i--;
		}
		System.out.println();
		i = 10;
		while(i>=1) {
			if(i>=3 && i<=6) {
				System.out.print(i+" ");
			}
			i--;
		}
		System.out.println();
		//문제4) 1~10까지 반복해 짝수만 출력
		// 정답4) 2, 4, 6, 8, 10
		i = 1;
		while(true) {
			if(i % 2 == 0) {
				System.out.print(i+" ");
			}
			if(i == 10) {
				break;
			}
			i++;
		}
		System.out.println();
		i = 1;
		while(i<=10) {
			if(i % 2 == 0) {
				System.out.print(i+" ");
			}
			i++;
		}

	}

}
