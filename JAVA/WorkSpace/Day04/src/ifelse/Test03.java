package ifelse;

import java.util.Scanner;

public class Test03 {

	public static void main(String[] args) {
		//�α���
		//1.���̵�� ��й�ȣ�� �Է¹޴´�.
		//2. �Է¹��� ���̵�� ��й�ȣ�� db�����͸� ���� �α��� ó���� �����Ѵ�.
		//ex) �α��� ���� or �α��� ����
		int dbId = 1234;
		int dbPw = 1111;
		Scanner sc = new Scanner(System.in);
		System.out.print("���̵� �Է� :");
		int userId = sc.nextInt();
		System.out.print("��й�ȣ �Է� :");
		int userPw = sc.nextInt();
		
//		if(userId == dbId && userPw == dbPw) {
//			System.out.println("�α��� ����!");
//		}
		if(userId == dbId) {
			if(userPw == dbPw) {
				System.out.println("�α��� ����!");
			}
			else {
				System.out.println("��й�ȣ�� �ٸ��ϴ�");
			}
		}
		else {
			System.out.println("���̵� �ٸ��ϴ�");
		}
//		else {
//			System.out.println("�α��� ����!");
//		}
		if(userId != dbId || userPw != dbPw) {
			System.out.println("�α��� ����!");
		}
		
		//ȸ������ �� �α���
		//1. ��������
		
		//2. �ܺ�if�ȿ� ����if
		
	}

}
