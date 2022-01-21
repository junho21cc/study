package forloop;

public class Test02 {

	public static void main(String[] args) {
		//=========2´Ü==========
		//2 * 1 = 2
		//2 * 2 = 4
		// ...
		//2 * 9 = 18
		//======================
		//=========3´Ü==========
		//3 * 1 = 3
		//...
		for(int i=2;i<=9;i++) {
			System.out.println("============"+i+"´Ü===========");
			for(int j=1;j<=9;j++) {
				System.out.println(i+" * "+j+" = "+(i*j));
			}
			System.out.println("==============================");
		}

	}

}
