package variable;

public class Test01 {

	public static void main(String[] args) {
		//�Ǽ�
		
		//�Ǽ��� �ڷ��� - double	��ȿ�ڸ���
		// float 	4byte		7�ڸ�
		// double	8byte		15�ڸ�
		
		float a = 123.456f;//float�� Ư¡�� �Ǽ��ڿ� f�ٿ��� ���� �ʱ�ȭ�ؾ��Ѵ�.
		//�Ǽ��� ����� �⺻������ double��
		//float���� �νĽ�Ű���� ����ڿ� f�� �����ָ�ȴ�.
		double d = 123.456;
		
		//1.�ڷ����� ū�ʿ��� ���������� �̵��Ϸ��Ҷ��� Error�߻�
		// - ���� ũ���� �������� �Ǽ��� ũ��
		// - �����̶� �������� �ս��� �߻��� �� �ִ� ��Ȳ�̶�� eclipse����
		//   ����������.(�˷��ش�)
		
		// double > long > float > int > short == char > byte
		
		// CAST ������
		// (�ڷ���)���,����,(�����)
		// - ���� ���ϴ� ������ Ÿ������ �����͸� �Ͻ������� ��ȯ��Ű�� ������
		
		//a = 20; float�ڷ����� ���� 20 -> 20.0 ( �����ʿ��� ū������ ���ԵǾ��⶧���� )
		//System.out.println(a);
		
		//int b = a; int�ڷ����� float 20.0 x ( ū�ʿ��� ���������� ���ԵǾ��⶧���� )
		
		int b = (int)a;
		System.out.println(b);
		
		// 2. �Ǽ��� �Ѱ��� ���Ե� ���꿡���� �Ǽ����� ���´�..
		int kor = 60;
		int eng = 13;
		int math = 98;
		int sub = 3;//������ ����
		System.out.println((kor+eng) / 2);//(����+����) / ����
		System.out.println((kor+eng) / 2.0);//(����+����) / �Ǽ�
		System.out.println((kor+eng+math) / sub);
		System.out.println((double)(kor+eng+math) / sub);
		System.out.println((kor+eng+math) / (double)sub);
		
		// 3. ������ ��꿡���� �Ǽ��� ������� �ʴ´�.
		System.out.println(1.3 % 0.2);
		
	}

}
