package ifelse;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
//		ȭ�鿡 �������� ������ 1������ ����(2�� ~ 15��)
	//	2 X 1 = 	���� 		15 X 9 = 		����
	//	����ڰ� ������ �Է��� �� �ֵ��� ���α׷��� �ڵ带 ����(Scanner)
	//	������ ��� �Ʒ��� ���� ó��
	//
	//	[1] ���� ���	����! 10�� ȹ��!
	//	[2] Ʋ�� ���	����! 5�� ����!
	//
	//	�߰�������, ����� ����(11�� �̻�)�� ���߸� 10���� �߰��� ȹ���ϵ��� �ڵ� ����
		Scanner sc = new Scanner(System.in);
		int dan = (int)(Math.random()*14) +2;//2~15
		int su = (int)(Math.random()*9)+1;//1~9
		int com = dan * su;
		System.out.print(dan+"x"+su+"=");
		int user = sc.nextInt();
		if(com == user) {
			System.out.println("���� ! 10�� ȹ�� !");
			if(dan >= 11) {
				System.out.println("����� ����! 10�� �߰� ȹ�� !");
			}
		}
		else {
			System.out.println("���� ! 5�� ���� !");
		}
	}

}
