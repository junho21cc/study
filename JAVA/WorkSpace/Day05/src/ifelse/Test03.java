package ifelse;

import java.util.Scanner;

public class Test03 {
	

	public static void main(String[] args) {
		//System.currentTimeMillis();
		//1970�� 1�� 1�� 0�� 0�� 0�ʺ��� ���ݱ����� �ð��� �и��� �� ������ ��ȯ�ϴ� �Լ�
		// 1000�и����� == 1��
		long a = System.currentTimeMillis();//�и��� ��
		long b = a / 1000;//��
		long c = b / 60;//��
		long d = c /60;//�ð�
		long e = d /24;//��
		long f = e / 365;//��
		long g = 1970 + f;//���س⵵
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
		System.out.println(d);
		System.out.println(e);
		System.out.println(f);
		System.out.println(g);
		
		int sysyear = 1970 + (int)(System.currentTimeMillis()/1000/60/60/24/365);
		System.out.println(sysyear);
//		����ڿ��� ����⵵ 4�ڸ��� �Է¹����ð� ���̸� ����ؼ� ȭ�鿡 ���
		//	2000��� �� 23��
		//	2001��� �� 22��
		//	n     ��� �� ?��
		//
		//	���̰� 20�� �̻��̸� �����Դϴ�! ���
		//	���̰� 20�� �̸��̸� �̼������Դϴ�! ���
		Scanner sc = new Scanner(System.in);
		System.out.print("����⵵ �Է� :");
		int myYear = sc.nextInt();
		int year = sysyear - myYear + 1;//��� ���̴� 1�����
		if(year >= 20) {
			System.out.println("�����Դϴ�");
		}
		else {
			System.out.println("�̼������Դϴ�");
		}
		sc.close();
	}

}
