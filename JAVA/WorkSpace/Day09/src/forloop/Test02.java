package forloop;

public class Test02 {

	public static void main(String[] args) {
//		���� �����Ϸ� �մϴ�
//		���� ������ ���� ���� ������ ���� �ι�� �� �����̰�
//		ù°���� 1���� �����Ϸ��� �մϴ�
//
//		(Q1)	30�ϵ��� ���忡 ����� ���� ���Դϱ�?
		int cost = 1;//���忡 ���� ��
		int tot = 0;//����
		for(int i=0;i<30;i++) {
			tot += cost;//tot = tot + cost;
			cost *= 2;
		}
		System.out.println(tot);
		
//		(Q2)	40�ϵ��� ���忡 ����� ���� ���Դϱ�?
		long tot1 = 0;
		//long cost1 = 1;
		for(long i=0 , cost1 = 1; i<40; i++, cost1 *= 2) {
			tot1 += cost1;
			//cost1 *= 2;
		}
		System.out.println(tot1);
		//for���� �ʱ���� 1���̻�, �������� 1�� �̻��� �����ϴ�.
		//�� , ���ǽ��� 1�������Ѵ�.
	}

}
