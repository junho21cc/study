package switchcase;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("1~3 정수 입력 :");
		int num = sc.nextInt();
		
		switch(num) {
		case 1:
			System.out.println("1번 선택");
			break;
		case 2:
			System.out.println("1,2번 선택");
			break;
		case 3:
			System.out.println("3번 선택");
			break;
		default :
			System.out.println("잘못된 번호 입력 !");	
		}

	}

}
