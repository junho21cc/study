package ifelse;

import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//���ڸ� �Է¹ޱ�
		// ���� 1) ���, 0, ���� ���
		System.out.print("���� �Է� :");
		int num = sc.nextInt();
		if(num > 0) {
			System.out.println("���");
		}
		if(num < 0) {
			System.out.println("����");
		}
		if(num == 0) {
			System.out.println("0");
		}
		//sysout ctrl+�����̽��� -> �ڵ��ϼ�
		
		// ���� 2) 4�� ��� ���
		System.out.print("���� �Է� :");
		num = sc.nextInt();
		if(num % 4 == 0) {
			System.out.println("4�� ���");
		}
		else {
			System.out.println("4�� ����� �ƴϴ�");
		}
		
		// ���� 3) 80�� �̻� �հ�, ���հ� ���
		System.out.println("���� �Է� :");
		int score = sc.nextInt();
		if(score >= 80) {
			System.out.println("�հ�");
		}
		else {
			System.out.println("���հ�");
		}
	}

}
