package variable;

public class Test06 {

	public static void main(String[] args) {
		//��) ������ 1000���� �ִ�. 200��¥�� ���� ���� �� �ܵ����
		int price = 1000;
		int ���� = 200;
		int �ܵ� = price - ����;
		System.out.println("�ܵ� = "+�ܵ�+"��");
		
		// ����1) ������ 100���̴�. ������? (���� : ���� 10% ����)
		int ���� = 100;
		double ���� = ���� * 12 * 0.9;
		System.out.println("���� = "+����+"��");
		int ����1 = (int)����;//cast
		System.out.println("���� = "+����1+"��");

		// ����2) ���������� 30, 50, 4�� �� �޾Ҵ�. �����?
		int score1 = 30;
		int score2 = 50;
		int score3 = 4;
		int tot = score1 + score2 + score3;//����
		double avg = tot / 3.0;//���� / �Ǽ� -> �Ǽ�
		System.out.println("��� = "+avg+"��");

		// ����3) ���ΰ� 3�̰� ���ΰ� 6�� �ﰢ�� ���� ���
		int garo = 3;
		int sero = 6;
		double area = garo * sero / 2.0;
		System.out.println("�ﰢ���� ���� = "+area);

		// ����4) 100�ʸ� 1�� 40�ʷ� ���
		int su = 100;
		int m = su / 60;
		int s = su % 60;
		System.out.println(m+"�� "+s+"��");

		// ����5) 800������ 500��¥�� ���� , 100��¥�� ����
		// ����5) 500��(1��), 100��(3��)
		price = 800;//����ü
		int ����� = price / 500;//��
		int ��� = price % 500 / 100;
		//800 % 500 -> 300 / 100 -> 3
		System.out.println("500�� ="+�����+"��");
		System.out.println("100�� = "+���+"��");

	}

}
