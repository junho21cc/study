package variable;

public class Test02 {

	public static void main(String[] args) {
		//���� - boolean		1byte		true/false
		//���� ������ �����ϴ� �ڷ���
		// - true/ false
		// - � ����� ǥ���Ҷ� ���°��� �ΰ����� ���
		
		boolean a = true;//�� ( �´� )
		System.out.println(a);
		
		//���迬���� - �������� ���踦 �����ϴ� ������
		// < > <= >= == !=
		// == : ����
		// != : �ٸ���
		a = (10 > 5);
		System.out.println(a);
		
		a = (10 == 10);
		System.out.println(a);
		
		a = (10 != 10);
		System.out.println(a);
		
		//��������
		// - ���ǽĿ� ���� ���� ������ �Ǻ��ϴ� ������
		
		// && - and(����) - ���� ��� ���϶� ���� �߻�
		System.out.println(10 > 5 && 10 != 10);
		
		// || - or(����) - ���� �ϳ��� ���̸� ���� �߻�
		System.out.println(10 < 5 || 10 == 10);
		
		//true : 1		false : 0
		
		//���ǽ�	��������	 ���ǽ�	and		or
		//true			 true	true	true
		//false			 true	false	true
		//true			 false	false	true
		//false			 false	false	false
		
		// ! - not(����) - ���̸� ���� , �����̸� ��
		System.out.println(!(10>5));
		
	}

}
