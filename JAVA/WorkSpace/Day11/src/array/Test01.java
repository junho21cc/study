package array;

public class Test01 {

	public static void main(String[] args) {
		
		//������ �迭
		// - �迭�� ��ø���� ������ ������ �迭
		// - �������� �迭 ������ ������ ������ �� �ִ� �迭
		
		//2�����迭
		// - 1�����迭�� �迭
		
		int[][] arr = null;
		
		// - �ν��Ͻ�����
		// new �ڷ���[����][����];
		// new �ڷ���[][]{ { ������,������..}, {������,������..}, {������,������..}};
		
		arr = new int[3][3];
		//�迭��[�����ε���][�����ε���]
		arr[0][1] = 2;
		System.out.println(arr[0][1]);
		arr[1][1] = 5;
		System.out.println(arr[1][1]);
		
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				System.out.print(arr[i][j]+"\t");
			}
			System.out.println();
		}
		
		arr = new int[][] {
			{1,2},
			{3,4,5,6},
			{7,8,9}
		};
		System.out.println(arr[1][2]);
		//System.out.println(arr[0][2]); - ������ �����Ƿ� error
		System.out.println(arr[2][2]);
		//arr[0] = new int[2];
		//arr[1] = new int[4];
		//arr[2] = new int[3];
		//System.out.println(arr[0][0]);
		
		for(int i=0;i<arr.length;i++) {//i = 0 // i = 1 // i =2
			//j = 0 , 1 
			//j = 0 , 1 , 2 ,3
			//j = 0 , 1 , 2
			for(int j=0;j<arr[i].length;j++) {
				System.out.print(arr[i][j]+"\t");
				//arr[0][0] arr[0][1]
				//arr[1][0] arr[1][1] arr[1][2] arr[1][3]
				//arr[2][0] arr[2][1] arr[2][2]
			}
			System.out.println();
		}

	}

}
