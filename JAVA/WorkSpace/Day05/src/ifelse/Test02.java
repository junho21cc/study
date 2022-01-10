package ifelse;

import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
//		중국집 주문 프로그램
//
//		사용자에게 자장면, 짬뽕 주문 수량을 입력받아 결재 금액을 계산하여 출력
//
//		자장면 - 5000원
//		짬뽕	- 6000원
//
//		5그릇 이상 주문하면 3천원 할인되도록 금액을 계산하여 출력해주세요
//		10그릇 이상 주문하면 10% 할인 처리
		Scanner sc = new Scanner(System.in);
		int bp = 5000;
		int rp = 6000;
		
		int cnt1 = 5;
		int cnt2 = 10;
		
		int rate1 = 3000;
		int rate2 = 10;
		
		System.out.print("자장면 개수 입력 :");
		int black = sc.nextInt();
		
		System.out.print("짬뽕 개수 입력 :");
		int red = sc.nextInt();
		
		int tot = black + red;
		int price = (black * bp) + (red*rp);
		
		if(tot >= cnt2) {//10
			System.out.println(cnt2+"그릇 이상 주문시 "+rate2+"%할인");
			System.out.println("총 금액 : "+(int)(price *((100-rate2)/100.0))+"원");
		}
		else if(tot >= cnt1) {
			System.out.println(cnt1+"그릇 이상 주문시 "+rate1+"원 할인");
			System.out.println("총 금액 : "+(price-rate1)+"원");
		}
		else {
			System.out.println("총 금액 : "+price+"원");
		}
		
	}

}
