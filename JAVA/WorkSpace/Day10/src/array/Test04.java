package array;

public class Test04 {

	public static void main(String[] args) {
		int[] arr = new int[5];

		// ����1) arr�迭�� 1~100�� ������ ������ 5�� ����
		// ��   1) 87, 11, 92, 14, 47
		for(int i=0;i<arr.length;i++) {
			arr[i] = (int)(Math.random() * 100) + 1;
			System.out.print(arr[i]+"\t");
		}
		System.out.println();
		// ����2) �������� ������ ��� ���
		// ��   2) ����(251) ���(50.2)
		int tot = 0;
		for(int i=0;i<arr.length;i++) {
			tot += arr[i];
		}
		double avg = tot / 5.0;
		System.out.println("���� : "+tot+"��\t��� : "+avg+"��");
		
		// ����3) ������ 60�� �̻��̸� �հ�. �հݻ� �� ���
		// ��   3) 2��
		int cnt = 0;
		for(int i=0;i<arr.length;i++) {
			if(arr[i] >= 60) {
				cnt++;
			}
		}
		System.out.println("�հݻ� �� : "+cnt+"��");
	}

}
