package array;

public class Test02 {

	public static void main(String[] args) {
//아래의 형태가 되도록 2차원 배열을 구성하여 값을 대입 후 출력
		
//		1	2	3	4	5
//		6	7	8	9	10
//		11	12	13	14	15
//		16	17	18	19	20
//		21	22	23	24	25
		int[][] arr = new int[5][5];
		int cnt = 1;
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				arr[i][j] = cnt;
				cnt++;
			}
		}
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				System.out.print(arr[i][j]+"\t");
			}
			System.out.println();
		}
		
//		1	6	11	16	21
//		2	7	12	17	22
//		3	8	13	18	23
//		4	9	14	19	24
//		5	10	15	20	25
		int[][] arr1 = new int[5][5];
		cnt = 1;
		for(int i=0;i<5;i++) {
			for(int j=0; j<5; j++) {
				arr1[j][i] = cnt;
				cnt++;
			}
		}
		
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				System.out.print(arr1[i][j]+"\t");
			}
			System.out.println();
		}
	}

}
