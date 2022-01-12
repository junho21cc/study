package whileloop;

public class Test03 {

	public static void main(String[] args) {
		// 문제1) 1~5까지의 합 출력
		// 정답 1) 15
		int tot = 0;
		int i = 1;
		while(true) {
			tot = tot + i;//tot += i;
			if(i == 5) {
				break;
			}
			i++;
		}
		System.out.println(tot);
		i = 1;
		tot = 0;
		while(i <= 5) {
			tot += i;
			i++;
		}
		System.out.println(tot);
		// 문제2) 1~10까지 반복해 3미만 7이상만 출력
		// 정답2) 1, 2, 7, 8, 9, 10
		i = 1;
		while(true) {
			if(i < 3 || i>=7) {
				System.out.print(i+" ");
			}
			if(i == 10) {
				break;
			}
			i++;
		}
		System.out.println();
		i = 1;
		while(i<=10) {
			if(i < 3 || i >= 7) {
				System.out.print(i+ " ");
			}
			i++;
		}
		// 문제3) 문제2의 조건에 맞는 수들의 합 출력
		// 정답3) 37
		System.out.println();
		tot = 0;
		i = 1;
		while(true) {
			if(i < 3 || i>=7) {
				tot += i;// 1+ 2+ 7+ 8+ 9+ 10
			}
			if(i == 10) {
				break;
			}
			i++;
		}
		System.out.println(tot);
		i = 1;
		tot = 0;
		while(i<=10) {
			if(i<3 || i>=7) {
				tot += i;
			}
			i++;
		}
		System.out.println(tot);
		
		// 문제4) 문제2의 조건에 맞는 수들의 개수 출력
		// 정답4) 6
		int cnt = 0;
		i = 1;
		while(true) {
			if(i < 3 || i>=7) {
				cnt++;//1증가 cnt+=1; cnt =  cnt + 1;
			}
			if(i == 10) {
				break;
			}
			i++;
		}
		System.out.println(cnt);
		i = 1;
		cnt = 0;
		while(i<=10) {
			if(i < 3 || i>=7) {
				cnt++;//1증가 cnt+=1; cnt =  cnt + 1;
			}
			i++;
		}
		System.out.println(cnt);
	}

}
