package array;

import java.util.Scanner;

public class Test06 {

	public static void main(String[] args) {
		int[] arr1 = { 87, 11, 45, 98, 23 };
		Scanner sc = new Scanner(System.in);
		// ����1) �ε����� �Է¹޾� ���� ���
		// ����1) �ε��� �Է� : 1 ���� : 11��
		System.out.print("�ε��� �Է� :");
		int idx = sc.nextInt();
		System.out.println(arr1[idx]+"��");

		// ����2) ������ �Է¹޾� �ε��� ���
		// ����2) ���� �Է� : 11 �ε��� : 1
		int idx1 = -1;//�����ε�����ȣ
		System.out.print("���� �Է� :");
		int score = sc.nextInt();
		for(int i=0;i<arr1.length;i++) {
			if(score == arr1[i]) {
				idx1 = i;
			}
		}
		System.out.println("�ε��� : "+idx1);
		int[] hakbuns = { 1001, 1002, 1003, 1004, 1005 };
		int[] scores = { 87, 11, 45, 98, 23 };

		// ����3) �й��� �Է¹޾� ���� ���
		// ����3) �й� �Է� : 1003 ���� : 45��
		System.out.print("�й� �Է� :");
		int hakbun = sc.nextInt();
		for(int i=0;i<scores.length;i++) {
			if(hakbun == hakbuns[i]) {
				System.out.println("���� : "+scores[i]+"��");
			}
		}
	}

}
