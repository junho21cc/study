package forloop;

import java.util.Scanner;

public class Test03 {

	public static void main(String[] args) throws InterruptedException {
//		Ÿ�̸� �����
//	    ����ڿ��� ���� �Է¹޾Ƽ� �ش��ϴ� �ð��� �帥 �� �޼����� ��µǵ��� �ڵ屸��
		// (������)
		// �� �Է� : 3
		// 3�� 0�� ����
		// 2�� 59�� ����
		// ...
		// 0�� 2�� ����
		// 0�� 1�� ����
		// 0�� 0�� ����
		// �� !
		Scanner sc = new Scanner(System.in);
		System.out.print("�� �Է� :");
		int min = sc.nextInt();
		
		for(int s = min * 60;s >= 0; s--) {
			System.out.println(s/60+" �� "+s%60+" �� ����");
			Thread.sleep(1000);
			//���� ���ϴ� �ð���ŭ �ڵ带 ���ߴ� �޼ҵ�..
			// �и����� ������ �����Ͽ� �ð��� �����Ѵ�.
			// 1000ms == 1s
		}

	}

}
