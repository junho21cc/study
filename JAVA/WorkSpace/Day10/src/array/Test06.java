package array;

import java.util.Scanner;

public class Test06 {

	public static void main(String[] args) {
		int[] arr1 = { 87, 11, 45, 98, 23 };
		Scanner sc = new Scanner(System.in);
		// 문제1) 인덱스를 입력받아 성적 출력
		// 정답1) 인덱스 입력 : 1 성적 : 11점
		System.out.print("인덱스 입력 :");
		int idx = sc.nextInt();
		System.out.println(arr1[idx]+"점");

		// 문제2) 성적을 입력받아 인덱스 출력
		// 정답2) 성적 입력 : 11 인덱스 : 1
		int idx1 = -1;//없는인덱스번호
		System.out.print("성적 입력 :");
		int score = sc.nextInt();
		for(int i=0;i<arr1.length;i++) {
			if(score == arr1[i]) {
				idx1 = i;
			}
		}
		System.out.println("인덱스 : "+idx1);
		int[] hakbuns = { 1001, 1002, 1003, 1004, 1005 };
		int[] scores = { 87, 11, 45, 98, 23 };

		// 문제3) 학번을 입력받아 성적 출력
		// 정답3) 학번 입력 : 1003 성적 : 45점
		System.out.print("학번 입력 :");
		int hakbun = sc.nextInt();
		for(int i=0;i<scores.length;i++) {
			if(hakbun == hakbuns[i]) {
				System.out.println("성적 : "+scores[i]+"점");
			}
		}
	}

}
