javascript

변수
var(변수명)=(저장할값)

출력함수
console.log()

배열.push: 요소추가
배열.splice(지우고싶은인덱스, 지우고싶은개수): 특정요소 제거
배열.indexOF(값): 값에 대한 인덱스 찾기
배열.pop: 요소 마지막부터 출력

Math.random(): 0보다크고 1보다작은 무작위 수
Math.floor(값): 값에대해서 소수부분 삭제

<p id="text" class="content></p>
<script>
	var element = document.getElementById('text');
	var name = prompt('이름을 입력하세요.');
	element.innerText = name + '님, 안녕하세요.';
</script>