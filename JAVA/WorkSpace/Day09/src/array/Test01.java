package array;

public class Test01 {

	public static void main(String[] args) {
		//������������ �Ϲݺ����� ������
		//�Ϲݺ����� null �ʱ�ȭ�� �����ʴ´�.
		
		//�Ϲݺ���
//		int a = 0;
//		a = null;
		
		//�迭 ������ ���� ����
		int[] arr = null;//����������
		
		//�ν��Ͻ� ���� - new
		arr = new int[3];
		
		System.out.println(arr.length);//�迭�� ������ �����ش�.
		
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		//arr[3] = 4;
		//System.out.println(arr[3]); - index�� ����⶧���� error
		for(int i=0;i<arr.length;i++) {
			System.out.println("arr["+i+"] = "+arr[i]);
		}
		
	}

}
