package ifelse;

import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
//		�߱��� �ֹ� ���α׷�
//
//		����ڿ��� �����, «�� �ֹ� ������ �Է¹޾� ���� �ݾ��� ����Ͽ� ���
//
//		����� - 5000��
//		«��	- 6000��
//
//		5�׸� �̻� �ֹ��ϸ� 3õ�� ���εǵ��� �ݾ��� ����Ͽ� ������ּ���
//		10�׸� �̻� �ֹ��ϸ� 10% ���� ó��
		Scanner sc = new Scanner(System.in);
		int bp = 5000;
		int rp = 6000;
		
		int cnt1 = 5;
		int cnt2 = 10;
		
		int rate1 = 3000;
		int rate2 = 10;
		
		System.out.print("����� ���� �Է� :");
		int black = sc.nextInt();
		
		System.out.print("«�� ���� �Է� :");
		int red = sc.nextInt();
		
		int tot = black + red;
		int price = (black * bp) + (red*rp);
		
		if(tot >= cnt2) {//10
			System.out.println(cnt2+"�׸� �̻� �ֹ��� "+rate2+"%����");
			System.out.println("�� �ݾ� : "+(int)(price *((100-rate2)/100.0))+"��");
		}
		else if(tot >= cnt1) {
			System.out.println(cnt1+"�׸� �̻� �ֹ��� "+rate1+"�� ����");
			System.out.println("�� �ݾ� : "+(price-rate1)+"��");
		}
		else {
			System.out.println("�� �ݾ� : "+price+"��");
		}
		
	}

}
