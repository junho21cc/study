package ifelse;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		int a = 9;
		int b = 9;
		
		//if���� ���ǽ��� true�϶� �����Ѵ�.
		if(a >= 10) { //�ܼ�if
			System.out.println("a�� 10�̻��̴�");
			System.out.println("a�� 10�̻��̴�");
		}
		
		if(a==b)//�ܼ� if
			System.out.println("a�� ���� b�� ���� �����ϴ�");
		//{}�� ���δ� ���� ���ӹ����� 1�� �ʰ��϶�..
		//{}�� �Ⱦ����� ���ӹ����� 1���϶�..
		
		//ex) Ȧ ¦
		Scanner sc = new Scanner(System.in);
		System.out.print("���ڸ� �Է� :");
		int num = sc.nextInt();
		
		//¦��
		if(num % 2 == 0) {
			System.out.println("¦���̴�");
		}
		if(num % 2 == 1) {//Ȧ��
			System.out.println("Ȧ���̴�");
		}
		
		if(num % 2 == 0) {
			System.out.println("¦��");
		}
		else {//�� ���ǽ��� �����϶� ����ȴ�.
			System.out.println("Ȧ��");
		}
	}

}
