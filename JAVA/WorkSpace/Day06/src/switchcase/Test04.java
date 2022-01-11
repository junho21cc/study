package switchcase;

import java.util.Scanner;

public class Test04 {

	public static void main(String[] args) {
		//정수 입력후 홀수인지 짝수인지 switch case문으로 나타내기
		Scanner sc = new Scanner(System.in);
		System.out.print("정수 입력 :");
		int num = sc.nextInt();
		switch(num % 2) {
		case 1:
			System.out.println("홀수");
			break;
		case 0:
			System.out.println("짝수");
			break;
		}
	}

}
