package input;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		//System.in - ǥ�� �Է� ��ü
		//.read() - �����͸� 1byte�� �о���� ���
		
		//Scanner - �����͸� �о���� ���� ����
		//	- ���� , ���ڿ� , �Է½�Ʈ�� , URL..
		
		//Scanner �����
		//���� ����Ҷ� ���θ޼ҵ忡�� �ѹ��� ����� �ȴ�.
		Scanner sc = new Scanner(System.in);
		
		//.next() - �� �ܾ �о���� ���
		// - ���ڿ� ���·� �о�´�.
		// - ��, ���� ������ �о�´�.
		System.out.print("�̸� �Է� :");
		String name = sc.next();//���� �������� �Է¹޴´�.
		System.out.println("�̸� : "+name);
		
		//buffer
		// - �������� ����, �������� ó�� �ӵ�, ���ĵ��� ���� �ٸ� �� ��ġ��
		// ���α׷� ���̿��� �����͸� �ְ�ޱ� ���� �������� ���Ǵ� �ӽ� ��� ��ġ
		
		// - ��ǻ�Ϳ��� Ű���� �Է½ÿ��� �����͸� ���鹮�ڸ� �������� �����͸�
		//   �������´�..
		//   �����̽�, ��, ����..
		
		//JAVA������ �޼ҵ���� ù���ڴ� �ҹ��� �޶����� �ܾ��� ù���� �빮��
		//����, �Ǽ�..
		//.next�ڷ���();
		System.out.print("���� �Է� :");
		int age = sc.nextInt();
		System.out.println("���� : "+age);
		
		System.out.print("Ű �Է� :");
		double hei = sc.nextDouble();
		System.out.println("Ű : "+hei);
		
		//.nextLine() - �� ���� �о���� ���
		// - ��, \n(����)������ �о�´�.
		// - ���� �������� �о���°��� �ƴ϶�..\n�������� �����͸� �о�´�.
		// - ���𰡸� �Է¹��� �Ŀ� nextLine�� ����ϸ� ���ۿ� \n�� �����ֱ⶧����
		//   �����͸� �Է¹��� �ɷ� �ν��Ѵ�.. ���۾ȿ� ���Ͱ��� ����������Ѵ�.
		//			.nextLine()�� �ѹ� �� ���´�.
		sc.nextLine();//���۾ȿ� \n�� ����ش�.
		System.out.println("�ƹ��ų� �Ẹ����..");
		String str = sc.nextLine();
		System.out.println("str = "+str);
	}

}
