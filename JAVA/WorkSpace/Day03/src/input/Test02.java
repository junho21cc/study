package input;

import java.util.Scanner;

public class Test02 {

	public static void main(String[] args) {
//		���� ������ �����Ͻþ� ����ڿ��� �Է��� �޾� ������ ����Ͻÿ�
//
//		(��� ȭ��)	
//		�ڹ� ���� ���� �Է��ϼ���
//		95
//		���̽� ���� ���� �Է��ϼ���
//		80
//		�̸��� �Է��ϼ���
//		ȫ�浿
//		============================
//		ȫ�浿���� ���� �հ� = 175��, ��� = 87.5
//		��, �̸��� next��� x , nextLine��� o
		
		Scanner sc = new Scanner(System.in);
		System.out.println("�ڹ� ���� ���� �Է��ϼ���");
		int java = sc.nextInt();
		System.out.println("���̽� ���� ���� �Է��ϼ���");
		int python = sc.nextInt();
		System.out.println("�̸��� �Է��ϼ���");
		sc.nextLine();//buffer����
		String name = sc.nextLine();
		System.out.println("=============================");
		int tot = java + python;
		double avg = tot / 2.0;
		System.out.println(name+"���� ���� �հ� = "+tot+"��, ��� = "+avg);
	}

}
