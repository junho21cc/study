package ifelse;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		/*
		 * # 369게임[1단계]
		 * 1. 숫자입력
		 * 2. 위 수에 369의 개수가
		 * 	1) 2개이면, 짝짝을 출력
		 *  2) 1개이면, 짝을 출력
		 *  3) 0개이면, 해당 숫자를 출력
		 * 예)
		 * 		33	 : 짝짝
		 * 		16	 : 짝
		 * 		 7	 : 7
		 */
		int count = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("숫자 입력 :");
		int num = sc.nextInt();
		int ten = num / 10;
		int one = num % 10;
		
		if(ten % 3 == 0 && ten != 0) {
			count++;//count = count +1; count+=1;
		}
		if(one == 3 || one == 6 || one == 9) {
			count++;
		}
		
		if(count == 2) {
			System.out.println("짝짝");
		}
		else if(count==1) {
			System.out.println("짝");
		}
		else {
			System.out.println(num);
		}

	}

}
