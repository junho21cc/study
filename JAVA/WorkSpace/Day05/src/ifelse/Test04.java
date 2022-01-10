package ifelse;

public class Test04 {

	public static void main(String[] args) {
		//Math.random()
		// - 0부터 1미만의 임의의 실수를 구하는 명령
		// - 0.0000 ~ 0.9999
		
		//내가 원하는 범위의 임의의 수 구하기
		// - (int)(Math.random() * 개수) + 시작수;
		int su = (int)(Math.random() * 3) + 9;//9 10 11
		//9~11까지 랜덤
		
		double a = Math.random();//0.0000~0.9999
		double b = a*3;//0.0000~2.9999
		int c = (int)b;//0 ~ 2
		int d = c + 9;// 9 ~ 11
		System.out.println(d);
		
		//1~10
		int rand = (int)(Math.random()*10)+1;//1 2 3 4 5 6 7 8 9 10
		System.out.println(rand);
		//5~10
		int rand1 = (int)(Math.random()*6)+5;//5 6 7 8 9 10
		System.out.println(rand1);
		
	}

}
