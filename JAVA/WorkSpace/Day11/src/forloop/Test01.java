package forloop;

public class Test01 {

	public static void main(String[] args) {
		//���� for��
		for(int i=1;i<=3;i++) {//�ܺ� for�� �ѹ�����
			System.out.println("========="+i+"��° �ܺ�for�� ����===========");
			for(int j=1;j<=3;j++) {//����for���� ���ǽ��� true�϶����� �ݺ�
				System.out.println("���� for�� ����");//�ܺ� : 3 ���� : 3 3*3 = 9
			}
			System.out.println("========="+i+"��° �ܺ�for�� ����===========");
		}

	}

}
