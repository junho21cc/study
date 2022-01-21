package array;

import java.util.Scanner;

public class Test05 {

	public static void main(String[] args) throws InterruptedException {
//		선택장애 치료 프로그램
//
//		사용자에게 5가지 항목을 입력받아 배열에 저장
//		무작위로 1가지를 추첨하여 화면에 출력
//
//		(예)	항목 : 김밥
//			항목 : 라면
//			항목 : 떡볶이
//			항목 : 자장면
//			항목 : 순대국
//			추첨중입니다....
//			추첨된 항목은 떡볶이 입니다
		String[] menu = new String[5];
		Scanner sc = new Scanner(System.in);
		
		for(int i=0;i<menu.length;i++) {
			System.out.print("항목 입력 :");
			//String name = sc.next();
			//menu[i] = name;
			menu[i] = sc.next();
		}
		System.out.println("추첨중입니다...");
		Thread.sleep(1000);
		int rand = (int)(Math.random() * menu.length);//0 1 2 3 4
		System.out.println(menu[rand]);
		
	}

}
