package array;

import java.util.Scanner;

public class Test05 {

	public static void main(String[] args) throws InterruptedException {
//		������� ġ�� ���α׷�
//
//		����ڿ��� 5���� �׸��� �Է¹޾� �迭�� ����
//		�������� 1������ ��÷�Ͽ� ȭ�鿡 ���
//
//		(��)	�׸� : ���
//			�׸� : ���
//			�׸� : ������
//			�׸� : �����
//			�׸� : ���뱹
//			��÷���Դϴ�....
//			��÷�� �׸��� ������ �Դϴ�
		String[] menu = new String[5];
		Scanner sc = new Scanner(System.in);
		
		for(int i=0;i<menu.length;i++) {
			System.out.print("�׸� �Է� :");
			//String name = sc.next();
			//menu[i] = name;
			menu[i] = sc.next();
		}
		System.out.println("��÷���Դϴ�...");
		Thread.sleep(1000);
		int rand = (int)(Math.random() * menu.length);//0 1 2 3 4
		System.out.println(menu[rand]);
		
	}

}
