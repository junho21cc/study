package array;

public class Test03 {

	public static void main(String[] args) {
//		�ֻ����� 10�� ���� ����� �����Ϸ��� �մϴ�
//		�迭�� �̿��Ͽ� ������ �����Ͻð� �Ʒ��� ����� ����ϼ���
		int[] arr = new int[10];
		//����=(int)(Math.random() *����)+���ۼ�
		for(int i=0;i<arr.length;i++) {
			int su = (int)(Math.random() * 6) + 1;
			//arr[i] = (int)(Math.random() * 6) + 1;
			arr[i] = su;
		}
		
//		[1] ��ü �ֻ��� ����� ���
		for(int i=0;i<arr.length;i++) {
			System.out.println((i+1)+"��° : "+arr[i]);
		}
		
//		[2] ¦�� �ֻ��� ����� ���
		for(int i=0;i<arr.length;i++) {
			if(arr[i] % 2 == 0) {
				System.out.println(i+1+"��° : "+arr[i]);
			}
		}
		
//		[3] �ֻ��� ������ �հ� ���
		int tot = 0;
		for(int i=0;i<5;i++) {
			tot += arr[i];
		}
		System.out.println(tot);

	}

}
